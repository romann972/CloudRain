#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace cloudraindaemon {
namespace socket {

    class TcpCLient : public QObject
    {
        Q_OBJECT

        private :
            QTcpSocket *soc;

        public :
            explicit TcpCLient(QObject *parent = nullptr);
            void start();
            void writeData(const QString data);
            ~TcpCLient() noexcept;

        private slots :
            void connectedSlot();
            void readDataSlot();
            void deconnection();
    };

}
}
#endif // TCPCLIENT_H
