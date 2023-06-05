#include "RentalService.hpp"

#include <fstream>
#include <ranges>

#include "Rent.hpp"
#include "Utils.hpp"

const std::string RentalService::RentsFilename = "data/rents.csv";

RentalService::RentalService()
{
	load();
}

RentalService::~RentalService()
{
	save();
}

void RentalService::load()
{
	std::fstream file(RentsFilename, std::ios::in);
	std::string line;

	while (std::getline(file, line))
	{
		auto substrings = Utils::splitString(line, ';');

		if (6 != substrings.size())
		{
			throw std::exception("Invalid save");
		}

		rents.emplace_back(Rent{
			std::stoull(substrings[0]),
			std::stoull(substrings[3]),
			std::stoull(substrings[4]),
			std::stoull(substrings[5]),
			static_cast<uint16_t>(std::stoi(substrings[1])),
			static_cast<uint16_t>(std::stoi(substrings[2]))
		});
	}
}

void RentalService::save() const
{
	std::fstream file(RentsFilename, std::ios::out);

	for (const auto& rent : rents)
	{
		file << rent << '\n';
	}
}

void RentalService::rentVehicle(uint64_t id, uint64_t userId, uint64_t vehicleId, uint64_t startDate, uint16_t timeHours, uint16_t timeDays)
{
	rents.emplace_back(Utils::generateId<Rent>(rents), userId, vehicleId, startDate, timeHours, timeDays);
}

std::vector<std::reference_wrapper<const Rent>> RentalService::getRentsByUserId(const uint64_t id) const
{
	std::vector<std::reference_wrapper<const Rent>> result;

	for (const auto& rent : rents)
	{
		if (id == rent.getId())
		{
			result.push_back(std::reference_wrapper(rent));
		}
	}

	return result;
}
