#pragma once

#include <map>

#include "MotorizedVehicle.hpp"

class VehicleParametersConverter
{
public:
	static std::string convert(MotorizedVehicle::Drive drive)
	{
		return driveToStringMap.at(drive);
	};

	static std::string convert(MotorizedVehicle::Transmission transmission)
	{
		return transmissionToStringMap.at(transmission);
	};

	static std::string convert(MotorizedVehicle::EngineSpec::FuelType fuelType)
	{
		return fuelTypeToStringMap.at(fuelType);
	};

private:
	inline static const std::map<MotorizedVehicle::Drive, std::string> driveToStringMap =
	{
		{ MotorizedVehicle::Drive::front, "przedni" },
		{ MotorizedVehicle::Drive::rear, "tylni" },
		{ MotorizedVehicle::Drive::all, "na wszystkie kola" }
	};

	inline static const std::map<MotorizedVehicle::Transmission, std::string> transmissionToStringMap =
	{
		{ MotorizedVehicle::Transmission::manual, "manualna" },
		{ MotorizedVehicle::Transmission::automatic, "automatyczna" }
	};

	inline static const std::map<MotorizedVehicle::EngineSpec::FuelType, std::string> fuelTypeToStringMap =
	{
		{ MotorizedVehicle::EngineSpec::FuelType::petrol, "benzyna" },
		{ MotorizedVehicle::EngineSpec::FuelType::petrolAndLPG, "benzyna i LPG" },
		{ MotorizedVehicle::EngineSpec::FuelType::diesel, "diesel" },
		{ MotorizedVehicle::EngineSpec::FuelType::electric, "elektryczne" }
	};
};
