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


namespace cloudrain{
namespace gui {

    class Connection : public QDialog
    {
        Q_OBJECT

        private :
        protected:
        public :
            explicit Connection(QWidget *parent = nullptr);
            void  cascadingStyleSheets();
            virtual ~Connection() noexcept;
    };

}
}

#endif // CONNECTION_H
