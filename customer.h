#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <memory>
#include <string>
#include "travel.h"

using std::string;
using std::shared_ptr;

class Customer
{
private:
    long id;
    string lastName;
    string firstName;
    vector<shared_ptr<Travel>> travelList;

public:
    Customer(long& id, string& lastName, string& firstName);
    void addTravel(shared_ptr<Travel> travel);
    long getId() const;
    string getLastName() const;
    string getFirstName() const;
    vector<shared_ptr<Travel>> getTravelList();
};

#endif // CUSTOMER_H
