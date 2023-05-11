#include "Vehicle.hpp"

Vehicle::Vehicle(std::string mf, std::string mo, const std::uint16_t py, const float pph, const float ppd) :
	productionYear{ py },
	pricePerHour{ pph },
	pricePerDay{ ppd },
	manufacturer{ std::move(mf) },
	model{ std::move(mo) } {}
