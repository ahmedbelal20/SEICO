#pragma once

#include <QTableView>
#include <QStandardItemModel>

class Trace : public QTableView
{
    Q_OBJECT
public:
    explicit Trace(QWidget *parent = nullptr);
    void insertRow();
    QStandardItemModel *model = new QStandardItemModel(0, 6, this);

signals:

};


