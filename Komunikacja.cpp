//
// Komunikacja plytki z  Qt
//
#include <iostream>
#include <QCoreApplication>
#include <QDebug>
#include <QSerialPort>
#include <Windows.h>
using namespace std;
QSerialPort serial;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    serial.setPortName("COM21");
    serial.open(QIODevice::ReadWrite);
       serial.setBaudRate(QSerialPort::Baud115200);
       serial.setDataBits(QSerialPort::Data8);
       serial.setParity(QSerialPort::NoParity);
       serial.setStopBits(QSerialPort::OneStop);
       serial.setFlowControl(QSerialPort::NoFlowControl);
    while(!serial.isOpen()) serial.open(QIODevice::ReadWrite);
     
    if (serial.isOpen() && serial.isWritable())
       {
       qDebug() << "Serial port is open";

       QByteArray output;
       QByteArray input;

    while(true)
         {
// Po wysłaniu litery a powinniśmy  dostać odpowiedż w postaci stringu
         output = "a";
         serial.write(output);
        serial.flush();

         serial.waitForBytesWritten(1000);
         serial.waitForReadyRead(1000);

         input = serial.readAll();
         qDebug()<<input;

         }
       }
    return a.exec();
}

