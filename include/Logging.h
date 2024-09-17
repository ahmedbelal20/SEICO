#pragma once

namespace Logging {

    class Logger
    {

    public:

        Logger();

        void LogInfo(const char* message);
        void LogWarning(const char* message);
        void LogError(const char* message);

    };
}
