Package   'axis_ctrl_pkg',
  info: 'EL7211 Controller Package'
  desc: 'EL7211 Controller Package'
  uses: ["ocs_core_fwk"]

  connectors: [
    # hw adapter outputs
   {
      id: 8102,
      from: {element: "axis_hw1_adapter", port: "axis_sdo_out"},
      to:   {element: "axis_main_ctrl",   port: "axis_sdo_in"},
      max_latency: 0.5,
      nom_rate: 100,
      on_fault: "",
      conversion: "",
      bus: ""
    }

   {
      id: 8105,
      from: {element: "axis_hw1_adapter", port: "axis_ro_sdo_out"},
      to:   {element: "axis_main_ctrl",   port: "axis_ro_sdo_in"},
      max_latency: 0.5,
      nom_rate: 100,
      on_fault: "",
      conversion: "",
      bus: ""
    }


    {
      id: 8101,
      from: {element: "axis_hw1_adapter", port: "axis_state_port"},
      to:   {element: "axis_main_ctrl",   port: "axis_state_port"},
      max_latency: 0.5,
      nom_rate: 100,
      on_fault: "",
      conversion: "",
      bus: ""
    }
    
    {
      id: 8109,
      from: {element: "axis_hw1_adapter", port: "hmi_input_port"},
      to:   {element: "axis_main_ctrl",   port: "hmi_input_port"},
      max_latency: 0.5,
      nom_rate: 100,
      on_fault: "",
      conversion: "",
      bus: ""
    }

    # hw adapter inputs
    {
      id: 8103,
      from: {element: "axis_main_ctrl", port: "axis_sdo_out"},
      to: {element: "axis_hw1_adapter", port: "axis_sdo_in"},
      max_latency: 0.5,
      nom_rate: 100,
      on_fault: "",
      conversion: "",
      bus: ""
    }
    {
      id: 8104,
      from: {element: "axis_main_ctrl", port: "axis_control_port"},
      to: {element: "axis_hw1_adapter", port: "axis_control_port"},
      max_latency: 0.5,
      nom_rate: 100,
      on_fault: "",
      conversion: "",
      bus: ""
    }
    {
      id: 8110,
      from: {element: "axis_main_ctrl", port: "hmi_output_port"},
      to: {element: "axis_hw1_adapter", port: "hmi_output_port"},
      max_latency: 0.5,
      nom_rate: 100,
      on_fault: "",
      conversion: "",
      bus: ""
    }



    # heartbeats
    {
      id: 8107,
      from: {element: "axis_hw1_adapter", port: "heartbeat_out"},
      to: {element: "axis_ctrl_super", port: "heartbeat_in"},
      max_latency: 0.5,
      nom_rate: 100,
    }
    {
      id: 8108,
      from: {element: "axis_main_ctrl", port: "heartbeat_out"},
      to: {element: "axis_ctrl_super", port: "heartbeat_in"},
      max_latency: 0.5,
      nom_rate: 100,
    }
  ]
