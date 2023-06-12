#include "Car.hpp"

#include <string>

#include <QObject>

#include "Converters.hpp"

Car::Car(const VehicleParameters& vehicleParams, const MotorizedVehicleParameters& motorizedVehicleParams) : MotorizedVehicle(vehicleParams, motorizedVehicleParams) {}

std::string Car::getDescription() const
{
	return QObject::tr("car_description")
		.arg(model.c_str())
		.arg(manufacturer.c_str())
		.arg(productionYear)
        .arg(engineSpec.power)
        .arg(QObject::tr(converters::toString(drive).c_str()))
        .arg(QObject::tr(converters::toString(transmission).c_str()))
        .arg(QObject::tr(converters::toString(engineSpec.fuelType).c_str()))
        .toStdString();
}
