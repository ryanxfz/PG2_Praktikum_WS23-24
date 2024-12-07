#include "checkconfiguration.h"
#include <QSettings>

checkConfiguration::checkConfiguration(std::shared_ptr<TravelAgency> travelAgency, QWidget *parent) :
    QDialog(parent),
    travelAgency(travelAgency),
    ui(new Ui::checkConfiguration)
{
    ui->setupUi(this);
}

checkConfiguration::~checkConfiguration()
{
    delete ui;
}

void checkConfiguration::loadCheckBoxState()
{
    // Load the state of each checkbox
    QSettings settings("MyCompany", "MyApp");
    ui->overlapHotel->setChecked(settings.value("overlapHotelChecked", false).toBool());
    ui->overlapRental->setChecked(settings.value("overlapRentalChecked", false).toBool());
    ui->overlapTravel->setChecked(settings.value("overlapTravelChecked", false).toBool());
    ui->missingHotel->setChecked(settings.value("missingHotelChecked", false).toBool());
}

bool checkConfiguration::getOverlapHotelState() const
{
    return ui->overlapHotel->isChecked();
}

bool checkConfiguration::getOverlapRentalState() const
{
    return ui->overlapRental->isChecked();
}

bool checkConfiguration::getOverlapTravelState() const
{
    return ui->overlapTravel->isChecked();
}

bool checkConfiguration::getMissingHotelState() const
{
    return ui->missingHotel->isChecked();
}



void checkConfiguration::on_okButton_clicked()
{
    QSettings settings("MyCompany", "MyApp");
    settings.setValue("checkBox1Checked", ui->overlapHotel->isChecked());
    settings.setValue("checkBox2Checked", ui->overlapRental->isChecked());
    settings.setValue("checkBox3Checked", ui->overlapTravel->isChecked());
    settings.setValue("checkBox4Checked", ui->missingHotel->isChecked());

    close();
}


void checkConfiguration::on_cancelButton_clicked()
{
    close();
}

