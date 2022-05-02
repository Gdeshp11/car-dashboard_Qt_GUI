#ifndef VEHICLEINFO_H
#define VEHICLEINFO_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDataStream>
#include <QtNetwork>
#include <QQmlContext>

class vehicleInfo : public QObject
{
    Q_OBJECT
public:
    explicit vehicleInfo(QQmlContext* ctx, QObject *parent = nullptr);

    void connectToServer();

signals:
    void speedUpdate(QString speed);
    void accelerationUpdate(QString accl);
    void distanceUpdate(QString distance);
    void steeringAngleUpdate(QString steering_angle);

public slots:
    void connected();
    void disconnected();
    void readyRead();

private:
    QTcpSocket *socket;
    QQmlContext* ctx;
};

#endif // VEHICLEINFO_H
