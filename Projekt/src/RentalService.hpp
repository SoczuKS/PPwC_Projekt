#pragma once

#include <random>
#include <vector>

struct Rent;

class RentalService final
{
public:
	RentalService() noexcept(false);
	~RentalService();

	std::vector<std::reference_wrapper<const Rent>> getRentsByUserId(uint64_t) const;

private:
	void load() noexcept(false);
	void save() const;

	void rentVehicle(uint64_t id, uint64_t userId, uint64_t vehicleId, uint64_t startDate, uint16_t timeHours, uint16_t timeDays);
	std::vector<Rent> rents;

	static const std::string RentsFilename;
};
