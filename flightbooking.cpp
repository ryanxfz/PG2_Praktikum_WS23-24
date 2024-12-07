#include "flightbooking.h"
#include <iostream>


string FlightBooking::getBookingClass() const
{
    return bookingClass;
}

void FlightBooking::setFromDestination(const string &newFromDestination)
{
    fromDestination = newFromDestination;
}

void FlightBooking::setToDestination(const string &newToDestination)
{
    toDestination = newToDestination;
}

void FlightBooking::setAirline(const string &newAirline)
{
    airline = newAirline;
}

void FlightBooking::setBookingClass(const string &newBookingClass)
{
    bookingClass = newBookingClass;
}


double FlightBooking::getFromDestLatitude() const
{
    return fromDestLatitude;
}

double FlightBooking::getFromDestLongitude() const
{
    return fromDestLongitude;
}

double FlightBooking::getToDestLatitude() const
{
    return toDestLatitude;
}

double FlightBooking::getToDestLongitude() const
{
    return toDestLongitude;
}

FlightBooking::FlightBooking(string& id, string& fromDate, string& toDate, double& price, long& travelId, string& predecessor1, string& predecessor2, string& fromDestination, string& toDestination, string& airline, string& bookingClass, double& fromDestLatitude, double& fromDestLongitude, double& toDestLatitude, double& toDestLongitude)
    : Booking(id, fromDate, toDate, price, travelId, predecessor1, predecessor2)
{
    this->fromDestination = fromDestination;
    this->toDestination = toDestination;
    this->airline = airline;
    this->bookingClass = bookingClass;
    this->fromDestLatitude = fromDestLatitude;
    this->fromDestLongitude = fromDestLongitude;
    this->toDestLatitude = toDestLatitude;
    this->toDestLongitude = toDestLongitude;
}

string FlightBooking::showDetails(){
    return "Flugbuchung mit ID " + std::to_string(travelId) + " of booking class " + bookingClass + "von " + fromDestination + " nach " + toDestination + " am " + fromDate + ". Preis: " + std::to_string(price) + " Euro \n";
    //used to_string() because you wanna return all string.
}

string FlightBooking::getFromDestination() const
{
    return fromDestination;
}

string FlightBooking::getToDestination() const
{
    return toDestination;
}

string FlightBooking::getAirline() const
{
    return airline;
}
