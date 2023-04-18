#pragma once

#include <string>
#include "Vehicle.hpp"

class Bike final : public Vehicle
{
public:
	Bike() = default;
	~Bike() override = default;

	std::string getDescription() const override;

private:

};
