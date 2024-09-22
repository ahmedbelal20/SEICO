#ifndef CANMESSAGE_H
#define CANMESSAGE_H

#include <string>

namespace Message {

    enum class Direction : bool {
        Dir_Rx = false, Dir_Tx = true
    };

    enum class Channel : char {
        Chn_A = 0, Chn_B = 1, Chn_C = 2, Chn_D = 3
    };

    enum class Protocol : char {
        CAN = 0, CANFD = 1, Ethernet = 2
    };


    struct Message
    {
    public:

        Message() {}

    public:

        Protocol protocol;
        Direction direction;
        Channel channel;
        float time;
        // Database attributes
        std::string database;
        std::string name;
    };


    struct CanMessage : public Message
    {

    public:

        CanMessage() {}

    public:

        char dlc;
        bool isRtr, isExtended, isValid;
        char data[8];
        int id;

    };

};

#endif // CANMESSAGE_H
