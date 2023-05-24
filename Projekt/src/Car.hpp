#pragma once

#include <fstream>
#include <string>

#include "MotorizedVehicle.hpp"

class Car final : public MotorizedVehicle
{
public:
	Car(const VehicleParameters&, const MotorizedVehicleParameters&);
	~Car() override = default;

	std::string getDescription() const override;

	friend std::fstream& operator<<(std::fstream& file, const Car& c)
	{
		file << c.pricePerHour
			<< ';' << c.pricePerDay
			<< ';' << c.productionYear
			<< ';' << c.manufacturer
			<< ';' << c.model
			<< ';' << static_cast<int>(c.drive)
			<< ';' << static_cast<int>(c.transmission)
			<< ';' << c.engineSpec.capacity
			<< ';' << c.engineSpec.power
			<< ';' << static_cast<int>(c.engineSpec.fuelType)
			<< ';' << c.id;

		return file;
	}

private:

};
