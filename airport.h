#ifndef AIRPORT_H
#define AIRPORT_H
#include <string>
using std::string;

class Airport
{
private:
    string name;
    string iso_country;
    string municipality;
    string iata_code;

public:
    Airport(const string &name, const string &iso_country, const string &municipality, const string &iata_code);
    string getName() const;
    string getIso_country() const;
    string getMunicipality() const;
    string getIata_code() const;
};

#endif // AIRPORT_H
