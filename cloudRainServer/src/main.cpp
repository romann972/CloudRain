#include <QApplication>
#include <QTranslator>
#include <QLocale>

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include "gui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator translator;
    translator.load(QStringLiteral("cloudrain_") + QLocale::system().name());
    qDebug()<<QStringLiteral("cloudrain_") + QLocale::system().name();
    app.installTranslator(&translator);
    cloudrain::gui::MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}



