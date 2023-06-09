#pragma once

#include <fstream>
#include <string>

class Logger
{
public:
	Logger();

	void write(const std::string&);

private:
	std::fstream outputFile;

	static const std::string LogFilename;
};
