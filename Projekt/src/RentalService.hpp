#pragma once

#include <fstream>
#include <vector>

class RentalService final
{
public:
	RentalService() noexcept(false);
	~RentalService();

	struct Rent
	{
		uint64_t id;
		uint64_t userId;
		uint64_t vehicleId;
		uint64_t startDate;
		uint16_t timeHours;
		uint16_t timeDays;

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
	};

private:
	void load() noexcept(false);
	void save() const;

	std::vector<Rent> rents;

	static const std::string RentsFilename;
};
