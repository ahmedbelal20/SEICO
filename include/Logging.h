#pragma once

namespace Logging {

    class Logger
    {

    private:
        Logger() = delete;

    public:
        static void logInfo(const char* message);
        static void logWarning(const char* message);
        static void logError(const char* message);

    };
}
