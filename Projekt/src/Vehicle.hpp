#pragma once

#include <string>

class Vehicle
{
public:
	Vehicle() = default;
	virtual ~Vehicle() = default;

	void setPricePerHour(const float pph)
	{
		pricePerHour = pph;
	}
	float getPricePerHour() const
	{
		return pricePerHour;
	}

	void setPricePerDay(const float ppd)
	{
		pricePerDay = ppd;
	}
	float getPricePerDay() const
	{
		return pricePerDay;
	}

	virtual std::string getDescription() const = 0;

private:
	float pricePerHour;
	float pricePerDay;
};
