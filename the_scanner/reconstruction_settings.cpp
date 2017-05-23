#include "reconstruction_settings.h"
#include "ui_reconstruction_settings.h"
#include <iostream>

using namespace std;

// Manipulatin ui

reconstruction_settings::reconstruction_settings(QWidget *parent, dataclass *thedatabase) :
    QWidget(parent),
    ui(new Ui::reconstruction_settings)
{
    ui->setupUi(this);

    Database=thedatabase;

    ui->normalConsistency->setChecked(Database->getNormal_consistency());
    ui->searchRadius->setValue(Database->getRadius_search());
    ui->densityAdjust->setValue(Database->getMu());
    ui->nearestNeighbors->setValue(Database->getMax_nearest_neighbor());
    ui->surfaceAngle->setValue((Database->getMax_surface_angle()*180)/M_PI);
    ui->minTriangleAngle->setValue((Database->getMin_angle()*180)/M_PI);
    ui->maxTriangleAngle->setValue((Database->getMax_angle()*180)/M_PI);
    ui->octreeDepth->setValue(Database->getOctree_depth());

}

reconstruction_settings::~reconstruction_settings()
{
    delete ui;
}

void reconstruction_settings::on_searchRadius_valueChanged(double arg1)
{
    Database->setRadius_search(arg1);

}

void reconstruction_settings::on_densityAdjust_valueChanged(double arg1)
{
    Database->setMu(arg1);
}

void reconstruction_settings::on_nearestNeighbors_valueChanged(int arg1)
{
    Database->setMax_nearest_neighbor(arg1);
}

void reconstruction_settings::on_surfaceAngle_valueChanged(int arg1)
{
    Database->setMax_surface_angle((arg1*M_PI)/180);
}

void reconstruction_settings::on_minTriangleAngle_valueChanged(int arg1)
{
    Database->setMin_angle((arg1*M_PI)/180);
}

void reconstruction_settings::on_maxTriangleAngle_valueChanged(int arg1)
{
    Database->setMax_angle((arg1*M_PI)/180);
}

void reconstruction_settings::on_normalConsistency_toggled(bool checked)
{
    Database->setNormal_consistency(checked);
}

void reconstruction_settings::closeEvent (QCloseEvent *event)
{
    if(Database->getRecSettingsStatus()==1){
        Database->setRecSettingsStatus(0);
        cout<<"Toolbox closed";
    }
}

void reconstruction_settings::on_greedyBtn_clicked()
{
    Database->setRecSettingsStatus(2);
    close();
}

void reconstruction_settings::on_poissonBtn_clicked()
{
    Database->setRecSettingsStatus(3);
    close();
}
