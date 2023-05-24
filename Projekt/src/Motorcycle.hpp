#pragma once

#include <fstream>
#include <string>

#include "MotorizedVehicle.hpp"

class Motorcycle final : public MotorizedVehicle
{
public:
	Motorcycle(const VehicleParameters&, const MotorizedVehicleParameters&);
	~Motorcycle() override = default;

	std::string getDescription() const override;

	friend std::fstream& operator<<(std::fstream& file, const Motorcycle& m)
	{
		file << m.pricePerHour
			<< ';' << m.pricePerDay
			<< ';' << m.productionYear
			<< ';' << m.manufacturer
			<< ';' << m.model
			<< ';' << static_cast<int>(m.transmission)
			<< ';' << m.engineSpec.capacity
			<< ';' << m.engineSpec.power
			<< ';' << m.id;

		return file;
	};

private:

};
