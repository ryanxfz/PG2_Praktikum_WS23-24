#include "TravelAgency.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "RentalCarReservation.h"
#include "trainticket.h"
#include "airport.h"

#include <QFile>
#include <fstream>

using std::ifstream;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ios;
using std::stod;

int zeileNummer = 0; //fuer error handling benutzt

int flightCount = 0, trainCount = 0, hotelCount = 0, carCount = 0, totalCustomer = 0, totalTravel = 0, travelId1 = 0;
double totalFlightPrice = 0.0, totalTrainPrice = 0.0, totalHotelPrice = 0.0, totalCarPrice = 0.0;
double totalBookingPrice = 0.0;

TravelAgency::TravelAgency(){

}

TravelAgency::~TravelAgency(){
    //no need to delete unique_ptr, it's done automatically
    /*
    for(Booking* booking : allBookings){
        delete booking;
    }
*/
    allBookings.clear();
/*
    for(Travel* travel : allTravels){
        delete travel;
    }
*/
    allTravels.clear();
/*
    for(Customer* customer : allCustomers){
        delete customer;
    }
*/
    allCustomers.clear();

}

vector<shared_ptr<Booking>> TravelAgency::getAllBookings() const
{
    return allBookings;
}

vector<shared_ptr<Customer>> TravelAgency::getAllCustomers() const
{
    return allCustomers;
}

vector<shared_ptr<Travel>> TravelAgency::getAllTravels() const
{
    return allTravels;
}

shared_ptr<Booking>& TravelAgency::findBooking(string id)
{
    for(auto& booking: allBookings){
        if(booking->getId()==id){
            return booking;
        }
    }
    static shared_ptr<Booking> nullBooking;
    return nullBooking;
}

shared_ptr<Travel>& TravelAgency::findTravel(long id)
{
    for(auto& travel: allTravels){
        if (travel->getId()==id){
            return travel;
        }
    }
    static shared_ptr<Travel> nullTravel;
    return nullTravel;
}

shared_ptr<Customer>& TravelAgency::findCustomer(long id)
{
    for(auto& customer: allCustomers){
        if (customer->getId() == id){
            return customer;
        }
    }
    static shared_ptr<Customer> nullCustomer;
    return nullCustomer;
}

QMap<QString, std::shared_ptr<Airport>> TravelAgency::getAirports() const
{
    return airportsMap;
}
/*
std::map<long, vector<string> > TravelAgency::getMissingHotelsInfo() const
{
    return missingHotelsInfo;
}
*/
/*
void TravelAgency::storeMissingHotelInfo(long travelId, const std::string& missingHotelId) {
    // Check if the travel ID already exists in the map
    auto it = missingHotelsInfo.find(travelId);
    if (it != missingHotelsInfo.end()) {
        // Travel ID exists, add the missing hotel ID to the existing vector
        it->second.push_back(missingHotelId);
    } else {
        // Travel ID doesn't exist, create a new entry in the map
        missingHotelsInfo[travelId] = {missingHotelId};
    }
}
*/

void TravelAgency::readAirport(QString &filePathAirport){
    QFile datei(filePathAirport);
    if (!datei.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Datei kann nicht geoffnet werden";
        return;
    }
    airportsMap.clear();

    //read iatacodes.json file
    QJsonDocument jsonDocument = QJsonDocument::fromJson(datei.readAll());

    if(!jsonDocument.isNull()){
        QJsonArray jsonArray = jsonDocument.array();

        for(const QJsonValue& jsonValue : jsonArray){
            QJsonObject jsonObject = jsonValue.toObject();

            auto airport = std::make_shared<Airport>(//referring to airport class.
                jsonObject["name"].toString().toStdString(),
                jsonObject["iso_country"].toString().toStdString(),
                jsonObject["municipality"].toString().toStdString(),
                jsonObject["iata_code"].toString().toStdString()
                );

            //referring to airport QMap
            airportsMap[QString::fromStdString(airport->getIata_code())] = airport;
        }
    }else{
        std::cerr<<"Parsing failed\n";
    }
}
/*
std::map<long, vector<string> > TravelAgency::getOverlappingHotelsInfo() const
{
    return overlappingHotelsInfo;
}
*/
/*
void TravelAgency::storeOverlappingHotelInfo(long travelId, const std::string& overlappingHotelId){
    auto it = overlappingHotelsInfo.find(travelId);
    if (it != overlappingHotelsInfo.end()) {
        it->second.push_back(overlappingHotelId);
    } else {
        overlappingHotelsInfo[travelId] = {overlappingHotelId};
    }
}
*/
/*
void TravelAgency::storeOverlappingRentalCars(long travelId, const std::string& overlappingHotelId){
    auto it = overlappingRentalCars.find(travelId);
    if (it != overlappingRentalCars.end()) {
        it->second.push_back(overlappingHotelId);
    } else {
        overlappingHotelsInfo[travelId] = {overlappingHotelId};
    }
}
*/
void TravelAgency::readFile(QString &filePath){
    std::vector<long> processedTravelIds;
    std::vector<long> processCustomerIds;
    QFile datei(filePath);
    if (!datei.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Datei kann nicht geoffnet werden";
        return;
    }

    QString jsonString = datei.readAll();
    datei.close();

        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8());

        //check if the json file is valid
        if(jsonDocument.isNull()){
            std::cerr<< "Parsing failed";
        }

        if (jsonDocument.isArray()){
            QJsonArray jsonArray = jsonDocument.array();

            for(const QJsonValue& jsonValue : jsonArray){
                if(jsonValue.isObject()){
                    QJsonObject jsonObject = jsonValue.toObject();
                    zeileNummer++;

                    string id = jsonObject["id"].toString().toStdString();
                    string fromDate = jsonObject["fromDate"].toString().toStdString();
                    string toDate = jsonObject["toDate"].toString().toStdString();
                    double price = jsonObject["price"].toDouble();
                    long customerId = jsonObject["customerId"].toVariant().toLongLong();
                    long travelId = jsonObject["travelId"].toVariant().toLongLong();
                    string lastName = jsonObject["customerLastName"].toString().toStdString();
                    string firstName = jsonObject["customerFirstName"].toString().toStdString();

                    string predecessor1 = ""; //Default value for predecessor1
                    if(jsonObject.contains("predecessor1") && !jsonObject["predecessor1"].isNull()){
                        predecessor1 = jsonObject["predecessor1"].toString().toStdString();
                    }
                    string predecessor2 = ""; //Default value for predecessor2
                    if(jsonObject.contains("predecessor2") && !jsonObject["predecessor2"].isNull()){
                        predecessor2 = jsonObject["predecessor2"].toString().toStdString();
                    }
                    /*
                     * achtung:
                     * In json object in bookingsPraktikum 3, it's customerLastname bzw. customerFirstname (with lowercase N)
                     * In bookingsPraktikum 4, it's customerLastName bzw. customerFirstName (with uppercase N)
                     * (for some fucking reason)
                     */

                    QString type = jsonObject["type"].toString(); //flight, rentalcar, hotel, etc in the json file.

                    if (!findTravel(travelId)) {
                        shared_ptr<Travel> travel = std::make_shared<Travel>(travelId, customerId);
                        allTravels.push_back(travel);
                        totalTravel++;
                    }

                    if (!findCustomer(customerId)) {
                        std::shared_ptr<Customer> customer = std::make_shared<Customer>(customerId, lastName, firstName);
                        allCustomers.push_back(customer);
                        totalCustomer++;
                    } else {
                        bool check = false;
                        for(const auto& travel : findCustomer(customerId)->getTravelList()){
                            if(travel->getId() == travelId){
                                check = true;
                            }
                        }
                        if(!check){
                            findCustomer(customerId)->addTravel(findTravel(travelId));
                        }
                        if(customerId == 1){
                            travelId1++;
                        }
                    }

                    if(id.empty() || fromDate.empty() || toDate.empty()){
                        throw std::runtime_error("Empty Attribute (line "+ std::to_string(zeileNummer) + ")");
                    }

                    if(!jsonObject["price"].isDouble()){
                        throw std::runtime_error("Invalid price format (line " + std::to_string(zeileNummer)+ ")");
                    }

                    if(type == "Flight"){
                        //extract from flight
                        string fromDestination = jsonObject["fromDest"].toString().toStdString();
                        string toDestination = jsonObject["toDest"].toString().toStdString();
                        string airline = jsonObject["airline"].toString().toStdString();
                        string bookingClass = jsonObject["bookingClass"].toString().toStdString();

                        string fromDestLatitudeStr = jsonObject["fromDestLatitude"].toString().toStdString();
                        string fromDestLongitudeStr = jsonObject["fromDestLatitude"].toString().toStdString();
                        string toDestLatitudeStr = jsonObject["fromDestLatitude"].toString().toStdString();
                        string toDestLongitudeStr = jsonObject["fromDestLatitude"].toString().toStdString();

                        double fromDestLatitude = jsonObject["fromDestLatitude"].toDouble();
                        double fromDestLongitude = jsonObject["fromDestLatitude"].toDouble();
                        double toDestLatitude = jsonObject["fromDestLatitude"].toDouble();
                        double toDestLongitude = jsonObject["fromDestLatitude"].toDouble();

                        /*
                        double fromDestLatitude = std::stod(fromDestLatitudeStr);
                        double fromDestLongitude = std::stod(fromDestLongitudeStr);
                        double toDestLatitude = std::stod(toDestLatitudeStr);
                        double toDestLongitude = std::stod(toDestLongitudeStr);
*/

                        if (fromDestination.length() != 3 || toDestination.length() != 3) {
                            throw std::runtime_error("Empty Flughafenkuerzel (line " + std::to_string(zeileNummer) + ")");
                        }

                        if(airline.empty() || fromDestination.empty() || toDestination.empty()){
                            throw std::runtime_error("Empty Attribute (line "+ std::to_string(zeileNummer) + ")");
                        }

                        // Create a FlightBooking object
                        allBookings.push_back(std::make_shared<FlightBooking>(
                            id,
                            fromDate,
                            toDate,
                            price,
                            travelId,
                            predecessor1,
                            predecessor2,
                            fromDestination,
                            toDestination,
                            airline,
                            bookingClass,
                            fromDestLatitude,
                            fromDestLongitude,
                            toDestLatitude,
                            toDestLongitude));
                        findTravel(travelId)->addBooking(allBookings.back());
\
                        flightCount++;
                        totalFlightPrice += price;

                        //std::cout << flightBooking->showDetails() << std::endl;
                    }
                    else if(type == "Hotel"){
                        //extract from Hotel
                        string town = jsonObject["town"].toString().toStdString();
                        string hotel = jsonObject["hotel"].toString().toStdString();
                        string roomType = jsonObject["roomType"].toString().toStdString();

                        string hotelLatitudeStr = jsonObject["hotelLatitude"].toString().toStdString();
                        string hotelLongitudeStr = jsonObject["hotelLongitude"].toString().toStdString();

                        double hotelLatitude = jsonObject["hotelLatitude"].toDouble();
                        double hotelLongitude = jsonObject["hoteLongitude"].toDouble();
                        /*
                        double hotelLatitude = std::stod(hotelLatitudeStr);
                        double hotelLongitude = std::stod(hotelLongitudeStr);
                        */

                        if(town.empty() || hotel.empty()){
                            throw std::runtime_error("Empty Attribute (line "+ std::to_string(zeileNummer) + ")");
                        }

                        allBookings.push_back(std::make_shared<HotelBooking>(
                            id,
                            fromDate,
                            toDate,
                            price,
                            travelId,
                            predecessor1,
                            predecessor2,
                            town,
                            hotel,
                            roomType,
                            hotelLatitude,
                            hotelLongitude
                            ));
                        findTravel(travelId)->addBooking(allBookings.back());
\
                        hotelCount++;
                        totalHotelPrice += price;

                        //std::cout << hotelBooking->showDetails() << std::endl;
                    }
                    else if(type == "RentalCar"){
                        //extract from rental car
                        string pickupLocation = jsonObject["pickupLocation"].toString().toStdString();
                        string returnLocation = jsonObject["returnLocation"].toString().toStdString();
                        string company = jsonObject["company"].toString().toStdString();
                        string vehicleClass = jsonObject["vehicleClass"].toString().toStdString();

                        string pickupLatitudeStr = jsonObject["pickupLatitude"].toString().toStdString();
                        string pickupLongitudeStr = jsonObject["pickupLongitude"].toString().toStdString();
                        string returnLatitudeStr = jsonObject["returnLatitude"].toString().toStdString();
                        string returnLongitudeStr = jsonObject["returnLongitude"].toString().toStdString();

                        double pickupLatitude = jsonObject["pickupLatitude"].toDouble();
                        double pickupLongitude = jsonObject["pickupLongitude"].toDouble();
                        double returnLatitude = jsonObject["returnLatitude"].toDouble();
                        double returnLongitude = jsonObject["pickupLongitude"].toDouble();

                        /*
                        double pickupLatitude = std::stod(pickupLatitudeStr);
                        double pickupLongitude = std::stod(pickupLongitudeStr);
                        double returnLatitude = std::stod(returnLatitudeStr);
                        double returnLongitude = std::stod(returnLongitudeStr);
                        */

                        if(pickupLocation.empty() || returnLocation.empty() || company.empty()){
                            throw std::runtime_error("Empty Attribute (line "+ std::to_string(zeileNummer) + ")");
                        }
                        allBookings.push_back(std::make_shared<RentalCarReservation>(
                            id,
                            fromDate,
                            toDate,
                            price,
                            travelId,
                            predecessor1,
                            predecessor2,
                            pickupLocation,
                            returnLocation,
                            company,
                            vehicleClass,
                            pickupLatitude,
                            pickupLongitude,
                            returnLatitude,
                            returnLongitude
                            ));
                        findTravel(travelId)->addBooking(allBookings.back());

                        carCount++;
                        totalCarPrice += price;
                        //std::cout << rentalCarReservation->showDetails() << std::endl;
                    }
                    else if(type == "Train"){
                        //extract from train
                        string fromDestination = jsonObject["fromStation"].toString().toStdString();
                        string toDestination = jsonObject["toStation"].toString().toStdString();
                        string departureTime = jsonObject["departureTime"].toString().toStdString();
                        string arrivalTime = jsonObject["arrivalTime"].toString().toStdString(); //theres no arrivalTime in the json file, deswegen empty string.
                                                                                                //update: there is arrivalTime in json prak 4
                        vector<string> connectingStations;
                        string bookingClass = jsonObject["ticketType"].toString().toStdString();//theres no bookingClass in json

                        string fromStationLatitudeStr = jsonObject["fromStationLatitude"].toString().toStdString();
                        string fromStationLongitudeStr = jsonObject["fromStationLongitude"].toString().toStdString();
                        string toStationLatitudeStr = jsonObject["toStationLatitude"].toString().toStdString();
                        string toStationLongitudeStr = jsonObject["toStationLongitude"].toString().toStdString();

                        double fromStationLatitude = jsonObject["fromStationLatitude"].toDouble();
                        double fromStationLongitude = jsonObject["fromStationLongitude"].toDouble();
                        double toStationLatitude = jsonObject["toStationLatitude"].toDouble();
                        double toStationLongitude = jsonObject["toStationLongitude"].toDouble();
                        /*
                        double fromStationLatitude = std::stod(fromStationLatitudeStr);
                        double fromStationLongitude = std::stod(fromStationLongitudeStr);
                        double toStationLatitude = std::stod(toStationLatitudeStr);
                        double toStationLongitude = std::stod(toStationLongitudeStr);
                    */
                        vector<double> connectingStationsLatitude;
                        vector<double> connectingStationsLongitude;
                        //gk ada juga

                        if(jsonObject.contains("connectingStations") && jsonObject["connectingStations"].isArray()){
                            QJsonArray stationsArray = jsonObject["connectingStations"].toArray();

                            for(const QJsonValue &station : stationsArray){
                                QJsonObject stationObject = station.toObject();

                                if(stationObject.contains("stationName") && stationObject.contains("latitude") && stationObject.contains("longitude")){
                                    string stationName = stationObject["stationName"].toString().toStdString();

                                    string stationLatitudeStr = stationObject["latitude"].toString().toStdString();
                                    string stationLongitudeStr = stationObject["longitude"].toString().toStdString();

                                    double stationLatitude = stationObject["latitude"].toDouble();
                                    double stationLongitude = stationObject["longitude"].toDouble();

                                    /*
                                    double stationLatitude = std::stod(stationLatitudeStr);
                                    double stationLongitude = std::stod(stationLongitudeStr);
                                    */
                                    //double stationLongitude = std::stod(static_cast<string>(stationObject["longitude"].toString().toStdString()));

                                    connectingStations.push_back(stationName);
                                    connectingStationsLatitude.push_back(stationLatitude);
                                    connectingStationsLongitude.push_back(stationLongitude);
                                }
                            }
                        }

                        if(fromDestination.empty() || toDestination.empty() || departureTime.empty()){
                            throw std::runtime_error("Empty Attribute (line "+ std::to_string(zeileNummer) + ")");
                        }

                        allBookings.push_back(std::make_shared<TrainTicket>(
                            id,
                            fromDate,
                            toDate,
                            price,
                            travelId,
                            predecessor1,
                            predecessor2,
                            fromDestination,
                            toDestination,
                            departureTime,
                            arrivalTime,
                            connectingStations,
                            bookingClass,
                            fromStationLatitude,
                            fromStationLongitude,
                            toStationLatitude,
                            toStationLongitude,
                            connectingStationsLatitude,
                            connectingStationsLongitude
                            ));
                        findTravel(travelId)->addBooking(allBookings.back());

                        trainCount++;
                        totalTrainPrice += price;
                    }
                }
            }
            totalBookingPrice = totalHotelPrice + totalTrainPrice + totalFlightPrice + totalCarPrice;
        }
}

string TravelAgency::showTotal(){
        std::ostringstream result;
        result << "\nEs wurden " << flightCount  << " Flugreservierungen, " << hotelCount << " Hotelbuchungen und "
               << carCount << " Mietwagenreservierungen in Gesamtwert von " << totalBookingPrice << " EUR eingelesen.\n"
               << "Der Kunde mit der ID 1 hat "
               << travelId1/*(findCustomer(1)?static_cast<int>(findCustomer(1)->getTravelList().size()) : 0)*//*shud be 27 bookings*/
               << " Reisen gebucht. Zur reise mit der ID 17 gehoeren "
               << (findTravel(17) ? static_cast<int>(findTravel(17)->getTravelBookings().size()) : 0)
               << " Buchungen.\n\n";
        return result.str();
}
