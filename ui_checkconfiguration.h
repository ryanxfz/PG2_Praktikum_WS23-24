/********************************************************************************
** Form generated from reading UI file 'checkconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKCONFIGURATION_H
#define UI_CHECKCONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_checkConfiguration
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *overlapHotel;
    QCheckBox *overlapRental;
    QCheckBox *overlapTravel;
    QCheckBox *missingHotel;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *checkConfiguration)
    {
        if (checkConfiguration->objectName().isEmpty())
            checkConfiguration->setObjectName("checkConfiguration");
        checkConfiguration->resize(196, 146);
        widget = new QWidget(checkConfiguration);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 168, 121));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        overlapHotel = new QCheckBox(widget);
        overlapHotel->setObjectName("overlapHotel");

        verticalLayout->addWidget(overlapHotel);

        overlapRental = new QCheckBox(widget);
        overlapRental->setObjectName("overlapRental");

        verticalLayout->addWidget(overlapRental);

        overlapTravel = new QCheckBox(widget);
        overlapTravel->setObjectName("overlapTravel");

        verticalLayout->addWidget(overlapTravel);

        missingHotel = new QCheckBox(widget);
        missingHotel->setObjectName("missingHotel");

        verticalLayout->addWidget(missingHotel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        okButton = new QPushButton(widget);
        okButton->setObjectName("okButton");

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(checkConfiguration);

        QMetaObject::connectSlotsByName(checkConfiguration);
    } // setupUi

    void retranslateUi(QDialog *checkConfiguration)
    {
        checkConfiguration->setWindowTitle(QCoreApplication::translate("checkConfiguration", "Dialog", nullptr));
        overlapHotel->setText(QCoreApplication::translate("checkConfiguration", "Check Overlapping Hotel", nullptr));
        overlapRental->setText(QCoreApplication::translate("checkConfiguration", "Check Overlapping Rental", nullptr));
        overlapTravel->setText(QCoreApplication::translate("checkConfiguration", "Check Overlapping Travel", nullptr));
        missingHotel->setText(QCoreApplication::translate("checkConfiguration", "Check Missing Hotel", nullptr));
        okButton->setText(QCoreApplication::translate("checkConfiguration", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("checkConfiguration", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class checkConfiguration: public Ui_checkConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKCONFIGURATION_H
