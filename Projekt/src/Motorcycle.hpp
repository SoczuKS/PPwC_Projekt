#pragma once

#include <fstream>
#include <string>

#include "MotorizedVehicle.hpp"

class Motorcycle final : public MotorizedVehicle
{
public:
	Motorcycle() = default;
	~Motorcycle() override = default;

	std::string getDescription() const override;

	std::fstream& operator<<(std::fstream& file) override
	{
		file << pricePerHour
			<< ',' << pricePerDay
			<< ',' << productionYear
			<< ',' << manufacturer
			<< ',' << model
			<< ',' << static_cast<int>(transmission)
			<< ',' << engineSpec.capacity
			<< ',' << engineSpec.power
			<< ',' << id;

		return file;
	};

private:

};
