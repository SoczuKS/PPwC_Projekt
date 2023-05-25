#pragma once

#include "Vehicle.hpp"

struct MotorizedVehicleParameters;

class MotorizedVehicle : public Vehicle
{
public:
	enum class Drive
	{
		front,
		rear,
		all
	};
	enum class Transmission
	{
		manual,
		automatic
	};
	struct EngineSpec
	{
		float capacity;
		std::uint16_t power;
		enum class FuelType
		{
			petrol,
			petrolAndLPG,
			diesel,
			electric
		} fuelType;
	};

	MotorizedVehicle(const VehicleParameters&, const MotorizedVehicleParameters&);

	void setDrive(const Drive d)
	{
		drive = d;
	}
	Drive getDrive() const
	{
		return drive;
	}

	void setTransmission(const Transmission t)
	{
		transmission = t;
	}
	Transmission getTransmission() const
	{
		return transmission;
	}

	void setEngineSpec(const EngineSpec& es)
	{
		engineSpec = es;
	}
	EngineSpec getEngineSpec() const
	{
		return engineSpec;
	}

protected:
	Drive drive;
	Transmission transmission;
	EngineSpec engineSpec;
};

struct MotorizedVehicleParameters
{
	MotorizedVehicle::Drive drive;
	MotorizedVehicle::Transmission transmission;
	MotorizedVehicle::EngineSpec engineSpec;
};
