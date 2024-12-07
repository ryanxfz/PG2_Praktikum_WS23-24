/********************************************************************************
** Form generated from reading UI file 'bookingdetails.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINGDETAILS_H
#define UI_BOOKINGDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookingDetails
{
public:
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_4;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QFormLayout *formLayout_3;
    QDoubleSpinBox *bookingPrice;
    QDateEdit *bookingFromDate;
    QDateEdit *bookingToDate;
    QLineEdit *bookingId;
    QTabWidget *detailsTab;
    QWidget *trainTab;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLabel *abfahrtLabel;
    QLabel *label;
    QLabel *ankunftLabel;
    QLabel *label_3;
    QLabel *ankunftLabel_4;
    QLabel *uberLabel;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_2;
    QLineEdit *trainTicketType;
    QPlainTextEdit *trainConnectingStations;
    QLineEdit *trainAnkunftTime;
    QLineEdit *trainToDestination;
    QLineEdit *trainAbfahrtTime;
    QLineEdit *trainFromDestination;
    QWidget *hotelTab;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *abfahrtLabel_2;
    QLabel *ankunftLabel_2;
    QLabel *abfahrtLabel_4;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *townName;
    QLineEdit *hotelName;
    QLineEdit *hotelRoomType;
    QWidget *flightTab;
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_4;
    QLabel *abfahrtLabel_3;
    QLabel *label_5;
    QLabel *ankunftLabel_3;
    QLabel *label_7;
    QLabel *uberLabel_2;
    QLabel *uberLabel_3;
    QWidget *layoutWidget_8;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *flightFromDestination;
    QLineEdit *flightFromAirport;
    QLineEdit *flightToDestination;
    QLineEdit *flightToAirport;
    QLineEdit *flightAirline;
    QLineEdit *flightBookingClass;
    QWidget *carTab;
    QWidget *layoutWidget_9;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_14;
    QWidget *layoutWidget_10;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *carPickupLocation;
    QLineEdit *carReturnLocation;
    QLineEdit *carCompany;
    QLineEdit *carVehicleClass;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *bookingDetails)
    {
        if (bookingDetails->objectName().isEmpty())
            bookingDetails->setObjectName("bookingDetails");
        bookingDetails->resize(251, 444);
        groupBox_3 = new QGroupBox(bookingDetails);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 0, 211, 411));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 20, 203, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName("label_15");

        verticalLayout_12->addWidget(label_15);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName("label_16");
        label_16->setMaximumSize(QSize(39, 22));

        verticalLayout_12->addWidget(label_16);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName("label_17");

        verticalLayout_12->addWidget(label_17);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName("label_18");

        verticalLayout_12->addWidget(label_18);


        formLayout_4->setLayout(0, QFormLayout::LabelRole, verticalLayout_12);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        bookingPrice = new QDoubleSpinBox(layoutWidget);
        bookingPrice->setObjectName("bookingPrice");
        bookingPrice->setMaximum(99999999.000000000000000);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, bookingPrice);

        bookingFromDate = new QDateEdit(layoutWidget);
        bookingFromDate->setObjectName("bookingFromDate");

        formLayout_3->setWidget(2, QFormLayout::LabelRole, bookingFromDate);

        bookingToDate = new QDateEdit(layoutWidget);
        bookingToDate->setObjectName("bookingToDate");

        formLayout_3->setWidget(3, QFormLayout::LabelRole, bookingToDate);

        bookingId = new QLineEdit(layoutWidget);
        bookingId->setObjectName("bookingId");
        bookingId->setMaximumSize(QSize(161, 22));

        formLayout_3->setWidget(0, QFormLayout::SpanningRole, bookingId);


        formLayout_4->setLayout(0, QFormLayout::FieldRole, formLayout_3);


        verticalLayout->addLayout(formLayout_4);

        detailsTab = new QTabWidget(layoutWidget);
        detailsTab->setObjectName("detailsTab");
        detailsTab->setMinimumSize(QSize(201, 284));
        detailsTab->setMaximumSize(QSize(201, 291));
        trainTab = new QWidget();
        trainTab->setObjectName("trainTab");
        layoutWidget1 = new QWidget(trainTab);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 1, 60, 161));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        abfahrtLabel = new QLabel(layoutWidget1);
        abfahrtLabel->setObjectName("abfahrtLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, abfahrtLabel);

        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        ankunftLabel = new QLabel(layoutWidget1);
        ankunftLabel->setObjectName("ankunftLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, ankunftLabel);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(61, 16));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        ankunftLabel_4 = new QLabel(layoutWidget1);
        ankunftLabel_4->setObjectName("ankunftLabel_4");
        ankunftLabel_4->setMaximumSize(QSize(69, 21));

        formLayout->setWidget(4, QFormLayout::LabelRole, ankunftLabel_4);

        uberLabel = new QLabel(layoutWidget1);
        uberLabel->setObjectName("uberLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, uberLabel);

        layoutWidget2 = new QWidget(trainTab);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(60, 2, 141, 251));
        formLayout_2 = new QFormLayout(layoutWidget2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        trainTicketType = new QLineEdit(layoutWidget2);
        trainTicketType->setObjectName("trainTicketType");
        trainTicketType->setReadOnly(false);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, trainTicketType);

        trainConnectingStations = new QPlainTextEdit(layoutWidget2);
        trainConnectingStations->setObjectName("trainConnectingStations");
        trainConnectingStations->setMaximumSize(QSize(121, 101));
        trainConnectingStations->setReadOnly(true);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, trainConnectingStations);

        trainAnkunftTime = new QLineEdit(layoutWidget2);
        trainAnkunftTime->setObjectName("trainAnkunftTime");
        trainAnkunftTime->setReadOnly(false);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, trainAnkunftTime);

        trainToDestination = new QLineEdit(layoutWidget2);
        trainToDestination->setObjectName("trainToDestination");
        trainToDestination->setReadOnly(false);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, trainToDestination);

        trainAbfahrtTime = new QLineEdit(layoutWidget2);
        trainAbfahrtTime->setObjectName("trainAbfahrtTime");
        trainAbfahrtTime->setReadOnly(false);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, trainAbfahrtTime);

        trainFromDestination = new QLineEdit(layoutWidget2);
        trainFromDestination->setObjectName("trainFromDestination");
        trainFromDestination->setReadOnly(false);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, trainFromDestination);

        detailsTab->addTab(trainTab, QString());
        hotelTab = new QWidget();
        hotelTab->setObjectName("hotelTab");
        layoutWidget_5 = new QWidget(hotelTab);
        layoutWidget_5->setObjectName("layoutWidget_5");
        layoutWidget_5->setGeometry(QRect(0, 0, 71, 71));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        abfahrtLabel_2 = new QLabel(layoutWidget_5);
        abfahrtLabel_2->setObjectName("abfahrtLabel_2");

        verticalLayout_3->addWidget(abfahrtLabel_2);

        ankunftLabel_2 = new QLabel(layoutWidget_5);
        ankunftLabel_2->setObjectName("ankunftLabel_2");
        ankunftLabel_2->setMaximumSize(QSize(69, 21));

        verticalLayout_3->addWidget(ankunftLabel_2);

        abfahrtLabel_4 = new QLabel(layoutWidget_5);
        abfahrtLabel_4->setObjectName("abfahrtLabel_4");

        verticalLayout_3->addWidget(abfahrtLabel_4);

        layoutWidget_6 = new QWidget(hotelTab);
        layoutWidget_6->setObjectName("layoutWidget_6");
        layoutWidget_6->setGeometry(QRect(70, 0, 121, 76));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        townName = new QLineEdit(layoutWidget_6);
        townName->setObjectName("townName");
        townName->setReadOnly(false);

        verticalLayout_5->addWidget(townName);

        hotelName = new QLineEdit(layoutWidget_6);
        hotelName->setObjectName("hotelName");
        hotelName->setReadOnly(false);

        verticalLayout_5->addWidget(hotelName);

        hotelRoomType = new QLineEdit(layoutWidget_6);
        hotelRoomType->setObjectName("hotelRoomType");
        hotelRoomType->setReadOnly(false);

        verticalLayout_5->addWidget(hotelRoomType);

        detailsTab->addTab(hotelTab, QString());
        flightTab = new QWidget();
        flightTab->setObjectName("flightTab");
        layoutWidget_7 = new QWidget(flightTab);
        layoutWidget_7->setObjectName("layoutWidget_7");
        layoutWidget_7->setGeometry(QRect(0, 0, 71, 151));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        abfahrtLabel_3 = new QLabel(layoutWidget_7);
        abfahrtLabel_3->setObjectName("abfahrtLabel_3");

        verticalLayout_4->addWidget(abfahrtLabel_3);

        label_5 = new QLabel(layoutWidget_7);
        label_5->setObjectName("label_5");

        verticalLayout_4->addWidget(label_5);

        ankunftLabel_3 = new QLabel(layoutWidget_7);
        ankunftLabel_3->setObjectName("ankunftLabel_3");

        verticalLayout_4->addWidget(ankunftLabel_3);

        label_7 = new QLabel(layoutWidget_7);
        label_7->setObjectName("label_7");

        verticalLayout_4->addWidget(label_7);

        uberLabel_2 = new QLabel(layoutWidget_7);
        uberLabel_2->setObjectName("uberLabel_2");

        verticalLayout_4->addWidget(uberLabel_2);

        uberLabel_3 = new QLabel(layoutWidget_7);
        uberLabel_3->setObjectName("uberLabel_3");

        verticalLayout_4->addWidget(uberLabel_3);

        layoutWidget_8 = new QWidget(flightTab);
        layoutWidget_8->setObjectName("layoutWidget_8");
        layoutWidget_8->setGeometry(QRect(70, 0, 121, 154));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_8);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        flightFromDestination = new QLineEdit(layoutWidget_8);
        flightFromDestination->setObjectName("flightFromDestination");
        flightFromDestination->setReadOnly(false);

        verticalLayout_6->addWidget(flightFromDestination);

        flightFromAirport = new QLineEdit(layoutWidget_8);
        flightFromAirport->setObjectName("flightFromAirport");
        flightFromAirport->setReadOnly(true);

        verticalLayout_6->addWidget(flightFromAirport);

        flightToDestination = new QLineEdit(layoutWidget_8);
        flightToDestination->setObjectName("flightToDestination");
        flightToDestination->setReadOnly(false);

        verticalLayout_6->addWidget(flightToDestination);

        flightToAirport = new QLineEdit(layoutWidget_8);
        flightToAirport->setObjectName("flightToAirport");
        flightToAirport->setReadOnly(true);

        verticalLayout_6->addWidget(flightToAirport);

        flightAirline = new QLineEdit(layoutWidget_8);
        flightAirline->setObjectName("flightAirline");
        flightAirline->setReadOnly(false);

        verticalLayout_6->addWidget(flightAirline);

        flightBookingClass = new QLineEdit(layoutWidget_8);
        flightBookingClass->setObjectName("flightBookingClass");
        flightBookingClass->setReadOnly(false);

        verticalLayout_6->addWidget(flightBookingClass);

        detailsTab->addTab(flightTab, QString());
        carTab = new QWidget();
        carTab->setObjectName("carTab");
        layoutWidget_9 = new QWidget(carTab);
        layoutWidget_9->setObjectName("layoutWidget_9");
        layoutWidget_9->setGeometry(QRect(0, 0, 65, 101));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_9);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_9);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(63, 16));

        verticalLayout_7->addWidget(label_4);

        label_6 = new QLabel(layoutWidget_9);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(63, 16));

        verticalLayout_7->addWidget(label_6);

        label_2 = new QLabel(layoutWidget_9);
        label_2->setObjectName("label_2");

        verticalLayout_7->addWidget(label_2);

        label_14 = new QLabel(layoutWidget_9);
        label_14->setObjectName("label_14");

        verticalLayout_7->addWidget(label_14);

        layoutWidget_10 = new QWidget(carTab);
        layoutWidget_10->setObjectName("layoutWidget_10");
        layoutWidget_10->setGeometry(QRect(75, 0, 121, 102));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_10);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        carPickupLocation = new QLineEdit(layoutWidget_10);
        carPickupLocation->setObjectName("carPickupLocation");
        carPickupLocation->setReadOnly(false);

        verticalLayout_8->addWidget(carPickupLocation);

        carReturnLocation = new QLineEdit(layoutWidget_10);
        carReturnLocation->setObjectName("carReturnLocation");
        carReturnLocation->setReadOnly(false);

        verticalLayout_8->addWidget(carReturnLocation);

        carCompany = new QLineEdit(layoutWidget_10);
        carCompany->setObjectName("carCompany");
        carCompany->setReadOnly(false);

        verticalLayout_8->addWidget(carCompany);

        carVehicleClass = new QLineEdit(layoutWidget_10);
        carVehicleClass->setObjectName("carVehicleClass");
        carVehicleClass->setReadOnly(false);

        verticalLayout_8->addWidget(carVehicleClass);

        detailsTab->addTab(carTab, QString());

        verticalLayout->addWidget(detailsTab);

        saveButton = new QPushButton(bookingDetails);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(10, 420, 80, 18));
        cancelButton = new QPushButton(bookingDetails);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(140, 420, 80, 18));

        retranslateUi(bookingDetails);

        detailsTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(bookingDetails);
    } // setupUi

    void retranslateUi(QDialog *bookingDetails)
    {
        bookingDetails->setWindowTitle(QCoreApplication::translate("bookingDetails", "Dialog", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("bookingDetails", "Buchung Details", nullptr));
        label_15->setText(QCoreApplication::translate("bookingDetails", "ID", nullptr));
        label_16->setText(QCoreApplication::translate("bookingDetails", "Preis", nullptr));
        label_17->setText(QCoreApplication::translate("bookingDetails", "von", nullptr));
        label_18->setText(QCoreApplication::translate("bookingDetails", "bis", nullptr));
        abfahrtLabel->setText(QCoreApplication::translate("bookingDetails", "Abfahrt in", nullptr));
        label->setText(QCoreApplication::translate("bookingDetails", "Abfahrt Time", nullptr));
        ankunftLabel->setText(QCoreApplication::translate("bookingDetails", "Ankunft in", nullptr));
        label_3->setText(QCoreApplication::translate("bookingDetails", "Ankunft Time", nullptr));
        ankunftLabel_4->setText(QCoreApplication::translate("bookingDetails", "Ticket Type", nullptr));
        uberLabel->setText(QCoreApplication::translate("bookingDetails", "Uber:", nullptr));
        detailsTab->setTabText(detailsTab->indexOf(trainTab), QCoreApplication::translate("bookingDetails", "Train Booking", nullptr));
        abfahrtLabel_2->setText(QCoreApplication::translate("bookingDetails", "Town", nullptr));
        ankunftLabel_2->setText(QCoreApplication::translate("bookingDetails", "Hotel", nullptr));
        abfahrtLabel_4->setText(QCoreApplication::translate("bookingDetails", "Room Type", nullptr));
        detailsTab->setTabText(detailsTab->indexOf(hotelTab), QCoreApplication::translate("bookingDetails", "Hotel Booking", nullptr));
        abfahrtLabel_3->setText(QCoreApplication::translate("bookingDetails", "From", nullptr));
        label_5->setText(QString());
        ankunftLabel_3->setText(QCoreApplication::translate("bookingDetails", "To", nullptr));
        label_7->setText(QString());
        uberLabel_2->setText(QCoreApplication::translate("bookingDetails", "Airline", nullptr));
        uberLabel_3->setText(QCoreApplication::translate("bookingDetails", "Booking Class", nullptr));
        detailsTab->setTabText(detailsTab->indexOf(flightTab), QCoreApplication::translate("bookingDetails", "Flight Booking", nullptr));
        label_4->setText(QCoreApplication::translate("bookingDetails", "Pickup Location", nullptr));
        label_6->setText(QCoreApplication::translate("bookingDetails", "Return Location", nullptr));
        label_2->setText(QCoreApplication::translate("bookingDetails", "Company", nullptr));
        label_14->setText(QCoreApplication::translate("bookingDetails", "Vehicle Class", nullptr));
        detailsTab->setTabText(detailsTab->indexOf(carTab), QCoreApplication::translate("bookingDetails", "Car Rental", nullptr));
        saveButton->setText(QCoreApplication::translate("bookingDetails", "Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("bookingDetails", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookingDetails: public Ui_bookingDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINGDETAILS_H
