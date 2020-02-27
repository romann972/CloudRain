#ifndef CONNECTION_H
#define CONNECTION_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>
#include <QPainter>

#include <QVector>
#include <QPointF>
#include <QTimer>
#include <QRandomGenerator>

#ifdef QT_DEBUG
#include <QDebug>
#endif
#ifdef QT_NO_DEBUG
#endif

#include "global.h"
#include "windowanimation.h"


namespace cloudrain {
namespace gui {

    struct StateType {
        const QStringList stateList {
                                     "empty",
                                     "banned",
                                     "synch",
                                     "succes",
                                     "faillure"
                                     "lost"
                                    };
        QString state = "empty";
    };

    class Connection : public QDialog
    {
        Q_OBJECT

        private :
            StateType state;
            WindowAnimation *windowAnimation;
            QTimer *timer;
            QVector<QPair<QPointF, QSizeF>> starContainer;

        protected:
        public :
            explicit Connection(QWidget *parent = nullptr);
            void initLabel();
            void initButton();
            void initLineEdit();
            void generateStar();
            virtual void paintEvent(QPaintEvent *) override;
            virtual void keyPressEvent(QKeyEvent *event) override;
            void cascadingStyleSheets();
            void connectionDestroyed();
            virtual ~Connection() noexcept override;

        signals :
            void finishedConnection(bool);
    };

}
}

#endif // CONNECTION_H
