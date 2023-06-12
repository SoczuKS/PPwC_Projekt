#include "Motorcycle.hpp"

#include <string>

#include <QObject>

#include "Converters.hpp"

Motorcycle::Motorcycle(const VehicleParameters& vehicleParams, const MotorizedVehicleParameters& motorizedVehicleParams) : MotorizedVehicle(vehicleParams, motorizedVehicleParams) {}

std::string Motorcycle::getDescription() const
{
	return QObject::tr("motorcycle_description")
		.arg(model.c_str())
		.arg(manufacturer.c_str())
		.arg(productionYear)
		.arg(engineSpec.power)
		.arg(converters::toString(transmission).c_str())
		.arg(converters::toString(engineSpec.fuelType).c_str())
		.toStdString();
}
