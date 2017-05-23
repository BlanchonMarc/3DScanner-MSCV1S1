#include "ttable_thread.h"

using namespace std;
//Constructor
ttable_thread::ttable_thread(dataclass *thedatabase)
{
    Database = thedatabase;
}
//Runing process, setting the arduino settings using the serial connection // usb port selected
//this code run is in fact a translation of a c code to use arduino and to manage turning table
//Setting all the rate of communation, the flags if necessary, the port used, the format of data
void ttable_thread::run()
{

    if(Database->getTtConnect() && !Database->getTtConnected())
    {
        serial.setPortName(Database->getTtSerialPort());
        serial.open(QIODevice::ReadWrite);
        serial.setBaudRate(QSerialPort::Baud4800);
        serial.setDataBits(QSerialPort::Data8);
        serial.setParity(QSerialPort::NoParity);
        serial.setStopBits(QSerialPort::OneStop);
        serial.setFlowControl(QSerialPort::NoFlowControl);
        while(!serial.isOpen()) serial.open(QIODevice::ReadWrite);
        Database->setTtConnected(true);
    }
    else if (Database->getTtConnect() && Database->getTtConnected() && Database->getTtRotate() && serial.isOpen() && serial.isWritable())
   {
        QByteArray dayArray;

        dayArray[0]=1;
        serial.write(dayArray);
        serial.flush();
        timer.start();
        // Sleep(80);
        serial.waitForBytesWritten(100);
    }
    else if (Database->getTtConnect() && Database->getTtConnected() && !Database->getTtRotate() && serial.isOpen() && serial.isWritable())
    {
         QByteArray dayArray;

         dayArray[0]=0;
         serial.write(dayArray);
         serial.flush();
         timer.start();
         // Sleep(80);
         serial.waitForBytesWritten(100);
    }else if(!Database->getTtConnect() && Database->getTtConnected())
    {
        serial.close();
        Database->setTtConnected(false);
    }

}
