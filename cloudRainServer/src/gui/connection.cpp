#include "connection.h"

cloudrain::gui::Connection::Connection(QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(800,450);
    this->setWindowTitle(QObject::tr(""));
    this->setWindowIcon(QIcon("Icon en attente YaYa94"));

    // CONNEXION  WIDGETS //
    QLineEdit *usernameEdit = new QLineEdit(this);
    QLineEdit *idEdit = new QLineEdit(this);
    QLineEdit *ipEdit = new QLineEdit(this);
    QPushButton *optionsButton = new QPushButton(QObject::tr("Options"), this);
    QLabel *idLabel = new QLabel(QObject::tr("Identifiant de l'utilisateur : "), this );
    QLabel *ipLabel = new QLabel(QObject::tr("Adresse IP : "), this);
    QLabel *usernameLabel = new QLabel(QObject::tr("Identifiant : "), this);
    QLabel *connectionTitle = new QLabel(QObject::tr("Connexion"), this);

    // WIDGETS UI //

    idEdit->setGeometry(350, 150, 150 , 25);
    ipEdit->setGeometry(350, 200, 150 , 25);
    usernameEdit->setGeometry(350, 250, 150 , 25);
    idLabel->setGeometry(200, 150, 150 , 25);
    ipLabel->setGeometry(250, 200, 150 , 25);
    usernameLabel->setGeometry(250, 250, 150 , 25);
    connectionTitle->setGeometry(400, 50, 50 , 40);
    optionsButton->setGeometry(50, 50, 150 , 40);

    idLabel->setAlignment(Qt::AlignRight);
    ipLabel->setAlignment(Qt::AlignRight);
    usernameLabel->setAlignment(Qt::AlignRight);


    // IMPLEMENTED WIDGETS //
    QObject::connect(optionsButton, &QPushButton::clicked, []()->void {

    });

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

cloudrain::gui::Connection::~Connection() noexcept
{

}
