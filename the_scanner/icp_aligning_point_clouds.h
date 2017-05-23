#ifndef ICP_ALIGNING_POINT_CLOUDS_H
#define ICP_ALIGNING_POINT_CLOUDS_H
#include <QCoreApplication>
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <string>
#include <sstream>
#include <pcl/point_cloud.h>
#include <pcl/surface/organized_fast_mesh.h>
#include <pcl/registration/gicp.h>
#include <pcl/features/from_meshes.h>
#include <pcl/registration/correspondence_estimation.h>
#include <pcl/registration/correspondence_rejection_one_to_one.h>
#include <pcl/registration/transformation_estimation_svd.h>
#include <pcl/keypoints/iss_3d.h>
#include <pcl/keypoints/sift_keypoint.h>
#include <pcl/features/normal_3d.h>
#include <pcl/keypoints/uniform_sampling.h>
#include <pcl/registration/correspondence_rejection_sample_consensus.h>
#include <pcl/registration/transformation_estimation_svd.h>
#include <pcl/registration/elch.h>
#include <vector>
#include <boost/make_shared.hpp>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>
#include <pcl/point_representation.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/filter.h>
#include <pcl/features/normal_3d.h>
#include <pcl/registration/icp_nl.h>
#include <pcl/registration/transforms.h>
#include <pcl/filters/statistical_outlier_removal.h>
//#include <pcl/visualization/pcl_visualizer.h>
#include "dataclass.h"

//Libraries included

using namespace std;

//Type definitions:
typedef pcl::PointXYZ PointType; //Black and white pointcloud
typedef pcl::PointCloud<PointType> PointCloudT;


class icp_Aligning_Point_Clouds
{

private :

     //Member variables:
    pcl::IterativeClosestPoint<PointType, PointType> icp;
    pcl::MovingLeastSquares<PointType, PointType> mls;
    pcl::search::KdTree<PointType>::Ptr tree;

public:
    //Constructor
   icp_Aligning_Point_Clouds();

   //Destructor
 ~icp_Aligning_Point_Clouds();

   //Accesors and mutators:
    float getDownsampling_gridLeafSize() const;
    void setDownsampling_gridLeafSize(float value);
    int getIcp_iterartions() const;
    void setIcp_iterartions(int value);
    float getIcp_MaxCorrespondenceDistance() const;
    void setIcp_MaxCorrespondenceDistance(float value);
    float getIcp_TransformationEpsilon() const;
    void setIcp_TransformationEpsilon(float value);
    float getIcp_RANSACOutlierRejectionThreshold() const;
    void setIcp_RANSACOutlierRejectionThreshold(float value);
    float getSmoothing_mls_SearchRadius() const;
    void setSmoothing_mls_SearchRadius(float value);

   //ICP align pointcloud function:
    void allign_PointClouds(  std::vector<PointCloudT::Ptr>  data, dataclass *Database   );

};

#endif // ICP_ALIGNING_POINT_CLOUDS_H
