#include "User.hpp"

User::User(uint64_t id, std::string username, std::string passwordHash, Role role) :
	id{ id },
	username{ username },
	passwordHash{ passwordHash },
	role{ role }
{}
