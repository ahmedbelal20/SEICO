#include "trace.h"

#include "logging.h"
#include "message.h"


Trace::Trace(QWidget *parent)
    : QTreeView(parent)
{
    initTrace();
    initModels();
    assignDuplicateMessageModel();
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
    m_duplicateMessageModel = new QStandardItemModel(0, m_columnCount, this);
    m_singleMessageModel = new QStandardItemModel(0, m_columnCount, this);
    // Initialize models headers
    m_duplicateMessageModel->setHorizontalHeaderLabels({"Time", "Chn", "ID", "Name", "Event", "Dir", "DLC", "Data", "Database"});
    m_singleMessageModel->setHorizontalHeaderLabels({"Time", "Chn", "ID", "Name", "Event", "Dir", "DLC", "Data", "Database"});
    // Unhide all columns
    displayAllColumns();
}

void Trace::assignDuplicateMessageModel()
{
    setSortingEnabled(false);
    setModel(m_duplicateMessageModel);
}

void Trace::assignSingleMessageModel()
{
    setSortingEnabled(true);
    setModel(m_singleMessageModel);
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
    for (int column = 0; column < m_columnCount; column++)
    {
        setColumnHidden(column, false);
    }
}

void Trace::updateTraceColumns(bool *isColumnHidden)
{
    for (int column = 0; column < m_columnCount; column++)
    {
        setColumnHidden(column, isColumnHidden[column]);
    }
}
