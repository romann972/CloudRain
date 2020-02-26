#ifndef MENU_H
#define MENU_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include "global.h"
#include "connection.h"


namespace cloudrain{
namespace gui {

    class Menu : public QDialog
    {
        Q_OBJECT

        private :

        protected:
        public :
            explicit Menu(QWidget *parent = nullptr);
            void initPushButton();
            void  cascadingStyleSheets();
            virtual ~Menu() noexcept;

        signals:
            void hideMainWindow(bool);
    };

}
}


#endif // MENU_H
