#ifndef RECONSTRUCTION_SETTINGS_H
#define RECONSTRUCTION_SETTINGS_H

#include <QWidget>
#include "dataclass.h"

namespace Ui {
class reconstruction_settings;
}

class reconstruction_settings : public QWidget
{
    Q_OBJECT

public:

    //Constructor:
    explicit reconstruction_settings(QWidget *parent = 0, dataclass *thedatabase = new dataclass());

    //Destructor:
    ~reconstruction_settings();

protected:

    //
    void closeEvent (QCloseEvent *event);

private slots:
  // Slots connected to the ui
    void on_searchRadius_valueChanged(double arg1);

    void on_densityAdjust_valueChanged(double arg1);

    void on_nearestNeighbors_valueChanged(int arg1);

    void on_surfaceAngle_valueChanged(int arg1);

    void on_minTriangleAngle_valueChanged(int arg1);

    void on_maxTriangleAngle_valueChanged(int arg1);

    void on_normalConsistency_toggled(bool checked);

    void on_greedyBtn_clicked();

    void on_poissonBtn_clicked();

private:
    Ui::reconstruction_settings *ui;
    dataclass *Database;
};

#endif // RECONSTRUCTION_SETTINGS_H
