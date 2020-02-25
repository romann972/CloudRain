#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include "connection.h"

namespace cloudrain{
namespace gui {

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

        private :
        protected:
        public :
            explicit MainWindow(QWidget *parent = nullptr); // no explicit values plz
            virtual ~MainWindow() noexcept;
    };

}
}

#endif // MAINWINDOW_H
