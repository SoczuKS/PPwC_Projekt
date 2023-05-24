#include "Scooter.hpp"

#include <string>

Scooter::Scooter(const VehicleParameters& params) : Vehicle(params) {}

std::string Scooter::getDescription() const
{
	return {};
}
