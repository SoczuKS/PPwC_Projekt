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

	friend std::fstream& operator<<(std::fstream& file, const Scooter& s)
	{
		file << s.pricePerHour
			<< ';' << s.pricePerDay
			<< ';' << s.productionYear
			<< ';' << s.manufacturer
			<< ';' << s.model
			<< ';' << s.id;

		return file;
	}

private:

};
