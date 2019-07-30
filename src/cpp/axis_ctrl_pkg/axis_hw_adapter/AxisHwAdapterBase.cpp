// GMT AUTO GENERATED CODE

#include "AxisHwAdapterSetup.h"
#include "AxisHwAdapterBase.h"

using namespace std;
using namespace gmt;

AxisHwAdapterBase::AxisHwAdapterBase(
                            const string& comp_uri,
                            const string& comp_name,
                            const string& comp_host,
                            int comp_port,
                            const string& comp_acl,
                            double comp_scan_rate,
                            int comp_prio,
                            int comp_stack_size)
    : EthercatAdapter(comp_uri, comp_name, comp_host, comp_port, comp_acl, comp_scan_rate, comp_prio, comp_stack_size)
    
{
}

AxisHwAdapterBase::~AxisHwAdapterBase()
{
}

void AxisHwAdapterBase::create_state()
{
    //create the features inherited from the base class
    Base::create_state();

    //create the input dataio of the class, and assign the default value
    new_input_dataio(axis_control_port,         "axis_control_port",     axis_control());
    new_input_dataio(axis_sdo_in,               "axis_sdo_in",           axis_sdo_data());
    new_input_dataio(hmi_output_port,           "hmi_output_port",       hmi_output());

    //create the output dataio of the class, and assign the default value
    new_output_dataio(axis_state_port,           "axis_state_port",       axis_state());
    new_output_dataio(axis_sdo_out,              "axis_sdo_out",          axis_sdo_data());
    new_output_dataio(axis_ro_sdo_out,           "axis_ro_sdo_out",       axis_ro_sdo_data());
    new_output_dataio(hmi_input_port,            "hmi_input_port",        hmi_input());

    //create the state vars of the class and assign the "class" default value

    //create the properties of the class and assign the "class" default value
}

//reads and unpacks the configuration file, and calls the setup() method with
//the decoded configuration
void AxisHwAdapterBase::configure_from_file (const std::string& fname)
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

void AxisHwAdapterBase::setup_state(ComponentSetup& config)
{
    Setup::StateVarConf&  sv_conf        = dynamic_cast<Setup&>(config).state_vars;
    Setup::InputConf&     input_confs    = dynamic_cast<Setup&>(config).inputs;
    Setup::OutputConf&    output_confs   = dynamic_cast<Setup&>(config).outputs;
    Setup::PropertyConf&  property_confs = dynamic_cast<Setup&>(config).properties;

    log_info("state setup");

    // create inputs
    new_input_dataio(axis_control_port,         "axis_control_port",     input_confs.axis_control_port);
    new_input_dataio(axis_sdo_in,               "axis_sdo_in",           input_confs.axis_sdo_in);
    new_input_dataio(hmi_output_port,           "hmi_output_port",       input_confs.hmi_output_port);
    new_input_dataio(sdo_read_update_req,       "sdo_read_update_req",   input_confs.sdo_read_update_req);
    new_input_dataio(sdo_write_enable,          "sdo_write_enable",      input_confs.sdo_write_enable);

    // create outputs
    new_output_dataio(axis_state_port,          "axis_state_port",       output_confs.axis_state_port);
    new_output_dataio(axis_sdo_out,             "axis_sdo_out",          output_confs.axis_sdo_out);
    new_output_dataio(axis_ro_sdo_out,          "axis_ro_sdo_out",       output_confs.axis_ro_sdo_out);
    new_output_dataio(hmi_input_port,           "hmi_input_port",        output_confs.hmi_input_port);
    new_output_dataio(sdo_read_update_done,     "sdo_read_update_done",  output_confs.sdo_read_update_done);

    // Create state variables
    new_state_var(op_state,                     "op_state",              sv_conf.op_state,             input_confs.op_state_goal,    output_confs.op_state_value);

    // Create properties
    new_property(uri,                           "uri",                   property_confs.uri);
    new_property(name,                          "name",                  property_confs.name);
    new_property(host,                          "host",                  property_confs.host);
    new_property(port,                          "port",                  property_confs.port);
    new_property(scan_rate,                     "scan_rate",             property_confs.scan_rate);
    new_property(acl,                           "acl",                   property_confs.acl);
    new_property(priority,                      "priority",              property_confs.priority);
    new_property(ecat_cfg_name,                 "ecat_cfg_name",         property_confs.ecat_cfg_name);

    // create data_object references
    create_data_object_ref(axis_control_port.control_word,          "control_word");
    create_data_object_ref(axis_control_port.target_velocity,       "target_velocity");
    create_data_object_ref(axis_state_port.status_word,             "status_word");
    create_data_object_ref(axis_state_port.position,                "position");
    create_data_object_ref(axis_state_port.actual_velocity,         "actual_velocity");
    create_data_object_ref(hmi_input_port.switch_home,              "input1");
    create_data_object_ref(hmi_input_port.switch_limit_max,         "input2");
    create_data_object_ref(hmi_input_port.switch_limit_min,         "input3");
    create_data_object_ref(hmi_output_port.pilot_led,               "output1");
    create_data_object_ref(axis_sdo_out.velocity_limitation,        "TxSDO_velocity_limitation");
    create_data_object_ref(axis_sdo_in.velocity_limitation,         "RxSDO_velocity_limitation");
    create_data_object_ref(axis_sdo_out.singleturn_bits,            "TxSDO_singleturn_bits");
    create_data_object_ref(axis_sdo_in.singleturn_bits,             "RxSDO_singleturn_bits");
    create_data_object_ref(axis_ro_sdo_out.max_speed,               "RoSDO_max_speed");
    create_data_object_ref(axis_ro_sdo_out.velocity_encoder_resolution, "RoSDO_velocity_encoder_resolution");
}
