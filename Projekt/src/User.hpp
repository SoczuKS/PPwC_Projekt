#pragma once

#include <cstdint>
#include <string>

class User final
{
public:
	enum class Role
	{
		admin,
		customer
	};

	User() = default;

private:
	std::string username;
	std::string password;
	uint64_t id;
	Role role;

};
