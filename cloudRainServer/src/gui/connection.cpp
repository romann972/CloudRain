#include "connection.h"

cloudrain::gui::Connection::Connection(QWidget *parent)
    : QDialog(parent)
{
    using namespace cloudrain::gui;

    this->setFixedSize(800,450);
    this->setWindowTitle(QObject::tr("Connect to a client"));
    this->setWindowIcon(QIcon(""));

    this->initLabel();
    this->initButton();
    this->initLineEdit();

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_PaintOnScreen);

    this->windowAnimation = new WindowAnimation(this);
    this->windowAnimation->runWindowAnimation(QStringLiteral("windowGoDown"), this);
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
    //cancelButton->setIcon(QIcon(global::icon::FLAG_FR_512));

     QObject::connect(cancelButton, &QPushButton::clicked, []()->void {
        qDebug()<<"optButton";
     });

     QPushButton *frButton = new QPushButton(QObject::tr(""), this);
     frButton->setGeometry(300, 300, 50 , 50);
     //frButton->setIcon(QIcon(global::icon::FLAG_FR_512));
     frButton->setIconSize(QSize(50, 50));
     frButton->setStyleSheet("background: transparent;"
                             "QPushButton::hover {"
                             "background: blue;"
                                "image: url("+ global::icon::INFO_512 +");"
                             "}");



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

void cloudrain::gui::Connection::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        windowAnimation->runWindowAnimation("windowGoUp", this);
        QObject::connect(windowAnimation, &WindowAnimation::finishedAnimation, [this]()->void {
            emit finishedConnection(true);
            this->close();
        });
    }
}

void cloudrain::gui::Connection::connectionDestroyed()
{
    windowAnimation->runWindowAnimation("windowGoUp", this);
    QObject::connect(windowAnimation, &WindowAnimation::finishedAnimation, [this]()->void {
        emit finishedConnection(true);
        this->close();
    });
}

void cloudrain::gui::Connection::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor color(0, 0, 0);
    color.setAlpha(192);
    painter.setBrush(QBrush(color));
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, this->width(), this->height());
}

cloudrain::gui::Connection::~Connection() noexcept
{

}
