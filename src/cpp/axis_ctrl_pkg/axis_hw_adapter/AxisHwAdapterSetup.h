#ifndef _AxisHwAdapterSetup_h_
#define _AxisHwAdapterSetup_h_

#include <msgpack.hpp>
#include <ocs_core_fwk.h>
#include <ocs_io_fwk.h>
#include "../../include/axis_dcs_port_types.h"

namespace gmt
{

struct AxisHwAdapterSetup : public  EthercatAdapterSetup
{

    struct PropertyConf : public  EthercatAdapterSetup::PropertyConf
    {
        MSGPACK_DEFINE_MAP(uri, name, host, port, scan_rate, acl, priority, ecat_cfg_name)
    };

    struct StateVarConf : public  EthercatAdapterSetup::StateVarConf
    {
        MSGPACK_DEFINE_MAP(op_state)
    };

    struct InputConf : public EthercatAdapterSetup::InputConf
    {
        DataIODef<axis_control>        axis_control_port;
        DataIODef<axis_sdo_data>       axis_sdo_in;
        DataIODef<hmi_output>          hmi_output_port;
        MSGPACK_DEFINE_MAP(axis_control_port, axis_sdo_in, hmi_output_port, sdo_read_update_req, sdo_write_enable, op_state_goal)
    };

    struct OutputConf : public EthercatAdapterSetup::OutputConf
    {
        DataIODef<axis_state>          axis_state_port;
        DataIODef<axis_sdo_data>       axis_sdo_out;
        DataIODef<axis_ro_sdo_data>    axis_ro_sdo_out;
        DataIODef<hmi_input>           hmi_input_port;
        MSGPACK_DEFINE_MAP(axis_state_port, axis_sdo_out, axis_ro_sdo_out, hmi_input_port, sdo_read_update_done, op_state_value)
    };

    PropertyConf     properties;
    StateVarConf     state_vars;
    InputConf        inputs;
    OutputConf       outputs;

    MSGPACK_DEFINE_MAP(properties, state_vars, inputs, outputs, connectors)
};

} //namespace gmt

#endif // _AxisHwAdapterSetup_h_
