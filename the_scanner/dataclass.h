#ifndef DATACLASS_H
#define DATACLASS_H

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/registration/icp.h>
#include <pcl/registration/gicp.h>
#include <pcl/registration/elch.h>
#include <boost/make_shared.hpp>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/filter.h>
#include <pcl/registration/icp_nl.h>
#include <pcl/registration/transforms.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <vector>
#include <QString>




//using namespace pcl;

/*
  ///Constructors  /// Each incrementation of inputs gives more precise definition the process remain the same
        @NULL :: Initialize the settings
  ///Destructor
        @NULL ::
  ///Function
    Accessors and Mutators

 */


class dataclass
{
private:
    typedef pcl::PointXYZ PointType;
    typedef pcl::PointCloud<PointType> PointCloudT;
    typedef pcl::PointXYZRGBA PointTypeColor;
    typedef pcl::PointCloud<PointTypeColor> PointCloudColorT;

public:
    //Pointcloud and figure variables:
    dataclass();
    ~dataclass();

private:

    //Configuration variables:
    double   m_depth_xLow,
                    m_depth_xHigh,
                    m_depth_yLow,
                    m_depth_yHigh,
                    m_depth_zLow,
                    m_depth_zHigh;

    int m_activeStage;

    double m_capturingSpeed;
    bool m_enableCapture;

    //********************ICP VARIABLES ********************//
    float m_downsampling_gridLeafSize;
    int m_icp_iterartions;
    float m_icp_MaxCorrespondenceDistance;
    float m_icp_TransformationEpsilon;
    float m_icp_TransformationEpsilon2;
    float m_icp_RANSACOutlierRejectionThreshold;
    float m_smoothing_mls_SearchRadius;

    //**********************ENDING ICP********************************//

    //*******************POISSON ALGORITHM************************

    unsigned int m_octree_depth;
    //Create the variable to defined the octree depth in the Poisson Algorithm

    //******************GREEDY TRIANGULATION***********************

    float m_radius_search;
    //Create the variable to defined the maximum allowable length of an edge of a triangle

    float m_mu;
    //Create the variable to defined the density parameter

    unsigned int m_max_nearest_neighbor;
    //Create the variable to defined the maximum neighbor taking in account for creating the triangles

    double m_max_surface_angle;
    //Create the variable to defined the angle between the normal of subject point and the sel point

    double m_min_angle;
    //Create the variable to defined the minimal angle for a triangle

    double m_max_angle;
    //Create the variable to defined the maximum angle for a triangle

    bool m_normal_consistency;
    //Create the variable to set a flag if the normals are oriented consistently

    //Variables for interaction with interfaces of settings:
    int m_recSettingsStatus; //0=closed; 1=opened; 2=Greedy; 3=Poisson
    int m_ICPSettingsStatus; //0=closed; 1=opened; 2=Apply
    int m_icpState;
    int m_ReconstructionState;
    int m_fileReadingState;

    //Turning table variables:
    int m_ttRotationDegrees;
    bool m_ttConnect;
    bool m_ttConnected;
    bool m_ttRotate;
    QString m_ttSerialPort;


public: // Accessors mutators


        PointCloudT::Ptr m_cloud;
        boost::shared_ptr<pcl::PolygonMesh> m_Mesh;
        std::vector<PointCloudT::Ptr>  m_pointcloud_data;

        double getDepth_xLow() const;
        void setDepth_xLow(double depth_xLow);
        double getDepth_xHigh() const;
        void setDepth_xHigh(double depth_xHigh);
        double getDepth_yLow() const;
        void setDepth_yLow(double depth_yLow);
        double getDepth_yHigh() const;
        void setDepth_yHigh(double depth_yHigh);
        double getDepth_zLow() const;
        void setDepth_zLow(double depth_zLow);
        double getDepth_zHigh() const;
        void setDepth_zHigh(double depth_zHigh);
        double getCapturingSpeed() const;
        void setCapturingSpeed(double capturingSpeed);
        unsigned int getOctree_depth() const;
        void setOctree_depth(unsigned int octree_depth);
        float getRadius_search() const;
        void setRadius_search(float radius_search);
        unsigned int getMax_nearest_neighbor() const;
        void setMax_nearest_neighbor(unsigned int max_nearest_neighbor);
        double getMax_surface_angle() const;
        void setMax_surface_angle(double max_surface_angle);
        double getMin_angle() const;
        void setMin_angle(double min_angle);
        double getMax_angle() const;
        void setMax_angle(double max_angle);
        float getMu() const;
        void setMu(float mu);
        bool getNormal_consistency() const;
        void setNormal_consistency(bool normal_consistency);

        //ICP setter and getters
        float getDownsampling_gridLeafSize() const;
        void setDownsampling_gridLeafSize(float downsampling_gridLeafSize);
        int getIcp_iterartions() const;
        void setIcp_iterartions(int icp_iterartions);
        float getIcp_MaxCorrespondenceDistance() const;
        void setIcp_MaxCorrespondenceDistance(float icp_MaxCorrespondenceDistance);
        float getIcp_TransformationEpsilon() const;
        void setIcp_TransformationEpsilon(float icp_TransformationEpsilon);
        float getIcp_RANSACOutlierRejectionThreshold() const;
        void setIcp_RANSACOutlierRejectionThreshold(float icp_RANSACOutlierRejectionThreshold);
        float getSmoothing_mls_SearchRadius() const;
        void setSmoothing_mls_SearchRadius(float smoothing_mls_SearchRadius);
        float getIcp_TransformationEpsilon2() const;
        void setIcp_TransformationEpsilon2(float icp_TransformationEpsilon2);

        int getRecSettingsStatus() const;
        void setRecSettingsStatus(int recSettingsStatus);
        int getICPSettingsStatus() const;
        void setICPSettingsStatus(int ICPSettingsStatus);
        bool getEnableCapture() const;
        void setEnableCapture(bool enableCapture);
        int getIcpState() const;
        void setIcpState(int icpState);
        int getReconstructionState() const;
        void setReconstructionState(int ReconstructionState);
        int getFileReadingState() const;
        void setFileReadingState(int fileReadingState);
        int getActiveStage() const;
        void setActiveStage(int activeStage);
        int getTtRotationDegrees() const;
        void setTtRotationDegrees(int ttRotationDegrees);
        bool getTtConnected() const;
        void setTtConnected(bool ttConnected);
        bool getTtRotate() const;
        void setTtRotate(bool ttRotate);
        bool getTtConnect() const;
        void setTtConnect(bool ttConnect);
        QString getTtSerialPort() const;
        void setTtSerialPort(const QString &ttSerialPort);
};

#endif // DATACLASS_H
