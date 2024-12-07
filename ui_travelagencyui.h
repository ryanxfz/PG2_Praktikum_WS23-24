/********************************************************************************
** Form generated from reading UI file 'travelagencyui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELAGENCYUI_H
#define UI_TRAVELAGENCYUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TravelAgencyUI
{
public:
    QAction *actionEinlesen;
    QAction *actionsearch;
    QAction *actionIata_Codes;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_10;
    QSplitter *splitter;
    QLabel *label_8;
    QLineEdit *kundeID;
    QSplitter *splitter_3;
    QLabel *label_9;
    QLineEdit *kundeVorname;
    QSplitter *splitter_4;
    QLabel *label_11;
    QLineEdit *kundeNachname;
    QFormLayout *formLayout_2;
    QLabel *label_10;
    QTableWidget *reiseTable;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_11;
    QSplitter *splitter_2;
    QLabel *label_12;
    QLineEdit *travelIdui;
    QFormLayout *formLayout;
    QLabel *label_13;
    QTableWidget *buchungTable;
    QPushButton *pushButton;
    QPushButton *checkButton;
    QPushButton *configurationButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menukunde;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TravelAgencyUI)
    {
        if (TravelAgencyUI->objectName().isEmpty())
            TravelAgencyUI->setObjectName("TravelAgencyUI");
        TravelAgencyUI->resize(438, 653);
        actionEinlesen = new QAction(TravelAgencyUI);
        actionEinlesen->setObjectName("actionEinlesen");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("fileIcon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionEinlesen->setIcon(icon);
        actionsearch = new QAction(TravelAgencyUI);
        actionsearch->setObjectName("actionsearch");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/bookingIcons/searchIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsearch->setIcon(icon1);
        actionIata_Codes = new QAction(TravelAgencyUI);
        actionIata_Codes->setObjectName("actionIata_Codes");
        centralwidget = new QWidget(TravelAgencyUI);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 10, 391, 261));
        verticalLayout_9 = new QVBoxLayout(groupBox);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        splitter = new QSplitter(groupBox);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(splitter);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(41, 16));
        splitter->addWidget(label_8);
        kundeID = new QLineEdit(splitter);
        kundeID->setObjectName("kundeID");
        kundeID->setMaximumSize(QSize(61, 22));
        splitter->addWidget(kundeID);

        verticalLayout_10->addWidget(splitter);

        splitter_3 = new QSplitter(groupBox);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Horizontal);
        label_9 = new QLabel(splitter_3);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(41, 16));
        splitter_3->addWidget(label_9);
        kundeVorname = new QLineEdit(splitter_3);
        kundeVorname->setObjectName("kundeVorname");
        kundeVorname->setMaximumSize(QSize(74, 22));
        splitter_3->addWidget(kundeVorname);

        verticalLayout_10->addWidget(splitter_3);

        splitter_4 = new QSplitter(groupBox);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setOrientation(Qt::Horizontal);
        label_11 = new QLabel(splitter_4);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(43, 16));
        splitter_4->addWidget(label_11);
        kundeNachname = new QLineEdit(splitter_4);
        kundeNachname->setObjectName("kundeNachname");
        kundeNachname->setMaximumSize(QSize(74, 22));
        splitter_4->addWidget(kundeNachname);

        verticalLayout_10->addWidget(splitter_4);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(41, 16));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_10);

        reiseTable = new QTableWidget(groupBox);
        if (reiseTable->columnCount() < 3)
            reiseTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        reiseTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        reiseTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        reiseTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        reiseTable->setObjectName("reiseTable");
        reiseTable->setShowGrid(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, reiseTable);


        verticalLayout_10->addLayout(formLayout_2);


        verticalLayout_9->addLayout(verticalLayout_10);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 270, 391, 271));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 20, 391, 251));
        verticalLayout_11 = new QVBoxLayout(layoutWidget);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        splitter_2 = new QSplitter(layoutWidget);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(splitter_2);
        label_12->setObjectName("label_12");
        label_12->setMaximumSize(QSize(51, 16));
        splitter_2->addWidget(label_12);
        travelIdui = new QLineEdit(splitter_2);
        travelIdui->setObjectName("travelIdui");
        travelIdui->setMaximumSize(QSize(62, 22));
        splitter_2->addWidget(travelIdui);

        verticalLayout_11->addWidget(splitter_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName("label_13");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_13);

        buchungTable = new QTableWidget(layoutWidget);
        if (buchungTable->columnCount() < 4)
            buchungTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        buchungTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        buchungTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        buchungTable->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        buchungTable->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        buchungTable->setObjectName("buchungTable");
        buchungTable->setMaximumSize(QSize(331, 192));

        formLayout->setWidget(0, QFormLayout::FieldRole, buchungTable);


        verticalLayout_11->addLayout(formLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 550, 80, 18));
        checkButton = new QPushButton(centralwidget);
        checkButton->setObjectName("checkButton");
        checkButton->setGeometry(QRect(230, 550, 80, 18));
        configurationButton = new QPushButton(centralwidget);
        configurationButton->setObjectName("configurationButton");
        configurationButton->setGeometry(QRect(130, 550, 80, 18));
        TravelAgencyUI->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TravelAgencyUI);
        statusbar->setObjectName("statusbar");
        TravelAgencyUI->setStatusBar(statusbar);
        menubar = new QMenuBar(TravelAgencyUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 438, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menukunde = new QMenu(menubar);
        menukunde->setObjectName("menukunde");
        TravelAgencyUI->setMenuBar(menubar);
        toolBar = new QToolBar(TravelAgencyUI);
        toolBar->setObjectName("toolBar");
        TravelAgencyUI->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menukunde->menuAction());
        menuFile->addAction(actionEinlesen);
        menuFile->addAction(actionIata_Codes);
        toolBar->addAction(actionEinlesen);
        toolBar->addAction(actionsearch);

        retranslateUi(TravelAgencyUI);

        QMetaObject::connectSlotsByName(TravelAgencyUI);
    } // setupUi

    void retranslateUi(QMainWindow *TravelAgencyUI)
    {
        TravelAgencyUI->setWindowTitle(QCoreApplication::translate("TravelAgencyUI", "TravelAgencyUI", nullptr));
        actionEinlesen->setText(QCoreApplication::translate("TravelAgencyUI", "Einlesen", nullptr));
#if QT_CONFIG(shortcut)
        actionEinlesen->setShortcut(QCoreApplication::translate("TravelAgencyUI", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionsearch->setText(QCoreApplication::translate("TravelAgencyUI", "search", nullptr));
        actionIata_Codes->setText(QCoreApplication::translate("TravelAgencyUI", "Read IATA Codes", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TravelAgencyUI", "Kund*in", nullptr));
        label_8->setText(QCoreApplication::translate("TravelAgencyUI", "ID", nullptr));
        label_9->setText(QCoreApplication::translate("TravelAgencyUI", "Vorname", nullptr));
        label_11->setText(QCoreApplication::translate("TravelAgencyUI", "Nachname", nullptr));
        label_10->setText(QCoreApplication::translate("TravelAgencyUI", "Reisen", nullptr));
        QTableWidgetItem *___qtablewidgetitem = reiseTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TravelAgencyUI", "Reise Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = reiseTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TravelAgencyUI", "Begin der Reise", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = reiseTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TravelAgencyUI", "Ende der Reise", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("TravelAgencyUI", "Reise", nullptr));
        label_12->setText(QCoreApplication::translate("TravelAgencyUI", "Reise-ID", nullptr));
        label_13->setText(QCoreApplication::translate("TravelAgencyUI", "Buchungen", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = buchungTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TravelAgencyUI", "Buchungstyp", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = buchungTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TravelAgencyUI", "Start", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = buchungTable->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TravelAgencyUI", "Ende", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = buchungTable->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TravelAgencyUI", "Preis", nullptr));
        pushButton->setText(QCoreApplication::translate("TravelAgencyUI", "Save", nullptr));
        checkButton->setText(QCoreApplication::translate("TravelAgencyUI", "Check", nullptr));
        configurationButton->setText(QCoreApplication::translate("TravelAgencyUI", "Configuration", nullptr));
        menuFile->setTitle(QCoreApplication::translate("TravelAgencyUI", "Datei", nullptr));
        menukunde->setTitle(QCoreApplication::translate("TravelAgencyUI", "kunde", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("TravelAgencyUI", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TravelAgencyUI: public Ui_TravelAgencyUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELAGENCYUI_H
