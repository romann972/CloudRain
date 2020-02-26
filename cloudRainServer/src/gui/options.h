#ifndef OPTIONS_H
#define OPTIONS_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include <QToolBar>

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include "global.h"


namespace cloudrain{
namespace gui {

    class Options : public QDialog
    {
        Q_OBJECT

        private :
        protected:
        public :
            explicit Options(QWidget *parent = nullptr);
            void  cascadingStyleSheets();
            virtual ~Options() noexcept;
    };

}
}


#endif // OPTIONS_H
