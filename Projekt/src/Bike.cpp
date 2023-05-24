#include "Bike.hpp"

#include <string>

Bike::Bike(const VehicleParameters& params) : Vehicle(params) {}

std::string Bike::getDescription() const
{
	return {};
}
