#pragma once

#include <cstdint>
#include <optional>
#include <random>
#include <string>
#include <vector>

class User;

class UserManager final
{
public:
	UserManager();
	~UserManager();

	std::optional<std::reference_wrapper<User>> registration(std::string, std::string);
	std::optional<std::reference_wrapper<User>> login(std::string, std::string);

private:
	std::string hashPassword(const std::string&) const;
	uint64_t generateUserId();
	bool load();
	bool save() const;

	std::vector<User> users;
	std::random_device randomDevice;
	std::mt19937 mersenneTwisterEngine;
	std::uniform_int_distribution<uint64_t> distribution;

	static const std::string UsersFilename;
};
