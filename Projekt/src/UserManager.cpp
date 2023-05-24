#include "UserManager.hpp"

#include <algorithm>
#include <fstream>
#include <functional>
#include <numbers>
#include <sstream>

#include <QCryptographicHash>

#include "User.hpp"
#include "Utils.hpp"

const std::string UserManager::UsersFilename = "passwd.txt";

UserManager::UserManager() :
	randomDevice{ std::random_device() },
	mersenneTwisterEngine{ randomDevice() },
	distribution{ std::uniform_int_distribution<uint64_t>(0.0, std::numeric_limits<uint64_t>::max()) }
{
	load();
}

UserManager::~UserManager()
{
	save();
}

std::optional<std::reference_wrapper<User>> UserManager::login(std::string username, std::string plainPassword)
{
	const auto it = std::find_if(users.begin(), users.end(), [this, &username, &plainPassword](const auto& user) {
		return username == user.getUsername() and hashPassword(plainPassword) == user.getPasswordHash();
	});

	if (it == users.end())
	{
		return std::nullopt;
	}

	return *it;
}

std::optional<std::reference_wrapper<User>> UserManager::registration(std::string username, std::string plainPassword)
{
	if (users.end() != std::find_if(users.begin(), users.end(), [&username](const auto& user) {
		return username == user.getUsername();
	}))
	{
		return std::nullopt;
	}

	users.emplace_back(User(generateUserId(), username, hashPassword(plainPassword), User::Role::customer));

	return users.at(users.size() - 1);
}

std::string UserManager::hashPassword(const std::string& plainPassword) const
{
	auto qtHash = QCryptographicHash::hash(plainPassword, QCryptographicHash::Sha256);

	return std::string{qtHash.toHex()};
}

uint64_t UserManager::generateUserId()
{
	bool isFree{ false };
	uint64_t id{ 0 };
	do
	{
		id = distribution(mersenneTwisterEngine);

		isFree = users.end() == std::find_if(users.begin(), users.end(), [&id](const auto& user) {
			return id == user.getId();
		});
	} while (not isFree);

	return id;
}

bool UserManager::load()
{
	try
	{
		std::fstream file(UsersFilename, std::ios::in);
		std::string line;

		while (std::getline(file, line))
		{
			const auto substrings = utils::splitString(line, ',');

			if (substrings.size() != 4)
			{
				throw std::exception("Invalid save");
			}

			users.emplace_back(User{ std::stoull(substrings[0]), substrings[1], substrings[2], static_cast<User::Role>(std::stoi(substrings[3])) });
		}
	}
	catch (std::exception&)
	{
		return false;
	}

	return true;
}

bool UserManager::save() const
{
	std::fstream file(UsersFilename, std::ios::out);

	for (const auto& user : users)
	{
		file << user << '\n';
	}

	return true;
}
