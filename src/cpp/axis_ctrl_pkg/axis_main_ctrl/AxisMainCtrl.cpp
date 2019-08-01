#include "AxisMainCtrl.h"

using namespace std;
using namespace gmt;

AxisMainCtrl::AxisMainCtrl(
                            const string& comp_uri,
                            const string& comp_name,
                            const string& comp_host,
                            int comp_port,
                            const string& comp_acl,
                            double comp_scan_rate,
                            int comp_prio,
                            int comp_stack_size)
    : AxisMainCtrlBase(comp_uri, comp_name, comp_host, comp_port, comp_acl, comp_scan_rate, comp_prio, comp_stack_size)
{

}

AxisMainCtrl::~AxisMainCtrl()
{
}

void AxisMainCtrl::step()
{
	   // Implement activation state machine for EL7211
    if ((axis_state_port.status_word >> 3) & 0x01) { // EL7211 status: fault
        axis_control_port.control_word = 0x80;
        log_info("EL7211 status: fault");
    } else if ((axis_state_port.status_word >> 6) & 0x01) { // EL7211 status: disabled
        axis_control_port.control_word = 0x06;
        log_info("EL7211 status: switch on disabled");
    } else if (((axis_state_port.status_word >> 0) & 0x01) &&
               !((axis_state_port.status_word >> 1) & 0x01)) { // EL7211 status: ready and no switched on
        axis_control_port.control_word = 0x07;
        log_info("EL7211 status: ready to switch on");
    } else if ((axis_state_port.status_word >> 1) & 0x01) { // EL7211 status: switched on
        if (axis_control_port.control_word != 0xf) {
            log_info("EL7211 status: Switched on");
      }
      axis_control_port.control_word = 0xf;
    }
    //Top priority
    gfloat_one_rpm_increments = axis_ro_sdo_in.velocity_encoder_resolution/60.0;
    if (hmi_input_port.switch_home){position_captured = axis_state_port.position;}
    servo_motor_state.value.home_offset = position_captured - axis_state_port.position;
    servo_motor_state.value.position_absolute = -(servo_motor_state.value.home_offset);


    // motor home initializing 
    if (!servo_motor_state.value.home_init){ 
      axis_control_port.target_velocity = -120 * gfloat_one_rpm_increments; //move to CCW to find the home switch
      state_msg("home init");
      if(timer_start(20)){ // home init timer
	      stop();
	      state_msg("failed to home init");
              return;
      }
      if (hmi_input_port.switch_home){ // when find the home
        axis_control_port.target_velocity =0;
        servo_motor_state.value.home_init= true; // no more init
	timer_kill();
	}
    }

    // check safety of current motor state;
    else if(!safety_state()){}

    // motor control
    else{
      switch (servo_motor_control.value.mode){ //select mode  
        case 0: {stop();break;}                                                 //stop and wait
   	case 1: {homing(); break;}                                              //homing
        case 2: {move_to_position(servo_motor_control.value.position); break;}  //move to position
        case 3: {manual(); break;}                                              //move with velocity
      }
      safety_command(); // check safety of motor command
    }    
}

void AxisMainCtrl::stop() //stop the motor and change the mode to 0
{
    servo_motor_control.value.mode = 0;
    servo_motor_control.value.stop = true;
    axis_control_port.target_velocity = 0;
    state_msg("stop");
}	


bool AxisMainCtrl::safety_state() //safety state function
{
      if (servo_motor_state.value.position_absolute > position_max+20){ //20 is oscillating offset
        stop();
        state_msg("limit_max");
        move_to_position(position_max);
      }
      else if (servo_motor_state.value.position_absolute < position_min-20){ //20 is oscillation offset
	stop();
	state_msg("limit_min");
        move_to_position(position_min);	
      }
      else if ((((servo_motor_state.value.position_absolute==position_max || servo_motor_state.value.position_absolute==position_min) && axis_control_port.target_velocity != 0)
	       || servo_motor_control.value.stop == true)
               || hmi_input_port.switch_limit_min == true
	       || hmi_input_port.switch_limit_max == true
	       || hmi_input_port.switch_home == true) {
        stop();
      }  
      else {return true;} //safety
      return false; //unsafety
}

void AxisMainCtrl::safety_command() //prevent to over the limits by current commands
{
    int offset_min = abs(servo_motor_state.value.position_absolute - position_min);
    int offset_max = abs(servo_motor_state.value.position_absolute - position_max);  
    if (axis_control_port.target_velocity < 0  && abs(axis_control_port.target_velocity) >= offset_min){
      move_to_position(position_min);
    } 
    if (axis_control_port.target_velocity > 0 && abs(axis_control_port.target_velocity) >= offset_max){
    move_to_position(position_max);
    }
}

void AxisMainCtrl::manual() //velocity mode
{
    axis_control_port.target_velocity = servo_motor_control.value.speed * gfloat_one_rpm_increments;
    state_reset();
    state_msg("moving");
}	

bool AxisMainCtrl::move_to_position(int position_goal)
{
    int position_offset = position_goal - servo_motor_state.value.position_absolute;
    if (position_offset == 0){
      state_reset();
      stop();
      return true;
    }
    else{
      axis_control_port.target_velocity = abs(servo_motor_control.value.speed) * gfloat_one_rpm_increments;
      if (position_offset < 0){axis_control_port.target_velocity *= -1;} // velocity sign

      while (abs(position_offset) < abs(axis_control_port.target_velocity) && abs(position_offset) >10 ){ //slow down 
          axis_control_port.target_velocity /= 3;
      }
      if (abs(position_offset) <= 10) {axis_control_port.target_velocity = 1;} //slow down

      state_reset();
      state_msg("moving");
      return false;
    }
}	

void AxisMainCtrl::homing()
{
      state_reset();
      if (move_to_position(0)){ //when homed
        servo_motor_state.value.homed=true;
        hmi_output_port.pilot_led = true;
      }
      else {servo_motor_state.value.home_in_progress=true;}
}

bool AxisMainCtrl::timer_start(int timeout)
{
    if(is_step_rate(100))
      servo_motor_state.value.home_init_time++;
    if(servo_motor_state.value.home_init_time >= timeout) {return true;}
    return false;
}
void AxisMainCtrl::timer_kill()
{
    servo_motor_state.value.home_init_time=0;
}

void AxisMainCtrl::state_reset()
{
    servo_motor_state.value.home_in_progress=false;
    servo_motor_state.value.homed=false;
    hmi_output_port.pilot_led = false;
}

void AxisMainCtrl::state_msg(std::string msg)
{
servo_motor_state.value.state = msg;
}

void AxisMainCtrl::setup()
{
    servo_motor_state.value.home_init=false;

    servo_motor_control.value.mode = 0;
    servo_motor_control.value.speed = 60;
    servo_motor_control.value.position = position_min*2;
    servo_motor_control.value.stop = true;

    servo_motor_state.value.home_in_progress=false;
    servo_motor_state.value.homed=false;
    servo_motor_state.value.home_init_time=0;

    hmi_output_port.pilot_led = false;
}
