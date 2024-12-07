/********************************************************************************
** Form generated from reading UI file 'buchungDetails.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUCHUNGDETAILS_H
#define UI_BUCHUNGDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout_3;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_13;
    QLineEdit *bookingId;
    QDoubleSpinBox *bookingPrice;
    QDateEdit *bookingFromDate;
    QDateEdit *bookingToDate;
    QTabWidget *detailsTab;
    QWidget *trainTab;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *abfahrtLabel;
    QLabel *ankunftLabel;
    QLabel *ankunftLabel_4;
    QLabel *uberLabel;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *trainFromDestination;
    QLineEdit *trainToDestination;
    QLineEdit *trainTicketType;
    QPlainTextEdit *trainConnectingStations;
    QWidget *hotelTab;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *abfahrtLabel_2;
    QLabel *ankunftLabel_2;
    QLabel *abfahrtLabel_4;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *townName;
    QLineEdit *hotelName;
    QLineEdit *hotelName_2;
    QWidget *flightTab;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *abfahrtLabel_3;
    QLabel *ankunftLabel_3;
    QLabel *uberLabel_2;
    QLabel *uberLabel_3;
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *flightFromDestination;
    QLineEdit *flightToDestination;
    QLineEdit *flightAirline;
    QLineEdit *flightAirline_2;
    QWidget *carTab;
    QWidget *layoutWidget_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_14;
    QWidget *layoutWidget_9;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *carPickupLocation;
    QLineEdit *carReturnLocation;
    QLineEdit *carCompany;
    QLineEdit *carCompany_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(60, 190, 211, 351));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 20, 206, 331));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
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


        formLayout_3->setLayout(0, QFormLayout::LabelRole, verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        bookingId = new QLineEdit(layoutWidget);
        bookingId->setObjectName("bookingId");

        verticalLayout_13->addWidget(bookingId);

        bookingPrice = new QDoubleSpinBox(layoutWidget);
        bookingPrice->setObjectName("bookingPrice");

        verticalLayout_13->addWidget(bookingPrice);

        bookingFromDate = new QDateEdit(layoutWidget);
        bookingFromDate->setObjectName("bookingFromDate");

        verticalLayout_13->addWidget(bookingFromDate);

        bookingToDate = new QDateEdit(layoutWidget);
        bookingToDate->setObjectName("bookingToDate");

        verticalLayout_13->addWidget(bookingToDate);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, verticalLayout_13);


        gridLayout->addLayout(formLayout_3, 0, 0, 1, 1);

        detailsTab = new QTabWidget(layoutWidget);
        detailsTab->setObjectName("detailsTab");
        trainTab = new QWidget();
        trainTab->setObjectName("trainTab");
        layoutWidget_2 = new QWidget(trainTab);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(0, 0, 71, 101));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        abfahrtLabel = new QLabel(layoutWidget_2);
        abfahrtLabel->setObjectName("abfahrtLabel");

        verticalLayout->addWidget(abfahrtLabel);

        ankunftLabel = new QLabel(layoutWidget_2);
        ankunftLabel->setObjectName("ankunftLabel");

        verticalLayout->addWidget(ankunftLabel);

        ankunftLabel_4 = new QLabel(layoutWidget_2);
        ankunftLabel_4->setObjectName("ankunftLabel_4");
        ankunftLabel_4->setMaximumSize(QSize(69, 21));

        verticalLayout->addWidget(ankunftLabel_4);

        uberLabel = new QLabel(layoutWidget_2);
        uberLabel->setObjectName("uberLabel");

        verticalLayout->addWidget(uberLabel);

        layoutWidget_3 = new QWidget(trainTab);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(70, 0, 101, 201));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        trainFromDestination = new QLineEdit(layoutWidget_3);
        trainFromDestination->setObjectName("trainFromDestination");
        trainFromDestination->setReadOnly(true);

        verticalLayout_2->addWidget(trainFromDestination);

        trainToDestination = new QLineEdit(layoutWidget_3);
        trainToDestination->setObjectName("trainToDestination");
        trainToDestination->setReadOnly(true);

        verticalLayout_2->addWidget(trainToDestination);

        trainTicketType = new QLineEdit(layoutWidget_3);
        trainTicketType->setObjectName("trainTicketType");
        trainTicketType->setReadOnly(true);

        verticalLayout_2->addWidget(trainTicketType);

        trainConnectingStations = new QPlainTextEdit(layoutWidget_3);
        trainConnectingStations->setObjectName("trainConnectingStations");
        trainConnectingStations->setReadOnly(true);

        verticalLayout_2->addWidget(trainConnectingStations);

        detailsTab->addTab(trainTab, QString());
        hotelTab = new QWidget();
        hotelTab->setObjectName("hotelTab");
        layoutWidget_4 = new QWidget(hotelTab);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(0, 0, 71, 71));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        abfahrtLabel_2 = new QLabel(layoutWidget_4);
        abfahrtLabel_2->setObjectName("abfahrtLabel_2");

        verticalLayout_3->addWidget(abfahrtLabel_2);

        ankunftLabel_2 = new QLabel(layoutWidget_4);
        ankunftLabel_2->setObjectName("ankunftLabel_2");
        ankunftLabel_2->setMaximumSize(QSize(69, 21));

        verticalLayout_3->addWidget(ankunftLabel_2);

        abfahrtLabel_4 = new QLabel(layoutWidget_4);
        abfahrtLabel_4->setObjectName("abfahrtLabel_4");

        verticalLayout_3->addWidget(abfahrtLabel_4);

        layoutWidget_5 = new QWidget(hotelTab);
        layoutWidget_5->setObjectName("layoutWidget_5");
        layoutWidget_5->setGeometry(QRect(70, 0, 76, 76));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        townName = new QLineEdit(layoutWidget_5);
        townName->setObjectName("townName");
        townName->setReadOnly(true);

        verticalLayout_5->addWidget(townName);

        hotelName = new QLineEdit(layoutWidget_5);
        hotelName->setObjectName("hotelName");
        hotelName->setReadOnly(true);

        verticalLayout_5->addWidget(hotelName);

        hotelName_2 = new QLineEdit(layoutWidget_5);
        hotelName_2->setObjectName("hotelName_2");
        hotelName_2->setReadOnly(true);

        verticalLayout_5->addWidget(hotelName_2);

        detailsTab->addTab(hotelTab, QString());
        flightTab = new QWidget();
        flightTab->setObjectName("flightTab");
        layoutWidget_6 = new QWidget(flightTab);
        layoutWidget_6->setObjectName("layoutWidget_6");
        layoutWidget_6->setGeometry(QRect(0, 0, 81, 101));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        abfahrtLabel_3 = new QLabel(layoutWidget_6);
        abfahrtLabel_3->setObjectName("abfahrtLabel_3");

        verticalLayout_4->addWidget(abfahrtLabel_3);

        ankunftLabel_3 = new QLabel(layoutWidget_6);
        ankunftLabel_3->setObjectName("ankunftLabel_3");

        verticalLayout_4->addWidget(ankunftLabel_3);

        uberLabel_2 = new QLabel(layoutWidget_6);
        uberLabel_2->setObjectName("uberLabel_2");

        verticalLayout_4->addWidget(uberLabel_2);

        uberLabel_3 = new QLabel(layoutWidget_6);
        uberLabel_3->setObjectName("uberLabel_3");

        verticalLayout_4->addWidget(uberLabel_3);

        layoutWidget_7 = new QWidget(flightTab);
        layoutWidget_7->setObjectName("layoutWidget_7");
        layoutWidget_7->setGeometry(QRect(80, 0, 76, 102));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        flightFromDestination = new QLineEdit(layoutWidget_7);
        flightFromDestination->setObjectName("flightFromDestination");
        flightFromDestination->setReadOnly(true);

        verticalLayout_6->addWidget(flightFromDestination);

        flightToDestination = new QLineEdit(layoutWidget_7);
        flightToDestination->setObjectName("flightToDestination");
        flightToDestination->setReadOnly(true);

        verticalLayout_6->addWidget(flightToDestination);

        flightAirline = new QLineEdit(layoutWidget_7);
        flightAirline->setObjectName("flightAirline");
        flightAirline->setReadOnly(true);

        verticalLayout_6->addWidget(flightAirline);

        flightAirline_2 = new QLineEdit(layoutWidget_7);
        flightAirline_2->setObjectName("flightAirline_2");
        flightAirline_2->setReadOnly(true);

        verticalLayout_6->addWidget(flightAirline_2);

        detailsTab->addTab(flightTab, QString());
        carTab = new QWidget();
        carTab->setObjectName("carTab");
        layoutWidget_8 = new QWidget(carTab);
        layoutWidget_8->setObjectName("layoutWidget_8");
        layoutWidget_8->setGeometry(QRect(0, 0, 65, 101));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_8);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_8);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(63, 16));

        verticalLayout_7->addWidget(label_4);

        label_6 = new QLabel(layoutWidget_8);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(63, 16));

        verticalLayout_7->addWidget(label_6);

        label_2 = new QLabel(layoutWidget_8);
        label_2->setObjectName("label_2");

        verticalLayout_7->addWidget(label_2);

        label_14 = new QLabel(layoutWidget_8);
        label_14->setObjectName("label_14");

        verticalLayout_7->addWidget(label_14);

        layoutWidget_9 = new QWidget(carTab);
        layoutWidget_9->setObjectName("layoutWidget_9");
        layoutWidget_9->setGeometry(QRect(90, 0, 76, 102));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_9);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        carPickupLocation = new QLineEdit(layoutWidget_9);
        carPickupLocation->setObjectName("carPickupLocation");
        carPickupLocation->setReadOnly(true);

        verticalLayout_8->addWidget(carPickupLocation);

        carReturnLocation = new QLineEdit(layoutWidget_9);
        carReturnLocation->setObjectName("carReturnLocation");
        carReturnLocation->setReadOnly(true);

        verticalLayout_8->addWidget(carReturnLocation);

        carCompany = new QLineEdit(layoutWidget_9);
        carCompany->setObjectName("carCompany");
        carCompany->setReadOnly(true);

        verticalLayout_8->addWidget(carCompany);

        carCompany_2 = new QLineEdit(layoutWidget_9);
        carCompany_2->setObjectName("carCompany_2");
        carCompany_2->setReadOnly(true);

        verticalLayout_8->addWidget(carCompany_2);

        detailsTab->addTab(carTab, QString());

        gridLayout->addWidget(detailsTab, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        detailsTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Buchung Details", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "von", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "bis", nullptr));
        abfahrtLabel->setText(QCoreApplication::translate("MainWindow", "Abfahrt in", nullptr));
        ankunftLabel->setText(QCoreApplication::translate("MainWindow", "Ankunft in", nullptr));
        ankunftLabel_4->setText(QCoreApplication::translate("MainWindow", "Ticket Type", nullptr));
        uberLabel->setText(QCoreApplication::translate("MainWindow", "Uber:", nullptr));
        detailsTab->setTabText(detailsTab->indexOf(trainTab), QCoreApplication::translate("MainWindow", "Train Booking", nullptr));
        abfahrtLabel_2->setText(QCoreApplication::translate("MainWindow", "Town", nullptr));
        ankunftLabel_2->setText(QCoreApplication::translate("MainWindow", "Hotel", nullptr));
        abfahrtLabel_4->setText(QCoreApplication::translate("MainWindow", "Room Type", nullptr));
        detailsTab->setTabText(detailsTab->indexOf(hotelTab), QCoreApplication::translate("MainWindow", "Hotel Booking", nullptr));
        abfahrtLabel_3->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
        ankunftLabel_3->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
        uberLabel_2->setText(QCoreApplication::translate("MainWindow", "Airline", nullptr));
        uberLabel_3->setText(QCoreApplication::translate("MainWindow", "Booking Class", nullptr));
        detailsTab->setTabText(detailsTab->indexOf(flightTab), QCoreApplication::translate("MainWindow", "Flight Booking", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Pickup Location", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Return Location", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Company", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Vehicle Class", nullptr));
        detailsTab->setTabText(detailsTab->indexOf(carTab), QCoreApplication::translate("MainWindow", "Car Rental", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUCHUNGDETAILS_H
