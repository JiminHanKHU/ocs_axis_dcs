module.exports =
    master: [
      { id: 0, rate: 10000 }
    ]

    domains: [
      { id: 0, master: 0,   rate_factor: 1    }
    ]

    modules: [
      { name: "coupler",  position: 0, type: "coupler",     master_id:0 }
      { name: "motor",    position: 1, type: "EL7211-0010", master_id:0 }
      { name: "dig_inp",  position: 3, type: "EL1809",      master_id:0 }    
      { name: "dig_out",  position: 4, type: "EL2809",      master_id:0 }
      ]

    data_objects: [
      { name: "status_word",           type: "tx_pdo",    label: "Statusword",                               std_name: "Statusword",                                 module: 1, domain: 0 }
      { name: "actual_velocity",       type: "tx_pdo",    label: "Velocity actual value",                    std_name: "Velocity actual value",                      module: 1, domain: 0 }
      { name: "position",              type: "tx_pdo",    label: "Position",                                 std_name: "Position",                                   module: 1, domain: 0 }

      { name: "control_word",          type: "rx_pdo",    label: "Controlword",                              std_name: "Controlword",                                module: 1, domain: 0 }
      { name: "target_velocity",       type: "rx_pdo",    label: "Target velocity",                          std_name: "Target velocity",                            module: 1, domain: 0 }

      { name: "input1",          type: "tx_pdo",    label: "input1",              std_name: "Channel 1 : Input",                  module: 2, domain: 0 }
      { name: "input2",          type: "tx_pdo",    label: "input2",              std_name: "Channel 2 : Input",              module: 2, domain: 0 }
      { name: "input3",          type: "tx_pdo",    label: "input3",              std_name: "Channel 3 : Input",              module: 2, domain: 0 }
      { name: "output1",         type: "rx_pdo",    label: "output1",             std_name: "Channel 1 : Output",              module: 3, domain: 0 }


      #SDO Data
      { name: "TxSDO_velocity_limitation",       type: "tx_sdo",    label: "velocity limitation",                          std_name: "TxSDO : velocity limitation",              module: 1, domain: 0 }
      { name: "RxSDO_velocity_limitation",       type: "rx_sdo",    label: "velocity limitation",                          std_name: "RxSDO : velocity limitation",              module: 1, domain: 0 }

      { name: "TxSDO_singleturn_bits",           type: "tx_sdo",    label: "singleturn bits",                              std_name: "TxSDO : singleturn bits",                  module: 1, domain: 0 }
      { name: "RxSDO_singleturn_bits",           type: "rx_sdo",    label: "singleturn bits",                              std_name: "RxSDO : singleturn bits",                  module: 1, domain: 0 }

      #Read Only SDO Data
      { name: "RoSDO_max_speed",                   type: "tx_sdo",    label: "max velocity",                                 std_name: "RoSDO : max speed",                        module: 1, domain: 0 }
      { name: "RoSDO_velocity_encoder_resolution", type: "tx_sdo",    label: "velocity encoder resolution",                  std_name: "RoSDO : velocity encoder resolution",      module: 1, domain: 0 }
    #  { name: "RoSDO_brake_type",                 type: "tx_sdo",    label: "brake type",                                   std_name: "RoSDO : brake type",                       module: 1, domain: 0 }  

    ]

    catalog: [
      {
        product_name: "coupler",
        vendor_id:    0x00000002,
        product_code:  0x144c2c52,
        revision_id:  0x10110000,
        objs: [],
        clocks: []
      }
      {
        product_name: "EL1809",
        vendor_id:    0x00000002,
        product_code:  0x07113052,
        revision_id:  0x00100000,
        objs: [
          {name: "Channel 1 : Input", index: 0x6000, sub_index: 0x1, bit: 0}
          {name: "Channel 2 : Input", index: 0x6010, sub_index: 0x1, bit: 0}
          {name: "Channel 3 : Input", index: 0x6020, sub_index: 0x1, bit: 0}
      ],
        clocks: []
      }
      {
        product_name: "EL2809",
        vendor_id:    0x00000002,
        product_code:  0x0af93052,
        revision_id:  0x00100000,
        objs: [
          {name: "Channel 1 : Output", index: 0x7000, sub_index: 0x1, bit: 0}
      ],
        clocks: []
      }
 
      {
        product_name: "EL7211-0010",
        vendor_id:    0x00000002,
        product_code: 0x1c2b3052,
        revision_id:  0x0018000a,
        objs: [
          #PDO data
          { name: "Statusword",            index: 0x6010, sub_index: 0x01,   bit: 0} #TxPDO-Map Statusword
          { name: "Controlword",           index: 0x7010, sub_index: 0x01,   bit: 0} #DRV RxPDO-Map Controlword

          { name: "Velocity actual value", index: 0x6010, sub_index: 0x07,   bit: 0} #DRV TxPDO-Map Velocity actual value
          { name: "Position",              index: 0x6000, sub_index: 0x11,   bit: 0} #FB TxPDO-Map Position
          { name: "Target velocity",       index: 0x7010, sub_index: 0x06,   bit: 0} #DRV RxPDO-Map Target velocity

          #SDO data
          { name: "TxSDO : velocity limitation",            index: 0x8011, sub_index: 0x1b,   bit: 0} 
          { name: "RxSDO : velocity limitation",            index: 0x8011, sub_index: 0x1b,   bit: 0} 
          { name: "TxSDO : singleturn bits",                index: 0x8000, sub_index: 0x12,   bit: 0} 
          { name: "RxSDO : singleturn bits",                index: 0x8000, sub_index: 0x12,   bit: 0} 

          #Read Only SDO data
          { name: "RoSDO : max speed",                      index: 0x9009, sub_index: 0x13,   bit: 0}
          { name: "RoSDO : velocity encoder resolution",    index: 0x9010, sub_index: 0x14,   bit: 0}     
         # { name: "RoSDO : brake type",                     index: 0x9009, sub_index: 0x1b,   bit: 0}        

        ],
        clocks: [
          { assign_activate: 0x0700,   cycle_time_sync0: 10000000, shift_time_sync0: 4400000,   cycle_time_sync1: 10000000, shift_time_sync1: 4400000 }
        ]
      }
    ]
