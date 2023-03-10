#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QDataStream>
#include <QDebug>

class Server : public QTcpServer
{
  Q_OBJECT

public:
    Server();
    QTcpSocket *socket;

private:

    QVector <QTcpSocket*> Sockets;
    QByteArray Data;

    void SendToClient(QString str);

    quint16 nextBlockSize;

private slots:

    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();

};

#endif // SERVER_H
