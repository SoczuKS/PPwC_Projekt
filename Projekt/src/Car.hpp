#pragma once

#include <string>
#include "MotorizedVehicle.hpp"

class Car final : public MotorizedVehicle
{
public:
	Car() = default;
	~Car() override = default;

	std::string getDescription() const override;

private:

};
