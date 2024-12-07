#ifndef BOOKING_H
#define BOOKING_H
#include <string>


using std::string;

class Booking{
protected:
    string id;
    string fromDate;
    string toDate;
    double price;
    long travelId;
    string predecessor1;
    string predecessor2;
public:
    Booking(string& id, string& fromDate, string& toDate, double& price, long& travelId, string& predecessor1, string& predecessor2);
    virtual ~Booking(); //virtual wegen Abstract
    virtual string showDetails() = 0;// pure virtual
    string getId() const;
    string getFromDate() const;
    string getToDate() const;
    double getPrice() const;
    long getTravelId() const;
    void setFromDate(const string &newFromDate);
    void setToDate(const string &newToDate);
    void setPrice(double newPrice);
    string getPredecessor1() const;
    void setPredecessor1(const string &newPredecessor1);
    string getPredecessor2() const;
    void setPredecessor2(const string &newPredecessor2);
};

#endif // BOOKING_H
