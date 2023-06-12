#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

class Logger;
class User;

class UserManager final
{
public:
	UserManager(const std::shared_ptr<Logger>&) noexcept(false);
	~UserManager();

	std::optional<std::reference_wrapper<User>> registration(const std::string&, const std::string&);
	std::optional<std::reference_wrapper<User>> login(const std::string&, const std::string&);
	void removeUser(uint64_t id);

private:
	void load() noexcept(false);
	void save() const;

	std::string hashPassword(const std::string&) const;

	std::vector<User> users;
	std::shared_ptr<Logger> logger;

	static const std::string UsersFilename;
};
