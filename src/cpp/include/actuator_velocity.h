#ifndef _actuator_velocity_h_
#define _actuator_velocity_h_

#include <msgpack.hpp>
#include <string>
#include <array>
#include <vector>

struct actuator_velocity {
    uint32_t                 actuator_actual_velocity; // actuator_actual_velcoity
    uint16_t                 actuator_desired_velocity; // actuator_desired_velcoity
    MSGPACK_DEFINE_MAP(actuator_actual_velocity, actuator_desired_velocity)
};


#endif // _actuator_velocity_h_
