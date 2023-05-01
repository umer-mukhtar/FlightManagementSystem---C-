#pragma once
#include "Airport.h"
#include "Time.h"

class Country : public Airport
{
	double distanceFromPak;//distance from pakistan in kms
	Time flightTimeFromPak;
	bool travelRestrictions;
	string country;
		//- city : string
public:
	Country();
	friend istream& operator>>(istream&, Country&);
	void setDistanceFromPak(double);
	double getDistanceFromPak();
	void setFlightTImeFromPak(Time);
	Time getFlightTimeFromPak();
	void setTravelRestrictions(bool);
	bool getTravelRestrictions();
	void setCountry(string);
	string getCountry();
	~Country();
};

