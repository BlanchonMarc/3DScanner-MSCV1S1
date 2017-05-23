#ifndef TTABLE_THREAD_H
#define TTABLE_THREAD_H

#include <QThread>
#include <QSerialPort>
#include <QElapsedTimer>
#include "dataclass.h"

// Turning table class


class ttable_thread : public QThread
{
public:// constructor
    ttable_thread(dataclass *thedatabase);

private:// variables
    dataclass *Database;
    QSerialPort serial;
    QElapsedTimer timer;

protected://special behaviour
    void run();

};

#endif // TTABLE_THREAD_H
