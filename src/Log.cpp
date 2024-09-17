#include <iostream>

#include "Log.h"
    
class Logging {

    Logging() {}

private:
    LogLevel LogLevel = LEVEL_ERROR;


    void inline LogMessage(const char* message)
    {
    std::cout << message << std::endl;
    }
}


