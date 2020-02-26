#include <QApplication>
#include <QTranslator>

#include "gui/mainwindow.h"
#include "gui/connection.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    cloudrain::gui::Connection connection;
    connection.exec();
    cloudrain::gui::MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
