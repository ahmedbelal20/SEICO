#include <iostream>

#include "Log.h"
    

namespace Log {

    void LogMessage(const char* message)
    {
        std::cout << message << std::endl;
    }

}
