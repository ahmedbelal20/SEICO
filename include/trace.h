#pragma once

#include <QTableView>
#include <QStandardItemModel>

class Trace : public QTableView
{
    Q_OBJECT
public:
    explicit Trace(QWidget *parent = nullptr);
    QStandardItemModel *model;

signals:

public slots:
    void addEntry(QList<QStandardItem *> rowItems);
};


