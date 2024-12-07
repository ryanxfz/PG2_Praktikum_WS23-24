#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include "Booking.h"
#include "customer.h"
#include "travel.h"
#include "airport.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

using std::vector;
using std::unique_ptr;
using std::shared_ptr;

class TravelAgency{
private:
    vector<shared_ptr<Booking>> allBookings;
    vector<shared_ptr<Customer>> allCustomers;
    vector<shared_ptr<Travel>> allTravels;

    QMap<QString, std::shared_ptr<Airport>> airportsMap;

    //for missing hotel
    /*
    std::map<long, vector<string>> missingHotelsInfo;
    std::map<long, vector<string>> overlappingHotelsInfo;
*/

public:
    void readFile(QString &filePath);
    void readAirport(QString &filePathAirport);
    //getter for qmap
    QMap<QString, std::shared_ptr<Airport> > getAirports() const;

    TravelAgency();
    ~TravelAgency();
    string showTotal();

    shared_ptr<Booking>& findBooking(string id);
    shared_ptr<Travel>& findTravel(long id);
    shared_ptr<Customer>& findCustomer(long id);

    vector<shared_ptr<Booking>> getAllBookings() const;
    vector<shared_ptr<Customer>> getAllCustomers() const;
    vector<shared_ptr<Travel>> getAllTravels() const;

    /*
    // Method to check for missing hotels and store the information
    void storeMissingHotelInfo(long travelId, const std::string& missingHotelId);
    void storeOverlappingHotelInfo(long travelId, const std::string& overlappingHotelId);
    void storeOverlappingRentalCars(long travelId, const std::string& overlappingRentalCarID);

    // Method to get missing hotels information
    std::map<long, vector<string> > getMissingHotelsInfo() const;
    std::map<long, vector<string> > getOverlappingHotelsInfo() const;
*/
};

#endif // TRAVELAGENCY_H
