#ifndef BOOKINGDETAILS_H
#define BOOKINGDETAILS_H
#include "TravelAgency.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "check.h"
#include <QDialog>

namespace Ui {
class bookingDetails;
}

class bookingDetails : public QDialog
{
    Q_OBJECT

public:
    explicit bookingDetails(std::shared_ptr<TravelAgency> travelAgency, QWidget *parent = nullptr);
    ~bookingDetails();
    void showDetails(QString QString_row, QString reiseId);
    void setToAirportCode(const QString& airportCode);
    void updateBooking(std::shared_ptr<Booking> newBooking);
public slots:
    void checkUpdatedBooking();
signals:
    void checkUpdate();
private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void on_flightFromDestination_returnPressed();
    void on_flightToDestination_returnPressed();

private:
    Ui::bookingDetails *ui;
    shared_ptr<TravelAgency> travelAgency;
    bookingDetails* bookingDetailsUI;
    Check* check;

    //void openGeoJsonMap(const QString &geoJson);

};

#endif // BOOKINGDETAILS_H
