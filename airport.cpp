#include "airport.h"

Airport::Airport(const string &name, const string &iso_country, const string &municipality, const string &iata_code) :
    name(name),
    iso_country(iso_country),
    municipality(municipality),
    iata_code(iata_code)
{}

string Airport::getName() const
{
    return name;
}

string Airport::getIso_country() const
{
    return iso_country;
}

string Airport::getMunicipality() const
{
    return municipality;
}

string Airport::getIata_code() const
{
    return iata_code;
}
