#include "travelagencyui.h"
#include "RentalCarReservation.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "trainticket.h"
#include "ui_travelagencyui.h"
#include "travelagencyui.h"
#include "travel.h"
#include "bookingdetails.h"
#include "results.h"
#include "check.h"
#include "checkconfiguration.h"

#include <QString>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QInputDialog>
#include <QIcon>
#include <QDesktopServices>
#include <QUrl>
#include <error.h>

TravelAgencyUI::TravelAgencyUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TravelAgencyUI)
    , travelAgency(std::make_shared<TravelAgency>())
    , check(std::make_unique<Check>(travelAgency))
{
    ui->setupUi(this);
}

TravelAgencyUI::~TravelAgencyUI()
{
    delete ui;
}

int earliestFromDate(vector<shared_ptr<Booking>> travelBookings){

    int currentDate = 0;
    int earliestDate = 30000000;//random big ass number
    for(unsigned int i = 0; i < travelBookings.size(); i++){
        currentDate = stoi(travelBookings[i]->getFromDate());
        if(currentDate < earliestDate){
            earliestDate = currentDate;
        }
    }
    qDebug() << "Earliest Date inside function: " << earliestDate;
    return earliestDate;
}

int latestToDate(vector<shared_ptr<Booking>> travelBookings){
    int currentDate = 0;
    int latestDate = 0;
    for(unsigned int i = 0; i < travelBookings.size(); i++){
        currentDate = stoi(travelBookings[i]->getToDate());
        if(currentDate > latestDate){
            latestDate = currentDate;
        }
    }
    qDebug() << "Latest Date inside function: " << latestDate;
    return latestDate;
}

QString TravelAgencyUI::generateBookingGeoJson(const shared_ptr<Booking>& booking)
{
    QJsonObject geoJsonObject;

    geoJsonObject["type"] = "Feature";

    if(const auto flightBooking = std::dynamic_pointer_cast<const FlightBooking>(booking)){
        QJsonObject flightRouteFeature;
        flightRouteFeature["type"] = "Feature";
        flightRouteFeature["geometry"] = QJsonObject{
            {"type", "LineString"},
            {"coordinates", QJsonArray{
                                QJsonArray{flightBooking->getFromDestLongitude(), flightBooking->getFromDestLatitude()},
                                QJsonArray{flightBooking->getToDestLongitude(), flightBooking->getToDestLatitude()}
                            }}
        };
        flightRouteFeature["properties"] = QJsonObject{
            {"Origin Airport:", QString::fromStdString(flightBooking->getFromDestination())},
            {"Destination Airport:", QString::fromStdString(flightBooking->getToDestination())}
        };
        geoJsonObject = flightRouteFeature;
    }
    else if(const auto rentalCarReservation = std::dynamic_pointer_cast<const RentalCarReservation>(booking)){
        if (rentalCarReservation->getPickupLocation() == rentalCarReservation->getReturnLocation()) {
            // Only a single point if pickup and return locations are the same
            geoJsonObject["geometry"] = QJsonObject{
                {"type", "Point"},
                {"coordinates", QJsonArray{rentalCarReservation->getPickupLongitude(), rentalCarReservation->getPickupLatitude()}}
            };
            geoJsonObject["properties"] = QJsonObject{
                {"Pickup/Return Location: ", QString::fromStdString(rentalCarReservation->getPickupLocation())},
                {"Company: ", QString::fromStdString(rentalCarReservation->getCompany())}
            };
        } else {
            // Display a line if pickup and return locations are different
            QJsonObject rentalCarRouteFeature;
            rentalCarRouteFeature["type"] = "Feature";
            rentalCarRouteFeature["geometry"] = QJsonObject{
                {"type", "LineString"},
                {"coordinates", QJsonArray{
                                    QJsonArray{rentalCarReservation->getPickupLongitude(), rentalCarReservation->getPickupLatitude()},
                                    QJsonArray{rentalCarReservation->getReturnLongitude(), rentalCarReservation->getReturnLatitude()}
                                }}
            };
            rentalCarRouteFeature["properties"] = QJsonObject{
                {"Pickup Location", QString::fromStdString(rentalCarReservation->getPickupLocation())},
                {"Return Location", QString::fromStdString(rentalCarReservation->getReturnLocation())},
                {"company", QString::fromStdString(rentalCarReservation->getCompany())}
            };

            geoJsonObject = rentalCarRouteFeature;
        }
    }else if(const auto hotelBooking = std::dynamic_pointer_cast<const HotelBooking>(booking)){
        geoJsonObject["geometry"] = QJsonObject{
            {"type", "Point"},
            {"coordinates", QJsonArray{hotelBooking->getHotelLongitude(), hotelBooking->getHotelLatitude()}}
        };
        geoJsonObject["properties"] = QJsonObject{
            {"Hotel: ", QString::fromStdString(hotelBooking->getHotel())}
        };
    }else if(const auto trainTicket = std::dynamic_pointer_cast<const TrainTicket>(booking)){
        //Train code isn't quite working properly yet..

        // GeoJson feature for the start station
        QJsonObject fromStationFeature;
        fromStationFeature["type"] = "Feature";
        fromStationFeature["geometry"] = QJsonObject{
            {"type", "Point"},
            {"coordinates", QJsonArray{trainTicket->getFromStationLongitude(), trainTicket->getFromStationLatitude()}}
        };
        fromStationFeature["properties"] = QJsonObject{
            {"name", QString::fromStdString(trainTicket->getFromDestination())}
        };

        // GeoJson feature for end station
        QJsonObject toStationFeature;
        toStationFeature["type"] = "Feature";
        toStationFeature["geometry"] = QJsonObject{
            {"type", "Point"},
            {"coordinates", QJsonArray{trainTicket->getToStationLongitude(), trainTicket->getToStationLatitude()}}
        };
        toStationFeature["properties"] = QJsonObject{
            {"name", QString::fromStdString(trainTicket->getToDestination())}
        };

        // GeoJson feature for the connecting stations
        QJsonArray connectingStationsArray;
        for (size_t i = 0; i < trainTicket->getConnectingStations().size(); ++i) {
            QJsonObject connectingStationFeature;
            connectingStationFeature["type"] = "Feature";
            connectingStationFeature["geometry"] = QJsonObject{
                {"type", "Point"},
                {"coordinates", QJsonArray{trainTicket->getConnectingStationsLongitude()[i], trainTicket->getConnectingStationsLatitude()[i]}}
            };
            connectingStationFeature["properties"] = QJsonObject{
                {"name", QString::fromStdString(trainTicket->getConnectingStations()[i])}
            };
            connectingStationsArray.append(connectingStationFeature);
        }

        // GeoJson feature for the line connecting all stations
        QJsonObject trainRouteFeature;
        trainRouteFeature["type"] = "Feature";
        trainRouteFeature["geometry"] = QJsonObject{
            {"type", "LineString"},
            {"coordinates", QJsonArray{
                                QJsonArray{trainTicket->getFromStationLongitude(), trainTicket->getFromStationLatitude()},
                                QJsonArray{trainTicket->getToStationLongitude(), trainTicket->getToStationLatitude()}
                            }}
        };
        trainRouteFeature["properties"] = QJsonObject{
            {"startStation", fromStationFeature},
            {"endStation", toStationFeature},
            {"connectingStations", connectingStationsArray}
        };

        geoJsonObject = trainRouteFeature;
    }else{
        geoJsonObject["type"] = "Feature";
    }
    QJsonDocument jsonDocument(geoJsonObject);

    return jsonDocument.toJson(QJsonDocument::Compact);
}

void TravelAgencyUI::on_actionEinlesen_triggered()
{
    try{
        QString filePath = QFileDialog::getOpenFileName(this, "Open File", "C:/Users/ryanz/OneDrive/Desktop/infor hda/Semester 2/PG2/Praktikum/PG2_Praktikum2");

        if(!filePath.isEmpty()){
            //open and read file
            travelAgency->readFile(filePath);

            //sucessful
            QString successMessage = QString::fromStdString(travelAgency->showTotal());

            QMessageBox::information(this, "File opened", successMessage);

        }else{
            //cancelled operation
            QMessageBox::critical(this, tr("error"), tr("Operation Cancelled"));
        }
    }catch(std::runtime_error& e){
        QString error;

        error = e.what();
        messageBox.setWindowTitle("Fehler beim Einelsen der Buchungen");
        messageBox.setText(error);
        messageBox.setDetailedText("Wenn Sie die Datei bereits korrigiert haben, wahlen Sie 'Retry'. "
                                   "Wahlen Sie 'Discard', um alle Buchungen zu loschen "
                                   "und 'Cancel', um die vorhandenen Buchungen stehenzulassen "
                                   "und diesen Dialog zu verlassen.");
        messageBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Discard | QMessageBox::Cancel);
        messageBox.setDefaultButton(QMessageBox::Cancel);

        int retry = messageBox.exec();

        switch(retry){
        case QMessageBox::Retry:
            on_actionEinlesen_triggered();
            break;
        case QMessageBox::Discard:
            break;
        case QMessageBox::Cancel:
            break;
        default:
            messageBox.critical(this,"Error", "Error");
        }
    }
}

void TravelAgencyUI::on_actionsearch_triggered()
{
    // Use a QInputDialog for simplicity
    bool ok;
    QString customerId = QInputDialog::getText(this, "Search Customer", "Enter Customer ID:", QLineEdit::Normal, "", &ok);
    ui->reiseTable->setRowCount(0);

    if (ok && !customerId.isEmpty()) {
        shared_ptr<Customer> customer = travelAgency->findCustomer(customerId.toLong());

        QMessageBox messageBox;
        //messageBox.setWindowTitle("Search Result");

        if (customer) {
            //Customer found
            //Kunde
            ui->kundeID->setText(QString::number(customer->getId()));
            ui->kundeVorname->setText(QString::fromStdString(customer->getFirstName()));
            ui->kundeNachname->setText(QString::fromStdString(customer->getLastName()));

            //ui->reiseTable->setRowCount(customer->getTravelList().size());
            unsigned int travelSize = customer->getTravelList().size();
            QSet<int> seenTravelIds;

            for (unsigned int row = 0; row < travelSize; ++row){
                shared_ptr<Travel> travel = customer->getTravelList()[row];
                int travelId = travel->getId();

                if(seenTravelIds.contains(travelId)){
                    continue;
                }

                int newRow = ui->reiseTable->rowCount();
                ui->reiseTable->insertRow(newRow);

                seenTravelIds.insert(travelId);

                ui->reiseTable->setItem(newRow, 0, new QTableWidgetItem(QString::number(travelId)));

                QDate fromDate = QDate::fromString(QString::number(earliestFromDate(travel->getTravelBookings())),"yyyyMMdd");
                ui->reiseTable->setItem(newRow, 1, new QTableWidgetItem(fromDate.toString()));

                QDate toDate = QDate::fromString(QString::number(latestToDate(travel->getTravelBookings())),"yyyyMMdd");
                ui->reiseTable->setItem(newRow, 2, new QTableWidgetItem(toDate.toString()));

                travel->setFromDate(earliestFromDate(travel->getTravelBookings()));
                travel->setToDate(latestToDate(travel->getTravelBookings()));
            }
        } else {
            messageBox.setText("Customer not found.");
            messageBox.exec();
        }
    }
}


void TravelAgencyUI::on_reiseTable_itemDoubleClicked(QTableWidgetItem *item)
{
    int row = item->row();

    QTableWidgetItem* travelId_Item = ui->reiseTable->item(row,0);
    if(!travelId_Item){
        return;
    }

    long travelId = travelId_Item->text().toLong();

    Travel* clickedTravel = travelAgency->findTravel(travelId).get();

    ui->buchungTable->clearContents();
    ui->buchungTable->setRowCount(0);

    //QString allBookingsGeoJson;

    QJsonObject featureCollection;
    featureCollection["type"] = "FeatureCollection";
    QJsonArray featuresArray;

    for (auto booking: clickedTravel->getTravelBookings()){

        QIcon bookingIcon;

        if(dynamic_cast<FlightBooking*>(booking.get())){
            bookingIcon = QIcon("C:/Users/ryanz/OneDrive/Desktop/infor hda/Semester 2/PG2/Praktikum/PG2_Praktikum2/planeIcon.png");
        }else if(dynamic_cast<HotelBooking*>(booking.get())){
            bookingIcon = QIcon("C:/Users/ryanz/OneDrive/Desktop/infor hda/Semester 2/PG2/Praktikum/PG2_Praktikum2/hotelIcon.png");
        }else if(dynamic_cast<RentalCarReservation*>(booking.get())){
            bookingIcon = QIcon("C:/Users/ryanz/OneDrive/Desktop/infor hda/Semester 2/PG2/Praktikum/PG2_Praktikum2/carIcon.png");
        }else if(dynamic_cast<TrainTicket*>(booking.get())){
            bookingIcon = QIcon("C:/Users/ryanz/OneDrive/Desktop/infor hda/Semester 2/PG2/Praktikum/PG2_Praktikum2/trainIcon.png");
        }

        //string startDate = booking->getFromDate();
        //string endDate = booking->getToDate();
        double preis = booking->getPrice();

        ui->travelIdui->setText(QString::number(travelId));

        //new row
        int rowPosition = ui->buchungTable->rowCount();
        ui->buchungTable->insertRow(rowPosition);

        ui->buchungTable->setItem(rowPosition, 0, new QTableWidgetItem(bookingIcon,""));

        QDate fromDate = QDate::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd");
        ui->buchungTable->setItem(rowPosition, 1, new QTableWidgetItem(fromDate.toString()));

        QDate toDate = QDate::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd");
        ui->buchungTable->setItem(rowPosition, 2, new QTableWidgetItem(toDate.toString()));
        ui->buchungTable->setItem(rowPosition, 3, new QTableWidgetItem(QString::number(preis)));

        //show the map
        QString geoJson = generateBookingGeoJson(booking);
        QJsonObject feature = QJsonDocument::fromJson(geoJson.toUtf8()).object();
        featuresArray.append(feature);
    }
    featureCollection["features"] = featuresArray;
    QString allBookingsGeoJson = QJsonDocument(featureCollection).toJson();

    QUrl url("http://townsendjennings.com/geo/?geojson=" + QUrl::toPercentEncoding(allBookingsGeoJson));
    //QUrl url("http://townsendjennings.com/geo/?geojson=" + QUrl::toPercentEncoding(allBookingsGeoJson));
    QDesktopServices::openUrl(url);
}

void TravelAgencyUI::on_buchungTable_cellDoubleClicked(int row)
{
    bookingDetails* bookingDetailsUI = new bookingDetails(travelAgency, this);
    QString QString_row = QString::number(row);
    QString travelID = ui->travelIdui->text();
    bookingDetailsUI->showDetails(QString_row, travelID);
    bookingDetailsUI->show();

    /*
    long travelId = ui->travelIdui->text().toLong();
    Travel* clickedTravel = travelAgency->findTravel(travelId).get();
    auto bookings = clickedTravel->getTravelBookings();

    // Ensure that the row index is within bounds
    if (row >= 0 && row < static_cast<int>(bookings.size())) {
        auto clickedBooking = bookings[row];

        // Generate GeoJSON for the clicked booking
        QString geoJson = generateBookingGeoJson(clickedBooking);

        // Open the web page with the GeoJSON code in a web browser
        QUrl url("http://townsendjennings.com/geo/?geojson=" + QUrl::toPercentEncoding(geoJson));
        QDesktopServices::openUrl(url);
    }
    */
}

void TravelAgencyUI::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save JSON File"), "", tr("JSON Files (*.json);;All Files(*)"));

    if(!fileName.isEmpty()){
        saveFile(fileName);
    }
}

void TravelAgencyUI::saveFile(const QString& fileName)
{//Dont forget to change everything to smart pointer
    QJsonArray bookingsArray;
    for(const auto& savedBookingPtr : travelAgency->getAllBookings()){
        const Booking* savedBookings = savedBookingPtr.get();
        QJsonObject bookingObject;
        bookingObject["id"] = QString::fromStdString(savedBookings->getId());
        bookingObject["fromDate"] = QString::fromStdString(savedBookings->getFromDate());
        bookingObject["toDate"] = QString::fromStdString(savedBookings->getToDate());
        bookingObject["price"] = savedBookings->getPrice();
        int travelId = savedBookings->getTravelId();
        bookingObject["travelId"] = travelId;
        if(const FlightBooking* flightBooking = dynamic_cast<const FlightBooking*>(savedBookings)){
            bookingObject["type"] = "Flight";
            bookingObject["airline"] = QString::fromStdString(flightBooking->getAirline());
            bookingObject["fromDestination"] = QString::fromStdString(flightBooking->getFromDestination());
            bookingObject["toDestination"] = QString::fromStdString(flightBooking->getToDestination());
            bookingObject["bookingClass"] = QString::fromStdString(flightBooking->getBookingClass());
        }else if(const HotelBooking* hotelBooking = dynamic_cast<const HotelBooking*>(savedBookings)){
            bookingObject["type"] = "Hotel";
            bookingObject["town"] = QString::fromStdString(hotelBooking->getTown());
            bookingObject["hotel"] = QString::fromStdString(hotelBooking->getHotel());
            bookingObject["roomType"] = QString::fromStdString(hotelBooking->getRoomType());
        }else if(const RentalCarReservation* rentalCarReservation = dynamic_cast<const RentalCarReservation*>(savedBookings)){
            bookingObject["pickupLocation"] = QString::fromStdString(rentalCarReservation->getPickupLocation());
            bookingObject["returnLocation"] = QString::fromStdString(rentalCarReservation->getReturnLocation());
            bookingObject["company"] = QString::fromStdString(rentalCarReservation->getCompany());
            bookingObject["vehicleClass"] = QString::fromStdString(rentalCarReservation->getVehicleClass());
        }else if(const TrainTicket* trainTicket = dynamic_cast<const TrainTicket*>(savedBookings)){
            bookingObject["fromStation"] = QString::fromStdString(trainTicket->getFromDestination());
            bookingObject["toStation"] = QString::fromStdString(trainTicket->getToDestination());
            bookingObject["departureTime"] = QString::fromStdString(trainTicket->getDepartureTime());
            bookingObject["arrivalTime"] = QString::fromStdString(trainTicket->getArrivalTime());
            bookingObject["ticketType"] = QString::fromStdString(trainTicket->getBookingClass());
        }
        Travel* travel = travelAgency->findTravel(savedBookings->getTravelId()).get();
        long customerId = travel->getCustomerId();
        bookingObject["customerId"] = QString::number(customerId);
        Customer* customer = travelAgency->findCustomer(customerId).get();
        bookingObject["customerFirstName"] = QString::fromStdString(customer->getFirstName());
        bookingObject["customerLastName"] = QString::fromStdString(customer->getLastName());

        bookingsArray.append(bookingObject);
    }
    QJsonDocument jsonDoc(bookingsArray);

    QFile outputFile(fileName);
    if (outputFile.open(QIODevice::WriteOnly)){
        outputFile.write(jsonDoc.toJson());
        outputFile.close();
    }else{
        qDebug() << "File write error";
    }
}

void TravelAgencyUI::on_actionIata_Codes_triggered()
{
    try{
        QString airportFile = QFileDialog::getOpenFileName(this, "Open File", "C:/Users/ryanz/OneDrive/Desktop/infor hda/Semester 2/PG2/Praktikum/PG2_Praktikum2");

        if(!airportFile.isEmpty()){
            //open and read file
            travelAgency->readAirport(airportFile);

            //sucessful
            //QString successMessage = QString::fromStdString(travelAgency->showTotal());

            QMessageBox::information(this, "File opened", "iatacodes.json succesfully read");

        }else{
            //cancelled operation
            QMessageBox::critical(this, tr("error"), tr("Operation Cancelled"));
        }
    }catch(std::runtime_error& e){
        QString error;

        error = e.what();
        messageBox.setWindowTitle("Fehler beim Einelsen der Buchungen");
        messageBox.setText(error);
        messageBox.setDetailedText("Wenn Sie die Datei bereits korrigiert haben, wahlen Sie 'Retry'. "
                                   "Wahlen Sie 'Discard', um alle Buchungen zu loschen "
                                   "und 'Cancel', um die vorhandenen Buchungen stehenzulassen "
                                   "und diesen Dialog zu verlassen.");
        messageBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Discard | QMessageBox::Cancel);
        messageBox.setDefaultButton(QMessageBox::Cancel);

        int retry = messageBox.exec();

        switch(retry){
        case QMessageBox::Retry:
            on_actionEinlesen_triggered();
            break;
        case QMessageBox::Discard:
            break;
        case QMessageBox::Cancel:
            break;
        default:
            messageBox.critical(this,"Error", "Error");
        }
    }
}


void TravelAgencyUI::on_checkButton_clicked()
{
    try {
        qDebug() << "Ergebnisse button clicked";
        vector<shared_ptr<Travel>> travels = travelAgency->getAllTravels();
        qDebug() << "error here1";
        for(auto& travel : travels){
            travel->buildGraph();
        }
        qDebug() << "error here2";
        Results* resultsDialog = new Results(this);
        qDebug() << "error here3";
        qDebug() << "Inspecting check object: " << check.get();
        connect(check.get(), &Check::sendCheckResult, resultsDialog, &Results::updateTableWidget);
        //sumthing wong here

        if(overlapHotel) {
            check->checkNoOverlappingHotels();
        }
        if(missingHotel) {
            check->checkNoMissingHotels();
        }
        if(overlapCar) {
            check->checkNoOverlappingRentalCars();
        }
/*
        check->checkNoOverlappingHotels();
        check->checkNoMissingHotels();
        check->checkNoOverlappingRentalCars();
*/
        resultsDialog->exec();
    } catch (const std::exception& e) {
        qDebug() << "Exception caught: " << e.what();
    }
}

void TravelAgencyUI::on_configurationButton_clicked()
{
    checkConfiguration* checkConfigurationUI = new checkConfiguration(travelAgency, this);
    checkConfigurationUI->loadCheckBoxState();
    checkConfigurationUI->exec();
    //default false
    if(checkConfigurationUI->getOverlapTravelState() == true) {
        overlapTravel = true;
    } else {
        overlapTravel = false;
    }

    if(checkConfigurationUI->getOverlapHotelState() == true) {
        overlapHotel = true;
    } else {
        overlapHotel = false;
    }

    if(checkConfigurationUI->getOverlapRentalState() == true) {
        overlapCar = true;
    } else {
        overlapCar = false;
    }

    if(checkConfigurationUI->getMissingHotelState() == true) {
        missingHotel = true;
    } else {
        missingHotel = false;
    }
}

