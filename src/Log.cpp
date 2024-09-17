#include <iostream>

#include "Log.h"
    
class Logging {

public:

    Logging() {}

    void inline LogMessage(const char* message)
    {
    std::cout << message << std::endl;
    }

    Logging::LogLevel logLevel = LEVEL_ERROR;

private:
    
};