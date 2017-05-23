/*
By downloading, copying, installing or using the software you agree to this license.
If you do not agree to this license, do not download, install,
copy or use the software.
                          License Agreement
            For Open Source Computer Vision and Robotics Project
Copyright (C) 2016,
      Moreno Genis Maria del Carmen (mc.genis2@gmail.com),
      Khalid Omair (omair.khalid92@hotmail.com),
      Drevet Thomas (dreve2thom@hotmail.fr),
Third party copyrights are property of their respective owners.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
  * Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  * Neither the names of the copyright holders nor the names of the contributors
    may be used to endorse or promote products derived from this software
    without specific prior written permission.
This software is provided by the copyright holders and contributors "as is" and
any express or implied warranties, including, but not limited to, the implied
warranties of merchantability and fitness for a particular purpose are disclaimed.
In no event shall copyright holders or contributors be liable for any direct,
indirect, incidental, special, exemplary, or consequential damages
(including, but not limited to, procurement of substitute goods or services;
loss of use, data, or profits; or business interruption) however caused
and on any theory of liability, whether in contract, strict liability,
or tort (including negligence or otherwise) arising in any way out of
the use of this software, even if advised of the possibility of such damage.

*/


#ifndef Reconstruction_H
#define Reconstruction_H

#include <pcl/io/vtk_io.h>
#include <Windows.h>
#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/search/kdtree.h>
#include <pcl/features/normal_3d.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/surface/poisson.h>
#include <pcl/surface/gp3.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/visualization/pcl_visualizer.h>

#include "dataclass.h"

//using namespace pcl;

/*
  This class was created to achieve 3D Reconstruction, as part of a project to make a 3D Scanner. It
  takes a registered point cloud as the input and then outputs a watertight mesh which is suitable for
  3D Printing.

  The 3D Reconstruction can be achieved by either one of the two methods:
    -Poisson 3D Reconstruction
    -Greedy Reconstruction.

  The user can change the default parameters for the 3D Reconstruction method through the
  GUI to achieve desirable results.

  ///Constructors
        @NULL :: Creating default file with default values for parameters
        @PointCloud< PointXYZ > :: Ptr :: Creating a parametric file to pass a point cloud as parameter into the class
  ///Destructor
        @NULL :: Closing the file opened
  ///Functions
        reconstruction :: Called function in the software containing the other functions
        getU_octree_depth :: Accessor for the u_octree_depth parameter
        setU_octree_depth :: Mutator for the u_octree_depth parameter
        getU_radius_search :: Accessor for the u_radius_search parameter
        setU_radius_search :: Mutator for the u_radius_search parameter
        getU_mu :: Accessor for the u_mu parameter
        setU_mu :: Mutator for the u_mu parameter
        getU_max_nearest_neighbor :: Accessor for the u_max_nearest_neighbor parameter
        setU_max_nearest_neighbor :: Mutator for the u_max_nearest_neighbor parameter
        getU_max_surface_angle :: Accessor for the u_max_surface_angle parameter
        setU_max_surface_angle :: Mutator for the u_max_surface_angle parameter
        getU_min_angle :: Accessor for the u_min_angle parameter
        setU_min_angle :: Mutator for the u_min_angle parameter
        getU_max_angle :: Accessor for the u_max_angle parameter
        setU_max_angle :: Mutator for the u_max_angle parameter
        getU_normal_consistency :: Accessor for the u_normal_consistency parameter
        setU_normal_consistency :: Mutator for the u_normal_consistency parameter
        normal_estimation :: Compute the normal estimation needed Poisson and the Greedy Triangulation
        poisson_algorithm :: Create a 3D Mesh using the Poisson Algorithm from a point cloud
        greedy_triangulation :: Create a 3D Mesh using the Greedy Triangulation method from a point cloud
 */

class Reconstruction
{

public:

    Reconstruction(dataclass* Database);
    //Default Constructor

//    Reconstruction(PointCloud< PointXYZ > :: Ptr input_point_cloud , dataclass* Database);
//    //Parametric Constructor

    ~Reconstruction();
    //Destructor

    boost::shared_ptr<pcl::PolygonMesh> reconstruction(bool method, dataclass *Database);

protected:

    pcl::PointCloud<pcl::PointNormal>::Ptr normal_estimation(pcl::PointCloud<pcl::PointXYZ>::Ptr input_point_cloud , dataclass* Database);
    //Create the "tool" function to do the normal estimation

    boost::shared_ptr<pcl::PolygonMesh> poisson_algorithm(pcl::PointCloud<pcl::PointNormal>::Ptr input_point_cloud, dataclass* Database);
    //Create the "tool" function to perform the Poisson algorithm

    boost::shared_ptr<pcl::PolygonMesh> greedy_triangulation(pcl::PointCloud<pcl::PointNormal>::Ptr input_point_cloud, dataclass* Database);
    //Create the "tool" function to perform the greedy triangulation
};

#endif // Reconstruction_H
