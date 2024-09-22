#include <iostream>

#include "logging.h"

/*
Defines the configuration for the logging system. Options are:
LOG_LEVEL_DISABLED
LOG_LEVEL_ERROR
LOG_LEVEL_WARNING
LOG_LEVEL_INFO
*/ 
#define LOG_LEVEL_INFO

#ifdef LOG_LEVEL_WARNING
    #define LOG_LEVEL_ERROR
#endif

#ifdef LOG_LEVEL_INFO
    #define LOG_LEVEL_WARNING
    #define LOG_LEVEL_ERROR
#endif

#ifdef LOG_LEVEL_DISABLED
    #undef LOG_LEVEL_ERROR
    #undef LOG_LEVEL_WARNING
    #undef LOG_LEVEL_INFO
#endif


void Logging::Logger::logInfo(const char* message)
{
    #ifdef LOG_LEVEL_INFO
        std::cout << "[INFO]: " << message << std::endl;
    #endif
}

void Logging::Logger::logWarning(const char* message)
{
    #ifdef LOG_LEVEL_WARNING
        std::cout << "[WARNING]: " << message << std::endl;
    #endif
}

void Logging::Logger::logError(const char* message)
{
    #ifdef LOG_LEVEL_ERROR
        std::cout << "[ERROR]: " << message << std::endl;
    #endif
}
