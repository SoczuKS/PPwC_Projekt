#pragma once

#include <memory>
#include <vector>

class Vehicle;

class VehicleDatabase final
{
public:

private:
	void save() const;
	void load();
	std::vector<std::shared_ptr<Vehicle>> vehicles;
};
