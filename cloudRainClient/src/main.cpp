#include <QCoreApplication>
#include "socket/tcpclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    cloudraindaemon::socket::TcpCLient *client = new cloudraindaemon::socket::TcpCLient(qApp);
    client->start();
    return 0;
}
