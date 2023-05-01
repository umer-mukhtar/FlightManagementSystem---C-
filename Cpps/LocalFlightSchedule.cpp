#include "LocalFlightSchedule.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Time.h"
#include "Date.h"
#include "GlobalFunctions.h"
#include "Country.h"
#include "IntFlightTime.h"

using namespace std;

void LocalFlightSchedule::setBaseCity(string baseCity)
{
	this->city[0] = baseCity;
	this->baseCity = baseCity;
}

LocalFlightSchedule::LocalFlightSchedule()
{
	flightDuration = new Time[100];
	city = new string[100];
	int tossNum = 0 + rand() % 10;
	switch (tossNum)
	{
	case 0:
		flightStatus = "Cancelled";
		break;
	default:
		flightStatus = "Expected";
		break;
	}
	departureTime.setHours(0 + rand() % 24);
	departureTime.setMinutes(10 + rand() % 60);
	departureDate.setData(23, 6, 2021);
}

void LocalFlightSchedule::setCountOfStops(int countOfStops)
{
	this->countOfStops = countOfStops;
	//cout << countOfStops << endl;
}


istream& operator>>(istream& istreamObj, LocalFlightSchedule& classObj)
{
	//istreamObj >> classObj.flightID;
	//istreamObj >> classObj.id; //plane ID
	//istreamObj >> classObj.departureDate;
	//int tempHrs; int tempMins;
	//istreamObj >> tempHrs >> tempMins;
	//Time tempObj(tempHrs, tempMins);
	//classObj.departureTime = tempObj;
	//istreamObj >> classObj.baseCity;
	//classObj.city[0] = classObj.baseCity;
	//classObj.country[0] = "Pakistan";
	//istreamObj >> classObj.countOfStops;
	//for (int i = 1; i < classObj.countOfStops + 1; i++)
	//{
	//	istreamObj >> classObj.country[i];
	//}
	//istreamObj >> classObj.availableSeatsEco >> classObj.availableSeatsBusiness;
	//istreamObj >> classObj.flightStatus;
	return istreamObj;
}

void LocalFlightSchedule::makeCalculations(IntFlightTime intFlightTime[]) //makes calculations of all the departure/arrival times/dates
{
	//double flightDuration;
	//Time* departureTime;
	//Time* arrivalTime;
	//Date* departurDate;
	//Date* arrivalDate;
	//Cost cost;
	//cout << endl << endl;
	//for (int i = 0; i < countOfStops; i++)
	//{
	//	cout << city[i] << " ";
	//}
	//cout << endl;
	double totalFlightDur = 0;
	for (int i = 0; i < countOfStops; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (compareStrings(city[i], intFlightTime[j].getSourceCountry()) && compareStrings(city[i + 1], intFlightTime[j].getDestCountry()))
			{
				flightDuration[i] = intFlightTime[j].getFlightTime();
				totalFlightDur += flightDuration[i].getHoursOnly();
			}
		}
	}
	totalFlightDur += (2.00 * countOfStops - 1); //2 hour gap b/w Local flights
	totalFlightDur -= 1.00;
	totalFlightTime.setHoursOnly(totalFlightDur);
}

ostream& operator<<(ostream& ostreamObj, LocalFlightSchedule& classObj)
{
	ostreamObj << "Flight ID:" << classObj.flightID << "\tAirplane: " << classObj.id << "\t\t\tFrom: " << classObj.city[0] << "\t\tTo: " << classObj.city[classObj.countOfStops] << "\t\tStatus: " << classObj.flightStatus << endl;
	ostreamObj << "\nDeparture Date: " << classObj.departureDate << "\tDeparture Time: ";
	classObj.departureTime.displayTime();
	ostreamObj << "\t\t\tTotal Flight Duration: " << classObj.totalFlightTime << " (including 2 hour gap b/w each take-off)" << endl;
	cout << endl;
	for (int i = 0; i < classObj.countOfStops; i++)
	{
		ostreamObj << "From: " << classObj.city[i] << "\t\tTo: " << classObj.city[i + 1];
		ostreamObj << "\t\tFlight Duration: " << classObj.flightDuration[i] << endl;
	}
	cout << "Available Seats (Economy): " << classObj.availableSeatsEco << endl;
	cout << "Available Seats (Business): " << classObj.availableSeatsBusiness;
	cout << endl << endl << endl;
	return ostreamObj;
}

Cost LocalFlightSchedule::getFlightCost(string countryOfPassenger)
{
	Cost c("LOC");
	double timeOfPassengerFlight = 0;
	for (int i = 0;; i++)
	{
		if (compareStrings(city[i], countryOfPassenger))
		{
			break;
		}
		timeOfPassengerFlight += flightDuration[i].getHoursOnly();
	}
	c.setFlightCost(timeOfPassengerFlight * 10000.0);
	this->cost = c;
	return c;
}

void LocalFlightSchedule::setCity(string city, int index)
{
	this->city[index] = city;
}

int LocalFlightSchedule::getCountOfStops()
{
	return countOfStops;
}

string LocalFlightSchedule::getCity(int index)
{
	return city[index];
}

LocalFlightSchedule::~LocalFlightSchedule()
{

}