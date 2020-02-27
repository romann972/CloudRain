#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QObject>

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace cloudraindaemon {
namespace socket {

    class TcpServer : public QObject
    {
        private :
        public :
            explicit TcpServer(QObject *parent = nullptr);
            ~TcpServer() noexcept;
    };

}
}
#endif // SERVERSOCKET_H
