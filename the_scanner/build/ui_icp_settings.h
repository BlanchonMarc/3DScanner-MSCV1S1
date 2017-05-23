/********************************************************************************
** Form generated from reading UI file 'icp_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ICP_SETTINGS_H
#define UI_ICP_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_icp_settings
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *leafSize;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *numIterations;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *corrDistance;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *epsilon1;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *epsilon2;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *ransacThreshold;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QDoubleSpinBox *smoothingRadius;
    QPushButton *ICPBtn;

    void setupUi(QWidget *icp_settings)
    {
        if (icp_settings->objectName().isEmpty())
            icp_settings->setObjectName(QStringLiteral("icp_settings"));
        icp_settings->setWindowModality(Qt::WindowModal);
        icp_settings->resize(249, 456);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(icp_settings->sizePolicy().hasHeightForWidth());
        icp_settings->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(icp_settings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(icp_settings);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        label_7->setTextFormat(Qt::AutoText);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_7);


        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(icp_settings);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label->setWordWrap(true);

        horizontalLayout->addWidget(label);

        leafSize = new QDoubleSpinBox(widget_3);
        leafSize->setObjectName(QStringLiteral("leafSize"));
        leafSize->setDecimals(3);
        leafSize->setMinimum(0.01);
        leafSize->setMaximum(3);
        leafSize->setValue(0.8);

        horizontalLayout->addWidget(leafSize);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(icp_settings);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2->setWordWrap(true);

        horizontalLayout_2->addWidget(label_2);

        numIterations = new QSpinBox(widget_4);
        numIterations->setObjectName(QStringLiteral("numIterations"));

        horizontalLayout_2->addWidget(numIterations);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(icp_settings);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3->setWordWrap(true);

        horizontalLayout_3->addWidget(label_3);

        corrDistance = new QDoubleSpinBox(widget_5);
        corrDistance->setObjectName(QStringLiteral("corrDistance"));
        corrDistance->setDecimals(3);

        horizontalLayout_3->addWidget(corrDistance);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(icp_settings);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4->setWordWrap(true);

        horizontalLayout_4->addWidget(label_4);

        epsilon1 = new QDoubleSpinBox(widget_6);
        epsilon1->setObjectName(QStringLiteral("epsilon1"));

        horizontalLayout_4->addWidget(epsilon1);


        verticalLayout->addWidget(widget_6);

        widget_7 = new QWidget(icp_settings);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget_7);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5->setWordWrap(true);

        horizontalLayout_5->addWidget(label_5);

        epsilon2 = new QDoubleSpinBox(widget_7);
        epsilon2->setObjectName(QStringLiteral("epsilon2"));

        horizontalLayout_5->addWidget(epsilon2);


        verticalLayout->addWidget(widget_7);

        widget_8 = new QWidget(icp_settings);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        horizontalLayout_6 = new QHBoxLayout(widget_8);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(widget_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6->setWordWrap(true);

        horizontalLayout_6->addWidget(label_6);

        ransacThreshold = new QDoubleSpinBox(widget_8);
        ransacThreshold->setObjectName(QStringLiteral("ransacThreshold"));

        horizontalLayout_6->addWidget(ransacThreshold);


        verticalLayout->addWidget(widget_8);

        widget_2 = new QWidget(icp_settings);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_8 = new QHBoxLayout(widget_2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_8->setWordWrap(true);

        horizontalLayout_8->addWidget(label_8);

        smoothingRadius = new QDoubleSpinBox(widget_2);
        smoothingRadius->setObjectName(QStringLiteral("smoothingRadius"));

        horizontalLayout_8->addWidget(smoothingRadius);


        verticalLayout->addWidget(widget_2);

        ICPBtn = new QPushButton(icp_settings);
        ICPBtn->setObjectName(QStringLiteral("ICPBtn"));

        verticalLayout->addWidget(ICPBtn);


        retranslateUi(icp_settings);

        QMetaObject::connectSlotsByName(icp_settings);
    } // setupUi

    void retranslateUi(QWidget *icp_settings)
    {
        icp_settings->setWindowTitle(QApplication::translate("icp_settings", "ICP Settings", 0));
        label_7->setText(QApplication::translate("icp_settings", "ICP Stitching", 0));
        label->setText(QApplication::translate("icp_settings", "Downsampling grid leaf size:", 0));
        label_2->setText(QApplication::translate("icp_settings", "Number of iterations:", 0));
        label_3->setText(QApplication::translate("icp_settings", "Max. correspondance distance:", 0));
        label_4->setText(QApplication::translate("icp_settings", "Transformation Epsilon 1 (x10^-8):", 0));
        label_5->setText(QApplication::translate("icp_settings", "Transformation Epsilon 2 (x10^-8):", 0));
        label_6->setText(QApplication::translate("icp_settings", "RANSAC Outlier Rejection Threshold:", 0));
        label_8->setText(QApplication::translate("icp_settings", "Smoothing search radius:", 0));
        ICPBtn->setText(QApplication::translate("icp_settings", "Apply", 0));
    } // retranslateUi

};

namespace Ui {
    class icp_settings: public Ui_icp_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ICP_SETTINGS_H
