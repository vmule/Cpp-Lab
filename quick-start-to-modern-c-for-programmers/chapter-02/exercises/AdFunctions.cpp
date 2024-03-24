#include "AdFunctions.h"

#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdTypes.h"

namespace Ad {
namespace Utils {

constexpr static float kph_to_mps(const float kph) {
    //
    return kph / 3.6F;
}

};  // namespace Utils

namespace Data {

Ad::Types::VehicleType init_ego_vehicle() {
    return Ad::Types::VehicleType{
        .id = Ad::Constants::EGO_VEHICLE_ID,
        .lane = Ad::Types::LaneAssociationType::LEFT,
        .speed_ms = Ad::Utils::kph_to_mps(130.0F),
        .distance_m = 5.0F,
    };
}

}  // namespace Data

namespace Visualize {
void print_vehicle(const Ad::Types::VehicleType vehicle) {
    std::cout << "Vehicle Data:\n"
              << "ID: " << vehicle.id << "\n"
              << "Lane: " << static_cast<int>(vehicle.lane) << "\n"
              << "Speed (m/s): " << vehicle.speed_ms << "\n"
              << "Distance (m): " << vehicle.distance_m << "\n";
}

}  // namespace Visualize

}  // namespace Ad
