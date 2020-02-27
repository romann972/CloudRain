#include "Menu.h"

cloudrain::gui::Menu::Menu(cloudrain::socket::TcpServer *TcpServer, QWidget *parent)
    : QDialog(parent), tcpServer(TcpServer)
{
    this->setFixedSize(800,450);
    this->setWindowTitle(QObject::tr("Menu"));
    this->setWindowIcon(QIcon(""));
    /*
    QLabel *analyseTitleLabel = new QLabel("Logs Analyse", this);
    QPushButton *logsServerButton = new QPushButton("Logs Server", this);
    QPushButton *logsWebSiteButton = new QPushButton("Logs WebSite", this);
    QPushButton *logsAccessButton = new QPushButton("Logs Access", this);
    QPushButton *clearButton = new QPushButton("Clear", this);

    analyseTitleLabel->setGeometry(400, 50, 150 , 40);
    logsServerButton->setGeometry(50, 50, 150 , 40);
    logsWebSiteButton->setGeometry(50, 100, 150 , 40);
    logsAccessButton->setGeometry(50, 150, 150 , 40);
    clearButton->setGeometry(150, 200, 150 , 40);

    QObject::connect(logsServerButton, &QPushButton::clicked, []()->void {
        qDebug()<<"fff";
    });

    analyseTitleLabel->setAlignment(Qt::AlignRight);

    QObject::connect(logsServerButton, &QPushButton::clicked, []()->void {

    });

    QObject::connect(logsWebSiteButton, &QPushButton::clicked, []()->void {

    });

    QObject::connect(logsAccessButton, &QPushButton::clicked, []()->void {

    });

    QObject::connect(clearButton, &QPushButton::clicked, []()->void {

    });
    */

    this->initPushButton();
    this->initLabel();
    this->cascadingStyleSheets();
}

void cloudrain::gui::Menu::initLabel()
{
    QLabel *statusTitle = new QLabel("<strong>Server status</strong>", this);
    this->statusView = new QLabel("<em style=\"color:red;\">\""+ this->tcpServer->getServerStatus() +"\"</em>", this);

    statusTitle->setGeometry(500, 0, 50 ,50);
    this->statusView->setGeometry(550, 0,60 , 50);
}
QString cloudrain::gui::Menu::startStopStatus()
{
    if(this->tcpServer->getServerStatus() == "Listen")
    {
        return "Stop";
    }else {
        return "Start";
    }
}
void cloudrain::gui::Menu::initPushButton()
{
    this->serverStartStop = new QPushButton(this->startStopStatus(), this);
    this->serverStartStop->setGeometry(720, 0, 80, 50);
    QObject::connect(this->serverStartStop, &QPushButton::clicked, [this]()->void {
        if(this->startStopStatus() == "Stop")
        {
            this->tcpServer->shutdownServer();
            this->serverStartStop->setText(this->startStopStatus());
        } else if(this->startStopStatus() == "Start") {
            this->tcpServer->connectServer();
            this->serverStartStop->setText(this->startStopStatus());
        }else {
            this->serverStartStop->setText(this->startStopStatus());
        }
    });
    [this]()->void {
        int x{5}, y{5};
        for(auto &i : {"FR", "PL", "EN", "AR"})
        {
            QPushButton *flagButton = new QPushButton(this);
            if(i == QStringLiteral("FR"))
            {
                flagButton->setIcon(QIcon(cloudrain::gui::global::icon::FLAG_FR));
            }else if(i == QStringLiteral("PL")) {
                flagButton->setIcon(QIcon(cloudrain::gui::global::icon::FLAG_PL));
            }else if(i == QStringLiteral("EN")) {
                flagButton->setIcon(QIcon(cloudrain::gui::global::icon::FLAG_US));
            }else if(i == QStringLiteral("AR")) {
                flagButton->setIcon(QIcon(cloudrain::gui::global::icon::FLAG_AR));
            }

            flagButton->setObjectName(i);
            flagButton->setIconSize(QSize(50, 50));
            flagButton->setGeometry(x, y, 60, 60);
            flagButton->setStyleSheet("QPushButton {"
                                        "border-radius: 30%;"
                                        "border: 2px solid black;"
                                        "outline: none;"
                                      "}"
                                        "QPushButton:focus {"
                                        "border-radius: 30%;"
                                        "border: 2px dashed blue;"
                                      "}"
                                      "QPushButton:hover {"
                                        "border-radius: 30%;"
                                        "border: 2px dashed blue;"
                                      "}");

            x = x + 61;
            QObject::connect(flagButton, &QPushButton::clicked, []()->void{
                qDebug()<<"flag";
            });
        }
    }();

    QPushButton *connectionButton = new QPushButton("New client", this);
    connectionButton->setGeometry(100, 100, 60, 60);
    QObject::connect(connectionButton, &QPushButton::clicked, [this]()->void{
        emit hideMainWindow(true);
        Connection connection;
        QObject::connect(&connection, &Connection::finishedConnection, [this]()->void{
            emit hideMainWindow(false);
        });
        connection.exec();
    });
}

void cloudrain::gui::Menu::cascadingStyleSheets()
{
    this->setStyleSheet("background-color:white;");
}

cloudrain::gui::Menu::~Menu() noexcept
{

}
