#include "mainwindow.h"
#include "ui_SEICO.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setStyleSheet("background-color: dark;");
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::on_click);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_click()
{
    ui->trace->testFunction();
}
