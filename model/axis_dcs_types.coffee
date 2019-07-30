StructType "axis_control",
  desc: "Control (write) variables",
  elements:
    control_word: {desc: "Control Word", type: "uint16", units: ""}
    target_velocity: {desc: "Target Velocity", type: "int32", units: ""}


StructType "axis_state",
  desc: "State (read) variables",
  elements:
    status_word: {desc: "Status Word", type: "uint16", units: ""}
    position: {desc: "Position", type: "uint32", units: ""}
    actual_velocity: {desc: "Velocity actual value", type: "int32", units: ""}

StructType "axis_sdo_data",
  desc: "SDO data configurations"
  elements:
    velocity_limitation: {desc: "Velocity limitation", type: "uint32", units: ""}
    singleturn_bits:     {desc: "singleturn bits",     type: "uint8",  units: ""}

StructType "axis_ro_sdo_data",
  desc: "Read Only SDO data configurations"
  elements:
    max_speed:                  {desc: "max speed",           type: "uint32", units: ""}
    velocity_encoder_resolution:{desc: "ender resoluction",   type: "uint32", units: "increments/revolution"}

StructType "hmi_output",
  desc: "digit output"
  elements:
    pilot_led:    {desc: "pilot_led",     type: "bool", units: ""}
 
StructType "hmi_input",
  desc: "digit input"
  elements:
    switch_home:    {desc: "green button",     type: "bool", units: ""}
    switch_limit_max:      {desc: "red button",    type: "bool", units: ""}
    switch_limit_min:      {desc: "input3",    type: "bool", units: ""}

StructType "motor_control",
  desc: "home control var"
  elements:
    stop:             {desc: "stop",     type: "bool",   units: ""}
    mode:             {desc: "control mode (0: wait, 1: homing, 2: positioning, 3: velocity",     type: "int",   units: ""} 
    speed:            {desc: "positioning",    type: "int32",  units: ""}
    position:         {desc: "position",       type: "uint32",  units: ""} 

StructType "motor_state",
  desc: "motor state var"
  elements:
    state:             {desc: "state message",         type: "string", units: ""}
    position_absolute: {desc: "absolute position",     type: "int32", units: ""} 
    homed:                 {desc: "homed",                type: "bool",   units: ""}     
    home_in_progress:      {desc: "in_progress",          type: "bool",   units: ""}
    home_offset:           {desc: "offset",               type: "int32",  units: ""}
    home_init:             {desc: "init sqnc",            type: "bool",  units: ""}
    home_init_time:        {desc: "first find home",      type: "int",  units: ""}
