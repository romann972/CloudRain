#include "Menu.h"

cloudrain::gui::Menu::Menu(QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(800,450);
    this->setWindowTitle(QObject::tr("Menu"));
    this->setWindowIcon(QIcon(""));

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
    this->initPushButton();
    this->cascadingStyleSheets();
}

void cloudrain::gui::Menu::initPushButton()
{
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
        this->hide();
        Connection connection;
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
