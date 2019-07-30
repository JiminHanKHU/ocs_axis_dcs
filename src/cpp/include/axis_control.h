#ifndef _axis_control_h_
#define _axis_control_h_

#include <msgpack.hpp>
#include <string>
#include <array>
#include <vector>

struct axis_control {
    uint16_t                 control_word;        // Control Word
    int32_t                  target_velocity;     // Target Velocity
    MSGPACK_DEFINE_MAP(control_word, target_velocity)
};


#endif // _axis_control_h_
