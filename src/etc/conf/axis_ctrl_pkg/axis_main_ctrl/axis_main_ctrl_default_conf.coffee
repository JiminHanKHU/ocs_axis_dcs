
# Component  axis_main_ctrl instance configuration file
# Ports should be setup per instance

module.exports =

    properties:
        uri: { name: 'uri', default_value: 'gmt://127.0.0.1/axis_dcs/axis_main_ctrl' , type: 'string', desc: 'Uri path for the component' }
        name: { name: 'name', default_value: 'axis_main_ctrl' , type: 'string', desc: 'Name the component' }
        host: { name: 'host', default_value: '127.0.0.1' , type: 'string', desc: 'Default host for deployment.' }
        port: { name: 'port', default_value: 8020 , type: 'integer', desc: 'Default configuration port' }
        scan_rate: { name: 'scan_rate', default_value: 100 , type: 'float', desc: 'The scanning rate of the component loop in Hz. In each iteration of the loop the component must process its ports and health status. The estimation of the state variables, is defined by the state variable sampling rate and it may use an estimation model. The control of the state variable is defined by the state variable control rate. It must calculate the control output, if necessary with a control model. The scanning rate shall be always higher that the maximum of the sampling or control rate of any of its states variables' }
        position_min: { name: 'position_min', default_value: 1000000 , type: 'Integer' }
        position_max: { name: 'position_max', default_value: 10000000 , type: 'Integer' }
        position_captured: { name: 'position_captured', default_value: 0 , type: 'Integer' }
        acl: { name: 'acl', default_value: 'PRIVATE' , type: 'string', desc: 'Access Control List. List of namespaces that can issue a command to the controller. TBC' }
        priority: { name: 'priority', default_value: 0 , max: 100, type: 'integer', desc: 'The priority property defines the relative priority between Component running in different Threads. The priority shall be interpreted higher when the value is higher. This property can be used by implementations that support real time behavior. When the property value is 0 the Component doesn&#x27;t require any real-time consideration by the implementation' }

    state_vars:
        servo_motor_control: { name: 'servo_motor_control' , type: 'motor_control', desc: 'motor control' }
        servo_motor_state: { name: 'servo_motor_state' , type: 'motor_state', desc: 'motor state' }
        op_state: { name: 'op_state', default_value: 'OFF' , type: 'OperationalState', desc: 'Operational Mode State Variable' }
        sim_mode: { name: 'sim_mode', default_value: 'ON_LINE' , type: 'SimulationMode', desc: 'Simulation Mode State Variable' }
        control_mode: { name: 'control_mode', default_value: 'STANDALONE' , type: 'ControlMode', desc: 'Control Mode State Variable' }

    inputs:
        axis_state_port:     { name: 'axis_state_port',       port_type: 'pull',  url: 'tcp://127.0.0.1:8101', blocking_mode: 'sync',  max_rate: 1000,  nom_rate: 100,   owner: true  }
        axis_sdo_in:         { name: 'axis_sdo_in',           port_type: 'pull',  url: 'tcp://127.0.0.1:8102', blocking_mode: 'sync',  max_rate: 1000,  nom_rate: 100,   owner: true  }
        axis_ro_sdo_in:      { name: 'axis_ro_sdo_in',        port_type: 'pull',  url: 'tcp://127.0.0.1:8105', blocking_mode: 'sync',  max_rate: 1000,  nom_rate: 100,   owner: true  }
        hmi_input_port:      { name: 'hmi_input_port',        port_type: 'pull',  url: 'tcp://127.0.0.1:8109', blocking_mode: 'sync',  max_rate: 1000,  nom_rate: 100,   owner: true  }
        servo_motor_control_goal: { name: 'servo_motor_control_goal', port_type: 'pull',  url: 'tcp://127.0.0.1:8000', blocking_mode: 'sync',  max_rate: 1000,  nom_rate: 1,     owner: true}
        servo_motor_state_goal: { name: 'servo_motor_state_goal', port_type: 'pull',  url: 'tcp://127.0.0.1:8000', blocking_mode: 'sync',  max_rate: 1000,  nom_rate: 1,     owner: true}
        op_state_goal:       { name: 'op_state_goal',         port_type: 'pull',  url: 'tcp://127.0.0.1:8000', blocking_mode: 'async', max_rate: 1,     nom_rate: 1,     owner: true}
        sim_mode_goal:       { name: 'sim_mode_goal',         port_type: 'pull',  url: 'tcp://127.0.0.1:8000', blocking_mode: 'async', max_rate: 1,     nom_rate: 1,     owner: true}
        control_mode_goal:   { name: 'control_mode_goal',     port_type: 'pull',  url: 'tcp://127.0.0.1:8000', blocking_mode: 'async', max_rate: 1,     nom_rate: 1,     owner: true}

    outputs:
        axis_control_port:   { name: 'axis_control_port',     port_type: 'push',  url: 'tcp://127.0.0.1:8104', blocking_mode: 'sync',  max_rate: 1000,  nom_rate: 100,   owner: false }
        axis_sdo_out:        { name: 'axis_sdo_out',          port_type: 'push',  url: 'tcp://127.0.0.1:8103', blocking_mode: 'sync',  max_rate: 1000,  nom_rate: 100,   owner: false }
        hmi_output_port:     { name: 'hmi_output_port',       port_type: 'push',  url: 'tcp://127.0.0.1:8110', blocking_mode: 'sync',  max_rate: 1000,  nom_rate: 100,   owner: false }
        servo_motor_control_value: { name: 'servo_motor_control_value', port_type: 'push',  url: 'tcp://127.0.0.1:8000', blocking_mode: 'sync',  max_rate: 1000,  nom_rate: 1,     owner: false}
        servo_motor_state_value: { name: 'servo_motor_state_value', port_type: 'push',  url: 'tcp://127.0.0.1:8000', blocking_mode: 'sync',  max_rate: 1000,  nom_rate: 1,     owner: false}
        op_state_value:      { name: 'op_state_value',        port_type: 'push',  url: 'tcp://127.0.0.1:8000', blocking_mode: 'async', max_rate: 1,     nom_rate: 1,     owner: false}
        sim_mode_value:      { name: 'sim_mode_value',        port_type: 'push',  url: 'tcp://127.0.0.1:8000', blocking_mode: 'async', max_rate: 1,     nom_rate: 1,     owner: false}
        control_mode_value:  { name: 'control_mode_value',    port_type: 'push',  url: 'tcp://127.0.0.1:8000', blocking_mode: 'async', max_rate: 1,     nom_rate: 1,     owner: false}
