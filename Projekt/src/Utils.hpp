#pragma once

#include <cstdint>
#include <random>
#include <string>
#include <vector>

class Utils
{
public:
	static std::vector<std::string> splitString(const std::string&, char);

	template<class T>
	static uint64_t generateId(const std::vector<T>&);

private:
	static std::random_device randomDevice;
	static std::mt19937 mersenneTwisterEngine;
	static std::uniform_int_distribution<uint64_t> distribution;
};

template <class T>
uint64_t Utils::generateId(const std::vector<T>& data)
{
	bool isFree;
	uint64_t id{ 0 };
	do
	{
		id = distribution(mersenneTwisterEngine);

		isFree = data.end() == std::ranges::find_if(data, [&id](const auto& el) {
			return id == el.getId();
		});
	} while (not isFree);

	return id;
}
