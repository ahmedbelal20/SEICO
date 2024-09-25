#ifndef MESSAGEDATAMODEL_H
#define MESSAGEDATAMODEL_H

#include <QAbstractItemModel>
#include <QObject>

namespace DataModel {

    enum class CanMessageColumns {
        Col_Time = 0, Col_Chn, Col_Id, Col_Name, Col_Event, Col_Dir, Col_Dlc, Col_Data, Col_Database, CAN_MESSAGE_COLUMNS_COUNT
    };

    class MessageDataModel : public QAbstractItemModel
    {

        Q_OBJECT

    private:
        int m_dataRowCount = 0;
        const static int m_dataColumnCount = 9;

    public:
        explicit MessageDataModel(const QStringList &headers, QObject *parent = nullptr); // Not implemented
        ~MessageDataModel(); // Not implemented

        inline int rowCount(const QModelIndex &parent = QModelIndex()) const override {return m_dataRowCount;}
        inline int columnCount(const QModelIndex &parent = QModelIndex()) const override{return m_dataColumnCount;}
    };
}

#endif // MESSAGEDATAMODEL_H
