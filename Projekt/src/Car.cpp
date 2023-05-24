#include "Car.hpp"

#include <string>

Car::Car(const VehicleParameters& vehicleParams, const MotorizedVehicleParameters& motorizedVehicleParams) : MotorizedVehicle(vehicleParams, motorizedVehicleParams) {}

std::string Car::getDescription() const
{
	return {};
}
