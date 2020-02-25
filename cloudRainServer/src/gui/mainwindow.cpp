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

//    QMenuBar *mainMenu = new QMenuBar(this);
//    QMenu *fileMenu = new QMenu(mainMenu);
//    QMenu *editMenu = new QMenu(mainMenu);
//    QMenu *optionsMenu = new QMenu(mainMenu);
//    QMenu *langageMenu = new QMenu(mainMenu);
//    QMenu *aideMenu = new QMenu(mainMenu);

    // CONNEXION  WIDGETS //
    QLineEdit *usernameEdit = new QLineEdit(this);
    QLineEdit *idEdit = new QLineEdit(this);
    QLineEdit *ipEdit = new QLineEdit(this);
    QPushButton *optionsButton = new QPushButton("Options", this);
    QLabel *idLabel = new QLabel("ID : ", this );
    QLabel *ipLabel = new QLabel("Adresse IP : ", this);
    QLabel *usernameLabel = new QLabel("Username : ", this);
    QLabel *connectionTitle = new QLabel("Connexion", this);
    //*********************************

    // CONNEXION WIDGETS UI //
    usernameEdit->setGeometry(50, 350, 150 , 40);
    idEdit->setGeometry(50, 350, 150 , 40);
    ipEdit->setGeometry(50, 350, 150 , 40);
    optionsButton->setGeometry(50, 350, 150 , 40);
    idLabel->setGeometry(50, 350, 150 , 40);
    ipLabel->setGeometry(50, 350, 150 , 40);
    usernameLabel->setGeometry(50, 350, 150 , 40);
    connectionTitle->setGeometry(50, 350, 150 , 40);
    //*********************************

    //  ACCUEIL WIDGETS UI //
    QLabel *analyseTitleLabel = new QLabel("Logs Analyse", this);
    QPushButton *logsServerButton = new QPushButton("Logs Server", this);
    QPushButton *logsWebSiteButton = new QPushButton("Logs WebSite", this);
    QPushButton *logsAccessButton = new QPushButton("Logs Access", this);
    QPushButton *clearButton = new QPushButton("Clear", this);
    //*********************************

    // ACCUEIL WIDGETS UI //
    analyseTitleLabel->setGeometry(50, 350, 150 , 40);
    logsServerButton->setGeometry(50, 350, 150 , 40);
    logsWebSiteButton->setGeometry(50, 350, 150 , 40);
    logsAccessButton->setGeometry(50, 350, 150 , 40);
    clearButton->setGeometry(50, 350, 150 , 40);
    //*********************************

    // CONNEXION IMPLEMENTED WIDGETS //
    QObject::connect(optionsButton, &QPushButton::clicked, []()->void {
        qDebug()<<"fff";
    });
    //*********************************

    // ACCUEIL IMPLEMENTED WIDGETS //
    QObject::connect(optionsButton, &QPushButton::clicked, []()->void {
        qDebug()<<"fff";
    });
    //*********************************


}

cloudrain::gui::MainWindow::~MainWindow() noexcept
{

}
