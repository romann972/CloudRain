#include <QApplication>
#include "gui/mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    cloudrain::gui::MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
