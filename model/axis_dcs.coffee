DCS       'axis_dcs',
  info: 'Test Control System'
  desc: require './axis_dcs.rst'

  uses: [
    "ocs_core_fwk"
    "ocs_ctrl_fwk"
  ]

  types: [
    "axis_control"
    "axis_state"
    "axis_sdo_data"
    "axis_ro_sdo_data"
    "hmi_input"
    "hmi_output"
    "motor_control"
    "motor_state"
  ]


  connectors: [
    # EL7211 hw adapter
    # inputs
###
    {
      id: 8110,
      to: {element: "axis_hw1_adapter", port: "axis_control_port"},
      from: {element: "*", port: "*"},
      max_latency: 0.5,
      nom_rate: 100,
      on_fault: "",
      conversion: "",
      bus: ""
    }

    # outputs
    {
      id: 8113,
      from: {element: "axis_hw1_adapter", port: "axis_state_port"},
      to: {element: "*", port: "*"},
      max_latency: 0.5,
      nom_rate: 1,
      on_fault: "",
      conversion: "",
      bus: ""
    }

    # op state
    {
      id: 8111,
      to: {element: "axis_hw1_adapter", port: "op_state_goal"},
      from: {element: "*", port: "*"},
      max_latency: 0.5,
      nom_rate: 1,
      on_fault: "",
      conversion: "",
      bus: ""
    }
    {
      id: 8112,
      from: {element: "axis_hw1_adapter", port: "op_state_value"},
      to: {element: "*", port: "*"},
      max_latency: 0.5,
      nom_rate: 1,
      on_fault: "",
      conversion: "",
      bus: ""
    }

    # EL7211 main controller
    # inputs
    {
      id: 8213,
      to: {element: "axis_main_ctrl", port: "axis_state_port"},
      from: {element: "*", port: "*"},
      max_latency: 0.5,
      nom_rate: 1,
      on_fault: "",
      conversion: "",
      bus: ""
    }
    # outputs
    {
      id: 8210,
      from: {element: "axis_main_ctrl", port: "axis_control_port"},
      to: {element: "*", port: "*"},
      max_latency: 0.5,
      nom_rate: 100,
      on_fault: "",
      conversion: "",
      bus: ""
    }

    # op state
    {
      id: 8211,
      to: {element: "axis_main_ctrl", port: "op_state_goal"},
      from: {element: "*", port: "*"},
      max_latency: 0.5,
      nom_rate: 1,
      on_fault: "",
      conversion: "",
      bus: ""
    }
    {
      id: 8212,
      from: {element: "axis_main_ctrl", port: "op_state_value"},
      to: {element: "*", port: "*"},
      max_latency: 0.5,
      nom_rate: 1,
      on_fault: "",
      conversion: "",
      bus: ""
    }
###

#    # Serial
#    # serial_hw_adapter
#    # inputs
#    {
#      id: 9110,
#      to: {element: "serial_hw1_adapter", port: "device_data_out"},
#      from: {element: "*", port: "*"},
#      max_latency: 0.5,
#      nom_rate: 100,
#      on_fault: "",
#      conversion: "",
#      bus: ""
#    }
#
#    # outputs
#    {
#      id: 9113,
#      from: {element: "serial_hw1_adapter", port: "device_data_in"},
#      to: {element: "*", port: "*"},
#      max_latency: 0.5,
#      nom_rate: 1,
#      on_fault: "",
#      conversion: "",
#      bus: ""
#    }
#
#    # op state
#    {
#      id: 9111,
#      to: {element: "serial_hw1_adapter", port: "op_state_goal"},
#      from: {element: "*", port: "*"},
#      max_latency: 0.5,
#      nom_rate: 1,
#      on_fault: "",
#      conversion: "",
#      bus: ""
#    }
#    {
#      id: 9112,
#      from: {element: "serial_hw1_adapter", port: "op_state_value"},
#      to: {element: "*", port: "*"},
#      max_latency: 0.5,
#      nom_rate: 1,
#      on_fault: "",
#      conversion: "",
#      bus: ""
#    }
#
#    # serial_main_ctrl
#    # inputs
#    {
#      id: 9213,
#      to: {element: "serial_main_ctrl", port: "device_data_in"},
#      from: {element: "*", port: "*"},
#      max_latency: 0.5,
#      nom_rate: 1,
#      on_fault: "",
#      conversion: "",
#      bus: ""
#    }
#    # outputs
#    {
#      id: 9210,
#      from: {element: "serial_main_ctrl", port: "device_data_out"},
#      to: {element: "*", port: "*"},
#      max_latency: 0.5,
#      nom_rate: 100,
#      on_fault: "",
#      conversion: "",
#      bus: ""
#    }
#
#    # op state
#    {
#      id: 9211,
#      to: {element: "serial_main_ctrl", port: "op_state_goal"},
#      from: {element: "*", port: "*"},
#      max_latency: 0.5,
#      nom_rate: 1,
#      on_fault: "",
#      conversion: "",
#      bus: ""
#    }
#    {
#      id: 9212,
#      from: {element: "serial_main_ctrl", port: "op_state_value"},
#      to: {element: "*", port: "*"},
#      max_latency: 0.5,
#      nom_rate: 1,
#      on_fault: "",
#      conversion: "",
#      bus: ""
#    }
#

  ]
