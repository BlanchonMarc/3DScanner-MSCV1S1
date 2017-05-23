#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <vector>
#include<QElapsedTimer>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>

#include "dataclass.h"
#include "reconstruction_settings.h"
#include "icp_settings.h"
#include "log_management.h"
#include "icp_thread.h"
#include "reconstruction_thread.h"
#include "fileread_thread.h"
#include "ttable_thread.h"

#include <QMovie>
#include <QLabel>
#include <QWidget>
#include <QStandardItemModel>

/*
  MainWindow class: This class contain all the code that controls the behavior of the
  principal window and serves as a joining point for all the classes that conform
  this project.
 */

using namespace std;
//using namespace pcl;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    //Constructor:
    explicit MainWindow(QWidget *parent = 0);
    //Destructor:
    ~MainWindow();

protected:

    //Function for performing certain actions when the window is closed
    void closeEvent(QCloseEvent *event);

    void updatePointcloudList();

    void showPointcloud(int idPointcloud);

    void resetVtk();
private slots:

    //Slot in charge of opening a pointcloud file
    void on_actionOpen_triggered();

    //Slots for saving the Kinect range configurations in the database:
    void on_x1_range_valueChanged(double arg1);

    void on_x2_range_valueChanged(double arg1);

    void on_y1_range_valueChanged(double arg1);

    void on_y2_range_valueChanged(double arg1);

    void on_z1_range_valueChanged(double arg1);

    void on_z2_range_valueChanged(double arg1);

    //Slot in charge of performing the 3D reconstruction process:
    void on_reconstructBtn_clicked();

    //Slot in charge of performing the pointcloud stitching process:
    void on_stitchBtn_clicked();

    //Slot for setting the capturing speed of the data coming from the Kinect
    void on_captureSpeed_valueChanged(double arg1);

    //Slot for connecting to the Kinect and start a data capturing process:
    void on_actionConnect_to_Kinect_triggered();

    //Slot for saving the data received from the Kinect:
    void on_actionStart_capture_toggled(bool arg1);

    //Slot for changing the point size
    void on_horizontalSlider_sliderMoved(int position);

    void on_pointcloudList_doubleClicked(const QModelIndex &index);

    void on_ttConnect_toggled(bool checked);

    void on_ttMove_toggled(bool checked);

    void on_tablePort_textChanged(const QString &arg1);


    void on_deleteBtn_clicked();

    void on_deleteAllBtn_clicked();

    void on_actionPointclouds_triggered();

    void on_pointsBtn_clicked();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_horizontalSlider_2_sliderMoved(int position);

private:

    typedef pcl::PointXYZRGBA PointTypeColor;
    typedef pcl::PointCloud<PointTypeColor> PointCloudColorT;

    //Objects for adding an animated icon to the right of the toolbar:
    QWidget* spacer = new QWidget();
    QMovie *movie;
    QLabel *processLabel;

    //Object in charge of visualizing pointclouds and meshes:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;

    //Object for loading a PLY file
    pcl::PLYReader plyReader;

    //Flag that states if there is a capturing process running
    bool capturing;

    //Timer for controlling data registration speed
    QElapsedTimer timer;

    //User interface object of the main window
    Ui::MainWindow *ui;

    //Database object
    dataclass *Database;

    //Instance of the ICP thread class:
    icp_thread *icp_thread_class ;

    //Instance of the 3D reconstruction class:
    reconstruction_thread *reconstruction_thread_class;

    //Instance of the file reading class:
    fileread_thread *fileread_thread_class;

    //Instance of the turning table class:
    ttable_thread *ttable_thread_class;

    //Model for list of pointclouds:
    QStandardItemModel* ListModel;

};

#endif // MAINWINDOW_H
