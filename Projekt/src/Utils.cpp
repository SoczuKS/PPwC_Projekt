#include "Utils.hpp"

#include <sstream>

namespace utils
{
	std::vector<std::string> splitString(const std::string& str, char delimeter)
	{
		std::stringstream sstr{str};
		std::vector<std::string> substrings;
		std::string substring;

		while (sstr.good())
		{
			std::getline(sstr, substring, delimeter);
			substrings.push_back(substring);
		}

		return substrings;
	}
}