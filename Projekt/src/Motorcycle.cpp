#include "Motorcycle.hpp"

#include <string>

#include "VehicleParametersConverter.hpp"

Motorcycle::Motorcycle(const VehicleParameters& vehicleParams, const MotorizedVehicleParameters& motorizedVehicleParams) : MotorizedVehicle(vehicleParams, motorizedVehicleParams) {}

std::string Motorcycle::getDescription() const
{
	return QObject::tr("motorcycle_description")
		.arg(model.c_str())
		.arg(manufacturer.c_str())
		.arg(productionYear)
		.arg(engineSpec.power)
		.arg(VehicleParametersConverter::convert(transmission).c_str())
		.arg(VehicleParametersConverter::convert(engineSpec.fuelType).c_str())
		.toStdString();

	return { model + "został wyprodukowany przez firmę: " + manufacturer + " w roku: " + std::to_string(productionYear) +
		" posiada moc o wielkości: " + std::to_string(engineSpec.power) };
}
