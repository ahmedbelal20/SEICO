#include "mainwindow.h"
#include "ui_SEICO.h"

#include "logging.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: black;");
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::on_click);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_click()
{
    Logging::Logger::LogInfo("Button clicked!");
}
