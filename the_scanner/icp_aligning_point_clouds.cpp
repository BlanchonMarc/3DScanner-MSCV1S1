#include "icp_aligning_point_clouds.h"
#include <string.h>
#include <vector>
#include <iostream>
#include <pcl/filters/radius_outlier_removal.h>

using namespace std;

//Constructor
icp_Aligning_Point_Clouds::icp_Aligning_Point_Clouds()
{

}

//Destructor
icp_Aligning_Point_Clouds::~icp_Aligning_Point_Clouds()
{

}

//ICP algorithm
void icp_Aligning_Point_Clouds::allign_PointClouds(std::vector<PointCloudT::Ptr>  data, dataclass *Database  )
{

    PointCloudT::Ptr cloud_source (new PointCloudT) ; //Cloud source
    PointCloudT::Ptr cloud_target  (new PointCloudT)  ; //Cloud target
    PointCloudT::Ptr result (new PointCloudT) ; //FInal output cloud
    PointCloudT::Ptr cloud_output1 (new PointCloudT); //Transformed output 1 cloud
    PointCloudT::Ptr cloud_output2 (new PointCloudT); //Transformet output 2 cloud
    PointCloudT::Ptr cloud_filtered (new PointCloudT); //Filtered cloud

    cout<<"Function invoked!! "<<endl;
    cout<<"Size of data is "<<data.size()<<endl;

    result = data[0]; //Initializing result with first pointcloud

    for (size_t i = 1; i < data.size () ; i++)
    {
        cout<<"Loop no. "<<i<<endl;
        //cout<<"Entering loop"<<endl;

        cloud_source = result ;
        cloud_target = data[i];

        //Downsampling voxel grid
        pcl::VoxelGrid<PointType> grid; //Instance of grid
        grid.setLeafSize (Database->getDownsampling_gridLeafSize(), Database->getDownsampling_gridLeafSize(), Database->getDownsampling_gridLeafSize()); //Setting leaf size
        grid.setInputCloud (cloud_source); //Input cloud
        grid.filter (*cloud_source); //Filtered cloud

        grid.setInputCloud (cloud_target); //Input target
        grid.filter (*cloud_target); //Filtered target

        //cout<<"Entering ICP"<<endl;
        icp.setInputCloud (cloud_source); //ICP input
        icp.setInputTarget (cloud_target); //ICP target
        //cout<<"Entering cafter source target"<<endl;
        icp.setMaxCorrespondenceDistance(Database->getIcp_MaxCorrespondenceDistance()); //Set MaxCorrespondenceDistance
        icp.setTransformationEpsilon (Database->getIcp_TransformationEpsilon()); //Seting TransformationEpsilon
        icp.setMaximumIterations (Database->getIcp_iterartions()); //Setting ICP Iterations
        // cout<<"Entering ransac"<<endl;
        icp.setRANSACOutlierRejectionThreshold(Database->getIcp_RANSACOutlierRejectionThreshold()); //Settting RANSAC Outlier Rejection Threshold
        icp.align (*cloud_output1);   //Transformed Point Cloud

        //cout<<"Entering convergence matrix"<<endl;
        Eigen::Matrix4f transform = icp.getFinalTransformation();  //Final Tranformation
        if (icp.hasConverged ())
        {
            pcl::transformPointCloud(*cloud_source, *cloud_output1, transform);  //Transforming Source to allign Point Cloud
            *cloud_output1 += *cloud_target;  //Concatinating Point Cloud

            cout << "\nICP has converged, score is " << icp.getFitnessScore () << endl;  //Checking Convergence Value of Point Clouds

        }
        else
        {
            PCL_ERROR ("\nICP has not converged.\n");

        }
        //Improving Transformation Matrix
        //cout<<"Entering ICP "<<endl;
        icp.setInputCloud (cloud_output1); //ICP input
        icp.setInputTarget (cloud_target); //ICP target
        icp.setMaxCorrespondenceDistance(Database->getIcp_MaxCorrespondenceDistance()); // -Set MaxCorrespondenceDistance
        icp.setTransformationEpsilon (Database->getIcp_TransformationEpsilon());//Seting TransformationEpsilon
        icp.setMaximumIterations (Database->getIcp_iterartions());//Setting ICP Iterations
        icp.setRANSACOutlierRejectionThreshold(Database->getIcp_RANSACOutlierRejectionThreshold()); //Settting RANSAC Outlier Rejection Threshold
        icp.align (*cloud_output2); //Transformed Point Cloud


        Eigen::Matrix4f transform2 = icp.getFinalTransformation();   //Final Tranformation
        if (icp.hasConverged ())
        {
            pcl::transformPointCloud(*cloud_output1, *cloud_output2, transform2); //Transforming Source to allign Point Cloud

            *cloud_output2 += *cloud_target;//Concatinating Point Cloud

            cout << "\nICP has converged, score is " << icp.getFitnessScore () << std::endl;//Checking Convergence Value of Point Clouds
            // SMOOTHING FILTER
            mls.setInputCloud (cloud_output2);  //MLS Smoothing Filter Input
            mls.setPolynomialFit (true);
            mls.setSearchMethod (tree);
            mls.setSearchRadius (Database->getSmoothing_mls_SearchRadius());
            //Reconstruct
            mls.process (*cloud_filtered); //MLS Smoothing Filter Output

        }
        else
        {
            PCL_ERROR ("\nICP has not converged.\n");
        }


        cout<<"FILTERED!"<<endl;

        result = cloud_filtered ;


        //           // set input cloud
        //           radius_outlier_removal.setInputCloud (result);

        //           // set radius for neighbor search
        //           radius_outlier_removal.setRadiusSearch (1.5);

        //           // set threshold for minimum required neighbors neighbors
        //           radius_outlier_removal.setMinNeighborsInRadius (150);

        //           // do filtering
        //           radius_outlier_removal.filter (*cleaned);

    }

    /************************************/

    pcl::io::savePLYFile("cloud_fusedcolor_filter.ply", *result);  //Saving Point Cloud

    Database->m_cloud= result; //Passing to main Data Base Class

}
