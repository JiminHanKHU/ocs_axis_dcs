#ifndef _AxisMainCtrlSetup_h_
#define _AxisMainCtrlSetup_h_

#include <msgpack.hpp>
#include <ocs_core_fwk.h>
#include <ocs_ctrl_fwk.h>
#include "../../include/axis_dcs_port_types.h"

namespace gmt
{

struct AxisMainCtrlSetup : public  BaseControllerSetup
{

    struct PropertyConf : public  BaseControllerSetup::PropertyConf
    {
        PropertyDef<int>               position_min;
        PropertyDef<int>               position_max;
        PropertyDef<int>               position_captured;
        MSGPACK_DEFINE_MAP(uri, name, host, port, scan_rate, position_min, position_max, position_captured, acl, priority)
    };

    struct StateVarConf : public  BaseControllerSetup::StateVarConf
    {
        StateVarDef<motor_control>     servo_motor_control;
        StateVarDef<motor_state>       servo_motor_state;
        MSGPACK_DEFINE_MAP(servo_motor_control, servo_motor_state, op_state, sim_mode, control_mode)
    };

    struct InputConf : public BaseControllerSetup::InputConf
    {
        DataIODef<axis_state>          axis_state_port;
        DataIODef<axis_sdo_data>       axis_sdo_in;
        DataIODef<axis_ro_sdo_data>    axis_ro_sdo_in;
        DataIODef<hmi_input>           hmi_input_port;
        DataIODef<motor_control>       servo_motor_control_goal;
        DataIODef<motor_state>         servo_motor_state_goal;
        MSGPACK_DEFINE_MAP(axis_state_port, axis_sdo_in, axis_ro_sdo_in, hmi_input_port, servo_motor_control_goal, servo_motor_state_goal, op_state_goal, sim_mode_goal, control_mode_goal)
    };

    struct OutputConf : public BaseControllerSetup::OutputConf
    {
        DataIODef<axis_control>        axis_control_port;
        DataIODef<axis_sdo_data>       axis_sdo_out;
        DataIODef<hmi_output>          hmi_output_port;
        DataIODef<motor_control>       servo_motor_control_value;
        DataIODef<motor_state>         servo_motor_state_value;
        MSGPACK_DEFINE_MAP(axis_control_port, axis_sdo_out, hmi_output_port, servo_motor_control_value, servo_motor_state_value, op_state_value, sim_mode_value, control_mode_value)
    };

    PropertyConf     properties;
    StateVarConf     state_vars;
    InputConf        inputs;
    OutputConf       outputs;

    MSGPACK_DEFINE_MAP(properties, state_vars, inputs, outputs, connectors)
};

} //namespace gmt

#endif // _AxisMainCtrlSetup_h_
