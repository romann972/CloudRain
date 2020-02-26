#include "connection.h"

cloudrain::gui::Connection::Connection(QWidget *parent)
    : QDialog(parent)
{
    using namespace cloudrain::gui;

    this->setFixedSize(800,450);
    this->setWindowTitle(QObject::tr(""));
    this->setWindowIcon(QIcon(global::icon::HELP_512));

    this->initLabel();
    this->initButton();
    this->initLineEdit();

   // this->cascadingStyleSheets();
}

/*void cloudrain::gui::Connection::cascadingStyleSheets()
{
    this->setStyleSheet("QPushButton::hover {"
                                "background: transparent;"
                                "image: url("+ global::icon::FLAG_FR_512 +");"
                                "border-radius:5px;"
                                "border: 2px dotted;"
                            "}"
                            "QLabel::hover {"
                                "image: url("+ global::icon::INFO_512 +");"
                                "color: transparent;"
                            "}"
                            "QIcon::hover {"
                                "background: transparent;"
                                "image: url(C:/Users/yyakoubi/Downloads/flag_united-kingdom_512.png);"
                            "}"
                            );
}*/

void cloudrain::gui::Connection::initLabel()
{
    QLabel *idLabel = new QLabel(QObject::tr("Token : "), this );
    QLabel *ipLabel = new QLabel(QObject::tr("IP Address : "), this);
    QLabel *tokenLabel = new QLabel(QObject::tr("User ID : "), this);
    QLabel *connectionTitle = new QLabel(QObject::tr("Connection"), this);

    idLabel->setGeometry(265, 150, 80 , 25);
    ipLabel->setGeometry(265, 200, 80 , 25);
    tokenLabel->setGeometry(265, 250, 80 , 25);
    connectionTitle->setGeometry(400, 50, 60 , 40);

    idLabel->setAlignment(Qt::AlignCenter | Qt::AlignRight);
    ipLabel->setAlignment(Qt::AlignCenter | Qt::AlignRight);
    tokenLabel->setAlignment(Qt::AlignCenter | Qt::AlignRight);
}

void cloudrain::gui::Connection::initButton()
{
     QPushButton *connectionButton = new QPushButton(QObject::tr("Connection"), this);

     connectionButton->setGeometry(275, 350, 150 , 40);

     QObject::connect(connectionButton, &QPushButton::clicked, []()->void {
        qDebug()<<"optButton";
     });

     QPushButton *cancelButton = new QPushButton(QObject::tr("Cancel"), this);

     cancelButton->setGeometry(425, 350, 150 , 40);
     cancelButton->setIcon(QIcon(global::icon::FLAG_FR_512));

     QObject::connect(cancelButton, &QPushButton::clicked, []()->void {
        qDebug()<<"optButton";
     });

     QPushButton *frButton = new QPushButton(QObject::tr(""), this);
     frButton->setGeometry(300, 300, 50 , 50);
     frButton->setIcon(QIcon(global::icon::FLAG_FR_512));
     frButton->setIconSize(QSize(50, 50));
     frButton->setStyleSheet("background: transparent;"
                             "QPushButton::hover {"
                             "background: blue;"
                                "image: url("+ global::icon::INFO_512 +");"
                             "}");
     QPushButton *enButton = new QPushButton(QObject::tr(""), this);
     enButton->setGeometry(375, 300, 50 , 50);
     enButton->setIcon(QIcon(global::icon::FLAG_UK_512));
     QPushButton *ptButton = new QPushButton(QObject::tr(""), this);
     ptButton->setGeometry(450, 300, 50 , 50);
     ptButton->setIcon(QIcon(global::icon::FLAG_FR_512));
     QPushButton *dzButton = new QPushButton(QObject::tr(""), this);
     dzButton->setGeometry(525, 300, 50 , 50);
     dzButton->setIcon(QIcon(global::icon::FLAG_FR_512));








}


void cloudrain::gui::Connection::initLineEdit()
{
    QLineEdit *tokenEdit = new QLineEdit(this);
    QLineEdit *idEdit = new QLineEdit(this);
    QLineEdit *ipEdit = new QLineEdit(this);

    idEdit->setGeometry(350, 150, 150 , 25);
    ipEdit->setGeometry(350, 200, 150 , 25);
    tokenEdit->setGeometry(350, 250, 150 , 25);
}

cloudrain::gui::Connection::~Connection() noexcept
{

}
