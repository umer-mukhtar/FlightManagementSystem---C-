#include <iostream>
#include <string>
#include "Country.h"

using namespace std;

Country::Country()
{

}

istream& operator>>(istream& istreamObj, Country& countryObj)
{
	istreamObj >> countryObj.id >> countryObj.city >> countryObj.country >> countryObj.distanceFromPak >> countryObj.flightTimeFromPak >> countryObj.travelRestrictions;
	return istreamObj;
}

void Country::setDistanceFromPak(double distanceFromPak)
{
	this->distanceFromPak = distanceFromPak;
}

double Country::getDistanceFromPak()
{
	return distanceFromPak;
}

void Country::setFlightTImeFromPak(Time flightTimeFromPak)
{
	this->flightTimeFromPak = flightTimeFromPak;
}

Time Country::getFlightTimeFromPak()
{
	return flightTimeFromPak;
}

void Country::setTravelRestrictions(bool travelRestrictions) 
{
	this->travelRestrictions = travelRestrictions;
}

bool Country::getTravelRestrictions()
{
	return travelRestrictions;
}

void Country::setCountry(string country)
{
	this->country = country;
}

string Country::getCountry()
{
	return country;
}

Country::~Country()
{

}