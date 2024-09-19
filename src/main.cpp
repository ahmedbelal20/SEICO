#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication guiApplication(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return guiApplication.exec();
}
