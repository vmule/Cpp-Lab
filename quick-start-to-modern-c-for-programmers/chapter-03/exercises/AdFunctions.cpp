#include "AdFunctions.h"

#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"
#include "AdTypes.h"

namespace {
void init_vehicle(Ad::Types::VehicleType& vehicle, const std::int32_t id,
                  const float speed_kph, const float distance_m,
                  const Ad::Types::LaneAssociationType lane) {
    vehicle.id = id;
    vehicle.speed_ms = Ad::Utils::kph_to_mps(speed_kph);
    vehicle.distance_m = distance_m;
    vehicle.lane = lane;
}
}  // namespace

namespace Ad {

using namespace Ad::Types;
using namespace Ad::Constants;
using namespace Ad::Data;
using namespace Ad::Visualize;
using namespace Ad::Utils;

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

Ad::Types::NeighborVehiclesType init_vehicles() {
    auto vehicles = Ad::Types::NeighborVehiclesType{};

    init_vehicle(vehicles.vehicles_left_lane[0], 0, 110.0F, 70.0F,
                 Types::LaneAssociationType::LEFT);

    init_vehicle(vehicles.vehicles_left_lane[1], 1, 60.0F, -40.0F,
                 Types::LaneAssociationType::LEFT);

    init_vehicle(vehicles.vehicles_center_lane[0], 2, 90.0F, 30.0F,
                 Types::LaneAssociationType::CENTER);

    init_vehicle(vehicles.vehicles_center_lane[1], 3, 100.0F, -70.0F,
                 Types::LaneAssociationType::CENTER);

    init_vehicle(vehicles.vehicles_right_lane[0], 4, 90.0F, 20.0F,
                 Types::LaneAssociationType::RIGHT);

    init_vehicle(vehicles.vehicles_right_lane[1], 5, 100.0F, -40.0F,
                 Types::LaneAssociationType::RIGHT);

    return vehicles;
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

void print_neighbor_vehicles(const Ad::Types::NeighborVehiclesType& vehicles) {
    print_vehicle(vehicles.vehicles_left_lane[0]);
    print_vehicle(vehicles.vehicles_left_lane[1]);
    print_vehicle(vehicles.vehicles_center_lane[0]);
    print_vehicle(vehicles.vehicles_center_lane[1]);
    print_vehicle(vehicles.vehicles_right_lane[0]);
    print_vehicle(vehicles.vehicles_right_lane[1]);
}

void print_vehicle_on_lane(const Ad::Types::VehicleType* const vehicle,
                           const float range_m, const float offset_m,
                           std::string& string, std::size_t& idx) {
    if ((vehicle != nullptr) && (range_m >= vehicle->distance_m) &&
        (vehicle->distance_m > (range_m - offset_m))) {
        string[1] = 'V';
        idx++;
    } else if ((vehicle != nullptr) &&
               (std::abs(vehicle->distance_m) > VIEW_RANGE_M)) {
        idx++;
    }
}

void print_scene(const VehicleType& ego_vehicle,
                 const NeighborVehiclesType& vehicles) {
    std::cout << "    \t   L     C     R  \n";

    auto left_idx = std::size_t{0};
    auto center_idx = std::size_t{0};
    auto right_idx = std::size_t{0};

    const auto offset_m = std::int32_t{20};
    const auto view_range_m = static_cast<std::int32_t>(VIEW_RANGE_M);

    for (auto i = view_range_m; i >= -view_range_m; i -= offset_m) {
        const auto range_m = static_cast<float>(i);

        auto left_string = std::string{"   "};
        auto center_string = std::string{"   "};
        auto right_string = std::string{"   "};

        if ((range_m >= ego_vehicle.distance_m) &&
            (ego_vehicle.distance_m > (range_m - offset_m))) {
            center_string[1] = 'E';
        }

        if (left_idx < NUM_VEHICLES_ON_LANE) {
            print_vehicle_on_lane(&vehicles.vehicles_left_lane[left_idx],
                                  range_m, offset_m, left_string, left_idx);
        }
        if (center_idx < NUM_VEHICLES_ON_LANE) {
            print_vehicle_on_lane(&vehicles.vehicles_center_lane[center_idx],
                                  range_m, offset_m, center_string, center_idx);
        }
        if (right_idx < NUM_VEHICLES_ON_LANE) {
            print_vehicle_on_lane(&vehicles.vehicles_right_lane[right_idx],
                                  range_m, offset_m, right_string, right_idx);
        }

        std::cout << i << "\t| " << left_string << " | " << center_string
                  << " | " << right_string << " | \n";
    }
}
}  // namespace Visualize

}  // namespace Ad
