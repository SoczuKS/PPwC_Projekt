#include "Vehicle.hpp"

Vehicle::Vehicle(const VehicleParameters& params) :
	id{ params.id },
	productionYear{ params.productionYear },
	pricePerHour{ params.pricePerHour },
	pricePerDay{ params.pricePerDay },
	manufacturer{ params.manufacturer },
	model{ params.model }
{
}
