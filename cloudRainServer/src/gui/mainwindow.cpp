#include "mainwindow.h"

cloudrain::gui::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // UI WINDOWS //
    this->setFixedSize(800,450);
    this->setWindowIcon(QIcon("path"));

    this->tcpServer = new cloudrain::socket::TcpServer(this);

    this->widgetStack = new QStackedWidget(this);

    this->menu = new Menu(this->tcpServer, this);
    this->options = new Options(this);

    QObject::connect(this->menu, &Menu::hideMainWindow, [this](bool hide)->void {
        if(hide)
        {
            this->hide();
        } else{
            this->show();
        }
    });

    this->widgetStack->addWidget(menu);
    this->widgetStack->addWidget(options);
    this->widgetStack->setCurrentIndex(0);

    this->setCentralWidget(this->widgetStack);


    this->windowAnimation = new WindowAnimation(this);
    this->windowAnimation->runWindowAnimation(QStringLiteral("windowGoDown"), this);
}


void cloudrain::gui::MainWindow::closeEvent (QCloseEvent *event)
{
    if(!finishedCloseEvent)
    {
        event->ignore();
        this->windowAnimation->runWindowAnimation(QStringLiteral("windowGoUp"), this);
        QObject::connect(this->windowAnimation, &WindowAnimation::finishedAnimation, [this]()->void {
            this->finishedCloseEvent = true;
            this->close();
        });
    }
}

cloudrain::gui::MainWindow::~MainWindow() noexcept
{

}
