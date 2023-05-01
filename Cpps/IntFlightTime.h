#pragma once
#include "Time.h"
#include <string>

using namespace std;

class IntFlightTime
{
	string sourceCountry;
	string destCountry;
	Time flightTime;
public:
	IntFlightTime();
	string getSourceCountry();
	string getDestCountry();
	Time getFlightTime();
	void setFlightTime(string, string, Time);
	friend istream& operator>>(istream&, IntFlightTime&);
	~IntFlightTime();
};