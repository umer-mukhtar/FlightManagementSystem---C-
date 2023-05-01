#include <iostream>
#include <string>
#include "IntFlightTime.h"

IntFlightTime::IntFlightTime()
{

}

istream& operator>>(istream& istreamObj, IntFlightTime& flightTimeObj)
{
	istreamObj >> flightTimeObj.sourceCountry >> flightTimeObj.destCountry >> flightTimeObj.flightTime;
	return istreamObj;
}

void IntFlightTime::setFlightTime(string sourceCountry, string destCountry, Time flightTime) //the same as above function but with arguments
{
	this->sourceCountry = sourceCountry;
	this->destCountry = destCountry;
	//static int i = 0;
	//cout << i << " ";
	//cout << sourceCountry << " " << destCountry << endl;
	this->flightTime = flightTime;
	//i++;
}

string IntFlightTime::getSourceCountry()
{
	return sourceCountry;
}

string IntFlightTime::getDestCountry()
{
	return destCountry;
}

Time IntFlightTime::getFlightTime()
{
	//cout << sourceCountry << " " << destCountry << endl;
	//cout << endl;
	//cout << flightTime << endl;
	return flightTime;
}

IntFlightTime::~IntFlightTime()
{

}