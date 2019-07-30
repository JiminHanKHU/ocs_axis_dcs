Adapter            'axis_hw_adapter',
  info: 'HDK Hw Adapter'
  desc: 'This component defines the interface with the HDK Actuators and Sensors'
  abstract: false
  extends: ['EthercatAdapter']
  uses: ["ocs_core_fwk", "ocs_io_fwk"]

  input_ports:
    axis_control_port: {
      type: 'axis_control',
      protocol: 'pull',
      max_rate: 1000,
      owner: true,
      blocking_mode: 'sync',
      desc: 'Control (write) variables'
    }

    axis_sdo_in: {
      type: 'axis_sdo_data',
      protocol: 'pull',
      max_rate: 1000,
      owner: true,
      blocking_mode: 'sync',
      desc: 'SDO (read) get configurations'
    }

    hmi_output_port: {
      type: 'hmi_output',
      protocol: 'pull',
      max_rate: 1000,
      owner: true,
      blocking_mode: 'sync',
      desc: 'SDO (read) get configurations'
    }

  output_ports:
    axis_state_port: {
      type: 'axis_state',
      protocol: 'push',
      max_rate: 1000,
      owner: false,
      blocking_mode: 'sync',
      desc: 'State (read) variables'
    }

    axis_sdo_out: {
      type: 'axis_sdo_data',
      protocol: 'push',
      max_rate: 1000,
      owner: false,
      blocking_mode: 'sync',
      desc: 'SDO (read) get configurations'
    }

    axis_ro_sdo_out: {
      type: 'axis_ro_sdo_data',
      protocol: 'push',
      max_rate: 1000,
      owner: false,
      blocking_mode: 'sync',
      desc: 'SDO (read) get configurations'
    }

    hmi_input_port: {
      type: 'hmi_input',
      protocol: 'push',
      max_rate: 1000,
      owner: false,
      blocking_mode: 'sync',
      desc: 'digit input variables'
    }


  data_object_map: [
    {data_object: "control_word", port: "axis_control_port", field: "control_word"}
    {data_object: "target_velocity", port: "axis_control_port", field: "target_velocity"}
    {data_object: "status_word", port: "axis_state_port", field: "status_word"}
    {data_object: "position", port: "axis_state_port", field: "position"}
    {data_object: "actual_velocity", port: "axis_state_port", field: "actual_velocity"}

    {data_object: "input1", port: "hmi_input_port", field: "switch_home"}
    {data_object: "input2", port: "hmi_input_port", field: "switch_limit_max"}
    {data_object: "input3", port: "hmi_input_port", field: "switch_limit_min"}

    {data_object: "output1", port: "hmi_output_port", field: "pilot_led"}

    #SDO Data
    {data_object: "TxSDO_velocity_limitation", port: "axis_sdo_out", field: "velocity_limitation"}
    {data_object: "RxSDO_velocity_limitation", port: "axis_sdo_in",  field: "velocity_limitation"}
    {data_object: "TxSDO_singleturn_bits",     port: "axis_sdo_out", field: "singleturn_bits"}
    {data_object: "RxSDO_singleturn_bits",     port: "axis_sdo_in",  field: "singleturn_bits"}
  
    #Read Only SDO Data
    {data_object: "RoSDO_max_speed",                   port: "axis_ro_sdo_out", field: "max_speed"}
    {data_object: "RoSDO_velocity_encoder_resolution", port: "axis_ro_sdo_out", field: "velocity_encoder_resolution"}      
    #{data_object: "RoSDO_brake_type",          port: "axis_ro_sdo_out", field: "brake_type"}

  ]

  properties:
    uri: {default: "gmt://127.0.0.1/axis_dcs"}
    name: {default: "axis_hw_adapter"}
    host: {default: "127.0.0.1"}
    port: {default: 10000}
    scan_rate: {default: 100}

  instance_configurations: ['axis_hw1_adapter']
