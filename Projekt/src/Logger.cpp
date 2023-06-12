#include "Logger.hpp"

#include <chrono>
#include <format>

const std::string Logger::LogFilename = "log.txt";

Logger::Logger() : outputFile{ std::fstream(LogFilename, std::ios::out | std::ios::app) } {}

void Logger::write(const std::string& logText)
{
	const auto time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());

	const auto formattedTime = std::format("{:%Y-%m-%d %X}", time);

	outputFile << '[' << formattedTime << ']' << ' ' << logText << '\n';
}
