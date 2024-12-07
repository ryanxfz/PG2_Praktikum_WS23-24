#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include "Booking.h"


class FlightBooking : public Booking{
private:
    string fromDestination;
    string toDestination;
    string airline;
    string bookingClass;

    double fromDestLatitude;
    double fromDestLongitude;
    double toDestLatitude;
    double toDestLongitude;
public:
    FlightBooking(string& id, string& fromDate, string& toDate, double& price, long& travelId, string& predecessor1, string& predecessor2, string& fromDestination, string& toDestination, string& airline, string& bookingClass,
                  double& fromDestLatitude, double& fromDestLongitude, double& toDestLatitude, double& toDestLongitude);
    virtual string showDetails() override;
    string getFromDestination() const;
    string getToDestination() const;
    string getAirline() const;
    string getBookingClass() const;
    void setFromDestination(const string &newFromDestination);
    void setToDestination(const string &newToDestination);
    void setAirline(const string &newAirline);
    void setBookingClass(const string &newBookingClass);

    double getFromDestLatitude() const;
    double getFromDestLongitude() const;
    double getToDestLatitude() const;
    double getToDestLongitude() const;
};

#endif // FLIGHTBOOKING_H
