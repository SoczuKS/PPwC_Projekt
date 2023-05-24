#pragma once

#include <fstream>
#include <string>

#include "Vehicle.hpp"

class Bike final : public Vehicle
{
public:
	Bike() = default;
	~Bike() override = default;

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
