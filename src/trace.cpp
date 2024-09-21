#include "trace.h"

#include <QStandardItemModel>
#include <QStandardItem>

#include "logging.h"

Trace::Trace(QWidget *parent)
    : QTableView(parent)
{
    // Set trace to read-only
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Initialize the grid model for the trace
    model = new QStandardItemModel(0, 6, this);
    // Initialize table headers
    model->setHorizontalHeaderLabels({"Time", "Chn", "ID", "Name", "Event", "Dir", "DLC", "Data"});
    // Assign the model to the trace
    setModel(model);
}

void Trace::addEntry(QList<QStandardItem *> rowItems)
{
    model->appendRow(rowItems);
    Logging::Logger::LogInfo("Click detected!");
}
