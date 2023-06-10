#include "Scooter.hpp"

#include <string>

Scooter::Scooter(const VehicleParameters& params) : Vehicle(params) {}

std::string Scooter::getDescription() const
{
	return { model + " został wyprodukowany przez firmę: " + manufacturer + " w roku: " + std::to_string(productionYear) };
}
