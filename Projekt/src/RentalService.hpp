#pragma once

#include <QDateTime>

#include <random>
#include <vector>

class Logger;
struct Rent;

class RentalService final
{
public:
	RentalService(std::shared_ptr<Logger>) noexcept(false);
	~RentalService();

	std::vector<std::reference_wrapper<const Rent>> getRentsByUserId(uint64_t) const;

	void rentVehicle(uint64_t userId, uint64_t vehicleId, uint16_t timeHours, uint16_t timeDays, uint64_t startDate = QDateTime::currentSecsSinceEpoch());

private:
	void load() noexcept(false);
	void save() const;

	std::vector<Rent> rents;
	std::shared_ptr<Logger> logger;

	static const std::string RentsFilename;
};
