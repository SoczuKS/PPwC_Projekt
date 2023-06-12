#pragma once

#include "MotorizedVehicle.hpp"

namespace converters
{
std::string toString(MotorizedVehicle::Drive drive);
std::string toString(MotorizedVehicle::Transmission transmission);
std::string toString(MotorizedVehicle::EngineSpec::FuelType fuelType);
};
