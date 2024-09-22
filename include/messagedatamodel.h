#ifndef MESSAGEDATAMODEL_H
#define MESSAGEDATAMODEL_H

#include <QAbstractTableModel>
#include <QObject>

class MessageDataModel : public QAbstractTableModel
{

    Q_OBJECT

private:
    int dataRowCount = 0;
    const static int dataColumnCount = 8;

public:
    explicit MessageDataModel(QObject *parent = nullptr);
    inline int rowCount(const QModelIndex &parent = QModelIndex()) const override {return dataRowCount;}
    inline int columnCount(const QModelIndex &parent = QModelIndex()) const override{return dataColumnCount;}

};

#endif // MESSAGEDATAMODEL_H
