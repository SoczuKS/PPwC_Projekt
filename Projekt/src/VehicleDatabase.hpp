#pragma once

#include <memory>
#include <string>
#include <vector>

class Vehicle;
class Bike;
class Car;
class Motorcycle;
class Scooter;

class VehicleDatabase final
{
public:
	VehicleDatabase() noexcept(false);
	~VehicleDatabase();

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

	static const std::string BikesDatabaseFilename;
	static const std::string CarsDatabaseFilename;
	static const std::string MotorcyclesDatabaseFilename;
	static const std::string ScootersDatabaseFilename;
};
