#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H

#include <QMainWindow>
#include "TravelAgency.h"
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidget>
#include <QTableWidget>
#include "check.h"
#include "results.h"
#include "bookingdetails.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TravelAgencyUI; }
QT_END_NAMESPACE

class TravelAgencyUI : public QMainWindow
{
    Q_OBJECT

public:
    TravelAgencyUI(QWidget *parent = nullptr);
    ~TravelAgencyUI();
    //void showDetails(QString row, QString reiseId);
    void saveFile(const QString& fileName);
    QString generateBookingGeoJson(const shared_ptr<Booking>& booking);

private slots:
    void on_actionEinlesen_triggered();

    void on_actionsearch_triggered();

    void on_reiseTable_itemDoubleClicked(QTableWidgetItem *item);

    void on_buchungTable_itemDoubleClicked(QTableWidgetItem *item);

    void on_buchungTable_cellDoubleClicked(int row);

    void on_pushButton_clicked();

    void on_actionIata_Codes_triggered();

    void on_checkButton_clicked();

    void on_configurationButton_clicked();

private:
    Ui::TravelAgencyUI *ui;
    std::shared_ptr<TravelAgency> travelAgency;
    //std::shared_ptr<bookingDetails> bookingDetails;
    QMessageBox messageBox;
    std::unique_ptr<Check> check;
    std::unique_ptr<Results> results;

    bool overlapTravel = false;
    bool overlapHotel = false;
    bool missingHotel = false;
    bool overlapCar = false;
};
#endif // TRAVELAGENCYUI_H
