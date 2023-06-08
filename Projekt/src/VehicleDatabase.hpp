#pragma once

#include <memory>
#include <string>
#include <vector>

class Bike;
class Car;
class Logger;
class Motorcycle;
class Scooter;
class Vehicle;

class VehicleDatabase final
{
public:
	VehicleDatabase(std::shared_ptr<Logger>) noexcept(false);
	~VehicleDatabase();

	const auto& getBikes() const { return bikes; }
	const auto& getCars() const { return cars; }
	const auto& getMotorcycles() const { return motorcycles; }
	const auto& getScooters() const { return scooters; }

	std::shared_ptr<Bike> getBikeById(uint64_t) const;
	std::shared_ptr<Car> getCarById(uint64_t) const;
	std::shared_ptr<Motorcycle> getMotorcycleById(uint64_t) const;
	std::shared_ptr<Scooter> getScooterById(uint64_t) const;

	void addVehicle(std::shared_ptr<Bike>);
	void addVehicle(std::shared_ptr<Car>);
	void addVehicle(std::shared_ptr<Motorcycle>);
	void addVehicle(std::shared_ptr<Scooter>);

	void removeVehicle(uint64_t id);

private:
	void save() const;
	void saveBikes() const;
	void saveCars() const;
	void saveMotorcycles() const;
	void saveScooters() const;

	void load() noexcept(false);
	void loadBikes() noexcept(false);
	void loadCars() noexcept(false);
	void loadMotorcycles() noexcept(false);
	void loadScooters() noexcept(false);

	std::vector<std::shared_ptr<Bike>> bikes;
	std::vector<std::shared_ptr<Car>> cars;
	std::vector<std::shared_ptr<Motorcycle>> motorcycles;
	std::vector<std::shared_ptr<Scooter>> scooters;

	std::shared_ptr<Logger> logger;

	static const std::string BikesDatabaseFilename;
	static const std::string CarsDatabaseFilename;
	static const std::string MotorcyclesDatabaseFilename;
	static const std::string ScootersDatabaseFilename;
};
