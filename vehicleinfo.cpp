#include "vehicleinfo.h"

vehicleInfo::vehicleInfo(QQmlContext* context, QObject *parent) : QObject(parent)
{
    connectToServer();
    ctx = context;
//    ctx->setContextProperty("vehicleInfo",this);
}

void vehicleInfo::connectToServer()
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "connecting...";

    // this is not blocking call
    socket->connectToHost("localhost", 8080);

    // we need to wait...
    if(!socket->waitForConnected(5000))
    {
        qDebug() << "Error: " << socket->errorString();
    }
}

void vehicleInfo::connected()
{
    qDebug() << "connected to server!";
}

void vehicleInfo::readyRead()
{
    qDebug() << "ready to read data from server..";
    QByteArray byteArray = socket->read(100);
    QString strData = QString(byteArray);
    qDebug() << "Data from server: "<<strData;

    if(strData.contains("speed",Qt::CaseInsensitive))
    {
        int index =strData.indexOf("speed:",Qt::CaseInsensitive);
        QString tmp = strData.mid(index);
        QString speed =  tmp.mid(0,tmp.indexOf('\n'));
        qDebug() << "speed:"<< speed;
        emit speedUpdate(speed);
    }
    if(strData.contains("acceleration",Qt::CaseInsensitive))
    {
        int index =strData.indexOf("acceleration:",Qt::CaseInsensitive);
        QString tmp = strData.mid(index);
        QString acceleration =  tmp.mid(0,tmp.indexOf('\n'));
        qDebug() <<"acceleration:"<< acceleration;
        emit accelerationUpdate(acceleration);
    }
    if(strData.contains("distance",Qt::CaseInsensitive))
    {
        int index =strData.indexOf("distance:",Qt::CaseInsensitive);
        QString tmp = strData.mid(index);
        QString distance =  tmp.mid(0,tmp.indexOf('\n'));
        qDebug() <<"Distance:"<< distance;
        emit distanceUpdate(distance);
    }
    if(strData.contains("steering angle",Qt::CaseInsensitive))
    {
        int index =strData.indexOf("steering angle:",Qt::CaseInsensitive);
        QString tmp = strData.mid(index);
        QString steering_angle =  tmp.mid(0,tmp.indexOf('\n'));
        qDebug() <<"steering angle:"<< steering_angle;
        emit steeringAngleUpdate(steering_angle);
    }
    else
    {
        qDebug() << "wrong data";
    }

}

void vehicleInfo::disconnected()
{
    qDebug() << "server disconnected..";
}
