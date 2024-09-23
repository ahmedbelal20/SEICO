#ifndef MESSAGEMODELITEM_H
#define MESSAGEMODELITEM_H

#include <QList>

#include "message.h"


class MessageModelItem
{

private:
    QList<MessageModelItem*> m_childItems;
    MessageModelItem *m_parentItem;
    Message::CanMessage m_message;

public:
    explicit MessageModelItem(const Message::CanMessage& message, MessageModelItem* parentItem);
    ~ MessageModelItem() {}
    QVariant data(int column) const;


};

#endif // MESSAGEMODELITEM_H
