#pragma once

#include <QTreeView>
#include <QStandardItemModel>
#include <QStringList>

#include "message.h"


class Trace : public QTreeView
{

    Q_OBJECT

private:

    QStandardItemModel *m_singleMessageModel, *m_duplicateMessageModel;
    static const int m_columnCount = 9;

public:
    explicit Trace(QWidget *parent = nullptr);
    void testFunction();
    void displayNewMessage(Message::Message& message);
    inline void displayAllColumns();
    inline void updateTraceColumns(bool *isColumnHidden);

private:
    inline void initTrace();
    inline void initModels();
    inline void assignDuplicateMessageModel();
    inline void assignSingleMessageModel();

signals:

};
