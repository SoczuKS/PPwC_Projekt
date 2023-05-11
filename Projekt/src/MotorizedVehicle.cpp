#include "MotorizedVehicle.hpp"

MotorizedVehicle::MotorizedVehicle(const VehicleParameters& vehicleParams, const MotorizedVehicleParameters& params) :
	Vehicle(vehicleParams),
	drive{ params.drive },
	transmission{ params.transmission },
	engineSpec{ params.engineSpec } {}
