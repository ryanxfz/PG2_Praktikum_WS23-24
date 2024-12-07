#ifndef CHECKCONFIGURATION_H
#define CHECKCONFIGURATION_H

#include "travelagency.h"
#include <QDialog>
#include <memory> // For std::shared_ptr
#include "ui_checkconfiguration.h"
#include "travelagency.h"

namespace Ui {
class checkConfiguration;
}

class checkConfiguration : public QDialog
{
    Q_OBJECT

public:
    explicit checkConfiguration(std::shared_ptr<TravelAgency> travelAgency, QWidget *parent = nullptr);
    ~checkConfiguration();
    void loadCheckBoxState();

    bool getOverlapHotelState() const;
    bool getOverlapRentalState() const;
    bool getOverlapTravelState() const;
    bool getMissingHotelState() const;

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    std::shared_ptr<TravelAgency> travelAgency;
    Ui::checkConfiguration *ui;
};

#endif // CHECKCONFIGURATION_H
