#include "VehicleDatabase.hpp"

#include <exception>
#include <fstream>

#include "Bike.hpp"
#include "Car.hpp"
#include "Motorcycle.hpp"
#include "Scooter.hpp"
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
	std::fstream file(BikesDatabaseFilename, std::ios::out);

	for (const auto& bike : bikes)
	{
		file << *bike << '\n';
	}
}

void VehicleDatabase::saveCars() const
{
	std::fstream file(CarsDatabaseFilename, std::ios::out);

	for (const auto& car : cars)
	{
		file << *car << '\n';
	}
}

void VehicleDatabase::saveMotorcycles() const
{
	std::fstream file(MotorcyclesDatabaseFilename, std::ios::out);

	for (const auto& motorcycle : motorcycles)
	{
		file << *motorcycle << '\n';
	}
}

void VehicleDatabase::saveScooters() const
{
	std::fstream file(ScootersDatabaseFilename, std::ios::out);

	for (const auto& scooter : scooters)
	{
		file << *scooter << '\n';
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
	std::fstream file(CarsDatabaseFilename, std::ios::in);
	std::string line;

	while (std::getline(file, line))
	{
		auto substrings = utils::splitString(line, ';');

		if (11 != substrings.size())
		{
			throw std::exception("Invalid bike database");
		}

		VehicleParameters vehicleParams{
			.id = std::stoull(substrings[10]),
			.productionYear = static_cast<uint16_t>(std::stoi(substrings[2])),
			.pricePerHour = std::stof(substrings[0]),
			.pricePerDay = std::stof(substrings[1]),
			.manufacturer = substrings[3],
			.model = substrings[4]
		};

		MotorizedVehicleParameters motorizedVehicleParams{
			.drive = static_cast<MotorizedVehicle::Drive>(std::stoi(substrings[5])),
			.transmission = static_cast<MotorizedVehicle::Transmission>(std::stoi(substrings[6])),
			.engineSpec = {
				.capacity = std::stof(substrings[7]),
				.power = static_cast<uint16_t>(std::stoi(substrings[8])),
				.fuelType = static_cast<MotorizedVehicle::EngineSpec::FuelType>(std::stoi(substrings[9])),
			}
		};

		cars.emplace_back(std::make_shared<Car>(vehicleParams, motorizedVehicleParams));
	}
}

void VehicleDatabase::loadMotorcycles()
{
	std::fstream file(MotorcyclesDatabaseFilename, std::ios::in);
	std::string line;

	while (std::getline(file, line))
	{
		auto substrings = utils::splitString(line, ';');

		if (9 != substrings.size())
		{
			throw std::exception("Invalid motorcycle database");
		}

		VehicleParameters vehicleParams{
			.id = std::stoull(substrings[5]),
			.productionYear = static_cast<uint16_t>(std::stoi(substrings[2])),
			.pricePerHour = std::stof(substrings[0]),
			.pricePerDay = std::stof(substrings[1]),
			.manufacturer = substrings[3],
			.model = substrings[4],
		};

		MotorizedVehicleParameters params{
			.drive = MotorizedVehicle::Drive::rear,
			.transmission = static_cast<MotorizedVehicle::Transmission>(std::stoi(substrings[5])),
			.engineSpec = {
				.capacity = std::stof(substrings[6]),
				.power = static_cast<uint16_t>(std::stoi(substrings[7]))
			}
		};

		motorcycles.emplace_back(std::make_shared<Motorcycle>(vehicleParams, params));
	}
}

void VehicleDatabase::loadScooters()
{
	std::fstream file(ScootersDatabaseFilename, std::ios::in);
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

		scooters.emplace_back(std::make_shared<Scooter>(vehicleParams));
	}
}

std::shared_ptr<Bike> VehicleDatabase::getBikeById(uint64_t id) const
{
	if (const auto& it = std::ranges::find_if(bikes, [&id](const std::shared_ptr<Bike>& bike)
	{
		return id == bike->getId();
	}); bikes.end() != it)
	{
		return *it;
	}
	return nullptr;
}

std::shared_ptr<Car> VehicleDatabase::getCarById(uint64_t id) const
{
	if (const auto& it = std::ranges::find_if(cars, [&id](const std::shared_ptr<Car>& car)
	{
		return id == car->getId();
	}); cars.end() != it)
	{
		return *it;
	}
	return nullptr;
}

std::shared_ptr<Motorcycle> VehicleDatabase::getMotorcycleById(uint64_t id) const
{
	if (const auto& it = std::ranges::find_if(motorcycles, [&id](const std::shared_ptr<Motorcycle>& motorcycle)
	{
		return id == motorcycle->getId();
	}); motorcycles.end() != it)
	{
		return *it;
	}
	return nullptr;
}

std::shared_ptr<Scooter> VehicleDatabase::getScooterById(uint64_t id) const
{
	if (const auto& it = std::ranges::find_if(scooters, [&id](const std::shared_ptr<Scooter>& scooter)
	{
		return id == scooter->getId();
	}); scooters.end() != it)
	{
		return *it;
	}
	return nullptr;
}
