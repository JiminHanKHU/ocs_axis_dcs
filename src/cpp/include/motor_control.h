#ifndef _motor_control_h_
#define _motor_control_h_

#include <msgpack.hpp>
#include <string>
#include <array>
#include <vector>

struct motor_control {
    bool                     stop;                // stop
    int                      mode;                // control mode (0: wait, 1: homing, 2: positioning, 3: velocity
    int32_t                  speed;               // positioning
    uint32_t                 position;            // position
    MSGPACK_DEFINE_MAP(stop, mode, speed, position)
};


#endif // _motor_control_h_
