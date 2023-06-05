#include "Utils.hpp"

#include <sstream>

std::random_device Utils::randomDevice{};
std::mt19937 Utils::mersenneTwisterEngine{randomDevice()};
std::uniform_int_distribution<uint64_t> Utils::distribution{std::uniform_int_distribution<uint64_t>(0.0, std::numeric_limits<uint64_t>::max())};

std::vector<std::string> Utils::splitString(const std::string& str, const char delimiter)
{
	std::stringstream sstr{str};
	std::vector<std::string> substrings;
	std::string substring;

	while (sstr.good())
	{
		std::getline(sstr, substring, delimiter);
		substrings.push_back(substring);
	}

	return substrings;
}
