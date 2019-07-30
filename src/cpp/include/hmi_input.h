#ifndef _hmi_input_h_
#define _hmi_input_h_

#include <msgpack.hpp>
#include <string>
#include <array>
#include <vector>

struct hmi_input {
    bool                     switch_home;         // green button
    bool                     switch_limit_max;    // red button
    bool                     switch_limit_min;    // input3
    MSGPACK_DEFINE_MAP(switch_home, switch_limit_max, switch_limit_min)
};


#endif // _hmi_input_h_
