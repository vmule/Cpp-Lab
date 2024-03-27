#pragma once

#include <array>
#include <cstdint>

#include "AdConstants.h"

namespace Ad {
namespace Types {

enum class LaneAssociationType {
    LEFT,
    CENTER,
    RIGHT,
    NONE,
};

struct VehicleType {
    std::int32_t id;
    LaneAssociationType lane;
    float speed_ms;
    float distance_m;
};

// template <std::size_t NUM_VEHICLES_ON_LANE>
struct NeighborVehiclesType {
    std::array<VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE>
        vehicles_left_lane;
    std::array<VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE>
        vehicles_center_lane;
    std::array<VehicleType, Ad::Constants::NUM_VEHICLES_ON_LANE>
        vehicles_right_lane;
};

}  // namespace Types
}  // namespace Ad
