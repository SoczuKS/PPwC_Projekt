#include "RentalService.hpp"

#include <fstream>

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
		auto substrings = utils::splitString(line, ';');

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
