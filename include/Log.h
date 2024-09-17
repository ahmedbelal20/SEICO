#pragma once

class Logging {

public:
    enum LogLevel
    {
        LEVEL_ERROR = 1, LEVEL_WARNING, LEVEL_DEBUG
    };

    Logging();

    void LogMessage(const char* message);
};