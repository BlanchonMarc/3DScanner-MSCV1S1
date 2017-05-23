#ifndef RECONSTRUCTION_THREAD_H
#define RECONSTRUCTION_THREAD_H

#include <QThread>
#include "dataclass.h"
#include "reconstructionproject.h"

class reconstruction_thread : public QThread
{
public:
    reconstruction_thread(dataclass *thedatabase);

private:
    dataclass *Database;

    //Instance of the Reconstruction class:
    Reconstruction *recproject ;

protected:
    void run();
};

#endif // RECONSTRUCTION_THREAD_H
