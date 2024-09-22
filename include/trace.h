#pragma once

#include <QTableView>
#include <QStandardItemModel>
#include <QStringList>

#include "message.h"

class Trace : public QTableView
{

    Q_OBJECT

private:
    QStandardItemModel *singleMessageInstanceModel, *duplicateMessageInstanceModel;
    static const int columnCount = 8;
    bool isColumnHidden[columnCount];

public:
    explicit Trace(QWidget *parent = nullptr);
    void testFunction();
    void displayNewMessage(Message::Message message);
    void inline updateHiddenColumns();
    void inline displayAllColumns();

private:
    void inline initModels();

signals:

};
