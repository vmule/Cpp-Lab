#pragma once

#include "AdTypes.h"

namespace Ad {

// using namespace Ad::Types;

namespace Utils {

constexpr static float kph_to_mps(const float kph);

}  // namespace Utils

namespace Data {

Ad::Types::VehicleType init_ego_vehicle();

Ad::Types::NeighborVehiclesType init_vehicles();

}  // namespace Data

namespace Visualize {

void print_vehicle(const Ad::Types::VehicleType vehicle);

void print_neighbor_vehicles(const Ad::Types::NeighborVehiclesType& vehicle);

void print_scene(const Ad::Types::VehicleType& ego_vehicle,
                 const Ad::Types::NeighborVehiclesType& vehicles);

}  // namespace Visualize

}  // namespace Ad
