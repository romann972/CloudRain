#ifndef VDWINDOWANIMATION_H
#define VDWINDOWANIMATION_H
#include <QApplication>
#include <QWidget>
#include <QTimer>
#include <QDesktopWidget>
#include <QStyle>
#include <QStringList>

#ifdef QT_DEBUG
#include <QDebug>
#endif

#ifdef QT_NO_DEBUG
#endif



class WindowAnimation : public QObject
{
    Q_OBJECT

    private :
        QStringList animationList;
        int posY, posX;

    public :
        explicit WindowAnimation(QObject *parent = nullptr);
        void runWindowAnimation(const QString &animationName, QWidget *widget);
        int getAnimationNumber(const QString &animationName);
        void windowGoDown(QWidget *widget);
        void windowGoUp(QWidget *widget);
        void windowGoFromCenterToLeft(QWidget *widget);
        void windowGoFromCenterToRight(QWidget *widget);
        ~WindowAnimation() noexcept;

    signals:
        void finishedAnimation(QString);
};


#endif // VDWINDOWANIMATION_H
