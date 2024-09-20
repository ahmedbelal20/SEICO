#include "trace.h"

#include <QStandardItemModel>
#include <QPalette>
#include <QStandardItem>

#include "logging.h"

Trace::Trace(QWidget *parent)
    : QTableView(parent)
{
    // Set trace to read-only
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Initialize the grid model for the trace
    // Initialize table headers
    model->setHorizontalHeaderLabels({"Time", "Chn", "ID", "Name", "Event", "Dir", "DLC", "Data"});
    // Assign the model to the trace
    setModel(model);
}


void Trace::insertRow()
{
    model->insertRow(1);
    setModel(model);
    Logging::Logger::LogInfo("Click detected!");

}
