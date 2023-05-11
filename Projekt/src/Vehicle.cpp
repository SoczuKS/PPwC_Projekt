#include "Vehicle.hpp"

Vehicle::Vehicle(const VehicleParameters& params) :
	productionYear{ params.productionYear },
	pricePerHour{ params.pricePerHour },
	pricePerDay{ params.pricePerDay },
	manufacturer{ params.manufacturer },
	model{ params.model } {}
