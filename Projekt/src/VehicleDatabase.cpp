#include "VehicleDatabase.hpp"

#include <exception>
#include <fstream>

#include "Bike.hpp"
#include "Car.hpp"
#include "Logger.hpp"
#include "Motorcycle.hpp"
#include "Scooter.hpp"
#include "Utils.hpp"

const std::string VehicleDatabase::BikesDatabaseFilename = "data/bikes.csv";
const std::string VehicleDatabase::CarsDatabaseFilename = "data/cars.csv";
const std::string VehicleDatabase::MotorcyclesDatabaseFilename = "data/motorcycles.csv";
const std::string VehicleDatabase::ScootersDatabaseFilename = "data/scooters.csv";

VehicleDatabase::VehicleDatabase(const std::shared_ptr<Logger>& logger) : logger{ logger }
{
	load();
}

VehicleDatabase::~VehicleDatabase()
{
	save();
}

void VehicleDatabase::addVehicle(std::shared_ptr<Bike> bike)
{
	bike->setId(bikes.back()->getId() + 1);
	logger->write("New bike [" + bike->getModel() + "] added");
	bikes.emplace_back(std::move(bike));
}

void VehicleDatabase::addVehicle(std::shared_ptr<Car> car)
{
	car->setId(cars.back()->getId() + 1);
	logger->write("New car [" + car->getModel() + "] added");
	cars.emplace_back(std::move(car));
}

void VehicleDatabase::addVehicle(std::shared_ptr<Motorcycle> motorcycle)
{
	motorcycle->setId(motorcycles.back()->getId() + 1);
	logger->write("New motorcycle [" + motorcycle->getModel() + "] added");
	motorcycles.emplace_back(std::move(motorcycle));
}

void VehicleDatabase::addVehicle(std::shared_ptr<Scooter> scooter)
{
	scooter->setId(scooters.back()->getId() + 1);
	logger->write("New scooter [" + scooter->getModel() + "] added");
	scooters.emplace_back(std::move(scooter));
}

void VehicleDatabase::removeVehicle(uint64_t id)
{
	if (0 < std::erase_if(bikes, [id](const auto& bike) {
		return id == bike->getId();
	}))
	{
		return;
	}

	if (0 < std::erase_if(cars, [id](const auto& car) {
		return id == car->getId();
	}))
	{
		return;
	}

	if (0 < std::erase_if(motorcycles, [id](const auto& motorcycle) {
		return id == motorcycle->getId();
	}))
	{
		return;
	}

	std::erase_if(scooters, [id](const auto& scooter) {
		return id == scooter->getId();
	});
}

void VehicleDatabase::save() const
{
	logger->write("Saving vehicles...");
	saveBikes();
	saveCars();
	saveMotorcycles();
	saveScooters();
	logger->write("All vehicles saved");
}

void VehicleDatabase::saveBikes() const
{
	logger->write("Saving bikes...");
	std::fstream file(BikesDatabaseFilename, std::ios::out);

	for (const auto& bike : bikes)
	{
		file << *bike << '\n';
	}
	logger->write("Saved bikes");
}

void VehicleDatabase::saveCars() const
{
	logger->write("Saving bikes...");
	std::fstream file(CarsDatabaseFilename, std::ios::out);

	for (const auto& car : cars)
	{
		file << *car << '\n';
	}
	logger->write("Saved cars");
}

void VehicleDatabase::saveMotorcycles() const
{
	logger->write("Saving motorcycles...");
	std::fstream file(MotorcyclesDatabaseFilename, std::ios::out);

	for (const auto& motorcycle : motorcycles)
	{
		file << *motorcycle << '\n';
	}
	logger->write("Saved motorcycles");
}

void VehicleDatabase::saveScooters() const
{
	logger->write("Saving scooters...");
	std::fstream file(ScootersDatabaseFilename, std::ios::out);

	for (const auto& scooter : scooters)
	{
		file << *scooter << '\n';
	}
	logger->write("Saved scooters...");
}

void VehicleDatabase::load()
{
	logger->write("Loading vehicles...");
	loadBikes();
	loadCars();
	loadMotorcycles();
	loadScooters();
	logger->write("Vehicles loaded");
}

void VehicleDatabase::loadBikes()
{
	logger->write("Loading bikes...");
	std::fstream file(BikesDatabaseFilename, std::ios::in);
	std::string line;

	while (std::getline(file, line))
	{
		auto substrings = Utils::splitString(line, ';');

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
	logger->write("Bikes loaded");
}

void VehicleDatabase::loadCars()
{
	logger->write("Loading cars...");
	std::fstream file(CarsDatabaseFilename, std::ios::in);
	std::string line;

	while (std::getline(file, line))
	{
		auto substrings = Utils::splitString(line, ';');

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
	logger->write("Cars loaded");
}

void VehicleDatabase::loadMotorcycles()
{
	logger->write("Loading motorcycles...");
	std::fstream file(MotorcyclesDatabaseFilename, std::ios::in);
	std::string line;

	while (std::getline(file, line))
	{
		auto substrings = Utils::splitString(line, ';');

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
	logger->write("Motorcycles loaded");
}

void VehicleDatabase::loadScooters()
{
	logger->write("Loading scooters...");
	std::fstream file(ScootersDatabaseFilename, std::ios::in);
	std::string line;

	while (std::getline(file, line))
	{
		auto substrings = Utils::splitString(line, ';');

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
	logger->write("Scooters loaded");
}

std::shared_ptr<Bike> VehicleDatabase::getBikeById(uint64_t id) const
{
	if (const auto& it = std::ranges::find_if(bikes, [&id](const std::shared_ptr<Bike>& bike) {
		return id == bike->getId();
	}); bikes.end() != it)
	{
		return *it;
	}
	return nullptr;
}

std::shared_ptr<Car> VehicleDatabase::getCarById(uint64_t id) const
{
	if (const auto& it = std::ranges::find_if(cars, [&id](const std::shared_ptr<Car>& car) {
		return id == car->getId();
	}); cars.end() != it)
	{
		return *it;
	}
	return nullptr;
}

std::shared_ptr<Motorcycle> VehicleDatabase::getMotorcycleById(uint64_t id) const
{
	if (const auto& it = std::ranges::find_if(motorcycles, [&id](const std::shared_ptr<Motorcycle>& motorcycle) {
		return id == motorcycle->getId();
	}); motorcycles.end() != it)
	{
		return *it;
	}
	return nullptr;
}

std::shared_ptr<Scooter> VehicleDatabase::getScooterById(uint64_t id) const
{
	if (const auto& it = std::ranges::find_if(scooters, [&id](const std::shared_ptr<Scooter>& scooter) {
		return id == scooter->getId();
	}); scooters.end() != it)
	{
		return *it;
	}
	return nullptr;
}

std::shared_ptr<Vehicle> VehicleDatabase::getVehicleById(const uint64_t id) const
{
	std::shared_ptr<Vehicle> vehicle = getCarById(id);
	if (vehicle)
	{
		return vehicle;
	}

	vehicle = getBikeById(id);
	if (vehicle)
	{
		return vehicle;
	}

	vehicle = getMotorcycleById(id);
	if (vehicle)
	{
		return vehicle;
	}

	vehicle = getScooterById(id);
	if (vehicle)
	{
		return vehicle;
	}

	return vehicle;
}
