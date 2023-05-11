#pragma once

#include <string>

class Vehicle
{
public:
	Vehicle() = default;
	Vehicle(std::string, std::string, std::uint16_t, float, float);
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

	void setProductionYear(const std::uint16_t py)
	{
		productionYear = py;
	}
	std::uint16_t getProductionYear() const
	{
		return productionYear;
	}

	void setManufacturer(std::string mf)
	{
		manufacturer = std::move(mf);
	}
	std::string getManufacturer()
	{
		return manufacturer;
	}

	void setModel(std::string mo)
	{
		model = std::move(mo);
	}
	std::string getModel()
	{
		return model;
	}

	virtual std::string getDescription() const = 0;

private:
	std::uint16_t productionYear;
	float pricePerHour;
	float pricePerDay;
	std::string manufacturer;
	std::string model;
};
