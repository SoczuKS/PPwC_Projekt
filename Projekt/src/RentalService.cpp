#include "RentalService.hpp"

#include <fstream>
#include <ranges>

#include "Logger.hpp"
#include "Rent.hpp"
#include "Utils.hpp"

const std::string RentalService::RentsFilename = "data/rents.csv";

RentalService::RentalService(const std::shared_ptr<Logger>& logger) : logger{ logger }
{
	load();
}

RentalService::~RentalService()
{
	save();
}

void RentalService::load()
{
	logger->write("Loading rents...");
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
	logger->write("Rents loaded");
}

void RentalService::save() const
{
	logger->write("Saving rents...");
	std::fstream file(RentsFilename, std::ios::out);

	for (const auto& rent : rents)
	{
		file << rent << '\n';
	}
	logger->write("Rents saved");
}

void RentalService::rentVehicle(uint64_t userId, uint64_t vehicleId, uint16_t timeHours, uint16_t timeDays, uint64_t startDate)
{
	rents.emplace_back(Utils::generateId<Rent>(rents), userId, vehicleId, startDate, timeHours, timeDays);
}

std::vector<std::reference_wrapper<const Rent>> RentalService::getRentsByUserId(const uint64_t id) const
{
	std::vector<std::reference_wrapper<const Rent>> result;

	for (const auto& rent : rents)
	{
		if (id == rent.getUserId())
		{
			result.push_back(std::reference_wrapper(rent));
		}
	}

	return result;
}
