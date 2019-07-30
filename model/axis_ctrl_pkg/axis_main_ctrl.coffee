Controller         'axis_main_ctrl',
  info: 'EL7211 main Controller'
  desc: 'This component implements the control of the EL7211 module'
  extends: ['BaseController']
  abstract: false
  uses: ["ocs_core_fwk", "ocs_ctrl_fwk"]

  state_vars:
    servo_motor_control:
      desc:               'motor control'
      type:               'motor_control'
      max_rate:           1000
      blocking_mode:      'sync'
      is_controllable:    true

    servo_motor_state:
      desc:               'motor state'
      type:               'motor_state'
      max_rate:           1000
      blocking_mode:      'sync'
      is_controllable:    true

  input_ports:
    axis_state_port:
      desc: 'EL7211 State (read) variables'
      type: 'axis_state'
      protocol: 'pull'
      max_rate: 1000
      owner: true
      blocking_mode: 'sync'

    axis_sdo_in:
      desc: 'EL7211 sdo variables'
      type: 'axis_sdo_data'
      protocol: 'pull'
      max_rate: 1000
      owner: true
      blocking_mode: 'sync'

    axis_ro_sdo_in:
      desc: 'EL7211 ro sdo variables'
      type: 'axis_ro_sdo_data'
      protocol: 'pull'
      max_rate: 1000
      owner: true
      blocking_mode: 'sync'

    hmi_input_port:
      desc: 'hmi input'
      type: 'hmi_input'
      protocol: 'pull'
      max_rate: 1000
      owner: true
      blocking_mode: 'sync'

  output_ports:
    axis_control_port:
      desc: 'EL7211 Control (write) variables'
      type: 'axis_control'
      protocol: 'push'
      max_rate: 1000
      owner: false
      blocking_mode: 'sync'

    axis_sdo_out:
      desc: 'EL7211 sdo  variables'
      type: 'axis_sdo_data'
      protocol: 'push'
      max_rate: 1000
      owner: false
      blocking_mode: 'sync'

    hmi_output_port:
      desc: 'hmi_output_port'
      type: 'hmi_output'
      protocol: 'push'
      max_rate: 1000
      owner: false
      blocking_mode: 'sync'

  properties:
    uri: {default: "gmt://127.0.0.1/axis_dcs"}
    name: {default: "axis_main_ctrl"}
    host: {default: "127.0.0.1"}
    port: {default: 8010}
    scan_rate: {default: 100}
    position_min: {type: 'Integer',default: 1000000} 
    position_max: {type: 'Integer',default: 10000000} 
    position_captured: {type: 'Integer',default: 0} 

  instance_configurations: ['axis_main_ctrl']
