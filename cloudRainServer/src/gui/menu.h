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


namespace cloudrain{
namespace gui {

    class Menu : public QDialog
    {
        Q_OBJECT

        private :
        protected:
        public :
            explicit Menu(QWidget *parent = nullptr);
            void  cascadingStyleSheets();
            virtual ~Menu() noexcept;
    };

}
}


#endif // MENU_H
