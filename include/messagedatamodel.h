#ifndef MESSAGEDATAMODEL_H
#define MESSAGEDATAMODEL_H

#include <QAbstractItemModel>
#include <QObject>

class MessageDataModel : public QAbstractItemModel
{

    Q_OBJECT

public:
    enum ModelColumn {
        Col_Time = 0, Col_Chn, Col_Id, Col_Name, Col_Event, Col_Dir, Col_Dlc, Col_Data, Col_Database
    };

private:
    int m_dataRowCount = 0;
    const static int m_dataColumnCount = 9;

public:
    explicit MessageDataModel(QObject *parent = nullptr);
    inline int rowCount(const QModelIndex &parent = QModelIndex()) const override {return m_dataRowCount;}
    inline int columnCount(const QModelIndex &parent = QModelIndex()) const override{return m_dataColumnCount;}
};

#endif // MESSAGEDATAMODEL_H
