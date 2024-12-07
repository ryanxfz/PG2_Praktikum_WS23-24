#include "Booking.h"


string Booking::getId() const
{
    return id;
}

string Booking::getFromDate() const
{
    return fromDate;
}

string Booking::getToDate() const
{
    return toDate;
}

double Booking::getPrice() const
{
    return price;
}

long Booking::getTravelId() const
{
    return travelId;
}

void Booking::setFromDate(const string &newFromDate)
{
    fromDate = newFromDate;
}

void Booking::setToDate(const string &newToDate)
{
    toDate = newToDate;
}

void Booking::setPrice(double newPrice)
{
    price = newPrice;
}

string Booking::getPredecessor1() const
{
    return predecessor1;
}

void Booking::setPredecessor1(const string &newPredecessor1)
{
    predecessor1 = newPredecessor1;
}

string Booking::getPredecessor2() const
{
    return predecessor2;
}

void Booking::setPredecessor2(const string &newPredecessor2)
{
    predecessor2 = newPredecessor2;
}

Booking::Booking(string& id, string& fromDate, string& toDate, double &price, long &travelId, string& predecessor1, string& predecessor2){
    this->id = id;
    this->fromDate = fromDate;
    this->toDate = toDate;
    this->price = price;
    this->travelId = travelId;
    this->predecessor1 = predecessor1;
    this->predecessor2 = predecessor2;
}

Booking::~Booking(){

}

string Booking::showDetails(){

}
