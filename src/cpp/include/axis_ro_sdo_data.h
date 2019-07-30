#ifndef _axis_ro_sdo_data_h_
#define _axis_ro_sdo_data_h_

#include <msgpack.hpp>
#include <string>
#include <array>
#include <vector>

struct axis_ro_sdo_data {
    uint32_t                 max_speed;           // max speed
    uint32_t                 velocity_encoder_resolution; // ender resoluction
    MSGPACK_DEFINE_MAP(max_speed, velocity_encoder_resolution)
};


#endif // _axis_ro_sdo_data_h_
