#ifndef _motor_state_h_
#define _motor_state_h_

#include <msgpack.hpp>
#include <string>
#include <array>
#include <vector>

struct motor_state {
    std::string              state;               // state message
    int32_t                  position_absolute;   // absolute position
    bool                     homed;               // homed
    bool                     home_in_progress;    // in_progress
    int32_t                  home_offset;         // offset
    bool                     home_init;           // init sqnc
    int                      home_init_time;      // first find home
    MSGPACK_DEFINE_MAP(state, position_absolute, homed, home_in_progress, home_offset, home_init, home_init_time)
};


#endif // _motor_state_h_
