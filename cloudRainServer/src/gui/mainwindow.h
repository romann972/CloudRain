#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include <QDebug>



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

        // use the functors if you can (with lambda preferably)
        private slots :
        protected slots :
        public slots :
    };
}
}

#endif // MAINWINDOW_H
