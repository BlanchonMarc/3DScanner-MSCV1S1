#include "icp_thread.h"
#include <iostream>
#include <vector>
#include <QDir>
#include <QDirIterator>
#include <sstream>

using namespace std;
//Constructor
icp_thread::icp_thread(dataclass *thedatabase)
{
    Database = thedatabase;

    //Calling ICP class
    icp_Class  =  new icp_Aligning_Point_Clouds() ;
}

void icp_thread::run()
{
    cout<<"The size of m_pointcloud_data is: "<<Database->m_pointcloud_data.size()<<endl;
    icp_Class->allign_PointClouds(Database->m_pointcloud_data, Database  );
    cout<<"ICP Finished!!!!!!!"<<endl;
    Database->setIcpState(1);
}
