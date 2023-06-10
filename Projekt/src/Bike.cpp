#include "Bike.hpp"

#include <string>

Bike::Bike(const VehicleParameters& params) : Vehicle(params) {}

std::string Bike::getDescription() const
{
	return { model + " został wyprodukowany przez firmę: " + manufacturer + " w roku: " + std::to_string(productionYear) };
}
