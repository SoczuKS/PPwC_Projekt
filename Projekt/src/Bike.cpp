#include "Bike.hpp"

#include <string>

#include <QObject>

Bike::Bike(const VehicleParameters& params) : Vehicle(params) {}

std::string Bike::getDescription() const
{
	return QObject::tr("bike_description").arg(model.c_str()).arg(manufacturer.c_str()).arg(productionYear).toStdString();
}
