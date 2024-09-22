#include "trace.h"

#include "logging.h"
#include "message.h"


Trace::Trace(QWidget *parent)
    : QTableView(parent)
{
    initTrace();
    initModels();
}

void::Trace::initTrace()
{
    // Set trace to read-only
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSortingEnabled(true);
}

void::Trace::initModels()
{
    // Initialize the grid models for the trace
    duplicateMessageInstanceModel = new QStandardItemModel(0, columnCount, this);
    singleMessageInstanceModel = new QStandardItemModel(0, columnCount, this);
    // Initialize models headers
    duplicateMessageInstanceModel->setHorizontalHeaderLabels({"Time", "Chn", "ID", "Name", "Event", "Dir", "DLC", "Data"});
    singleMessageInstanceModel->setHorizontalHeaderLabels({"Time", "Chn", "ID", "Name", "Event", "Dir", "DLC", "Data"});
    // Unhide all columns
    displayAllColumns();
    // Assign a model to the trace
    setModel(duplicateMessageInstanceModel);
}

void Trace::displayNewMessage (Message::Message& message)
{

}

void Trace::testFunction()
{
    Logging::Logger::logInfo("Entered test function!");
    Message::CanMessage message;
    message.time = 2.0f;
    displayNewMessage(message);
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
