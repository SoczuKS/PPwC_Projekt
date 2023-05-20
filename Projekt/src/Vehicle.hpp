#pragma once

#include <string>

struct VehicleParameters
{
	uint64_t id;
	std::uint16_t productionYear;
	float pricePerHour;
	float pricePerDay;
	std::string manufacturer;
	std::string model;
};

class Vehicle
{
public:
	Vehicle() = delete;
	Vehicle(const VehicleParameters&);
	virtual ~Vehicle() = default;

	uint64_t getId() const
	{ 
		return id;
	}

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
	std::string getManufacturer() const
	{
		return manufacturer;
	}

	void setModel(std::string mo)
	{
		model = std::move(mo);
	}
	std::string getModel() const
	{
		return model;
	}

	virtual std::string getDescription() const = 0;

private:
	const uint64_t id;
	uint16_t productionYear;
	float pricePerHour;
	float pricePerDay;
	std::string manufacturer;
	std::string model;
};
