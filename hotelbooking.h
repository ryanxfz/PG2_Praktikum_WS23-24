#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include "Booking.h"

using std::string;

class HotelBooking : public Booking{
private:
    string hotel;
    string town;
    string roomType;

    double hotelLatitude;
    double hotelLongitude;
public:
    HotelBooking(string& id, string& fromDate, string& toDate, double& price, long& travelId, string& predecessor1, string& predecessor2, string& town, string& hotel, string& roomType, double& hotelLatitude, double& hotelLongitude);
    virtual string showDetails() override;

    string getHotel() const;
    string getTown() const;
    string getRoomType() const;
    void setHotel(const string &newHotel);
    void setTown(const string &newTown);
    void setRoomType(const string &newRoomType);

    double getHotelLatitude() const;
    double getHotelLongitude() const;
};

#endif // HOTELBOOKING_H
