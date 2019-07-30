#ifndef _AxisHwAdapterBase_h_
#define _AxisHwAdapterBase_h_

// GMT AUTO GENERATED CODE

#include <ocs_core_fwk.h>
#include <ocs_io_fwk.h>
#include "../../include/axis_dcs_port_types.h"

class AxisHwAdapterSetup;

namespace gmt
{

class AxisHwAdapterBase : public EthercatAdapter
{
    public:
        AxisHwAdapterBase(
                        const  std::string& comp_uri,
                        const  std::string& comp_name,
                        const  std::string& comp_host,
                        int    comp_port,
                        const  std::string& comp_acl,
                        double comp_scan_rate = 1.0,
                        int comp_prio = GMT_THREAD_DEFAULT_PRIO,
                        int comp_stack_size = GMT_DEFAULT_STACK_SIZE);

        virtual ~AxisHwAdapterBase();

    protected:

        typedef AxisHwAdapterSetup Setup;
        typedef EthercatAdapter Base;

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

        // Inputs declaration
        axis_control             axis_control_port;   // Control (write) variables
        axis_sdo_data            axis_sdo_in;         // SDO (read) get configurations
        hmi_output               hmi_output_port;     // SDO (read) get configurations

        // Outputs declaration
        axis_state               axis_state_port;     // State (read) variables
        axis_sdo_data            axis_sdo_out;        // SDO (read) get configurations
        axis_ro_sdo_data         axis_ro_sdo_out;     // SDO (read) get configurations
        hmi_input                hmi_input_port;      // digit input variables

        // Configuration properties
};

} // namespace gmt

#endif   // _AxisHwAdapterBase_h_
