FieldBus "axis_ctrl_fb",
  info: "axis EtherCAT bus"
  desc: "axis EtherCAT bus"

  masters: [
    {id: 0, rate: 1000}
  ]

  domains: [
    {id: 0, master: 0, rate: 1000}
  ]

  slaves: [
    {name: "motor", position: 1, type: "EL7211-0010"}
  ]


  data_objects: [
    {
      name: "status_word",
      type: "tx_pdo",
      label: "Statusword",
      std_name: "Statusword",
      module: 0,
      domain: 0
    },
    {
      name: "actual_velocity",
      type: "tx_pdo",
      label: "Velocity actual value",
      std_name: "Velocity actual value",
      module: 0,
      domain: 0
    },
    {
      name: "position",
      type: "tx_pdo",
      label: "Position",
      std_name: "Position",
      module: 0,
      domain: 0
    },
    {
      name: "control_word",
      type: "rx_pdo",
      label: "Controlword",
      std_name: "Controlword",
      module: 0,
      domain: 0
    },
    {
      name: "target_velocity",
      type: "rx_pdo",
      label: "Target Velocity",
      std_name: "Target Velocity",
      module: 0,
      domain: 0
    }
    { name: "input1",          type: "tx_pdo",    label: "input1",              std_name: "Channel 1 : Input",                  module: 2, domain: 0 }
    { name: "input2",          type: "tx_pdo",    label: "input2",              std_name: "Channel 2 : Input",              module: 2, domain: 0 }


    #SDO Data
    { name: "RxSDO_velocity_limitation",       type: "rx_sdo",    label: "velocity limitation",                          std_name: "RxSDO : velocity limitation",              module: 1, domain: 0 }
    { name: "TxSDO_velocity_limitation",       type: "tx_sdo",    label: "velocity limitation",                          std_name: "TxSDO : velocity limitation",              module: 1, domain: 0 }

    { name: "TxSDO_singleturn_bits",           type: "tx_sdo",    label: "singleturn bits",                              std_name: "TxSDO : singleturn bits",                  module: 1, domain: 0 }
    { name: "RxSDO_singleturn_bits",           type: "rx_sdo",    label: "singleturn bits",                              std_name: "RxSDO : singleturn bits",                  module: 1, domain: 0 } 
    #Read Only SDO Data
    { name: "RoSDO_max_speed",                   type: "tx_sdo",    label: "max velocity",                                 std_name: "RoSDO : max velocity",                     module: 1, domain: 0 }
    { name: "RoSDO_velocity_encoder_resolution", type: "tx_sdo",    label: "velocity encoder resolution",                  std_name: "RoSDO : velocity encoder resolution",      module: 1, domain: 0 }
   # { name: "RoSDO_brake_type",                type: "tx_sdo",    label: "brake type",                                   std_name: "RoSDO : brake type",                       module: 1, domain: 0 }

  ]


