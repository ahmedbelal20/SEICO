#ifndef TRACEITEM_H
#define TRACEITEM_H

#include "message.h"

class TraceItem
{
public:
    explicit TraceItem(const Message::Message& message, TraceItem* parentItem);

};

#endif // TRACEITEM_H
