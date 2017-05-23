/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionStart_capture;
    QAction *actionConnect_to_Kinect;
    QAction *actionPointclouds;
    QAction *actionPerform_Stitching;
    QAction *action3D_Reconstruction;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QVTKWidget *qvtkWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuProcessing;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QToolButton *pointsBtn;
    QWidget *widget_2;
    QToolButton *stitchBtn;
    QWidget *widget_3;
    QToolButton *reconstructBtn;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *checkBox;
    QDockWidget *dockWidget_4;
    QWidget *dockWidgetContents_8;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget_6;
    QLabel *label;
    QLabel *label_3;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout;
    QDoubleSpinBox *z1_range;
    QLabel *label_11;
    QLabel *label_10;
    QDoubleSpinBox *x2_range;
    QLabel *label_12;
    QDoubleSpinBox *y1_range;
    QLabel *label_9;
    QDoubleSpinBox *x1_range;
    QLabel *label_7;
    QDoubleSpinBox *y2_range;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QDoubleSpinBox *z2_range;
    QLabel *label_8;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *ttableLabel;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *tablePort;
    QPushButton *ttConnect;
    QPushButton *ttMove;
    QPushButton *ttReset;
    QSpacerItem *horizontalSpacer_10;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_13;
    QDoubleSpinBox *captureSpeed;
    QSpacerItem *horizontalSpacer_2;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_4;
    QGridLayout *gridLayout_4;
    QPushButton *deleteBtn;
    QLabel *label_2;
    QPushButton *deleteAllBtn;
    QListView *pointcloudList;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(886, 740);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(176, 176, 176, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush3(QColor(95, 95, 95, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        MainWindow->setPalette(palette);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/1476926247_New.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/1476926622_Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/1476926747_floppy_disk_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionStart_capture = new QAction(MainWindow);
        actionStart_capture->setObjectName(QStringLiteral("actionStart_capture"));
        actionStart_capture->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/1476958047_player_record.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart_capture->setIcon(icon3);
        actionConnect_to_Kinect = new QAction(MainWindow);
        actionConnect_to_Kinect->setObjectName(QStringLiteral("actionConnect_to_Kinect"));
        actionConnect_to_Kinect->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/play-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect_to_Kinect->setIcon(icon4);
        actionPointclouds = new QAction(MainWindow);
        actionPointclouds->setObjectName(QStringLiteral("actionPointclouds"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/images/points.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPointclouds->setIcon(icon5);
        actionPerform_Stitching = new QAction(MainWindow);
        actionPerform_Stitching->setObjectName(QStringLiteral("actionPerform_Stitching"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/images/bunny_icp.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        actionPerform_Stitching->setIcon(icon6);
        action3D_Reconstruction = new QAction(MainWindow);
        action3D_Reconstruction->setObjectName(QStringLiteral("action3D_Reconstruction"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/images/cube.png"), QSize(), QIcon::Normal, QIcon::Off);
        action3D_Reconstruction->setIcon(icon7);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        qvtkWidget = new QVTKWidget(widget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(qvtkWidget);


        verticalLayout->addWidget(widget);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 886, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuProcessing = new QMenu(menuBar);
        menuProcessing->setObjectName(QStringLiteral("menuProcessing"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(132, 472));
        dockWidget->setBaseSize(QSize(0, 0));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_5 = new QWidget(dockWidgetContents);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        pointsBtn = new QToolButton(widget_5);
        pointsBtn->setObjectName(QStringLiteral("pointsBtn"));
        pointsBtn->setGeometry(QRect(10, 10, 81, 91));
        pointsBtn->setIcon(icon5);
        pointsBtn->setIconSize(QSize(60, 60));
        pointsBtn->setCheckable(false);
        pointsBtn->setPopupMode(QToolButton::DelayedPopup);
        pointsBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_3->addWidget(widget_5);

        widget_2 = new QWidget(dockWidgetContents);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        stitchBtn = new QToolButton(widget_2);
        stitchBtn->setObjectName(QStringLiteral("stitchBtn"));
        stitchBtn->setGeometry(QRect(10, 10, 81, 91));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stitchBtn->sizePolicy().hasHeightForWidth());
        stitchBtn->setSizePolicy(sizePolicy2);
        stitchBtn->setIcon(icon6);
        stitchBtn->setIconSize(QSize(60, 60));
        stitchBtn->setCheckable(false);
        stitchBtn->setPopupMode(QToolButton::DelayedPopup);
        stitchBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_3->addWidget(widget_2);

        widget_3 = new QWidget(dockWidgetContents);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        reconstructBtn = new QToolButton(widget_3);
        reconstructBtn->setObjectName(QStringLiteral("reconstructBtn"));
        reconstructBtn->setGeometry(QRect(10, 10, 81, 91));
        reconstructBtn->setIcon(icon7);
        reconstructBtn->setIconSize(QSize(60, 50));
        reconstructBtn->setCheckable(false);
        reconstructBtn->setPopupMode(QToolButton::DelayedPopup);
        reconstructBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(dockWidgetContents);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        checkBox = new QCheckBox(widget_4);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);

        verticalLayout_6->addWidget(checkBox);


        verticalLayout_3->addWidget(widget_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        dockWidget_4 = new QDockWidget(MainWindow);
        dockWidget_4->setObjectName(QStringLiteral("dockWidget_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dockWidget_4->sizePolicy().hasHeightForWidth());
        dockWidget_4->setSizePolicy(sizePolicy3);
        dockWidget_4->setMinimumSize(QSize(886, 185));
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName(QStringLiteral("dockWidgetContents_8"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents_8);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_2 = new QGroupBox(dockWidgetContents_8);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 0, 0, 1, 1);

        widget_6 = new QWidget(groupBox_2);
        widget_6->setObjectName(QStringLiteral("widget_6"));

        gridLayout_3->addWidget(widget_6, 4, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_3, 2, 1, 1, 1);

        horizontalSlider_2 = new QSlider(groupBox_2);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(horizontalSlider_2->sizePolicy().hasHeightForWidth());
        horizontalSlider_2->setSizePolicy(sizePolicy4);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_2, 3, 1, 1, 1);

        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        sizePolicy4.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy4);
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(10);
        horizontalSlider->setValue(3);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(1);

        gridLayout_3->addWidget(horizontalSlider, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 0, 2, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_5 = new QGroupBox(dockWidgetContents_8);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout = new QGridLayout(groupBox_5);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        z1_range = new QDoubleSpinBox(groupBox_5);
        z1_range->setObjectName(QStringLiteral("z1_range"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        z1_range->setPalette(palette1);
        z1_range->setMinimum(0.1);
        z1_range->setMaximum(2);
        z1_range->setSingleStep(0.1);
        z1_range->setValue(0.8);

        gridLayout->addWidget(z1_range, 0, 6, 1, 1);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 1, 1, 1, 1);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 0, 3, 1, 1);

        x2_range = new QDoubleSpinBox(groupBox_5);
        x2_range->setObjectName(QStringLiteral("x2_range"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        x2_range->setPalette(palette2);
        x2_range->setMaximum(5);
        x2_range->setSingleStep(0.1);
        x2_range->setValue(0.5);

        gridLayout->addWidget(x2_range, 1, 2, 1, 1);

        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setLayoutDirection(Qt::LeftToRight);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 0, 1, 1, 1);

        y1_range = new QDoubleSpinBox(groupBox_5);
        y1_range->setObjectName(QStringLiteral("y1_range"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        y1_range->setPalette(palette3);
        y1_range->setMinimum(-5);
        y1_range->setMaximum(0);
        y1_range->setSingleStep(0.1);
        y1_range->setValue(-1);

        gridLayout->addWidget(y1_range, 0, 4, 1, 1);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 1, 3, 1, 1);

        x1_range = new QDoubleSpinBox(groupBox_5);
        x1_range->setObjectName(QStringLiteral("x1_range"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        x1_range->setPalette(palette4);
        x1_range->setMinimum(-5);
        x1_range->setMaximum(0);
        x1_range->setSingleStep(0.1);
        x1_range->setValue(-0.5);

        gridLayout->addWidget(x1_range, 0, 2, 1, 1);

        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 0, 5, 1, 1);

        y2_range = new QDoubleSpinBox(groupBox_5);
        y2_range->setObjectName(QStringLiteral("y2_range"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        y2_range->setPalette(palette5);
        y2_range->setMaximum(5);
        y2_range->setSingleStep(0.1);
        y2_range->setValue(1);

        gridLayout->addWidget(y2_range, 1, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 7, 1, 1);

        z2_range = new QDoubleSpinBox(groupBox_5);
        z2_range->setObjectName(QStringLiteral("z2_range"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        z2_range->setPalette(palette6);
        z2_range->setMinimum(0.1);
        z2_range->setMaximum(2);
        z2_range->setSingleStep(0.1);
        z2_range->setValue(1.5);

        gridLayout->addWidget(z2_range, 1, 6, 1, 1);

        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 1, 5, 1, 1);


        horizontalLayout->addWidget(groupBox_5);

        groupBox = new QGroupBox(dockWidgetContents_8);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy5);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        ttableLabel = new QLabel(groupBox);
        ttableLabel->setObjectName(QStringLiteral("ttableLabel"));
        ttableLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_2->addWidget(ttableLabel, 1, 1, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 5, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        widget_7 = new QWidget(groupBox);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_2 = new QHBoxLayout(widget_7);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        tablePort = new QLineEdit(widget_7);
        tablePort->setObjectName(QStringLiteral("tablePort"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        tablePort->setPalette(palette7);
        tablePort->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(tablePort);

        ttConnect = new QPushButton(widget_7);
        ttConnect->setObjectName(QStringLiteral("ttConnect"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(ttConnect->sizePolicy().hasHeightForWidth());
        ttConnect->setSizePolicy(sizePolicy6);
        ttConnect->setCheckable(true);

        horizontalLayout_2->addWidget(ttConnect);

        ttMove = new QPushButton(widget_7);
        ttMove->setObjectName(QStringLiteral("ttMove"));
        sizePolicy6.setHeightForWidth(ttMove->sizePolicy().hasHeightForWidth());
        ttMove->setSizePolicy(sizePolicy6);
        ttMove->setCheckable(true);

        horizontalLayout_2->addWidget(ttMove);

        ttReset = new QPushButton(widget_7);
        ttReset->setObjectName(QStringLiteral("ttReset"));
        sizePolicy6.setHeightForWidth(ttReset->sizePolicy().hasHeightForWidth());
        ttReset->setSizePolicy(sizePolicy6);

        horizontalLayout_2->addWidget(ttReset);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);


        gridLayout_2->addWidget(widget_7, 2, 1, 1, 2);

        widget_8 = new QWidget(groupBox);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        horizontalLayout_3 = new QHBoxLayout(widget_8);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_13 = new QLabel(widget_8);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy5.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy5);
        label_13->setLayoutDirection(Qt::LeftToRight);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_13);

        captureSpeed = new QDoubleSpinBox(widget_8);
        captureSpeed->setObjectName(QStringLiteral("captureSpeed"));
        sizePolicy6.setHeightForWidth(captureSpeed->sizePolicy().hasHeightForWidth());
        captureSpeed->setSizePolicy(sizePolicy6);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        captureSpeed->setPalette(palette8);
        captureSpeed->setMinimum(0.5);
        captureSpeed->setMaximum(10);
        captureSpeed->setSingleStep(0.1);
        captureSpeed->setValue(2);

        horizontalLayout_3->addWidget(captureSpeed);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout_2->addWidget(widget_8, 0, 1, 1, 2);


        horizontalLayout->addWidget(groupBox);

        dockWidget_4->setWidget(dockWidgetContents_8);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_4);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(dockWidget_2->sizePolicy().hasHeightForWidth());
        dockWidget_2->setSizePolicy(sizePolicy7);
        dockWidget_2->setMinimumSize(QSize(242, 229));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        gridLayout_4 = new QGridLayout(dockWidgetContents_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        deleteBtn = new QPushButton(dockWidgetContents_4);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        sizePolicy4.setHeightForWidth(deleteBtn->sizePolicy().hasHeightForWidth());
        deleteBtn->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(deleteBtn, 2, 0, 1, 1);

        label_2 = new QLabel(dockWidgetContents_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        deleteAllBtn = new QPushButton(dockWidgetContents_4);
        deleteAllBtn->setObjectName(QStringLiteral("deleteAllBtn"));
        sizePolicy4.setHeightForWidth(deleteAllBtn->sizePolicy().hasHeightForWidth());
        deleteAllBtn->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(deleteAllBtn, 2, 1, 1, 1);

        pointcloudList = new QListView(dockWidgetContents_4);
        pointcloudList->setObjectName(QStringLiteral("pointcloudList"));
        pointcloudList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        pointcloudList->setSelectionMode(QAbstractItemView::SingleSelection);
        pointcloudList->setViewMode(QListView::ListMode);

        gridLayout_4->addWidget(pointcloudList, 1, 0, 1, 2);

        dockWidget_2->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_2);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuProcessing->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionConnect_to_Kinect);
        menuFile->addAction(actionStart_capture);
        menuProcessing->addAction(actionPointclouds);
        menuProcessing->addAction(actionPerform_Stitching);
        menuProcessing->addAction(action3D_Reconstruction);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionConnect_to_Kinect);
        mainToolBar->addAction(actionStart_capture);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "3D Scanner", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "Create new model", 0));
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open external model", 0));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save current model", 0));
#endif // QT_NO_TOOLTIP
        actionStart_capture->setText(QApplication::translate("MainWindow", "Start capture", 0));
#ifndef QT_NO_TOOLTIP
        actionStart_capture->setToolTip(QApplication::translate("MainWindow", "Save data from Kinect", 0));
#endif // QT_NO_TOOLTIP
        actionConnect_to_Kinect->setText(QApplication::translate("MainWindow", "Connect to Kinect", 0));
#ifndef QT_NO_TOOLTIP
        actionConnect_to_Kinect->setToolTip(QApplication::translate("MainWindow", "Connect to Kinnect", 0));
#endif // QT_NO_TOOLTIP
        actionPointclouds->setText(QApplication::translate("MainWindow", "View Pointclouds", 0));
#ifndef QT_NO_TOOLTIP
        actionPointclouds->setToolTip(QApplication::translate("MainWindow", "View list of pointclouds", 0));
#endif // QT_NO_TOOLTIP
        actionPerform_Stitching->setText(QApplication::translate("MainWindow", "Perform Stitching", 0));
        action3D_Reconstruction->setText(QApplication::translate("MainWindow", "3D Reconstruction", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuProcessing->setTitle(QApplication::translate("MainWindow", "Actions", 0));
        pointsBtn->setText(QApplication::translate("MainWindow", "Pointclouds", 0));
        stitchBtn->setText(QApplication::translate("MainWindow", "Stitch", 0));
        reconstructBtn->setText(QApplication::translate("MainWindow", "3D Reconstruct", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Auto Focus", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Visualization", 0));
        label->setText(QApplication::translate("MainWindow", "Point Size", 0));
        label_3->setText(QApplication::translate("MainWindow", "Point color", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Depth range", 0));
        label_11->setText(QApplication::translate("MainWindow", "X2:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Y1:", 0));
        label_12->setText(QApplication::translate("MainWindow", "X1:", 0));
        label_9->setText(QApplication::translate("MainWindow", "Y2:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Z1:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Z2:", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Capturing control", 0));
        ttableLabel->setText(QApplication::translate("MainWindow", "Turning table: Disconnected", 0));
        tablePort->setText(QApplication::translate("MainWindow", "COM3", 0));
        ttConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        ttMove->setText(QApplication::translate("MainWindow", ">", 0));
        ttReset->setText(QApplication::translate("MainWindow", "Reset", 0));
        label_13->setText(QApplication::translate("MainWindow", "Capturing speed (sec):", 0));
        deleteBtn->setText(QApplication::translate("MainWindow", "Delete", 0));
        label_2->setText(QApplication::translate("MainWindow", "List of pointclouds:", 0));
        deleteAllBtn->setText(QApplication::translate("MainWindow", "Delete all", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
