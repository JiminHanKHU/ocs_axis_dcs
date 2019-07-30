#ifndef _axis_state_h_
#define _axis_state_h_

#include <msgpack.hpp>
#include <string>
#include <array>
#include <vector>

struct axis_state {
    uint16_t                 status_word;         // Status Word
    uint32_t                 position;            // Position
    int32_t                  actual_velocity;     // Velocity actual value
    MSGPACK_DEFINE_MAP(status_word, position, actual_velocity)
};


#endif // _axis_state_h_
