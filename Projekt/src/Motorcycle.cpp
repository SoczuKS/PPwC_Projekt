#include "Motorcycle.hpp"

#include <string>

Motorcycle::Motorcycle(const VehicleParameters& vehicleParams, const MotorizedVehicleParameters& motorizedVehicleParams) : MotorizedVehicle(vehicleParams, motorizedVehicleParams) {}

std::string Motorcycle::getDescription() const
{
	return {};
}
