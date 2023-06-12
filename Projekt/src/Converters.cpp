#include "Converters.hpp"

#include <QObject>

namespace converters
{
std::string toString(const MotorizedVehicle::Drive drive)
{
	switch (drive)
	{
	case MotorizedVehicle::Drive::front: return QObject::tr("front").toStdString();
	case MotorizedVehicle::Drive::rear: return QObject::tr("rear").toStdString();
	case MotorizedVehicle::Drive::all: return QObject::tr("all").toStdString();
	default: return QObject::tr("undefined").toStdString();
	}
}

std::string toString(const MotorizedVehicle::Transmission transmission)
{
	switch (transmission)
	{
	case MotorizedVehicle::Transmission::manual: return QObject::tr("manual").toStdString();
	case MotorizedVehicle::Transmission::automatic: return QObject::tr("automatic").toStdString();
	default: return QObject::tr("undefined").toStdString();
	}
}

std::string toString(const MotorizedVehicle::EngineSpec::FuelType fuelType)
{
	switch (fuelType)
	{
	case MotorizedVehicle::EngineSpec::FuelType::petrol: return QObject::tr("petrol").toStdString();
	case MotorizedVehicle::EngineSpec::FuelType::petrolAndLPG: return QObject::tr("petrol_and_lpg").toStdString();
	case MotorizedVehicle::EngineSpec::FuelType::diesel: return QObject::tr("diesel").toStdString();
	case MotorizedVehicle::EngineSpec::FuelType::electric: return QObject::tr("electric").toStdString();
	default: return QObject::tr("undefined").toStdString();
	}
}
}