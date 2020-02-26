#ifndef CONNECTION_H
#define CONNECTION_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>
#include <QPainter>

#ifdef QT_DEBUG
#include <QDebug>
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

        protected:
        public :
            explicit Connection(QWidget *parent = nullptr);
            void initLabel();
            void initButton();
            void initLineEdit();
            virtual void paintEvent(QPaintEvent *) override;
            virtual void keyPressEvent(QKeyEvent *event) override;
            void cascadingStyleSheets();
            virtual ~Connection() noexcept override;
    };

}
}

#endif // CONNECTION_H
