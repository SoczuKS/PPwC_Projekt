#pragma once

#include <map>

#include <QObject>

#include "MotorizedVehicle.hpp"

class VehicleParametersConverter
{
public:
	static std::string convert(const MotorizedVehicle::Drive drive)
	{
		return DriveToStringMap.at(drive);
	};

	static std::string convert(const MotorizedVehicle::Transmission transmission)
	{
		return TransmissionToStringMap.at(transmission);
	};

	static std::string convert(const MotorizedVehicle::EngineSpec::FuelType fuelType)
	{
		return FuelTypeToStringMap.at(fuelType);
	};

private:
	inline static const std::map<MotorizedVehicle::Drive, std::string> DriveToStringMap =
	{
		{ MotorizedVehicle::Drive::front, QObject::tr("front").toStdString() },
		{ MotorizedVehicle::Drive::rear, QObject::tr("rear").toStdString() },
		{ MotorizedVehicle::Drive::all, QObject::tr("all").toStdString() }
	};

	inline static const std::map<MotorizedVehicle::Transmission, std::string> TransmissionToStringMap =
	{
		{ MotorizedVehicle::Transmission::manual, QObject::tr("manual").toStdString() },
		{ MotorizedVehicle::Transmission::automatic, QObject::tr("automatic").toStdString() }
	};

	inline static const std::map<MotorizedVehicle::EngineSpec::FuelType, std::string> FuelTypeToStringMap =
	{
		{ MotorizedVehicle::EngineSpec::FuelType::petrol, QObject::tr("petrol").toStdString() },
		{ MotorizedVehicle::EngineSpec::FuelType::petrolAndLPG, QObject::tr("petrol_and_lpg").toStdString() },
		{ MotorizedVehicle::EngineSpec::FuelType::diesel, QObject::tr("diesel").toStdString() },
		{ MotorizedVehicle::EngineSpec::FuelType::electric, QObject::tr("electric").toStdString() }
	};
};
