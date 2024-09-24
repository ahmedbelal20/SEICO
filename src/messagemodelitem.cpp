#include <QVariant>

#include "messagemodelitem.h"
#include "messagedatamodel.h"


DataModel::MessageModelItem::MessageModelItem(const Message::CanMessage& message, DataModel::MessageModelItem* parentItem = nullptr)
    : m_message(message), m_parentItem(parentItem)
{
    switch(message.protocol)
    {
        case Message::Protocol::CAN:
            m_columnCount = static_cast<char>(DataModel::CanMessageColumns::CAN_MESSAGE_COLUMNS_COUNT);
            break;
        default:
            break;
    }
}

DataModel::MessageModelItem::~MessageModelItem() {qDeleteAll(m_childItems);}

void DataModel::MessageModelItem::appendChild(MessageModelItem *child) {m_childItems.append(child);}

DataModel::MessageModelItem* DataModel::MessageModelItem::getChild(int childNumber) const
{
    if (childNumber < 0 || childNumber >= m_childItems.size())
        return nullptr;
    return m_childItems.at(childNumber);
}

DataModel::MessageModelItem* DataModel::MessageModelItem::getParent() const {return m_parentItem;}

int DataModel::MessageModelItem::getChildCount() const {return m_childItems.count();}

int DataModel::MessageModelItem::getColumnCount() const {return static_cast<int>(m_columnCount);}

int DataModel::MessageModelItem::getChildNumber() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<DataModel::MessageModelItem*>(this));
    return 0;
}

QVariant DataModel::MessageModelItem::getData(int column) const
{
    switch(m_message.protocol)
    {
        case Message::Protocol::CAN:
        {
            switch(column)
            {
            case static_cast<int>(DataModel::CanMessageColumns::Col_Id):
                return QVariant(m_message.id);
            case static_cast<int>(DataModel::CanMessageColumns::Col_Chn):
                return QVariant(static_cast<int>(m_message.channel));
            case static_cast<int>(DataModel::CanMessageColumns::Col_Data):
            {
                QString hexString;
                for (int i = 0; i < m_message.dlc; ++i) {
                    hexString += QString("%1 ").arg((m_message.data[i]), 2, 16, QChar('0')).toUpper();
                }
                return hexString.trimmed();
            }
            case static_cast<int>(DataModel::CanMessageColumns::Col_Dir):
                return QVariant(static_cast<int>(m_message.direction));
            case static_cast<int>(DataModel::CanMessageColumns::Col_Dlc):
                return QVariant(m_message.dlc);
            case static_cast<int>(DataModel::CanMessageColumns::Col_Event):
                return QString("CAN Frame");
            case static_cast<int>(DataModel::CanMessageColumns::Col_Time):
                return QVariant(m_message.time);
            case static_cast<int>(DataModel::CanMessageColumns::Col_Database):
                return QString::fromStdString(m_message.database);
            case static_cast<int>(DataModel::CanMessageColumns::Col_Name):
                return QString::fromStdString(m_message.name);
            default:
                return QVariant();
            }
        }
        default:
            return QVariant();
    }


}
