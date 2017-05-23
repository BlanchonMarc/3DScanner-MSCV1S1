#include "fileread_thread.h"
#include <vector>

// Process of file reading


//Copying function
fileread_thread::fileread_thread(QStringList thefilenames, dataclass *thedatabase)
{
    Database=thedatabase;
    filenames=thefilenames;
}

//Extracting all the point cloud
void fileread_thread::run()
{
    for (int i =0;i<filenames.count();i++) // through all the filenames
    {
        PointCloudT::Ptr tmpCloud (new PointCloudT) ;
        QString thefile=filenames.at(i);
        if(thefile.contains(".ply")){
            if (plyReader.read(thefile.toStdString(), *tmpCloud) == -1) //* load the file
            {
              PCL_ERROR ("Couldn't read ply file \n");
            }
        }else if(thefile.contains(".pcd")){
            if (pcl::io::loadPCDFile<pcl::PointXYZ> (thefile.toStdString(), *tmpCloud) == -1) //* load the file
            {
              PCL_ERROR ("Couldn't read pcd file \n");
            }
        }

        std::vector<int> indices;
        pcl::removeNaNFromPointCloud(*tmpCloud,*tmpCloud, indices);

        Database->m_pointcloud_data.push_back(tmpCloud);
        Database->m_cloud=tmpCloud;
    }
    Database->setFileReadingState(1);
}
