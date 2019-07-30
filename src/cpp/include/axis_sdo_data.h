#ifndef _axis_sdo_data_h_
#define _axis_sdo_data_h_

#include <msgpack.hpp>
#include <string>
#include <array>
#include <vector>

struct axis_sdo_data {
    uint32_t                 velocity_limitation; // Velocity limitation
    uint8_t                  singleturn_bits;     // singleturn bits
    MSGPACK_DEFINE_MAP(velocity_limitation, singleturn_bits)
};


#endif // _axis_sdo_data_h_
