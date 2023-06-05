#pragma once

#include <cstdint>
#include <fstream>

struct Rent
{
	Rent(const uint64_t rd, const uint64_t uid, const uint64_t vId, const uint64_t sd, const uint16_t th, const uint16_t td) :
		id(rd),
		userId(uid),
		vehicleId(vId),
		startDate(sd),
		timeHours(th),
		timeDays(td)
	{}

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

private:
	uint64_t id;
	uint64_t userId;
	uint64_t vehicleId;
	uint64_t startDate;
	uint16_t timeHours;
	uint16_t timeDays;
};
