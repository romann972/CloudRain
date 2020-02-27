#include "connection.h"

#define STAR_SIZE_MAX 10.0
#define STAR_NUMBER 50
#define STAR_SPEED_NORMAL 0.01
#define STAR_SPEED_PLUS 0.05


cloudrain::gui::Connection::Connection(QWidget *parent)
    : QDialog(parent)
{
    using namespace cloudrain::gui;

    this->setFixedSize(800,450);
    this->setWindowTitle(QObject::tr("Connect to a client"));
    this->setWindowIcon(QIcon(""));

    QLabel *backGroup = new QLabel(this);
    backGroup->setGeometry(175, 100, 425, 200);
    backGroup->setStyleSheet("background-color:beige; border-radius:7%;");

    this->initLabel();
    this->initButton();
    this->initLineEdit();

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_PaintOnScreen);

    this->windowAnimation = new WindowAnimation(this);
    this->windowAnimation->runWindowAnimation(QStringLiteral("windowGoDown"), this);
    this->generateStar();

    this->timer = new QTimer(this);

    this->timer->start(1);
    QObject::connect(timer, &QTimer::timeout, [this]()->void {
        this->update();
    });
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

void cloudrain::gui::Connection::generateStar(void)
{
    for(int i = 0; i<STAR_NUMBER; i++)
    {
        double size = QRandomGenerator::global()->bounded(STAR_SIZE_MAX);
        int x = QRandomGenerator::global()->bounded(0, this->width());
        int y = QRandomGenerator::global()->bounded(0, this->height());
        this->starContainer.push_back(qMakePair(QPointF(x, y),QSizeF(size, size)));
    }
}

void cloudrain::gui::Connection::initLabel()
{
    QLabel *idLabel = new QLabel(QObject::tr("Token : "), this );
    QLabel *ipLabel = new QLabel(QObject::tr("IP Address : "), this);
    QLabel *tokenLabel = new QLabel(QObject::tr("User ID : "), this);
    QLabel *connectionTitle = new QLabel(QObject::tr("<h1>Connect to a client</h1>"), this);

    idLabel->setGeometry(225, 150, 80 , 25);
    ipLabel->setGeometry(225, 200, 80 , 25);
    tokenLabel->setGeometry(225, 250, 80 , 25);
    connectionTitle->setGeometry(300, 100, 200 , 40);
    connectionTitle->setStyleSheet("font-family:Brush Script MT, Brush Script Std;");

    idLabel->setAlignment(Qt::AlignCenter | Qt::AlignRight);
    ipLabel->setAlignment(Qt::AlignCenter | Qt::AlignRight);
    tokenLabel->setAlignment(Qt::AlignCenter | Qt::AlignRight);
}

void cloudrain::gui::Connection::initButton()
{
     QPushButton *connectionButton = new QPushButton(QObject::tr("Connection"), this);
     connectionButton->setIcon(QIcon(cloudrain::gui::global::icon::TICK_512));
     connectionButton->setGeometry(225, 350, 150 , 40);

     QObject::connect(connectionButton, &QPushButton::clicked, []()->void {
        qDebug()<<"optButton";
     });

     QPushButton *cancelButton = new QPushButton(QObject::tr("Cancel"), this);
     cancelButton->setIcon(QIcon(cloudrain::gui::global::icon::CANCEL_512));
     cancelButton->setGeometry(400, 350, 150 , 40);

     QObject::connect(cancelButton, &QPushButton::clicked, [this]()->void {
        this->connectionDestroyed();
     });
}


void cloudrain::gui::Connection::initLineEdit()
{
    QLineEdit *tokenEdit = new QLineEdit(this);
    QLineEdit *idEdit = new QLineEdit(this);
    QLineEdit *ipEdit = new QLineEdit(this);

    idEdit->setGeometry(400, 150, 150, 25);
    ipEdit->setGeometry(400, 200, 150, 25);
    tokenEdit->setGeometry(400, 250, 150, 25);
}

void cloudrain::gui::Connection::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
       this->connectionDestroyed();
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
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, this->width(), this->height());

    auto drawPointLambda = [&painter](const double &x, const double &y, const double &w, const double &h)->void {
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(Qt::white));
        painter.drawEllipse(QRectF(x, y, w ,h));
    };
    for(auto &i: this->starContainer)
    {
        double speed = STAR_SPEED_NORMAL;
        if(i.second.width() > 8.0)
        {
            speed = STAR_SPEED_PLUS;
        }
        if(i.first.x() > this->width()/2 && i.first.y() >this->height()/2)
        {
            i.first.setX(i.first.x() + speed);
            i.first.setY(i.first.y() + speed);
        } else if (i.first.x() < this->width()/2 && i.first.y() < this->height()/2) {
            i.first.setX(i.first.x() - speed);
            i.first.setY(i.first.y() - speed);
        } else if(i.first.x() > this->width()/2 && i.first.y() < this->height()/2) {
            i.first.setX(i.first.x() + speed);
            i.first.setY(i.first.y() - speed);
        } else if (i.first.x() < this->width()/2 && i.first.y() > this->height()/2) {
            i.first.setX(i.first.x() - speed);
            i.first.setY(i.first.y() + speed);
        }
            i.second.setWidth(i.second.width() + speed);
            i.second.setHeight(i.second.height() + speed);
        if(i.second.width() > STAR_SIZE_MAX)
        {
            i.second.setWidth(0.0);
            i.second.setHeight(0.0);
            int x = QRandomGenerator::global()->bounded(0, this->width());
            int y = QRandomGenerator::global()->bounded(0, this->height());
            i.first.setX(x);
            i.first.setY(y);
         }
         drawPointLambda(i.first.x(), i.first.y(), i.second.width(), i.second.height());
    }
}

cloudrain::gui::Connection::~Connection() noexcept
{

}
