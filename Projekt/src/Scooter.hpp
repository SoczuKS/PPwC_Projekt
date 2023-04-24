#pragma once

#include <string>
#include "Vehicle.hpp"

class Scooter final : public Vehicle
{
public:
	Scooter() = default;
	~Scooter() override = default;

	std::string getDescription() const override;

private:

};
