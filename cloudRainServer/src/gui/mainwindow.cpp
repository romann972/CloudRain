#include "mainwindow.h"

cloudrain::gui::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // UI WINDOWS //
    setFixedSize(800,450);
    setWindowIcon(QIcon("path"));

//    QMenuBar *mainMenu = new QMenuBar(this);
//    QMenu *fileMenu = new QMenu(mainMenu);
//    QMenu *editMenu = new QMenu(mainMenu);
//    QMenu *optionsMenu = new QMenu(mainMenu);
//    QMenu *langageMenu = new QMenu(mainMenu);
//    QMenu *aideMenu = new QMenu(mainMenu);



}

cloudrain::gui::MainWindow::~MainWindow() noexcept
{

}
