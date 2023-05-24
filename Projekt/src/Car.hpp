#pragma once

#include <fstream>
#include <string>

#include "MotorizedVehicle.hpp"

class Car final : protected MotorizedVehicle
{
public:
	Car() = default;
	~Car() override = default;

	std::string getDescription() const override;


	std::fstream& operator<<(std::fstream& file) override
	{
		file << pricePerHour
			<< ',' << pricePerDay
			<< ',' << productionYear
			<< ',' << manufacturer
			<< ',' << model
			<< ',' << static_cast<int>(drive)
			<< ',' << static_cast<int>(transmission)
			<< ',' << engineSpec.capacity
			<< ',' << engineSpec.power
			<< ',' << static_cast<int>(engineSpec.fuelType)
			<< ',' << id;

		return file;
	}

private:

};
