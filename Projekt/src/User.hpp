#pragma once

#include <cstdint>
#include <fstream>
#include <string>

class User final
{
public:
	enum class Role : uint16_t
	{
		customer = 1,
		admin = 100
	};

	User(uint64_t, std::string, std::string, Role);

	uint64_t getId() const { return id; }

	std::string getUsername() const { return username; }

	std::string getPasswordHash() const { return passwordHash; }

	Role getRole() const { return role; }

	friend std::fstream& operator<<(std::fstream& file, const User& user)
	{
		file << user.id << ',' << user.username << ',' << user.passwordHash << ',' << static_cast<uint16_t>(user.role);
		return file;
	}

private:
	uint64_t id;
	std::string username;
	std::string passwordHash;
	Role role;
};
