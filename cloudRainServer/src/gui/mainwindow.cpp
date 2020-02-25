#include "mainwindow.h"


/*
QLabel(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
QPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr)
QLineEdit(const QString &contents, QWidget *parent = nullptr)
QCheckBox(const QString &text, QWidget *parent = nullptr)
*/

cloudrain::gui::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // UI WINDOWS //
    setFixedSize(800,450);
    setWindowIcon(QIcon("Icon en attente YaYa94"));

    // CONNEXION  WIDGETS //
    QLineEdit *usernameEdit = new QLineEdit(this);
    QLineEdit *idEdit = new QLineEdit(this);
    QLineEdit *ipEdit = new QLineEdit(this);
    QPushButton *optionsButton = new QPushButton("Options", this);
    QLabel *idLabel = new QLabel("ID : ", this );
    QLabel *ipLabel = new QLabel("Adresse IP : ", this);
    QLabel *usernameLabel = new QLabel("Username : ", this);
    QLabel *connectionTitle = new QLabel("Connexion", this);

    // WIDGETS UI //
    usernameEdit->setGeometry(50, 350, 150 , 40);
    idEdit->setGeometry(50, 350, 150 , 40);
    ipEdit->setGeometry(50, 350, 150 , 40);
    optionsButton->setGeometry(50, 350, 150 , 40);
    idLabel->setGeometry(50, 350, 150 , 40);
    ipLabel->setGeometry(50, 350, 150 , 40);
    usernameLabel->setGeometry(50, 350, 150 , 40);
    connectionTitle->setGeometry(50, 350, 150 , 40);

    // IMPLEMENTED WIDGETS //
    QObject::connect(optionsButton, &QPushButton::clicked, []()->void {
        qDebug()<<"fff";
    });



}

cloudrain::gui::MainWindow::~MainWindow() noexcept
{

}
