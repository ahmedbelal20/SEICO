#include <iostream>

#include "Logging.h"

int main()
{
	Logging::Logger logger;
	logger.LogError("This is an error!");
	logger.LogWarning("This is a warning!");
	logger.LogInfo("This is a message!");
	std::cin.get();
}