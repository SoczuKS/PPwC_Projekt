#pragma once

#include <fstream>
#include <string>

#include "Vehicle.hpp"

class Bike final : public Vehicle
{
public:
	Bike(const VehicleParameters&);
	~Bike() override = default;

	std::string getDescription() const override;

	friend std::fstream& operator<<(std::fstream& file, const Bike& b)
	{
		file << b.pricePerHour
			<< ';' << b.pricePerDay
			<< ';' << b.productionYear
			<< ';' << b.manufacturer
			<< ';' << b.model
			<< ';' << b.id;

		return file;
	}

private:

};
