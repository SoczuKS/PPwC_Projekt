#pragma once

#include <string>
#include "Vehicle.hpp"

class Motorcycle final : public Vehicle
{
public:
	Motorcycle() = default;
	~Motorcycle() override = default;

	std::string getDescription() const override;

private:

};
