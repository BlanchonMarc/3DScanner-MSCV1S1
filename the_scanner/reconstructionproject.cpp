#include "reconstructionproject.h"
#include "dataclass.h"

using namespace pcl;

//-----------------------------------------------------------------------------
//*********************CONSTRUCTORS AND DESTRUCTOR*****************************
//-----------------------------------------------------------------------------

Reconstruction::Reconstruction(dataclass* Database)
{
    /*
     * Default Constructor of the Class :
     * we set the initial values for our Parameters (check the header file to have the description)
     */

    //Set the default value for the u_octree_depth variable
    Database->setOctree_depth(10);

    //Set the default value for the u_radius_search variable
    Database->setRadius_search(0.8);

    //Set the default value for the u_mu variable
    Database->setMu(10);

    //Set the default value for the u_max_nearest_neighbor variable
    Database->setMax_nearest_neighbor(20);

    //Set the default value for the u_max_surface_angle variable
    Database->setMax_surface_angle(M_PI);

    //Set the default value for the u_min_angle variable
    Database->setMin_angle(M_PI/10);

    //Set the default value for the u_max_angle variable
    Database->setMax_angle(M_PI);

    //Set the default value for the u_normal_consistency variable
    Database->setNormal_consistency(false);

    //Set the default value for the u_StddevMulThresh variable
}

//Reconstruction::Reconstruction(PointCloud<PointXYZ>::Ptr input_point_cloud, dataclass* Database)
//{
//    /*
//     * Parametric Constructor of the Class :
//     * we pass a parameter a point cloud to get it into the class (input point cloud of the class and
//     * we set the initial values for our Parameters (check the header file to have the description)
//     */


//    //Set the default value for the u_octree_depth variable
//    Database->setOctree_depth(10);

//    //Set the default value for the u_radius_search variable
//     Database->setRadius_search(0.8);

//     //Set the default value for the u_mu variable
//     Database->setMu(10);

//     //Set the default value for the u_max_nearest_neighbor variable
//     Database->setMax_nearest_neighbor(20);

//     //Set the default value for the u_max_surface_angle variable
//     Database->setMax_surface_angle(M_PI);

//     //Set the default value for the u_min_angle variable
//     Database->setMin_angle(M_PI/10);

//     //Set the default value for the u_max_angle variable
//     Database->setMax_angle(M_PI);

//     //Set the default value for the u_normal_consistency variable
//     Database->setNormal_consistency(false);
//}


Reconstruction::~Reconstruction()
{
    /*
     * Destructor of the Class
     */
}


//-----------------------------------------------------------------------------
//*******************************"TOOL" FUNCTIONS******************************
//-----------------------------------------------------------------------------

//***************************NORMAL ESTIMATION FUNCTION************************

PointCloud< pcl::PointNormal > :: Ptr
Reconstruction :: normal_estimation
(PointCloud< PointXYZ > :: Ptr input_point_cloud , dataclass* Database)
{
    /*
     * This "tool" function is used to compute the normal estimation of a point
     * cloud, used in the Poisson algorithm and in the greedy triangulation
     * method. We need in input a XYZ point cloud and it returns us a normal
     * point cloud.
     */

    NormalEstimationOMP< PointXYZ, Normal > t_n;
    // Create an instance of the class Normal Estimation

    PointCloud<Normal> :: Ptr t_normals
            (new PointCloud<Normal>() ) ;
    //Read and Create a pointer "t_normals" and reserving space in the memory It's datatype Normal because we'll create a normal point cloud

    t_n.setNumberOfThreads (8);
    //Initialize the scheduler and set the number of threads to use.

    t_n.setInputCloud (input_point_cloud);
    //Insert the wanted point cloud as an input to the Normal Estimation

    t_n.setRadiusSearch (0.05);
    //Set the sphere radius that is to be used for determining the k-nearest neighbors

    Eigen::Vector4f t_centroid;
    //Create an eigenvector to store the centroid

    compute3DCentroid (*input_point_cloud, t_centroid);
    //Compute the centroid of the point cloud

    t_n.setViewPoint (t_centroid[0], t_centroid[1], t_centroid[2]);

    t_n.compute (*t_normals);
    //Compute the Normals from the point cloud

    PointCloud<PointNormal>::Ptr t_output_point_cloud
            (new PointCloud<PointNormal >) ;
    //Create a pointer (t_output_point_cloud) of the datatype PointNormal and reserve space on the memory

    for (size_t i = 0; i < t_normals->size (); ++i)
    {
    //Change the sign of our normals
        t_normals->points[i].normal_x *= -1;

        t_normals->points[i].normal_y *= -1;

        t_normals->points[i].normal_z *= -1;
    }

    concatenateFields(*t_normals, *input_point_cloud ,
                             *t_output_point_cloud);
    //Merging the Normal Estimation output & the point cloud and saved it in "t_output_point_cloud"

    return (t_output_point_cloud);
    //Return the Normal Estimation
}

//***************************POISSON ALGORITHM*********************************

boost :: shared_ptr<PolygonMesh>
Reconstruction::poisson_algorithm
(PointCloud<PointNormal>::Ptr input_point_cloud, dataclass* Database)
{
    /*
     * This "tool" function is used to apply the Poisson algorithm, a powerful
     * way to reconstruct directly a watertight mesh. This algorithm is very sensitive
     * to noise and it has some problems to reconstruct the ... volume. It needs
     * as input a normal point cloud and it returns a polygon mesh.
     */

    Poisson<PointNormal> poisson;
    //Create an object to Poisson of datatype PointNormal

    poisson.setDepth (Database->getOctree_depth()) ;
    //Set the value of the depth of the octree

    boost :: shared_ptr<PolygonMesh> t_triangles
            (new PolygonMesh );
    //Create a smart pointer (t_triangles) of datatype PolygonMesh and allocate space on memory

    poisson.setInputCloud (input_point_cloud) ;
    //Insert "input_point_cloud" as an input for the Poisson method

    poisson.reconstruct (*t_triangles) ;
    //Perfom the surface reconstruction method and save in "t_triangles"

    return(t_triangles);
    //Return the reconstructed Mesh
}

//****************************GREEDY TRIANGULATION*****************************

boost :: shared_ptr<PolygonMesh>
Reconstruction::greedy_triangulation
(PointCloud<PointNormal>::Ptr input_point_cloud, dataclass* Database)
{
    /*
     * This "tool" function is used to perform a greedy triangulation, a basic way to
     * reconstruct a mesh by creating triangles between the points. This algorithm
     * depends on many parameters and it don't give us a watertight mesh (we have to
     * use a holes filling algorithm after it).It needs as input a normal point cloud
     * and it returns a polygon mesh.
     */

    GreedyProjectionTriangulation<PointNormal> gt;
    //Create an object to GreedyProjectionTriangulation of datatype PointNormal

    boost :: shared_ptr<PolygonMesh> t_triangles
            (new PolygonMesh );
    //Create a smart pointer (t_triangles) of datatype PolygonMesh and allocate space on memory

    gt.setInputCloud(input_point_cloud);
    //Insert "input_point_cloud" as an input for the Greedy triangulation method

    gt.setSearchRadius (Database->getRadius_search()) ;
    //Select the maximum allowable length of an edge of a triangle

    gt.setMu (Database->getMu()) ;
    //Select the density parameter

    gt.setMaximumNearestNeighbors (Database->getMax_nearest_neighbor()) ;
    //Select the maximum neighbor taking in account for creating the triangles

    gt.setMaximumSurfaceAngle (Database->getMax_surface_angle()) ;
    //Select the angle between the normal of subject point and the sel point

    gt.setMinimumAngle (Database->getMin_angle()) ;
    //Select the minimal angle for a triangle

    gt.setMaximumAngle(Database->getMax_angle());
    //Select the maximum angle for a triangle

    gt.setNormalConsistency ( Database->getNormal_consistency() ) ;
    //Set a flag if the normals are oriented consistently

    gt.reconstruct(*t_triangles);
    //Perfom the surface reconstruction method and save in "t_triangles"

    return (t_triangles);
    //Return the reconstructed Mesh
}

//-----------------------------------------------------------------------------
//*******************************CALLED FUNCTION*******************************
//-----------------------------------------------------------------------------

boost :: shared_ptr<PolygonMesh>
Reconstruction::reconstruction(bool method, dataclass* Database)
{
    /*This function is called in the software to perform the 3D reconstruction
     * according to the choice from the user (buttons in the User Interface permit
     * to select the reconstruction method and if he want smoothing or not). This
     * function uses the "tool" functions created before. We need to provide to the
     * function two booleans (representing the choices of the user) and return a
     * polygon mesh.
     */

    PointCloud<PointNormal>::Ptr t_output_point_cloud_normal_estimation
            (new PointCloud<PointNormal >) ;
    //Read and Create a pointer "t_output_point_cloud_normal_estimation" and reserving space in the memory

    t_output_point_cloud_normal_estimation = normal_estimation(Database->m_cloud, Database);
    //Use the "tool" function for computing the normal estimation of the point cloud

    boost :: shared_ptr<PolygonMesh> t_output_recon (new PolygonMesh );
    //Create a smart pointer (t_output_recon) of datatype PolygonMesh and allocate space on memory

    if(method == true)
    {
        //Check which method has been selected by the user to perform the 3D reconstruction (true=Poisson, false=GT)

        t_output_recon =  poisson_algorithm(t_output_point_cloud_normal_estimation, Database);
        //Use the "tool" function for creating the 3D mesh using the Poisson algorithm

    }
    else
    {

        t_output_recon =  greedy_triangulation(t_output_point_cloud_normal_estimation, Database);
        //Use the "tool" function for creating the 3D mesh using the greedy triangulation method

    }

    return(t_output_recon);
    //Return the reconstructed Mesh according to the selected method
}
