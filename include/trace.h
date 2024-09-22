#pragma once

#include <QTableView>
#include <QStandardItemModel>
#include <QStringList>

#include "message.h"


class Trace : public QTableView
{

    Q_OBJECT

public:
    enum TraceColumn {
        Col_Time = 0, Col_Chn, Col_Id, Col_Name, Col_Event, Col_Dir, Col_Dlc, Col_Data
    };

private:

    QStandardItemModel *singleMessageInstanceModel, *duplicateMessageInstanceModel;
    static const int columnCount = 8;

public:
    explicit Trace(QWidget *parent = nullptr);
    void testFunction();
    void displayNewMessage(Message::Message& message);
    void inline displayAllColumns();
    void inline updateTraceColumns(bool *isColumnHidden);

private:
    void inline initTrace();
    void inline initModels();


signals:

};
