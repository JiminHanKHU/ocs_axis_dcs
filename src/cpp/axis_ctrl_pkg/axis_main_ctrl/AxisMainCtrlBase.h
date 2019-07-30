#ifndef _AxisMainCtrlBase_h_
#define _AxisMainCtrlBase_h_

// GMT AUTO GENERATED CODE

#include <ocs_core_fwk.h>
#include <ocs_ctrl_fwk.h>
#include "../../include/axis_dcs_port_types.h"

class AxisMainCtrlSetup;

namespace gmt
{

class AxisMainCtrlBase : public BaseController
{
    public:
        AxisMainCtrlBase(
                        const  std::string& comp_uri,
                        const  std::string& comp_name,
                        const  std::string& comp_host,
                        int    comp_port,
                        const  std::string& comp_acl,
                        double comp_scan_rate = 1.0,
                        int comp_prio = GMT_THREAD_DEFAULT_PRIO,
                        int comp_stack_size = GMT_DEFAULT_STACK_SIZE);

        virtual ~AxisMainCtrlBase();

    protected:

        typedef AxisMainCtrlSetup Setup;
        typedef BaseController Base;

        /**
        * Creates the state of the Component, i.e., state variables,
        * inputs, outputs, properties, alarms and faults
        * Overriden from the Component class
        */
        virtual void create_state() override;

        /**
        * Uses the given Component::Setup parameter to configure all the
        * Component interface features (state vars, inputs, outputs, properties, ...)
        * Overriden from the Component class
        */
        virtual void setup_state (ComponentSetup& conf) override;

        /**
        * Configure the object from a file. The classes that derive from Component
        * must reimplement this method, in order to unpack the binary contents of
        * the configuration file with their Setup structure.
        * Overriden from the Component class
        */
        virtual void configure_from_file (const std::string& fname) override;

    protected:

        // Create state variables
        StateVar<motor_control>        servo_motor_control;
        StateVar<motor_state>          servo_motor_state;

        // Inputs declaration
        axis_state               axis_state_port;     // EL7211 State (read) variables
        axis_sdo_data            axis_sdo_in;         // EL7211 sdo variables
        axis_ro_sdo_data         axis_ro_sdo_in;      // EL7211 ro sdo variables
        hmi_input                hmi_input_port;      // hmi input

        // Outputs declaration
        axis_control             axis_control_port;   // EL7211 Control (write) variables
        axis_sdo_data            axis_sdo_out;        // EL7211 sdo  variables
        hmi_output               hmi_output_port;     // hmi_output_port

        // Configuration properties
        int                      position_min;        // undefined
        int                      position_max;        // undefined
        int                      position_captured;   // undefined
};

} // namespace gmt

#endif   // _AxisMainCtrlBase_h_
