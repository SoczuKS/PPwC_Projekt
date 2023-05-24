#include "VehicleDatabase.hpp"

#include <fstream>

#include "Bike.hpp"

const std::string VehicleDatabase::BikesDatabaseFilename = "bikes.csv";
const std::string VehicleDatabase::CarsDatabaseFilename = "cars.csv";
const std::string VehicleDatabase::MotorcyclesDatabaseFilename = "motorcycles.csv";
const std::string VehicleDatabase::ScootersDatabaseFilename = "scooters.csv";

VehicleDatabase::VehicleDatabase()
{
	load();
}

VehicleDatabase::~VehicleDatabase()
{
	save();
}

void VehicleDatabase::save() const
{
	saveBikes();
	saveCars();
	saveMotorcycles();
	saveScooters();
}

void VehicleDatabase::saveBikes() const
{
	std::fstream file(BikesDatabaseFilename, std::ios::in);

	for (const auto& bike : bikes)
	{
		file << bike.get() << '\n';
	}
}

void VehicleDatabase::saveCars() const
{
	std::fstream file(CarsDatabaseFilename, std::ios::in);

	for (const auto& car : cars)
	{
		file << car.get() << '\n';
	}
}

void VehicleDatabase::saveMotorcycles() const
{
	std::fstream file(MotorcyclesDatabaseFilename, std::ios::in);

	for (const auto& motorcycle : motorcycles)
	{
		file << motorcycle.get() << '\n';
	}
}

void VehicleDatabase::saveScooters() const
{
	std::fstream file(ScootersDatabaseFilename, std::ios::in);

	for (const auto& scooter : scooters)
	{
		file << scooter.get() << '\n';
	}
}

void VehicleDatabase::load()
{
	loadBikes();
	loadCars();
	loadMotorcycles();
	loadScooters();
}

void VehicleDatabase::loadBikes()
{

}

void VehicleDatabase::loadCars()
{

}

void VehicleDatabase::loadMotorcycles()
{

}

void VehicleDatabase::loadScooters()
{

}
