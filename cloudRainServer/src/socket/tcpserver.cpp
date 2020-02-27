#include "tcpserver.h"

#define PORT 50605
#define IP "127.0.0.1"

cloudrain::socket::TcpServer::TcpServer(QObject *parent)
    : QObject(parent)
{
    this->serverSocket = new QTcpServer(this);
    this->clientSocket = new QTcpSocket(this);
    QObject::connect(serverSocket,&QTcpServer::newConnection,this,&TcpServer::connected);
}
void cloudrain::socket::TcpServer::connectServer()
{
    if(serverSocket->listen(QHostAddress::Any,PORT))
    {
        s.status = "Listen";
    } else {
        s.status = "Error";
    }
}
void cloudrain::socket::TcpServer::shutdownServer()
{
    this->clientSocket->close();
    this->serverSocket->close();
    s.status = "Offline";
}
void cloudrain::socket::TcpServer::writeData(QString data)
{
    if(this->clientSocket->isReadable())
    {
        this->clientSocket->write(data.toUtf8());
        this->clientSocket->flush();
    }
}
QString cloudrain::socket::TcpServer::getServerStatus()
{
    return s.status;
}
cloudrain::socket::TcpServer::~TcpServer() noexcept
{

}
// slot
void cloudrain::socket::TcpServer::connected()
{
    clientSocket = serverSocket->nextPendingConnection();
    QObject::connect(clientSocket,&QTcpSocket::readyRead,this,&TcpServer::readData);
}
void cloudrain::socket::TcpServer::readData()
{
    QString line;
    line = clientSocket->readAll();
    qDebug()<< line;
}
