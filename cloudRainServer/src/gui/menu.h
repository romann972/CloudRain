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
#include "../socket/tcpserver.h"


namespace cloudrain{
namespace gui {

    class Menu : public QDialog
    {
        Q_OBJECT

        private :
            QLabel *statusView;
            cloudrain::socket::TcpServer *tcpServer;
            QPushButton *serverStartStop;

        protected:
        public :
            explicit Menu(cloudrain::socket::TcpServer *tcpServer, QWidget *parent = nullptr);
            void initPushButton();
            void initLabel();
            QString startStopStatus();
            void  cascadingStyleSheets();
            virtual ~Menu() noexcept;

        signals:
            void hideMainWindow(bool);
    };

}
}


#endif // MENU_H
