#include "hotelbooking.h"

string HotelBooking::getHotel() const
{
    return hotel;
}

string HotelBooking::getTown() const
{
    return town;
}

string HotelBooking::getRoomType() const
{
    return roomType;
}

void HotelBooking::setHotel(const string &newHotel)
{
    hotel = newHotel;
}

void HotelBooking::setTown(const string &newTown)
{
    town = newTown;
}

void HotelBooking::setRoomType(const string &newRoomType)
{
    roomType = newRoomType;
}

double HotelBooking::getHotelLatitude() const
{
    return hotelLatitude;
}

double HotelBooking::getHotelLongitude() const
{
    return hotelLongitude;
}


HotelBooking::HotelBooking(string& id, string& fromDate, string& toDate, double& price, long& travelId, string& predecessor1, string& predecessor2, string& hotel, string& town, string& roomType, double& hotelLatitude, double& hotelLongitude)
    : Booking(id, fromDate, toDate, price, travelId, predecessor1, predecessor2)
{
    this->hotel = hotel;
    this->town = town;
    this->roomType = roomType;
    this->hotelLatitude = hotelLatitude;
    this->hotelLongitude = hotelLongitude;
}

string HotelBooking::showDetails(){
    return "Hotelreservierung mit ID " + std::to_string(travelId) + " im " + hotel + " mit room type "+ roomType + " in " + town + " vom " + fromDate + " bis zum " + toDate + ". Preis: " + std::to_string(price) + " Euro \n";
}
