#pragma once
#include "Date.h"
#include "Country.h"
#include <string>

using namespace std;

class TravelHistory
{
	Date* date;
	int countOfFlights;
	string* country;
public:
	TravelHistory();
	string mostVisitedCtr();
	int getCountOfFlights();
	string getCountry(int);
	Date getDate(int);
	void setCountries(Country []);
	~TravelHistory();
};

