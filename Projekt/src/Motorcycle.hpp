#pragma once

#include <string>
#include "MotorizedVehicle.hpp"

class Motorcycle final : public MotorizedVehicle
{
public:
	Motorcycle() = default;
	~Motorcycle() override = default;

	std::string getDescription() const override;

private:

};
