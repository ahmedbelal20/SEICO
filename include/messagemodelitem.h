#ifndef MESSAGEMODELITEM_H
#define MESSAGEMODELITEM_H

#include<QVector>

#include "message.h"

namespace DataModel {

    class MessageModelItem
    {

    private:
        QVector<MessageModelItem*> m_childItems;
        MessageModelItem *m_parentItem;
        Message::CanMessage m_message;
        char m_columnCount;

    public:
        explicit MessageModelItem(const Message::CanMessage& message, MessageModelItem* parentItem);
        // Other constructors can be added in the future for other types of messages (e.g. CAN FD, Ethernet, etc.)
        ~ MessageModelItem();

        void appendChild(MessageModelItem *child);
        QVariant getData(int column) const;
        MessageModelItem* getChild(int childNumber) const;
        MessageModelItem* getParent() const;
        int getChildCount() const;
        int getColumnCount() const;
        int getChildNumber() const;
    };
};

#endif // MESSAGEMODELITEM_H
