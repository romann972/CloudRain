#include "tcpclient.h"
#define IP "127.0.0.1"

#define PORT 50605

cloudraindaemon::socket::TcpCLient::TcpCLient(QObject *parent)
    : QObject(parent)
{
    this->soc = new QTcpSocket(this);
    QObject::connect(this->soc, &QTcpSocket::connected, this, &TcpCLient::connectedSlot);
    QObject::connect(this->soc, &QTcpSocket::readyRead, this, &TcpCLient::readDataSlot);
    QObject::connect(this->soc, &QTcpSocket::disconnected, this, &TcpCLient::deconnection);
}
void cloudraindaemon::socket::TcpCLient::start()
{
    do
    {
        this->soc->connectToHost(IP,PORT);
        if(!soc->waitForConnected(100))
        {
               qDebug() << IP << ":" << PORT << " Error: " << soc->errorString();
        } else{
        qDebug() << IP << ":" << PORT << " connected ";
        }
    }while((soc->state()==QAbstractSocket::ConnectedState) == false);
}
cloudraindaemon::socket::TcpCLient::~TcpCLient() noexcept
{

}

// private slots :
void cloudraindaemon::socket::TcpCLient::connectedSlot()
{
    if(this->soc->isWritable())
    {
        QString ipPort = this->soc->localAddress().toString()+":"+QString::number(this->soc->localPort());
        this->soc->write("Connection request "+ ipPort.toUtf8());
        this->soc->flush();
    } else {
        this->start();
    }
}
void cloudraindaemon::socket::TcpCLient::writeData(const QString data)
{
    this->soc->write("bonjour");
}
void cloudraindaemon::socket::TcpCLient::readDataSlot()
{
    if(this->soc->isReadable())
    {
        QString line;
        line = soc->readAll();
        if(line.contains("start:"))
        {
            qDebug()<<line;
        }
     } else {
            this->start();
     }
}
void cloudraindaemon::socket::TcpCLient::deconnection()
{
    qDebug()<<"deco";
    this->start();
}


struct lenom {

};
