#include "connection.h"

cloudrain::gui::Connection::Connection(QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(800,450);
    this->setWindowTitle(QObject::tr(""));
    this->setWindowIcon(QIcon("Icon en attente YaYa94"));

    this->initLabel();
    this->initButton();
    this->initLineEdit();

    this->cascadingStyleSheets();
}

void cloudrain::gui::Connection::cascadingStyleSheets()
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

void cloudrain::gui::Connection::initLabel()
{
    QLabel *idLabel = new QLabel(QObject::tr("Identifiant de l'utilisateur : "), this );
    QLabel *ipLabel = new QLabel(QObject::tr("Adresse IP : "), this);
    QLabel *tokenLabel = new QLabel(QObject::tr("Identifiant : "), this);
    QLabel *connectionTitle = new QLabel(QObject::tr("Connexion"), this);

    idLabel->setGeometry(200, 150, 150 , 25);
    ipLabel->setGeometry(250, 200, 150 , 25);
    tokenLabel->setGeometry(250, 250, 150 , 25);
    connectionTitle->setGeometry(400, 50, 50 , 40);

    idLabel->setAlignment(Qt::AlignRight);
    ipLabel->setAlignment(Qt::AlignRight);
    tokenLabel->setAlignment(Qt::AlignRight);
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

     QObject::connect(cancelButton, &QPushButton::clicked, []()->void {
        qDebug()<<"optButton";
     });
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
