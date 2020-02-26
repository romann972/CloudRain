#include "windowanimation.h"

enum ANIMATION_NAME {
    _WINDOW_GO_DOWN_ = 0,
    _WINDOW_GO_UP_ = 1,
    _WINDOW_GO_FROM_CENTER_TO_LEFT_ = 2,
    _WINDOW_GO_FROM_CENTER_TO_RIGHT_ = 3,
};

WindowAnimation::WindowAnimation(QObject *parent) : QObject(parent)
{
    this->posX = 0;
    this->posY = 0;

    this->animationList << "windowGoDown" << "windowGoUp"
                        << "windowGoFromCenterToLeft" << "windowGoFromCenterToRight";
}

void WindowAnimation::runWindowAnimation(const QString &animationName, QWidget *widget)
{
    int animationNumber = 0;
    for(int i = 0; i < this->animationList.size(); i++)
    {
        if(this->animationList[i] == animationName)
        {
            animationNumber = i;

        }
    }
    switch(animationNumber)
    {
        case ANIMATION_NAME::_WINDOW_GO_DOWN_ :
            this->windowGoDown(widget); break;

        case ANIMATION_NAME::_WINDOW_GO_UP_ :
            this->windowGoUp(widget); break;

        case ANIMATION_NAME::_WINDOW_GO_FROM_CENTER_TO_LEFT_ :
            this->windowGoFromCenterToLeft(widget); break;

        case ANIMATION_NAME::_WINDOW_GO_FROM_CENTER_TO_RIGHT_ :
            this->windowGoFromCenterToRight(widget); break;

        default: break;
    }
}

void WindowAnimation::windowGoDown(QWidget *widget)
{
    QDesktopWidget *windowSize = QApplication::desktop();

    this->posX = (windowSize->width()/2) - (widget->width()/2);
    this->posY = -widget->height();
    int centerHeight = (windowSize->height()/2) - (widget->height()/2);

    QTimer *timer = new QTimer(this);

    QObject::connect(timer, &QTimer::timeout, [this, timer, widget, centerHeight]()->void {
        this->posY = this->posY + 20;

        if(this->posY <= centerHeight)
        {
            widget->move(posX, posY);
        } else {
            timer->stop();
            timer->deleteLater();
            emit finishedAnimation("windowGoDown");
        }
    });

    timer->start(10);
}

void WindowAnimation::windowGoUp(QWidget *widget)
{
    QDesktopWidget *windowSize = QApplication::desktop();

    this->posX = (windowSize->width()/2) - (widget->width()/2);
    this->posY = (windowSize->height()/2) - (widget->height()/2);
    int finalHeight = -widget->height();

    QTimer *timer = new QTimer(this);

    QObject::connect(timer, &QTimer::timeout, [this, timer, widget, finalHeight]()->void {
        this->posY = this->posY - 20;

        if(this->posY >= finalHeight)
        {
            widget->move(posX, posY);
        } else {
            timer->stop();
            timer->deleteLater();
            emit finishedAnimation("windowGoUp");
        }
    });

    timer->start(10);
}
void WindowAnimation::windowGoFromCenterToLeft(QWidget *widget)
{
    QDesktopWidget *windowSize = QApplication::desktop();

    this->posX = (windowSize->width()/2) - (widget->width()/2);
    this->posY = (windowSize->height()/2) - (widget->height()/2);
    int centerWidth = -widget->width();

    QTimer *timer = new QTimer(this);

    QObject::connect(timer, &QTimer::timeout, [this, timer, widget, centerWidth]()->void {
        this->posX = this->posX - 20;
        if(this->posX >= centerWidth)
        {
            widget->move(posX, posY);
        } else {
            timer->stop();
            timer->deleteLater();
            emit finishedAnimation("windowGoFromCenterToLeft");
        }
   });

   timer->start(10);
}
void WindowAnimation::windowGoFromCenterToRight(QWidget *widget)
{
    QDesktopWidget *windowSize = QApplication::desktop();

    this->posX = (windowSize->width()/2) - (widget->width()/2);
    this->posY = (windowSize->height()/2) - (widget->height()/2);
    int centerWidth = windowSize->width() + widget->width();

    QTimer *timer = new QTimer(this);

    QObject::connect(timer, &QTimer::timeout, [this, timer, widget, centerWidth]()->void {
        this->posX = this->posX + 20;

        if(this->posX <= centerWidth)
        {
            widget->move(posX, posY);
        } else {
            timer->stop();
            timer->deleteLater();
            emit finishedAnimation("windowGoFromCenterToRight");
        }
    });

    timer->start(10);
}

WindowAnimation::~WindowAnimation() noexcept
{

}
