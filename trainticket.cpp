#include "trainticket.h"

string TrainTicket::getFromDestination() const
{
    return fromDestination;
}

string TrainTicket::getToDestination() const
{
    return toDestination;
}

string TrainTicket::getDepartureTime() const
{
    return departureTime;
}

string TrainTicket::getArrivalTime() const
{
    return arrivalTime;
}

std::vector<string> TrainTicket::getConnectingStations() const
{
    return connectingStations;
}

string TrainTicket::getBookingClass() const
{
    return bookingClass;
}

void TrainTicket::setFromDestination(const string &newFromDestination)
{
    fromDestination = newFromDestination;
}

void TrainTicket::setToDestination(const string &newToDestination)
{
    toDestination = newToDestination;
}

void TrainTicket::setDepartureTime(const string &newDepartureTime)
{
    departureTime = newDepartureTime;
}

void TrainTicket::setArrivalTime(const string &newArrivalTime)
{
    arrivalTime = newArrivalTime;
}

void TrainTicket::setConnectingStations(const std::vector<string> &newConnectingStations)
{
    connectingStations = newConnectingStations;
}

void TrainTicket::setBookingClass(const string &newBookingClass)
{
    bookingClass = newBookingClass;
}

double TrainTicket::getFromStationLatitude() const
{
    return fromStationLatitude;
}

double TrainTicket::getFromStationLongitude() const
{
    return fromStationLongitude;
}

double TrainTicket::getToStationLatitude() const
{
    return toStationLatitude;
}

double TrainTicket::getToStationLongitude() const
{
    return toStationLongitude;
}

std::vector<double> TrainTicket::getConnectingStationsLatitude() const
{
    return connectingStationsLatitude;
}

std::vector<double> TrainTicket::getConnectingStationsLongitude() const
{
    return connectingStationsLongitude;
}

TrainTicket::TrainTicket(string& id, string& fromDate, string& toDate, double& price, long& travelId, string& predecessor1, string& predecessor2, string& fromDestination, string& toDestination, string& departureTime, string& arrivalTime, std::vector<string>& connectingStations, string& bookingClass, double& fromStationLatitude, double& fromStationLongitude, double& toStationLatitude, double& toStationLongitude, std::vector<double>& connectingStationsLatitude, std::vector<double>& connectingStationsLongitude)
    : Booking(id, fromDate, toDate, price, travelId, predecessor1, predecessor2)
{
    this->fromDestination = fromDestination;
    this->toDestination = toDestination;
    this->departureTime = departureTime;
    this->arrivalTime = arrivalTime;
    this->connectingStations = connectingStations;
    this->bookingClass = bookingClass;
    this->fromStationLatitude = fromStationLatitude;
    this->fromStationLongitude = fromStationLongitude;
    this->toStationLatitude = toStationLatitude;
    this->toStationLongitude = toStationLongitude;
    this->connectingStationsLatitude = connectingStationsLatitude;
    this->connectingStationsLongitude = connectingStationsLongitude;
}

string TrainTicket::showDetails(){
    string details = "Zugticket mit ID " + std::to_string(travelId) + " und Booking Class " + bookingClass + " von " + fromDestination + " nach " + toDestination + " am " + fromDate + " um " + departureTime;
    if(!connectingStations.empty()){
        details += " uber ";
        for(unsigned int i = 0; i < connectingStations.size(); i++){
            details += connectingStations[i];
            if(i < connectingStations.size() - 1){//check if it's the last station or not. If not, add coma.
                details += ", ";
            }
            else{
                details += "\n";
            }
        }
    }
    return details;
}

string TrainTicket::showConnectingStationsDetails() const{
    string stationDetails;
    if(!connectingStations.empty()){
        for(unsigned int i = 0; i < connectingStations.size(); i++){
            stationDetails += connectingStations[i];
            if(i < connectingStations.size() - 1){//check if it's the last station or not. If not, add line break.
                stationDetails += "\n";
            }
        }
    }
    return stationDetails;
}

