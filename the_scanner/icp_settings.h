#ifndef ICP_SETTINGS_H
#define ICP_SETTINGS_H

#include <QWidget>
#include "dataclass.h"

namespace Ui {
class icp_settings;
}

class icp_settings : public QWidget
{
    Q_OBJECT

public://desctructor and constructor of the class
    explicit icp_settings(QWidget *parent = 0, dataclass *thedatabase = new dataclass());
    ~icp_settings();

protected: // Interactions declared in protected to avoid miss understanding
    void closeEvent(QCloseEvent *event);
private slots:
    void on_leafSize_valueChanged(double arg1);

    void on_numIterations_valueChanged(int arg1);

    void on_corrDistance_valueChanged(double arg1);

    void on_epsilon1_valueChanged(double arg1);

    void on_epsilon2_valueChanged(double arg1);

    void on_ransacThreshold_valueChanged(double arg1);

    void on_smoothingRadius_valueChanged(double arg1);

    void on_ICPBtn_clicked();

private: // Members
    Ui::icp_settings *ui;
    dataclass *Database;
};

#endif // ICP_SETTINGS_H
