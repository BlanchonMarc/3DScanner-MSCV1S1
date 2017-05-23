/********************************************************************************
** Form generated from reading UI file 'reconstruction_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECONSTRUCTION_SETTINGS_H
#define UI_RECONSTRUCTION_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reconstruction_settings
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *normalConsistency;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *searchRadius;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *densityAdjust;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *nearestNeighbors;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *surfaceAngle;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *minTriangleAngle;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *maxTriangleAngle;
    QPushButton *greedyBtn;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_10;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpinBox *octreeDepth;
    QWidget *widget_11;
    QPushButton *poissonBtn;

    void setupUi(QWidget *reconstruction_settings)
    {
        if (reconstruction_settings->objectName().isEmpty())
            reconstruction_settings->setObjectName(QStringLiteral("reconstruction_settings"));
        reconstruction_settings->setWindowModality(Qt::WindowModal);
        reconstruction_settings->resize(249, 433);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(reconstruction_settings->sizePolicy().hasHeightForWidth());
        reconstruction_settings->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(reconstruction_settings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(reconstruction_settings);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        normalConsistency = new QCheckBox(widget);
        normalConsistency->setObjectName(QStringLiteral("normalConsistency"));

        verticalLayout_4->addWidget(normalConsistency, 0, Qt::AlignHCenter);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label->setWordWrap(true);

        horizontalLayout->addWidget(label);

        searchRadius = new QDoubleSpinBox(widget_3);
        searchRadius->setObjectName(QStringLiteral("searchRadius"));
        searchRadius->setMinimum(0.01);
        searchRadius->setMaximum(3);
        searchRadius->setValue(0.8);

        horizontalLayout->addWidget(searchRadius);


        verticalLayout_4->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2->setWordWrap(true);

        horizontalLayout_2->addWidget(label_2);

        densityAdjust = new QDoubleSpinBox(widget_4);
        densityAdjust->setObjectName(QStringLiteral("densityAdjust"));
        densityAdjust->setMaximum(50);
        densityAdjust->setValue(10);

        horizontalLayout_2->addWidget(densityAdjust);


        verticalLayout_4->addWidget(widget_4);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3->setWordWrap(true);

        horizontalLayout_3->addWidget(label_3);

        nearestNeighbors = new QSpinBox(widget_5);
        nearestNeighbors->setObjectName(QStringLiteral("nearestNeighbors"));
        nearestNeighbors->setMinimum(1);
        nearestNeighbors->setMaximum(200);
        nearestNeighbors->setValue(20);

        horizontalLayout_3->addWidget(nearestNeighbors);


        verticalLayout_4->addWidget(widget_5);

        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4->setWordWrap(true);

        horizontalLayout_4->addWidget(label_4);

        surfaceAngle = new QSpinBox(widget_6);
        surfaceAngle->setObjectName(QStringLiteral("surfaceAngle"));
        surfaceAngle->setMaximum(360);
        surfaceAngle->setValue(180);

        horizontalLayout_4->addWidget(surfaceAngle);


        verticalLayout_4->addWidget(widget_6);

        widget_7 = new QWidget(widget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget_7);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5->setWordWrap(true);

        horizontalLayout_5->addWidget(label_5);

        minTriangleAngle = new QSpinBox(widget_7);
        minTriangleAngle->setObjectName(QStringLiteral("minTriangleAngle"));
        minTriangleAngle->setMinimum(1);
        minTriangleAngle->setMaximum(180);
        minTriangleAngle->setValue(18);

        horizontalLayout_5->addWidget(minTriangleAngle);


        verticalLayout_4->addWidget(widget_7);

        widget_8 = new QWidget(widget);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        horizontalLayout_6 = new QHBoxLayout(widget_8);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(widget_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6->setWordWrap(true);

        horizontalLayout_6->addWidget(label_6);

        maxTriangleAngle = new QSpinBox(widget_8);
        maxTriangleAngle->setObjectName(QStringLiteral("maxTriangleAngle"));
        maxTriangleAngle->setMinimum(1);
        maxTriangleAngle->setMaximum(180);
        maxTriangleAngle->setValue(180);

        horizontalLayout_6->addWidget(maxTriangleAngle);


        verticalLayout_4->addWidget(widget_8);

        greedyBtn = new QPushButton(widget);
        greedyBtn->setObjectName(QStringLiteral("greedyBtn"));

        verticalLayout_4->addWidget(greedyBtn);


        verticalLayout_2->addWidget(widget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        widget_10 = new QWidget(widget_2);
        widget_10->setObjectName(QStringLiteral("widget_10"));

        verticalLayout_5->addWidget(widget_10);

        widget_9 = new QWidget(widget_2);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy1);
        horizontalLayout_7 = new QHBoxLayout(widget_9);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(widget_9);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_7);

        octreeDepth = new QSpinBox(widget_9);
        octreeDepth->setObjectName(QStringLiteral("octreeDepth"));
        octreeDepth->setMinimum(1);
        octreeDepth->setMaximum(14);
        octreeDepth->setValue(10);

        horizontalLayout_7->addWidget(octreeDepth);


        verticalLayout_5->addWidget(widget_9);

        widget_11 = new QWidget(widget_2);
        widget_11->setObjectName(QStringLiteral("widget_11"));

        verticalLayout_5->addWidget(widget_11);

        poissonBtn = new QPushButton(widget_2);
        poissonBtn->setObjectName(QStringLiteral("poissonBtn"));

        verticalLayout_5->addWidget(poissonBtn);


        verticalLayout_3->addWidget(widget_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(reconstruction_settings);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(reconstruction_settings);
    } // setupUi

    void retranslateUi(QWidget *reconstruction_settings)
    {
        reconstruction_settings->setWindowTitle(QApplication::translate("reconstruction_settings", "Reconstruction Settings", 0));
        normalConsistency->setText(QApplication::translate("reconstruction_settings", "Normal consistency", 0));
        label->setText(QApplication::translate("reconstruction_settings", "Search radius:", 0));
        label_2->setText(QApplication::translate("reconstruction_settings", "Density adjustment parameter (\316\274):", 0));
        label_3->setText(QApplication::translate("reconstruction_settings", "Max. nearest neighbors:", 0));
        label_4->setText(QApplication::translate("reconstruction_settings", "Max. surface angle (degrees):", 0));
        label_5->setText(QApplication::translate("reconstruction_settings", "Minimum angle for triangle:", 0));
        label_6->setText(QApplication::translate("reconstruction_settings", "Maximum angle for triangle:", 0));
        greedyBtn->setText(QApplication::translate("reconstruction_settings", "Apply", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("reconstruction_settings", "Greedy", 0));
        label_7->setText(QApplication::translate("reconstruction_settings", "Octree depth:", 0));
        poissonBtn->setText(QApplication::translate("reconstruction_settings", "Apply", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("reconstruction_settings", "Poisson", 0));
    } // retranslateUi

};

namespace Ui {
    class reconstruction_settings: public Ui_reconstruction_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECONSTRUCTION_SETTINGS_H
