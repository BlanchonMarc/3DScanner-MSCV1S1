#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QFileDialog" //Menda

#include "kinect_management.h"

#include <thread>
#include <vector>
#include <iostream>
#include <QMessageBox>
#include <QCloseEvent>
#include <vtkOutputWindow.h>
#include <vtkFileOutputWindow.h>
#include <QDirIterator>
#include <iostream>
#include "dataclass.h"
#include <QStandardItem>
#include <QStandardItemModel>
#include <sstream>
#include <Windows.h>

using namespace std;

//Constructor of the MainWindow class:
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //Initialization of the database class
    Database = new dataclass();

    //Calling ICP class
    icp_thread_class  =  new icp_thread(Database) ;

    //Calling Reconstruction class
     reconstruction_thread_class  =  new reconstruction_thread(Database) ;

     //Calling Turning Table class
      ttable_thread_class  =  new ttable_thread(Database) ;

    //Pointcloud list model:
    ListModel = new QStandardItemModel();

    //Setup of the main interface
    ui->setupUi(this);

    //Add animated icon to the toolbar:
    spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    movie = new QMovie(":/images/images/box.gif");
    movie->setScaledSize(QSize(40,40));
    processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();
    movie->setPaused(true);
    ui->mainToolBar->addWidget(spacer);
    ui->mainToolBar->addWidget(processLabel);

    //Hide the VTK Warning popup
    vtkObject::GlobalWarningDisplayOff();

    //Set the data capturing state to false
    capturing=false;

    //Display the current Kinect range settings
    ui->x1_range->setValue(Database->getDepth_xLow());
    ui->x2_range->setValue(Database->getDepth_xHigh());
    ui->y1_range->setValue(Database->getDepth_yLow());
    ui->y2_range->setValue(Database->getDepth_yHigh());
    ui->z1_range->setValue(Database->getDepth_zLow());
    ui->z2_range->setValue(Database->getDepth_zHigh());

    //Display the current capturing control settings
    ui->captureSpeed->setValue(Database->getCapturingSpeed());

    // Setup the cloud pointer
    Database->m_cloud.reset (new PointCloudT);

    // Set up the QVTK widget
    resetVtk();

}

void MainWindow::resetVtk()
{

    // Set up the QVTK widget
    viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    //Set the QVTK to show the graphics rendered by "viewer"
    ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
    //Set "viewer" to receive the user interactions captured by the WVTK widget
    viewer->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
    viewer->addCoordinateSystem(0.3,-0.5,-0.5,-0.5);
    ui->qvtkWidget->update ();

    //Link the pointcloud container from the database to the visualization object:
    pcl::visualization::PointCloudColorHandlerCustom<PointType> colorPt (Database->m_cloud, 0, 123, 100);
    viewer->addPointCloud (Database->m_cloud, colorPt,  "cloud");
    viewer->resetCamera ();
    //Set visualization parameters such as size of points:
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "cloud");
    ui->qvtkWidget->update ();

}

//Destructor:
MainWindow::~MainWindow()
{
    //Set capturing state to false
    capturing=false;
    //Force application to quit
    QApplication::exit();
    cout<<"Closing!";
    delete ui;
}

//Slot function in charge of opening a .pcd or .ply file by using the file system dialog:
void MainWindow::on_actionOpen_triggered()
{

    //Open a file system dialog and return the path of the selected file:
    QStringList  filenames = QFileDialog::getOpenFileNames(this, tr("Open PCD or PLY files..."),"", tr(""));

    //If the user has selected one or more files
    if( !filenames.isEmpty() )
    {

        fileread_thread_class=new fileread_thread(filenames, Database);

        //Run the animated icon
        movie->setPaused(false);

        //Run the file reader class
        fileread_thread_class->start();

        //Wait until the file loading is finished
        while(Database->getFileReadingState()==0){
            QCoreApplication::processEvents();
        }

        //Stop the animated icon
        movie->setPaused(true);

    }

    //Update the visualizer with the new data from the opened file:

    viewer->updatePointCloud (Database->m_cloud, "cloud");
    if( ui->checkBox->isChecked() ) viewer->resetCamera ();
    ui->qvtkWidget->update ();
    updatePointcloudList();
    Database->setFileReadingState(0);
}

//Slots to update the settings in the database whenever the boundary controls from the UI are changed:
void MainWindow::on_x1_range_valueChanged(double arg1)
{
    Database->setDepth_xLow(arg1);
}

void MainWindow::on_x2_range_valueChanged(double arg1)
{
    Database->setDepth_xHigh(arg1);
}

void MainWindow::on_y1_range_valueChanged(double arg1)
{
    Database->setDepth_yLow(arg1);
}

void MainWindow::on_y2_range_valueChanged(double arg1)
{
    Database->setDepth_yHigh(arg1);
}

void MainWindow::on_z1_range_valueChanged(double arg1)
{
    Database->setDepth_zLow(arg1);
}

void MainWindow::on_z2_range_valueChanged(double arg1)
{
    Database->setDepth_zHigh(arg1);
}

//Function intended to perform or ignore the closing action by confirming user's decision
void MainWindow::closeEvent (QCloseEvent *event)
{
    //Generate a confirmation message
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "the_scanner",
                                                                tr("Are you sure? You're loose all your data!!!\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);

    //Ignore or accept the action according to user's election
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        capturing=false;
        event->accept();
    }
}

void MainWindow::updatePointcloudList()
{
    ListModel->clear();
    for (int i=1; i<=Database->m_pointcloud_data.size(); i++){
        stringstream ss;
        ss << "Pointcloud " << i;
        string pointcloudName = ss.str();
        QStandardItem* Items = new QStandardItem(QString::fromStdString(pointcloudName));
        ListModel->appendRow(Items);
    }

    ui->pointcloudList->setModel(ListModel);

}

void MainWindow::showPointcloud(int idPointcloud){
    Database->m_cloud=Database->m_pointcloud_data[idPointcloud];
    viewer->updatePointCloud (Database->m_cloud, "cloud");
    if( ui->checkBox->isChecked() ) viewer->resetCamera ();
    ui->qvtkWidget->update ();
}

//
void MainWindow::on_reconstructBtn_clicked()
{
    QPoint p = QCursor::pos();
    reconstruction_settings* settingsPopup = new reconstruction_settings(0, Database);
    settingsPopup->setWindowFlags(Qt::Popup);
    settingsPopup->move(p);
    settingsPopup->show();

    Database->setRecSettingsStatus(1);

    while(Database->getRecSettingsStatus()==1){
        QCoreApplication::processEvents();
    }

    if(Database->getRecSettingsStatus()>1){
        //3D Reconstruction test:::::::::

//        PCLPointCloud2 cloudblob ;
//        io :: loadPLYFile ( "C:\\Users\\elyamo\\Documents\\pcd_files\\cloud_fusedcolor_smmothing_without shoulder problem.ply" , cloudblob);
//        fromPCLPointCloud2(cloudblob, *Database->m_cloud);

        reconstruction_thread_class->start();
        movie->setPaused(false);
        while(Database->getReconstructionState()==0){
            QCoreApplication::processEvents();
        }

        if(Database->getReconstructionState()==1){
            int vPort1 = 1;
            if(!viewer->updatePolygonMesh(*Database->m_Mesh, "triangles")){
                viewer->createViewPort(0.0, 0, 1.0, 1.0, vPort1);
                viewer->addPolygonMesh(*Database->m_Mesh, "triangles", vPort1);
            }
            viewer->resetCameraViewpoint();
            ui->qvtkWidget->update ();
            Database->setReconstructionState(0);
        }


        movie->setPaused(true);
        Database->setRecSettingsStatus(0);
    }

    if( ui->checkBox->isChecked() ) viewer->resetCamera ();

    ui->qvtkWidget->update ();

}


void MainWindow::on_stitchBtn_clicked()
{
    QPoint p = QCursor::pos();
    icp_settings* settingsPopup = new icp_settings(0, Database);
    settingsPopup->setWindowFlags(Qt::Popup);
    settingsPopup->move(p);
    settingsPopup->show();

    Database->setICPSettingsStatus(1);

    while(Database->getICPSettingsStatus()==1){
        QCoreApplication::processEvents();
    }

    if(Database->getICPSettingsStatus()==2){
        //ICP test::::::::

        icp_thread_class->start();
        movie->setPaused(false);
        while(Database->getIcpState()==0){
            QCoreApplication::processEvents();
        }

        if(Database->getIcpState()==1){
            Database->m_pointcloud_data.push_back(Database->m_cloud);
            viewer->updatePointCloud (Database->m_cloud, "cloud");
            if( ui->checkBox->isChecked() ) viewer->resetCamera ();
            ui->qvtkWidget->update ();
            Database->setIcpState(0);
        }

        updatePointcloudList();

        movie->setPaused(true);

        Database->setICPSettingsStatus(0);

    }

}

void MainWindow::on_captureSpeed_valueChanged(double arg1)
{
    Database->setCapturingSpeed(arg1);
}

//Slot function for connecting to the Kinect and register the pointcloud data coming from it:
void MainWindow::on_actionConnect_to_Kinect_triggered()
{

    //Containers for vectors of pointcloud:
    vector<PointCloudColorT::Ptr>  filtered_data;
    vector<PointCloudColorT::Ptr>  clean_data;

    //Start timer for frame capturing
    timer.start();

    // Retrieved Point Cloud Callback Function
    boost::mutex mutex;

    // Point Cloud
     PointCloudColorT::Ptr cloud2;

     //FIle names counter:
     int filenum=1;

     //Reset camera position:
    viewer->setCameraPosition( 0.0, 0.0, -2.5, 0.0, 0.0, 0.0 );


    boost::function<void( const pcl::PointCloud<PointTypeColor>::ConstPtr& )> function =
        [&cloud2, &mutex]( const pcl::PointCloud<PointTypeColor>::ConstPtr& ptr ){
            boost::mutex::scoped_lock lock( mutex );

            /* Point Cloud Processing */

            cloud2 = ptr->makeShared();

        };

    // Kinect2Grabber
    boost::shared_ptr<pcl::Grabber> grabber = boost::make_shared<pcl::Kinect2Grabber>();

    // Register Callback Function
    boost::signals2::connection connection = grabber->registerCallback( function );

    //Flag for switching between capturing state on or off
    if(!capturing){
        capturing=true;
    }else{
        capturing=false;
    }

    // Start Grabber
    grabber->start();

    //Data capturing loop, only valid if the capturing state is on
    while(capturing ){
        ui->qvtkWidget->update ();

        boost::mutex::scoped_try_lock lock( mutex );
        if( lock.owns_lock() && cloud2 ){
            // Update Point Cloud
            pcl::PointCloud<PointTypeColor>::Ptr cloud_filtered (new pcl::PointCloud<PointTypeColor>);

            // Create and perform the filtering by depth
            pcl::PassThrough<PointTypeColor> pass;
            pass.setInputCloud (cloud2);
            pass.setFilterFieldName ("x");
            pass.setFilterLimits (Database->getDepth_xLow(), Database->getDepth_xHigh());
            pass.filter (*cloud2);

            pass.setInputCloud (cloud2);
            pass.setFilterFieldName ("y");
            pass.setFilterLimits (Database->getDepth_yLow(), Database->getDepth_yHigh());
            pass.filter (*cloud2);

            pass.setInputCloud (cloud2);
            pass.setFilterFieldName ("z");
            pass.setFilterLimits (Database->getDepth_zLow(), Database->getDepth_zHigh());
            pass.setInputCloud (cloud2);
            pass.filter (*cloud_filtered);

            //If the registration of data is enabled and the time elapsed is greater than the desired one, save the data in a
            //vector and also in the system
            if (Database->getEnableCapture() && timer.elapsed()>= Database->getCapturingSpeed()*1000)
            {

                //Append current pointcloud to the general vector
                filtered_data.push_back(cloud_filtered);
                stringstream ss;
                //Generate filename to store the current pointcloud
                ss << ".\\frame-" << filenum << ".ply";
                string filename = ss.str();
                filenum++;
                std::cout<<filename<<std::endl;
                //Save current pointcloud in the harddrive
                pcl::io::savePLYFile(filename, *cloud_filtered);
                //Reset timer and start counting again
                timer.restart();
           }

            if( !viewer->updatePointCloud( cloud_filtered, "cloud" ) ){
                //Show the current pointcloud in the visualization window
                viewer->addPointCloud( cloud_filtered, "cloud" );
                viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "cloud");
            }
        }

        QCoreApplication::processEvents();
    }

    //Remove non defined points from the registred data
    for (int i = 1; i < filtered_data.size(); i++)
      {

          //remove NAN points from the cloud
          std::vector<int> indices;
          pcl::removeNaNFromPointCloud(*filtered_data[i],*filtered_data[i], indices);

          clean_data.push_back (filtered_data[i]);
      }

    //Store the clean data into the global vector of pointclouds
    //Database->m_pointcloud_data = clean_data;

    // Stop Grabber
    grabber->stop();

    // Disconnect Callback Function
    if( connection.connected() ){
        connection.disconnect();
    }
}

void MainWindow::on_actionStart_capture_toggled(bool arg1)
{
    Database->setEnableCapture(arg1);
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, position, "cloud");
    ui->qvtkWidget->update ();
}

void MainWindow::on_pointcloudList_doubleClicked(const QModelIndex &index)
{
    showPointcloud(index.row());
}

void MainWindow::on_ttConnect_toggled(bool checked)
{
    if(checked){
        Database->setTtConnect(true);
        ttable_thread_class->start();
        while(!Database->getTtConnected()) QCoreApplication::processEvents();
        ui->ttableLabel->setText("Turning table: CONNECTED!");
    }else{
        Database->setTtConnect(false);
        ttable_thread_class->start();
        while(Database->getTtConnected()) QCoreApplication::processEvents();
        ui->ttableLabel->setText("Turning table: Disconnected");
    }
}

void MainWindow::on_ttMove_toggled(bool checked)
{
    if(checked){
        Database->setTtRotate(true);
        ttable_thread_class->start();
    }else{
        Database->setTtRotate(false);
        ttable_thread_class->start();
    }
}

void MainWindow::on_tablePort_textChanged(const QString &arg1)
{
    Database->setTtSerialPort(arg1);
}

void MainWindow::on_deleteBtn_clicked()
{
    QModelIndexList indexes = ui->pointcloudList->selectionModel()->selectedIndexes();
    foreach(QModelIndex index, indexes)
    {
        Database->m_pointcloud_data.erase(Database->m_pointcloud_data.begin()+(index.row()));
    }
    updatePointcloudList();
}

void MainWindow::on_deleteAllBtn_clicked()
{
    Database->m_pointcloud_data.clear();
    updatePointcloudList();
}

void MainWindow::on_actionPointclouds_triggered()
{
    on_pointsBtn_clicked();
}

void MainWindow::on_pointsBtn_clicked()
{
    resetVtk();
}

void MainWindow::on_actionNew_triggered()
{
    Database->m_cloud.reset (new PointCloudT);
    resetVtk();
    Database->m_pointcloud_data.clear();
    updatePointcloudList();
    Database->m_Mesh.reset(new pcl::PolygonMesh);
}

void MainWindow::on_actionSave_triggered()
{
    //pcl::io::savePLYFile(filename, *cloud_filtered);
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    //viewer->
}
