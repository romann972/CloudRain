#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QStringList>
#include <QHostAddress>

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace cloudrain {
namespace socket {

    class TcpServer : public QObject
    {
        Q_OBJECT

        private :
            struct serverStatus {
                QStringList statusList {
                                         "Offline",
                                         "Faillure"
                                         "Online"
                                         "Error"
                                       };
                QString status = "Offline";
            }s;


        private :
            QTcpServer *serverSocket;
            QTcpSocket *clientSocket;

        public :
            explicit TcpServer(QObject *parent = nullptr);
            void connectServer();
            void shutdownServer();
            QString getServerStatus();
            void writeData(QString data);
            ~TcpServer() noexcept;

        private slots :
            void connected();
            void readData();
    };

}
}
#endif // TCPSERVER_H
