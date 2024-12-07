#include "customer.h"

Customer::Customer(long& id, string& lastName, string& firstName)
    :id(id),
    lastName(lastName),
    firstName(firstName)
{

}

void Customer::addTravel(shared_ptr<Travel> travel)
{
    travelList.push_back(travel);
}


long Customer::getId() const
{
    return id;
}

string Customer::getLastName() const
{
    return lastName;
}

string Customer::getFirstName() const
{
    return firstName;
}

vector<shared_ptr<Travel>> Customer::getTravelList()
{
    return travelList;
}


