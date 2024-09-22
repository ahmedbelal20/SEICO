#include "trace.h"

#include <QStandardItemModel>
#include <QStandardItem>

#include "logging.h"

Trace::Trace(QWidget *parent)
    : QTableView(parent)
{
    // Set trace to read-only
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    initModels();

}

void::Trace::initModels()
{
    // Initialize the grid models for the trace
    duplicateMessageInstanceModel = new QStandardItemModel(0, 8, this);
    singleMessageInstanceModel = new QStandardItemModel(0, 8, this);
    // Initialize models headers
    duplicateMessageInstanceModel->setHorizontalHeaderLabels({"Time", "Chn", "ID", "Name", "Event", "Dir", "DLC", "Data"});
    singleMessageInstanceModel->setHorizontalHeaderLabels({"Time", "Chn", "ID", "Name", "Event", "Dir", "DLC", "Data"});
    // Unhide all columns
    displayAllColumns();
    // Assign a model to the trace
    setModel(duplicateMessageInstanceModel);
}

void Trace::displayNewMessage (Message::Message message)
{
    //QList<QStandardItem *> rowItems;
    //Trace::addEntry(rowItems);
}

void Trace::testFunction()
{
    Logging::Logger::logInfo("Entered test function!");
}

void Trace::displayAllColumns()
{
    for (int column = 0; column <columnCount; column++)
    {
        setColumnHidden(column, false);
    }
}

void Trace::updateTraceColumns(bool *isColumnHidden)
{
    for (int column = 0; column <columnCount; column++)
    {
        setColumnHidden(column, isColumnHidden[column]);
    }
}
