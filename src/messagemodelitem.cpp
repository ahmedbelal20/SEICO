#include <QVariant>

#include "messagemodelitem.h"
#include "messagedatamodel.h"


MessageModelItem::MessageModelItem(const Message::CanMessage& message, MessageModelItem* parentItem = nullptr)
    : m_message(message)
{

}

QVariant MessageModelItem::data(int column) const
{
    switch(column)
    {
        case MessageDataModel::Col_Id:
            return QVariant(m_message.id);
        case MessageDataModel::Col_Chn:
            return QVariant(static_cast<int>(m_message.channel));
        case MessageDataModel::Col_Data:
        {
            QString hexString;
            for (int i = 0; i < m_message.dlc; ++i) {
                hexString += QString("%1 ").arg((m_message.data[i]), 2, 16, QChar('0')).toUpper();
            }
            return hexString.trimmed();
        }
        case MessageDataModel::Col_Dir:
            return QVariant(static_cast<int>(m_message.direction));
        case MessageDataModel::Col_Dlc:
            return QVariant(m_message.dlc);
        case MessageDataModel::Col_Event:
            return QString("CAN Frame");
        case MessageDataModel::Col_Time:
            return QVariant(m_message.time);
        case MessageDataModel::Col_Database:
            return QString::fromStdString(m_message.database);
        case MessageDataModel::Col_Name:
            return QString::fromStdString(m_message.name);
    }
}
