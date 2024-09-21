#pragma once

namespace Logging {

    class Logger
    {

    private:
        Logger() = delete;

    public:
        static void LogInfo(const char* message);
        static void LogWarning(const char* message);
        static void LogError(const char* message);

    };
}
