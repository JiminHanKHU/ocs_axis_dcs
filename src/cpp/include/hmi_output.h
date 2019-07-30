#ifndef _hmi_output_h_
#define _hmi_output_h_

#include <msgpack.hpp>
#include <string>
#include <array>
#include <vector>

struct hmi_output {
    bool                     pilot_led;           // pilot_led
    MSGPACK_DEFINE_MAP(pilot_led)
};


#endif // _hmi_output_h_
