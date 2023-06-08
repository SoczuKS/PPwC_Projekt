#include "UserManager.hpp"

#include <fstream>
#include <ranges>

#include <QCryptographicHash>

#include "User.hpp"
#include "Utils.hpp"

const std::string UserManager::UsersFilename = "data/passwd.txt";

UserManager::UserManager(std::shared_ptr<Logger> logger) : logger{ logger }
{
	load();
}

UserManager::~UserManager()
{
	save();
}

void UserManager::removeUser(uint64_t id)
{
	std::erase_if(users, [id](const auto& user)
	{
		return id == user.getId();
	});
}

std::optional<std::reference_wrapper<User>> UserManager::login(const std::string& username, const std::string& plainPassword)
{
	if (const auto it = std::ranges::find_if(users, [this, &username, &plainPassword](const auto& user)
	{
		return username == user.getUsername() and hashPassword(plainPassword) == user.getPasswordHash();
	}); it != users.end())
	{
		return *it;
	}

	return std::nullopt;
}

std::optional<std::reference_wrapper<User>> UserManager::registration(const std::string& username, const std::string& plainPassword)
{
	if (users.end() != std::ranges::find_if(users, [&username](const auto& user)
	{
		return username == user.getUsername();
	}))
	{
		return std::nullopt;
	}

	users.emplace_back(User(Utils::generateId<User>(users), username, hashPassword(plainPassword), User::Role::customer));

	return users.at(users.size() - 1);
}

std::string UserManager::hashPassword(const std::string& plainPassword) const
{
	const auto qtHash = QCryptographicHash::hash(plainPassword, QCryptographicHash::Sha256);

	return std::string{qtHash.toHex()};
}

void UserManager::load()
{
	std::fstream file(UsersFilename, std::ios::in);
	std::string line;

	while (std::getline(file, line))
	{
		auto substrings = Utils::splitString(line, ',');

		if (4 != substrings.size())
		{
			throw std::exception("Invalid save");
		}

		users.emplace_back(User{ std::stoull(substrings[0]), substrings[1], substrings[2], static_cast<User::Role>(std::stoi(substrings[3])) });
	}
}

void UserManager::save() const
{
	std::fstream file(UsersFilename, std::ios::out);

	for (const auto& user : users)
	{
		file << user << '\n';
	}
}
