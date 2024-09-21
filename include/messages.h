#ifndef CANMESSAGE_H
#define CANMESSAGE_H

#include <string>

namespace Messages {

    enum class Direction : bool {
        Dir_Rx = false, Dir_Tx = true
    };

    enum class Channel : char {
        Chn_A = 1, Chn_B, Chn_C, Chn_D
    };

    struct CanMessage
    {

    public:
        CanMessage();

    public:

        float time;
        int id;
        std::string name = NULL;
        Direction direction;
        Channel channel;
        char dlc;
        bool isRtr, isExtended, isValid;
        char data[8];

    };

};

#endif // CANMESSAGE_H
