#ifndef ICP_THREAD_H
#define ICP_THREAD_H

#include <QThread>
#include "dataclass.h"
#include "icp_aligning_point_clouds.h"

class icp_thread : public QThread
{
    Q_OBJECT

public://Construcotor
    icp_thread(dataclass *thedatabase);

private:
    dataclass *Database;

    //Instance of the ICP Stitching class:
    icp_Aligning_Point_Clouds *icp_Class ;

protected://Specific function
    void run();
};

#endif // ICP_THREAD_H
