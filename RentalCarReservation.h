#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include "Booking.h"

class RentalCarReservation : public Booking{
private:
    string pickupLocation;
    string returnLocation;
    string company;
    string vehicleClass;

    double pickupLatitude;
    double pickupLongitude;
    double returnLatitude;
    double returnLongitude;
public:
    RentalCarReservation(string& id, string& fromDate, string& toDate, double& price, long& travelId, string& predecessor1, string& predecessor2, string& pickupLocation, string& returnLocation, string& company, string& vehicleClass, double& pickupLatitude, double& pickupLongitude, double& returnLatitude, double& returnLongitude);
    virtual string showDetails() override;
    string getPickupLocation() const;
    string getReturnLocation() const;
    string getCompany() const;
    string getVehicleClass() const;
    void setPickupLocation(const string &newPickupLocation);
    void setReturnLocation(const string &newReturnLocation);
    void setCompany(const string &newCompany);
    void setVehicleClass(const string &newVehicleClass);

    double getPickupLatitude() const;
    double getPickupLongitude() const;
    double getReturnLatitude() const;
    double getReturnLongitude() const;
};

#endif // RENTALCARRESERVATION_H
