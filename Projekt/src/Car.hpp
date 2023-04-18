#pragma once

#include <string>
#include "Vehicle.hpp"

class Car final : public Vehicle
{
public:
	Car() = default;
	~Car() override = default;

	std::string getDescription() const override;

private:

};
