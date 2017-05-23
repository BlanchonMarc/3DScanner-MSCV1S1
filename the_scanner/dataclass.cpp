
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <vector>
#include "dataclass.h"

//Constructor, settings all the variables necessary to the code

dataclass:: dataclass(){
    m_depth_xLow=-0.5;
    m_depth_xHigh=0.5;
    m_depth_yLow=-1;
    m_depth_yHigh=1;
    m_depth_zLow=0.8;
    m_depth_zHigh=1.5;

    m_activeStage=0;

    m_capturingSpeed=2;
    m_enableCapture=false;

    //ICP VARIABLES SET DEFAULT
     m_downsampling_gridLeafSize = 0.005;
     m_icp_iterartions = 500 ;
     m_icp_MaxCorrespondenceDistance =  0.015 ;
     m_icp_TransformationEpsilon = 1e-8  ;
     m_icp_TransformationEpsilon2 = 2e-8  ;
     m_icp_RANSACOutlierRejectionThreshold = 0.01 ;
     m_smoothing_mls_SearchRadius =  0.03;

     //Settings interaction variables:
     m_recSettingsStatus=0;
     m_ICPSettingsStatus=0;
     m_icpState=0;
     m_ReconstructionState=0;
     m_fileReadingState=0;

     m_ttRotationDegrees=0;
     m_ttConnect=false;
     m_ttConnected=false;
     m_ttRotate=false;
     m_ttSerialPort =" COM3";

}

// Accessors and Mutators for each members Definition

QString dataclass::getTtSerialPort() const
{
    return m_ttSerialPort;
}

void dataclass::setTtSerialPort(const QString &ttSerialPort)
{
    m_ttSerialPort = ttSerialPort;
}

bool dataclass::getTtConnect() const
{
    return m_ttConnect;
}

void dataclass::setTtConnect(bool ttConnect)
{
    m_ttConnect = ttConnect;
}

bool dataclass::getTtRotate() const
{
    return m_ttRotate;
}

void dataclass::setTtRotate(bool ttRotate)
{
    m_ttRotate = ttRotate;
}

bool dataclass::getTtConnected() const
{
    return m_ttConnected;
}

void dataclass::setTtConnected(bool ttConnected)
{
    m_ttConnected = ttConnected;
}

int dataclass::getTtRotationDegrees() const
{
    return m_ttRotationDegrees;
}

void dataclass::setTtRotationDegrees(int ttRotationDegrees)
{
    m_ttRotationDegrees = ttRotationDegrees;
}

int dataclass::getActiveStage() const
{
    return m_activeStage;
}

void dataclass::setActiveStage(int activeStage)
{
    m_activeStage = activeStage;
}

int dataclass::getFileReadingState() const
{
    return m_fileReadingState;
}

void dataclass::setFileReadingState(int fileReadingState)
{
    m_fileReadingState = fileReadingState;
}

int dataclass::getReconstructionState() const
{
    return m_ReconstructionState;
}

void dataclass::setReconstructionState(int ReconstructionState)
{
    m_ReconstructionState = ReconstructionState;
}

int dataclass::getIcpState() const
{
    return m_icpState;
}

void dataclass::setIcpState(int icpState)
{
    m_icpState = icpState;
}

bool dataclass::getEnableCapture() const
{
    return m_enableCapture;
}

void dataclass::setEnableCapture(bool enableCapture)
{
    m_enableCapture = enableCapture;
}

int dataclass::getICPSettingsStatus() const
{
    return m_ICPSettingsStatus;
}

void dataclass::setICPSettingsStatus(int ICPSettingsStatus)
{
    m_ICPSettingsStatus = ICPSettingsStatus;
}

float dataclass::getDownsampling_gridLeafSize() const
{
    return m_downsampling_gridLeafSize;
}

void dataclass::setDownsampling_gridLeafSize(float downsampling_gridLeafSize)
{
    m_downsampling_gridLeafSize = downsampling_gridLeafSize;
}

float dataclass::getIcp_TransformationEpsilon2() const
{
    return m_icp_TransformationEpsilon2;
}

void dataclass::setIcp_TransformationEpsilon2(float icp_TransformationEpsilon2)
{
    m_icp_TransformationEpsilon2 = icp_TransformationEpsilon2;
}

int dataclass::getRecSettingsStatus() const
{
    return m_recSettingsStatus;
}

void dataclass::setRecSettingsStatus(int recSettingsStatus)
{
    m_recSettingsStatus = recSettingsStatus;
}

float dataclass::getSmoothing_mls_SearchRadius() const
{
    return m_smoothing_mls_SearchRadius;
}

void dataclass::setSmoothing_mls_SearchRadius(float smoothing_mls_SearchRadius)
{
    m_smoothing_mls_SearchRadius = smoothing_mls_SearchRadius;
}

float dataclass::getIcp_RANSACOutlierRejectionThreshold() const
{
    return m_icp_RANSACOutlierRejectionThreshold;
}

void dataclass::setIcp_RANSACOutlierRejectionThreshold(float icp_RANSACOutlierRejectionThreshold)
{
    m_icp_RANSACOutlierRejectionThreshold = icp_RANSACOutlierRejectionThreshold;
}

float dataclass::getIcp_TransformationEpsilon() const
{
    return m_icp_TransformationEpsilon;
}

void dataclass::setIcp_TransformationEpsilon(float icp_TransformationEpsilon)
{
    m_icp_TransformationEpsilon = icp_TransformationEpsilon;
}

float dataclass::getIcp_MaxCorrespondenceDistance() const
{
    return m_icp_MaxCorrespondenceDistance;
}

void dataclass::setIcp_MaxCorrespondenceDistance(float icp_MaxCorrespondenceDistance)
{
    m_icp_MaxCorrespondenceDistance = icp_MaxCorrespondenceDistance;
}

int dataclass::getIcp_iterartions() const
{
    return m_icp_iterartions;
}

void dataclass::setIcp_iterartions(int icp_iterartions)
{
    m_icp_iterartions = icp_iterartions;
}


bool dataclass::getNormal_consistency() const
{
    return m_normal_consistency;
}

void dataclass::setNormal_consistency(bool normal_consistency)
{
    m_normal_consistency = normal_consistency;
}

double dataclass::getMax_angle() const
{
    return m_max_angle;
}

void dataclass::setMax_angle(double max_angle)
{
    m_max_angle = max_angle;
}

double dataclass::getMin_angle() const
{
    return m_min_angle;
}

void dataclass::setMin_angle(double min_angle)
{
    m_min_angle = min_angle;
}

double dataclass::getMax_surface_angle() const
{
    return m_max_surface_angle;
}

void dataclass::setMax_surface_angle(double max_surface_angle)
{
    m_max_surface_angle = max_surface_angle;
}

unsigned int dataclass::getMax_nearest_neighbor() const
{
    return m_max_nearest_neighbor;
}

void dataclass::setMax_nearest_neighbor(unsigned int max_nearest_neighbor)
{
    m_max_nearest_neighbor = max_nearest_neighbor;
}

float dataclass::getRadius_search() const
{
    return m_radius_search;
}

void dataclass::setRadius_search(float radius_search)
{
    m_radius_search = radius_search;
}

unsigned int dataclass::getOctree_depth() const
{
    return m_octree_depth;
}

void dataclass::setOctree_depth(unsigned int octree_depth)
{
    m_octree_depth = octree_depth;
}

double dataclass::getCapturingSpeed() const
{
    return m_capturingSpeed;
}

void dataclass::setCapturingSpeed(double capturingSpeed)
{
    m_capturingSpeed = capturingSpeed;
}

double dataclass::getDepth_zHigh() const
{
    return m_depth_zHigh;
}

void dataclass::setDepth_zHigh(double depth_zHigh)
{
    m_depth_zHigh = depth_zHigh;
}

double dataclass::getDepth_zLow() const
{
    return m_depth_zLow;
}

void dataclass::setDepth_zLow(double depth_zLow)
{
    m_depth_zLow = depth_zLow;
}

double dataclass::getDepth_yHigh() const
{
    return m_depth_yHigh;
}

void dataclass::setDepth_yHigh(double depth_yHigh)
{
    m_depth_yHigh = depth_yHigh;
}

double dataclass::getDepth_yLow() const
{
    return m_depth_yLow;
}

void dataclass::setDepth_yLow(double depth_yLow)
{
    m_depth_yLow = depth_yLow;
}

double dataclass::getDepth_xHigh() const
{
    return m_depth_xHigh;
}

void dataclass::setDepth_xHigh(double depth_xHigh)
{
    m_depth_xHigh = depth_xHigh;
}

double dataclass::getDepth_xLow() const
{
    return m_depth_xLow;
}

void dataclass::setDepth_xLow(double depth_xLow)
{
    m_depth_xLow = depth_xLow;
}

float dataclass::getMu() const
{
    return m_mu;
}

void dataclass::setMu(float mu)
{
    m_mu = mu;
}


//PointCloudT::Ptr dataclass:: get_cloud(void){
//    return m_cloud;
//}

//void& dataclass:: set_cloud(const PointCloudT::Ptr& u_cloud ){
//        m_cloud = u_cloud;
//}


//unsigned int dataclass:: get_octree_depth(){
//    return m_octree_depth;
//}

//void& dataclass:: set_octree_depth(const unsigned int& u_octree_depth ){
//    m_octree_depth = u_octree_depth;
//}

//float dataclass:: get_radius_search(){
// return m_radius_search;
//}

//void& dataclass:: set_radius_search(const float& u_radius_search ){
//     m_radius_search = u_radius_search;
//}
