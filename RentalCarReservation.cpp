#include "RentalCarReservation.h"
using std::string;

string RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

string RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

string RentalCarReservation::getCompany() const
{
    return company;
}

void RentalCarReservation::setPickupLocation(const string &newPickupLocation)
{
    pickupLocation = newPickupLocation;
}

void RentalCarReservation::setReturnLocation(const string &newReturnLocation)
{
    returnLocation = newReturnLocation;
}

void RentalCarReservation::setCompany(const string &newCompany)
{
    company = newCompany;
}

void RentalCarReservation::setVehicleClass(const string &newVehicleClass)
{
    vehicleClass = newVehicleClass;
}


double RentalCarReservation::getPickupLatitude() const
{
    return pickupLatitude;
}

double RentalCarReservation::getPickupLongitude() const
{
    return pickupLongitude;
}

double RentalCarReservation::getReturnLatitude() const
{
    return returnLatitude;
}

double RentalCarReservation::getReturnLongitude() const
{
    return returnLongitude;
}

RentalCarReservation::RentalCarReservation(string& id, string& fromDate, string& toDate, double& price, long& travelId, string& predecessor1, string& predecessor2, string& pickupLocation, string& returnLocation, string& company, string& vehicleClass, double& pickupLatitude, double& pickupLongitude, double& returnLatitude, double& returnLongitude)
    : Booking(id, fromDate, toDate, price, travelId, predecessor1, predecessor2)
{
    this->pickupLocation = pickupLocation;
    this->returnLocation = returnLocation;
    this->company = company;
    this->vehicleClass = vehicleClass;
    this->pickupLatitude = pickupLatitude;
    this->pickupLongitude = pickupLongitude;
    this->returnLatitude = returnLatitude;
    this->returnLongitude = returnLongitude;
}

string RentalCarReservation::getVehicleClass() const
{
    return vehicleClass;
}

string RentalCarReservation::showDetails()
{
    return "Mietwagenreservierung mit ID " + std::to_string(travelId) + " bei " + company + " mit Vehicle Class " + vehicleClass + ". Abholung am " + fromDate + " in " + pickupLocation + ". Ruckgabe am " + toDate + " in " + returnLocation + ". Preis: " + std::to_string(price) + " Euro \n";
}
