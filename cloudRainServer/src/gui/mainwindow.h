#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QStackedWidget>
#include <QCloseEvent>

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include "connection.h"
#include "menu.h"
#include "options.h"
#include "windowanimation.h"
#include "../db/management.h"

namespace cloudrain{
namespace gui {

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

        private :
            enum class centralWidget {
                _MENU_ = 0,
                _OPTIONS_ = 1,
                _CONNECTION_ = 2,

            };

            enum class toolWidget {

            };

        private :
            QStackedWidget *widgetStack;
            Menu *menu;
            Options *options;

        private :
            WindowAnimation *windowAnimation;
            bool finishedCloseEvent = false;

        protected:
        public :
            explicit MainWindow(QWidget *parent = nullptr);
            virtual void closeEvent (QCloseEvent *event) override;
            virtual ~MainWindow() noexcept override;
    };

}
}

#endif // MAINWINDOW_H
