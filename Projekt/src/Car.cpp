#include "Car.hpp"

#include <string>

#include "VehicleParametersConverter.hpp"

Car::Car(const VehicleParameters& vehicleParams, const MotorizedVehicleParameters& motorizedVehicleParams) : MotorizedVehicle(vehicleParams, motorizedVehicleParams) {}

std::string Car::getDescription() const
{
	return { model + "został wyprodukowany przez firmę: " + manufacturer + " w roku: " + std::to_string(productionYear) +
		" posiada moc: "
		+ std::to_string(engineSpec.power) + " oraz napęd na "
		+ VehicleParametersConverter::convert(drive) + " z "
		+ VehicleParametersConverter::convert(transmission)
		+ "\nJest to samochód na: " + VehicleParametersConverter::convert(engineSpec.fuelType) };
}
