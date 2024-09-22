#ifndef MESSAGEDATAMODEL_H
#define MESSAGEDATAMODEL_H

#include <QAbstractItemModel>
#include <QObject>

class MessageDataModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    MessageDataModel(QObject *parent = nullptr);
};

#endif // MESSAGEDATAMODEL_H
