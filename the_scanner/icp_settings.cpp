#include "icp_settings.h"
#include "ui_icp_settings.h"
//constructor
icp_settings::icp_settings(QWidget *parent, dataclass *thedatabase) :
    QWidget(parent),
    ui(new Ui::icp_settings)
{
    ui->setupUi(this);
    //Copy of the database, possible because of the light weight of the object
    Database=thedatabase;
    //Set gui values
    ui->leafSize->setValue(Database->getDownsampling_gridLeafSize());
    ui->numIterations->setValue(Database->getIcp_iterartions());
    ui->corrDistance->setValue(Database->getIcp_MaxCorrespondenceDistance());
    ui->epsilon1->setValue(Database->getIcp_TransformationEpsilon()*1e8);
    ui->epsilon2->setValue(Database->getIcp_TransformationEpsilon2()*1e8);
    ui->ransacThreshold->setValue(Database->getIcp_RANSACOutlierRejectionThreshold());
    ui->smoothingRadius->setValue(Database->getSmoothing_mls_SearchRadius());
}
//destructor
icp_settings::~icp_settings()
{
    delete ui;
}
//Interactions
void icp_settings::on_leafSize_valueChanged(double arg1)
{
    Database->setDownsampling_gridLeafSize(arg1);
}

void icp_settings::on_numIterations_valueChanged(int arg1)
{
    Database->setIcp_iterartions(arg1);
}

void icp_settings::on_corrDistance_valueChanged(double arg1)
{
    Database->setIcp_MaxCorrespondenceDistance(arg1);
}

void icp_settings::on_epsilon1_valueChanged(double arg1)
{
    Database->setIcp_TransformationEpsilon(arg1*1e-8);
}

void icp_settings::on_epsilon2_valueChanged(double arg1)
{
    Database->setIcp_TransformationEpsilon2(arg1*1e-8);
}

void icp_settings::on_ransacThreshold_valueChanged(double arg1)
{
    Database->setIcp_RANSACOutlierRejectionThreshold(arg1);
}

void icp_settings::on_smoothingRadius_valueChanged(double arg1)
{
    Database->setSmoothing_mls_SearchRadius(arg1);
}

void icp_settings::closeEvent (QCloseEvent *event)
{
    if(Database->getICPSettingsStatus()==1){
        Database->setICPSettingsStatus(0);
    }
}

void icp_settings::on_ICPBtn_clicked()
{
    Database->setICPSettingsStatus(2);
    close();
}
