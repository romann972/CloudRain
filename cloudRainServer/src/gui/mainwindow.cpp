#include "mainwindow.h"

cloudrain::gui::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Affichage de l'image dans le fond
    QLabel *label = new QLabel(this);
    QPixmap pixmap("C:/cloudrain.jpg");
    label->setPixmap(pixmap);
    label->resize(pixmap.size());

    // UI WINDOWS //
    setFixedSize(800,450);
    setWindowIcon(QIcon("path"));

    this->widgetStack = new QStackedWidget(this);
    this->menu = new Menu(this);
    this->options = new Options(this);
    this->connection = new Connection(this);

    this->widgetStack->addWidget(menu);
    this->widgetStack->addWidget(options);
    this->widgetStack->addWidget(connection);
    this->widgetStack->setCurrentIndex(0);

    this->setCentralWidget(this->widgetStack);

    QToolBar *toolBar = new QToolBar(this);
        QAction *openImage = new QAction("Open");
        QAction *editBar = new QAction("Edit");
        QAction *optionsBar = new QAction("Options");
        QAction *languageBar = new QAction("Language");
        QAction *helpBar = new QAction("Help");

        toolBar->addAction(openImage);
        toolBar->addAction(editBar);
        toolBar->addAction(optionsBar);
        toolBar->addAction(languageBar);
        toolBar->addAction(helpBar);
}

cloudrain::gui::MainWindow::~MainWindow() noexcept
{

}
