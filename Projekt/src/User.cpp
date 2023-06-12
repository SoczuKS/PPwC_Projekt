#include "User.hpp"

User::User(const uint64_t id, const std::string& username, const std::string& passwordHash, const Role role) :
	id{ id },
	username{ username },
	passwordHash{ passwordHash },
	role{ role }
{
}
