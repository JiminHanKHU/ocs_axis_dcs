// GMT AUTO GENERATED CODE

#include "AxisMainCtrlSetup.h"
#include "AxisMainCtrlBase.h"

using namespace std;
using namespace gmt;

AxisMainCtrlBase::AxisMainCtrlBase(
                            const string& comp_uri,
                            const string& comp_name,
                            const string& comp_host,
                            int comp_port,
                            const string& comp_acl,
                            double comp_scan_rate,
                            int comp_prio,
                            int comp_stack_size)
    : BaseController(comp_uri, comp_name, comp_host, comp_port, comp_acl, comp_scan_rate, comp_prio, comp_stack_size)
    , servo_motor_control("servo_motor_control", motor_control(), true)
    , servo_motor_state("servo_motor_state", motor_state(), true)
    
    
    
{
}

AxisMainCtrlBase::~AxisMainCtrlBase()
{
}

void AxisMainCtrlBase::create_state()
{
    //create the features inherited from the base class
    Base::create_state();

    //create the input dataio of the class, and assign the default value
    new_input_dataio(axis_state_port,           "axis_state_port",       axis_state());
    new_input_dataio(axis_sdo_in,               "axis_sdo_in",           axis_sdo_data());
    new_input_dataio(axis_ro_sdo_in,            "axis_ro_sdo_in",        axis_ro_sdo_data());
    new_input_dataio(hmi_input_port,            "hmi_input_port",        hmi_input());

    //create the output dataio of the class, and assign the default value
    new_output_dataio(axis_control_port,         "axis_control_port",     axis_control());
    new_output_dataio(axis_sdo_out,              "axis_sdo_out",          axis_sdo_data());
    new_output_dataio(hmi_output_port,           "hmi_output_port",       hmi_output());

    //create the state vars of the class and assign the "class" default value
    new_state_var(servo_motor_control,       "servo_motor_control",   motor_control());
    new_state_var(servo_motor_state,         "servo_motor_state",     motor_state());

    //create the properties of the class and assign the "class" default value
    new_property(position_min,              "position_min",          int());
    new_property(position_max,              "position_max",          int());
    new_property(position_captured,         "position_captured",     int());
}

//reads and unpacks the configuration file, and calls the setup() method with
//the decoded configuration
void AxisMainCtrlBase::configure_from_file (const std::string& fname)
{
    try
    {
        log_info ("Configure from file "+fname);
        Setup conf;

        load_conf_file (fname, conf);
        setup_wrapper (conf);
    }
    catch (std::exception& ex)
    {
        throw std::runtime_error("ERROR while opening configuration file "+fname+": "+ex.what());
    }
    catch (...)
    {
        throw std::runtime_error("ERROR while opening configuration file "+fname);
    }

    log_info ("Configuration applied!");
}

void AxisMainCtrlBase::setup_state(ComponentSetup& config)
{
    Setup::StateVarConf&  sv_conf        = dynamic_cast<Setup&>(config).state_vars;
    Setup::InputConf&     input_confs    = dynamic_cast<Setup&>(config).inputs;
    Setup::OutputConf&    output_confs   = dynamic_cast<Setup&>(config).outputs;
    Setup::PropertyConf&  property_confs = dynamic_cast<Setup&>(config).properties;

    log_info("state setup");

    // create inputs
    new_input_dataio(axis_state_port,           "axis_state_port",       input_confs.axis_state_port);
    new_input_dataio(axis_sdo_in,               "axis_sdo_in",           input_confs.axis_sdo_in);
    new_input_dataio(axis_ro_sdo_in,            "axis_ro_sdo_in",        input_confs.axis_ro_sdo_in);
    new_input_dataio(hmi_input_port,            "hmi_input_port",        input_confs.hmi_input_port);

    // create outputs
    new_output_dataio(axis_control_port,        "axis_control_port",     output_confs.axis_control_port);
    new_output_dataio(axis_sdo_out,             "axis_sdo_out",          output_confs.axis_sdo_out);
    new_output_dataio(hmi_output_port,          "hmi_output_port",       output_confs.hmi_output_port);

    // Create state variables
    new_state_var(servo_motor_control,          "servo_motor_control",   sv_conf.servo_motor_control,  input_confs.servo_motor_control_goal, output_confs.servo_motor_control_value);
    new_state_var(servo_motor_state,            "servo_motor_state",     sv_conf.servo_motor_state,    input_confs.servo_motor_state_goal, output_confs.servo_motor_state_value);
    new_state_var(op_state,                     "op_state",              sv_conf.op_state,             input_confs.op_state_goal,    output_confs.op_state_value);
    new_state_var(sim_mode,                     "sim_mode",              sv_conf.sim_mode,             input_confs.sim_mode_goal,    output_confs.sim_mode_value);
    new_state_var(control_mode,                 "control_mode",          sv_conf.control_mode,         input_confs.control_mode_goal, output_confs.control_mode_value);

    // Create properties
    new_property(uri,                           "uri",                   property_confs.uri);
    new_property(name,                          "name",                  property_confs.name);
    new_property(host,                          "host",                  property_confs.host);
    new_property(port,                          "port",                  property_confs.port);
    new_property(scan_rate,                     "scan_rate",             property_confs.scan_rate);
    new_property(position_min,                  "position_min",          property_confs.position_min);
    new_property(position_max,                  "position_max",          property_confs.position_max);
    new_property(position_captured,             "position_captured",     property_confs.position_captured);
    new_property(acl,                           "acl",                   property_confs.acl);
    new_property(priority,                      "priority",              property_confs.priority);

}
