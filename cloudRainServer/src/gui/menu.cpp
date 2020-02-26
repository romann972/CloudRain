#include "Menu.h"

cloudrain::gui::Menu::Menu(QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(800,450);
    this->setWindowTitle(QObject::tr(""));
    this->setWindowIcon(QIcon("Icon en attente YaYa94"));

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

    this->cascadingStyleSheets();

}

void cloudrain::gui::Menu::cascadingStyleSheets()
{
    this->setStyleSheet("QPushButton::hover {"
                            "background: transparent;"
                            "border-radius:20px;"
                            "border: 2px dotted;"
                        "}"
                        "QLabel::hover {"
                            "background-color: black;"
                        "}"
                        );
}

cloudrain::gui::Menu::~Menu() noexcept
{

}
