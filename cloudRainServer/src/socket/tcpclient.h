#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QTcpSocket>

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace cloudrain {
namespace socket {

    class TcpClient : public QObject
    {
        private :
        public :
            explicit TcpClient  (QObject *parent = nullptr);
            ~TcpClient () noexcept;
    };

}
}
#endif // TCPCLIENT_H
