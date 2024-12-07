#include "bookingdetails.h"
#include "check.h"
#include "qmessagebox.h"
#include "ui_bookingdetails.h"
#include "airport.h"
#include "RentalCarReservation.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "trainticket.h"
#include <QDesktopServices>
#include <QUrl>
#include <memory>


bookingDetails::bookingDetails(std::shared_ptr<TravelAgency> travelAgency, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookingDetails),
    travelAgency(travelAgency),
    check(new Check(travelAgency))
    //check(std::make_shared<Check>(travelAgency))
{
    ui->setupUi(this);
    connect(check, &Check::bookingupdated, this, &bookingDetails::checkUpdatedBooking);
    connect(this, &bookingDetails::checkUpdate, this, &bookingDetails::checkUpdatedBooking);
}

bookingDetails::~bookingDetails()
{
    delete ui;
}

void bookingDetails::checkUpdatedBooking(){
    bool result = (*check)();
    if(result){
        QMessageBox information;
        information.setText("No overlapping found!");
        information.exec();
    }
}

void bookingDetails::updateBooking(shared_ptr<Booking> newBooking){
    for(size_t i = 0; i < travelAgency->getAllBookings().size();++i){
        if(travelAgency->getAllBookings()[i] != newBooking){
            travelAgency->getAllBookings()[i] = newBooking;
            break;
        }
    }
    emit checkUpdate();
}

void bookingDetails::showDetails(QString QString_row, QString reiseId)
{
    bool ok;
    int row = QString_row.toInt(&ok);
    long travelId = reiseId.toInt(&ok);
    Travel* travel = travelAgency->findTravel(travelId).get();
    Booking* booking = travel->getTravelBookings()[row].get();

    //TODO: fromDate/toDate masih belom bener
    ui->bookingId->setText(QString::fromStdString(booking->getId()));
    ui->bookingFromDate->setDate(QDate::fromString(QString::fromStdString(booking->getFromDate()),"yyyyMMdd"));
    ui->bookingToDate->setDate(QDate::fromString(QString::fromStdString(booking->getToDate()),"yyyyMMdd"));
    ui->bookingPrice->setPrefix("EUR ");
    ui->bookingPrice->setValue(booking->getPrice());

    if(const FlightBooking* flightBooking = dynamic_cast<const FlightBooking*>(booking)){
        ui->detailsTab->setCurrentWidget(ui->flightTab);
        ui->flightAirline->setText(QString::fromStdString(flightBooking->getAirline()));
        //ui->flightFromDestination->setText(QString::fromStdString(flightBooking->getFromDestination()));
        //ui->flightToDestination->setText(QString::fromStdString(flightBooking->getToDestination()));

        QString fromDestinationCode = QString::fromStdString(flightBooking->getFromDestination());
        QString toDestinationCode = QString::fromStdString((flightBooking->getToDestination()));

        if (travelAgency->getAirports().contains(fromDestinationCode) && travelAgency->getAirports().contains(toDestinationCode)){
            std::shared_ptr<Airport> fromAirport = travelAgency->getAirports()[fromDestinationCode];
            std::shared_ptr<Airport> toAirport = travelAgency->getAirports()[toDestinationCode];

            ui->flightFromDestination->setText(QString::fromStdString(fromAirport->getIata_code()));
            ui->flightFromAirport->setText(QString::fromStdString(fromAirport->getName()));
            ui->flightToDestination->setText(QString::fromStdString(toAirport->getIata_code()));
            ui->flightToAirport->setText(QString::fromStdString(toAirport->getName()));
        }else{
            ui->flightFromDestination->setText("Ungultiger IATA Code");
            ui->flightToDestination->setText("Ungultiger IATA Code");
            ui->flightFromAirport->clear();
            ui->flightToAirport->clear();
        }

        QString bookingClass;
        if(flightBooking->getBookingClass() == "Y"){
            bookingClass = "Economy";
        }else if(flightBooking->getBookingClass() == "W"){
            bookingClass = "Premium Economy";
        }else if(flightBooking->getBookingClass() == "J"){
            bookingClass = "Business";
        }else if(flightBooking->getBookingClass() == "F"){
            bookingClass = "First";
        }else{
            bookingClass = "unknown";
        }
        ui->flightBookingClass->setText(bookingClass);
    } else if (const HotelBooking* hotelBooking = dynamic_cast<const HotelBooking*>(booking)){
        ui->detailsTab->setCurrentWidget(ui->hotelTab);
        ui->townName->setText(QString::fromStdString(hotelBooking->getTown()));
        ui->hotelName->setText(QString::fromStdString(hotelBooking->getHotel()));
        QString roomType;
        if(hotelBooking->getRoomType() == "EZ"){
            roomType = "Einzelzimmer";
        }if(hotelBooking->getRoomType() == "DZ"){
            roomType = "Doppelzimmer";
        }if(hotelBooking->getRoomType() == "SU"){
            roomType = "Suite";
        }if(hotelBooking->getRoomType() == "AP"){
            roomType = "Appartment";
        }else{
            roomType = "unknown";
        }
        ui->hotelRoomType->setText(roomType);
    }else if (const RentalCarReservation* rentalCarReservation = dynamic_cast<const RentalCarReservation*>(booking)){
        ui->detailsTab->setCurrentWidget(ui->carTab);
        ui->carPickupLocation->setText(QString::fromStdString(rentalCarReservation->getPickupLocation()));
        ui->carReturnLocation->setText(QString::fromStdString(rentalCarReservation->getReturnLocation()));
        ui->carCompany->setText(QString::fromStdString(rentalCarReservation->getCompany()));
        ui->carVehicleClass->setText(QString::fromStdString(rentalCarReservation->getVehicleClass()));
    }else if (const TrainTicket* trainTicket = dynamic_cast<const TrainTicket*>(booking)){
        ui->detailsTab->setCurrentWidget(ui->trainTab);
        ui->trainFromDestination->setText(QString::fromStdString(trainTicket->getFromDestination()));
        ui->trainToDestination->setText(QString::fromStdString(trainTicket->getToDestination()));
        //TODO: train time
        ui->trainAbfahrtTime->setText(QString::fromStdString(trainTicket->getDepartureTime()));
        ui->trainAnkunftTime->setText(QString::fromStdString(trainTicket->getArrivalTime()));
        ui->trainConnectingStations->setPlainText(QString::fromStdString(trainTicket->showConnectingStationsDetails()));
        QString trainBookingClass;
        if(trainTicket->getBookingClass() == "SSP1"){
            trainBookingClass = "Supersparpreis 1. Klasse";
        }if(trainTicket->getBookingClass() == "SSP2"){
            trainBookingClass = "Supersparpreis 2. Klasse";
        }if(trainTicket->getBookingClass() == "SP1"){
            trainBookingClass = "Sparpreis 1. Klasse";
        }if(trainTicket->getBookingClass() == "SP2"){
            trainBookingClass = "Sparpreis 2. Klasse";
        }if(trainTicket->getBookingClass() == "FP1"){
            trainBookingClass = "Flexpreis 1. Klasse";
        }if(trainTicket->getBookingClass() == "FP2"){
            trainBookingClass = "Flexpreis 2. Klasse";
        }
        ui->trainTicketType->setText(trainBookingClass);
    }
}

void bookingDetails::on_saveButton_clicked()
{

    QString QString_BookingID = ui->bookingId->text();
    shared_ptr<Booking> savedBooking = travelAgency->findBooking(QString_BookingID.toStdString());

    savedBooking->setFromDate(ui->bookingFromDate->text().toStdString());
    savedBooking->setToDate(ui->bookingToDate->text().toStdString());
    savedBooking->setPrice(ui->bookingPrice->value());

    if(ui->flightTab->isEnabled()){
        FlightBooking* flightBooking = dynamic_cast<FlightBooking*>(savedBooking.get());
        if(flightBooking){
            flightBooking->setFromDestination(ui->flightFromDestination->text().toStdString());
            flightBooking->setToDestination(ui->flightToDestination->text().toStdString());
            flightBooking->setAirline(ui->flightAirline->text().toStdString());
            flightBooking->setBookingClass(ui->flightBookingClass->text().toStdString());
        }
    }else if(ui->hotelTab->isEnabled()){
        HotelBooking* hotelBooking = dynamic_cast<HotelBooking*>(savedBooking.get());
        if(hotelBooking){
            hotelBooking->setHotel(ui->hotelName->text().toStdString());
            hotelBooking->setTown(ui->townName->text().toStdString());
            hotelBooking->setRoomType(ui->hotelRoomType->text().toStdString());
        }
    }else if(ui->carTab->isEnabled()){
        RentalCarReservation* rentalCarReservation = dynamic_cast<RentalCarReservation*>(savedBooking.get());
        if(rentalCarReservation){
            rentalCarReservation->setPickupLocation(ui->carPickupLocation->text().toStdString());
            rentalCarReservation->setReturnLocation(ui->carReturnLocation->text().toStdString());
            rentalCarReservation->setCompany(ui->carCompany->text().toStdString());
            rentalCarReservation->setVehicleClass(ui->carVehicleClass->text().toStdString());
        }
    }else if(ui->trainTab->isEnabled()){
        TrainTicket* trainTicket = dynamic_cast<TrainTicket*>(savedBooking.get());
        if(trainTicket){
            trainTicket->setFromDestination(ui->trainFromDestination->text().toStdString());
            trainTicket->setToDestination(ui->trainToDestination->text().toStdString());
            trainTicket->setDepartureTime(ui->trainAbfahrtTime->text().toStdString());
            trainTicket->setArrivalTime(ui->trainAnkunftTime->text().toStdString());
            trainTicket->setBookingClass(ui->trainTicketType->text().toStdString());
            //Connecting Stations blm
            QString connectingStationsText = ui->trainConnectingStations->toPlainText();
            QStringList connectingStationsList = connectingStationsText.split("\n");
            std::vector<std::string> connectingStationsData;
            for (const auto& stations : connectingStationsList) {
                connectingStationsData.push_back(stations.toStdString());
            }
            trainTicket->setConnectingStations(connectingStationsData);
        }
    }
    updateBooking(savedBooking);
    //ui->saveButton->setEnabled(false);
}


void bookingDetails::on_cancelButton_clicked()
{
    close();
}

void bookingDetails::on_flightFromDestination_returnPressed()
{   //destination is the IATA code
    //retrieve the current text that is in the QLineEdit
    QString airportCode = ui->flightFromDestination->text();
    if (travelAgency->getAirports().contains(airportCode)) {
        std::shared_ptr<Airport> airport = travelAgency->getAirports()[airportCode];
        ui->flightFromDestination->setText(QString::fromStdString(airport->getIata_code()));
        ui->flightFromAirport->setText(QString::fromStdString(airport->getName()));
        ui->flightFromAirport->setStyleSheet("color: black;");
        ui->flightFromDestination->setStyleSheet("color: black;");
    } else {
        ui->flightFromAirport->setText("Ungultiger IATA code");
        ui->flightFromDestination->setText("Ungultiger IATA code");
        ui->flightFromAirport->setStyleSheet("color: red;");
        ui->flightFromDestination->setStyleSheet("color: red;");
    }
}

void bookingDetails::on_flightToDestination_returnPressed()
{
    QString airportCode = ui->flightFromDestination->text();
    if (travelAgency->getAirports().contains(airportCode)) {
        std::shared_ptr<Airport> airport = travelAgency->getAirports()[airportCode];
        ui->flightToDestination->setText(QString::fromStdString(airport->getIata_code()));
        ui->flightToAirport->setText(QString::fromStdString(airport->getName()));
        ui->flightToAirport->setStyleSheet("color: black;");
        ui->flightToDestination->setStyleSheet("color: black;");

    } else {
        ui->flightToAirport->setText("Ungultiger IATA code");
        ui->flightToDestination->setText("Ungultiger IATA code");
        ui->flightToAirport->setStyleSheet("color: red;");
        ui->flightToDestination->setStyleSheet("color: red;");
    }
}

