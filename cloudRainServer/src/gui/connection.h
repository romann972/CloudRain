#ifndef CONNECTION_H
#define CONNECTION_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include "global.h"


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
            QString state;

        protected:
        public :
            explicit Connection(QWidget *parent = nullptr);
            void initLabel();
            void initButton();
            void initLineEdit();
            void cascadingStyleSheets();
            virtual ~Connection() noexcept;
    };

}
}

#endif // CONNECTION_H
