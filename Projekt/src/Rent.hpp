#pragma once

#include <cstdint>
#include <fstream>

struct Rent
{
	Rent(uint64_t rd, uint64_t uid, uint64_t vId, uint64_t sd, uint16_t th, uint16_t td);

	friend std::fstream& operator<<(std::fstream& file, const Rent& r)
	{
		file << r.id
			<< ';' << r.timeHours
			<< ';' << r.timeDays
			<< ';' << r.userId
			<< ';' << r.vehicleId
			<< ';' << r.startDate;
		return file;
	}

	uint64_t getId() const { return id; }

	uint64_t getUserId() const { return userId; }

	uint64_t getVehicleId() const { return vehicleId; }

	uint64_t getStartDate() const { return startDate; }

	uint16_t getHours() const { return timeHours; }

	uint16_t getDays() const { return timeDays; }

private:
	uint64_t id;
	uint64_t userId;
	uint64_t vehicleId;
	uint64_t startDate;
	uint16_t timeHours;
	uint16_t timeDays;
};
