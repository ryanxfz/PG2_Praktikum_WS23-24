#ifndef TRAINTICKET_H
#define TRAINTICKET_H
#include "Booking.h"
#include <vector>


class TrainTicket : public Booking
{
private:
    string fromDestination;
    string toDestination;
    string departureTime;
    string arrivalTime;
    std::vector<string> connectingStations;
    string bookingClass;

    double fromStationLatitude;
    double fromStationLongitude;
    double toStationLatitude;
    double toStationLongitude;
    std::vector<double> connectingStationsLatitude;
    std::vector<double> connectingStationsLongitude;

public:
    TrainTicket(string& id, string& fromDate, string& toDate, double& price, long& travelId, string& predecessor1, string& predecessor2, string& fromDestination, string& toDestination, string& departureTime, string& arrivalTime, std::vector<string>& connectingStations, string& bookingClass, double& fromStationLatitude, double& fromStationLongitude, double& toStationLatitude, double& toStationLongitude, std::vector<double>& connectingStationsLatitude, std::vector<double>& connectingStationsLongitude);
    virtual string showDetails() override; //to access the virtual in booking

    string showConnectingStationsDetails() const;
    string getFromDestination() const;
    string getToDestination() const;
    string getDepartureTime() const;
    string getArrivalTime() const;
    std::vector<string> getConnectingStations() const;
    string getBookingClass() const;
    void setFromDestination(const string &newFromDestination);
    void setToDestination(const string &newToDestination);
    void setDepartureTime(const string &newDepartureTime);
    void setArrivalTime(const string &newArrivalTime);
    void setConnectingStations(const std::vector<string> &newConnectingStations);
    void setBookingClass(const string &newBookingClass);

    double getFromStationLatitude() const;
    double getFromStationLongitude() const;
    double getToStationLatitude() const;
    double getToStationLongitude() const;
    std::vector<double> getConnectingStationsLatitude() const;
    std::vector<double> getConnectingStationsLongitude() const;
};

#endif // TRAINTICKET_H
