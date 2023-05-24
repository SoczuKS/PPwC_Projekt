#include "VehicleDatabase.hpp"

#include <exception>
#include <fstream>

#include "Bike.hpp"
#include "Utils.hpp"

const std::string VehicleDatabase::BikesDatabaseFilename = "data/bikes.csv";
const std::string VehicleDatabase::CarsDatabaseFilename = "data/cars.csv";
const std::string VehicleDatabase::MotorcyclesDatabaseFilename = "data/motorcycles.csv";
const std::string VehicleDatabase::ScootersDatabaseFilename = "data/scooters.csv";

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
	std::fstream file(BikesDatabaseFilename, std::ios::in);
	std::string line;

	while (std::getline(file, line))
	{
		auto substrings = utils::splitString(line, ';');

		if (6 != substrings.size())
		{
			throw std::exception("Invalid bike database");
		}

		VehicleParameters vehicleParams{
			.id = std::stoull(substrings[5]),
			.productionYear = static_cast<uint16_t>(std::stoi(substrings[2])),
			.pricePerHour = std::stof(substrings[0]),
			.pricePerDay = std::stof(substrings[1]),
			.manufacturer = substrings[3],
			.model = substrings[4]
		};

		bikes.emplace_back(std::make_shared<Bike>(vehicleParams));
	}
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
