#include "Scooter.hpp"

#include <QObject>

#include <string>

Scooter::Scooter(const VehicleParameters& params) : Vehicle(params) {}

std::string Scooter::getDescription() const
{
	return QObject::tr("scooter_description").arg(model.c_str()).arg(manufacturer.c_str()).arg(productionYear).toStdString();
}
