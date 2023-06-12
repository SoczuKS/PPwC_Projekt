#include "Car.hpp"

#include <string>

#include <QObject>

#include "VehicleParametersConverter.hpp"

Car::Car(const VehicleParameters& vehicleParams, const MotorizedVehicleParameters& motorizedVehicleParams) : MotorizedVehicle(vehicleParams, motorizedVehicleParams) {}

std::string Car::getDescription() const
{
	return QObject::tr("car_description")
		.arg(model.c_str())
		.arg(manufacturer.c_str())
		.arg(productionYear)
        .arg(engineSpec.power)
        .arg(VehicleParametersConverter::convert(drive).c_str())
        .arg(VehicleParametersConverter::convert(transmission).c_str())
        .arg(VehicleParametersConverter::convert(engineSpec.fuelType).c_str())
        .toStdString();

	return { model + "został wyprodukowany przez firmę: " + manufacturer + " w roku: " + std::to_string(productionYear) +
		" posiada moc: "
		+ std::to_string(engineSpec.power) + " oraz napęd na "
		+ VehicleParametersConverter::convert(drive) + " z "
		+ VehicleParametersConverter::convert(transmission)
		+ "\nJest to samochód na: " + VehicleParametersConverter::convert(engineSpec.fuelType) };
}
