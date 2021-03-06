#ifndef SPHEREBOT_H
#define SPHEREBOT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QtGui>
#include <iostream>
#include <QtCore/QCoreApplication>

class spherebot : public QObject
{
    Q_OBJECT
public:
    QSerialPort *port;

    bool isConnected();
    bool send(QString cmd);
    bool repeatLastLine();
    QString generateChecksumString(QString msg);
    explicit spherebot(QObject *parent = 0);
signals:
    void dataSent(QString data);
public slots:
    bool connectWithBot(QString portName);
    bool connectWithBot();
    bool disconnectWithBot();
private:
    bool port_connected;
    QString lastSentLine;
};

#endif // SPHEREBOT_H
