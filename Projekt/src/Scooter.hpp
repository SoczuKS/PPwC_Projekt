#pragma once

#include <fstream>
#include <string>

#include "Vehicle.hpp"

class Scooter final : public Vehicle
{
public:
	Scooter(const VehicleParameters&);
	~Scooter() override = default;

	std::string getDescription() const override;

	std::fstream& operator<<(std::fstream& file) override
	{
		file << pricePerHour
			<< ',' << pricePerDay
			<< ',' << productionYear
			<< ',' << manufacturer
			<< ',' << model
			<< ',' << id;

		return file;
	}

private:

};
