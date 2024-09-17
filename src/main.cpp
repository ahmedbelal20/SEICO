#include <iostream>

#include "Log.h"

int main()
{
	Logging log;
	log.LogMessage("Hello World!");
	std::cin.get();
}