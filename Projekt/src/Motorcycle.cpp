#include "Motorcycle.hpp"

#include <string>

Motorcycle::Motorcycle(const VehicleParameters& vehicleParams, const MotorizedVehicleParameters& motorizedVehicleParams) : MotorizedVehicle(vehicleParams, motorizedVehicleParams) {}

std::string Motorcycle::getDescription() const
{
	return { model + "został wyprodukowany przez firmę: " + manufacturer + " w roku: " + std::to_string(productionYear) +
		" posiada moc o wielkości: " + std::to_string(engineSpec.power) };
}
