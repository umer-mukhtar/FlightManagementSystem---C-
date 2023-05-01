#include <iostream>
#include <string>
#include <fstream>
#include "Time.h"
#include "Date.h"
#include "GlobalFunctions.h"
#include "Country.h"
#include "InternationalFlightSchedule.h"

using namespace std;

int InternationalFlightSchedule::getRouteCat()
{
	return routeCategory;
}

InternationalFlightSchedule::InternationalFlightSchedule()
{
	flightDuration = new Time[20];
	country = new string[20];
	city = new string[20];
	//routeCategory = 1 + rand() % 5;
	//switch (routeCategory)
	//{
	//case 1:
	//	countOfStops = 1 + rand() % 4;
	//	break;
	//case 2:
	//	countOfStops = 1 + rand() % 6;
	//	break;
	//case 3:
	//	countOfStops = 1 + rand() % 5;
	//	break;
	//case 4:
	//	countOfStops = 1 + rand() % 4;
	//	break;
	//case 5:
	//	countOfStops = 1 + rand() % 6;
	//	break;
	//}
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
	;	int toss2 = 0 + rand() % 10;
	switch (toss2)
	{
	case 0:
		baseCity = "IslamabadN";
		city[0] = "Islamabad";
		break;
	case 1:
		baseCity = "IslamabadS";
		city[0] = "Islamabad";
		break;
	case 2:
		baseCity = "LahoreN";
		city[0] = "Lahore";
		break;
	case 3:
		baseCity = "LahoreS";
		city[0] = "Lahore";
		break;
	case 4:
		baseCity = "PeshawarN";
		city[0] = "Peshawar";
		break;
	case 5:
		baseCity = "PeshawarS";
		city[0] = "Peshawar";
		break;
	case 6:
		baseCity = "QuettaN";
		city[0] = "Quetta";
		break;
	case 7:
		baseCity = "QuettaS";
		city[0] = "Quetta";
		break;
	case 8:
		baseCity = "KarachiN";
		city[0] = "Karachi";
		break;
	case 9:
		baseCity = "KarachiS";
		city[0] = "Karachi";
		break;
	}
	country[0] = "Pakistan";
}

void InternationalFlightSchedule::setCountOfStops(int countOfStops)
{
	this->countOfStops = countOfStops;
	//cout << countOfStops << endl;
}


istream& operator>>(istream& istreamObj, InternationalFlightSchedule& classObj)
{
	istreamObj >> classObj.flightID;
	istreamObj >> classObj.id; //plane ID
	istreamObj >> classObj.departureDate;
	int tempHrs; int tempMins;
	istreamObj >> tempHrs >> tempMins;
	Time tempObj(tempHrs, tempMins);
	classObj.departureTime = tempObj;
	istreamObj >> classObj.baseCity;
	classObj.city[0] = classObj.baseCity;
	classObj.country[0] = "Pakistan"; 
	istreamObj >> classObj.countOfStops;
	for (int i = 1; i < classObj.countOfStops + 1; i++)
	{
		istreamObj >> classObj.country[i];
	}
	istreamObj >> classObj.availableSeatsEco >> classObj.availableSeatsBusiness;
	istreamObj >> classObj.flightStatus;
	return istreamObj;
}

void InternationalFlightSchedule::makeCalculations(IntFlightTime intFlightTime[]) //makes calculations of all the departure/arrival times/dates
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
	//	cout << country[i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i < 20; i++)
	//{
	//	cout << country[i] << endl;
	//}
	double totalFlightDur = 0;
	for (int i = 0; i < countOfStops; i++)
	{
		for (int j = 0; j < 154; j++)
		{
			if (compareStrings(country[i], intFlightTime[j].getSourceCountry()) && compareStrings(country[i + 1], intFlightTime[j].getDestCountry()))
			{
				flightDuration[i] = intFlightTime[j].getFlightTime();
				totalFlightDur += flightDuration[i].getHoursOnly();
			}
		}
	}
	totalFlightDur += (1.00 * countOfStops - 1); //1 hour gap b/w international flights
	totalFlightTime.setHoursOnly(totalFlightDur);
}

ostream& operator<<(ostream& ostreamObj, InternationalFlightSchedule& classObj)
{
	if (lengthOfString(classObj.country[0] + ", " + classObj.baseCity) < 19)
	{
		ostreamObj << "Flight ID:" << classObj.flightID << "\tAirplane: " << classObj.id << "\t\t\tFrom: " << classObj.baseCity << ", " << classObj.country[0] << "\t\t\tTo: " << classObj.city[classObj.countOfStops] << ", " << classObj.country[classObj.countOfStops] << "\t\tStatus: " << classObj.flightStatus << endl;
	}
	else
	{
		ostreamObj << "Flight ID:" << classObj.flightID << "\tAirplane: " << classObj.id << "\t\t\tFrom: " << classObj.baseCity << ", " << classObj.country[0] << "\t\tTo: " << classObj.city[classObj.countOfStops] << ", " << classObj.country[classObj.countOfStops] << "\t\tStatus: " << classObj.flightStatus << endl;
	}
	ostreamObj << "Departure Date: " << classObj.departureDate << "\tDeparture Time: ";
	classObj.departureTime.displayTime();
	ostreamObj << "\t\t\tTotal Flight Duration: " << classObj.totalFlightTime << " (including 1 hour gap b/w each take-off)" << endl;
	cout << endl;
	for (int i = 0; i < classObj.countOfStops; i++)
	{
		if (lengthOfString(classObj.country[i] + ", " + classObj.city[i]) < 18)
		{
			ostreamObj << "From: " << classObj.city[i] << ", " << classObj.country[i] << "\t\t\tTo: " << classObj.city[i + 1] << ", " << classObj.country[i + 1];
		}
		else
		{
			ostreamObj << "From: " << classObj.city[i] << ", " << classObj.country[i] << "\t\tTo: " << classObj.city[i + 1] << ", " << classObj.country[i + 1];
		}
		if (lengthOfString(classObj.country[i + 1] + ", " + classObj.city[i + 1]) < 12)
		{
			ostreamObj << "\t\t\t\tFlight Duration: " << classObj.flightDuration[i] << endl;
		}
		else if (lengthOfString(classObj.country[i + 1] + ", " + classObj.city[i + 1]) < 20)
		{
			ostreamObj << "\t\t\tFlight Duration: " << classObj.flightDuration[i] << endl;
		}
		else
		{
			ostreamObj << "\t\tFlight Duration: " << classObj.flightDuration[i] << endl;
		}
	}
	cout << "Available Seats (Economy): " << classObj.availableSeatsEco << endl;
	cout << "Available Seats (Business): " << classObj.availableSeatsBusiness;
	cout << endl << endl << endl;
	return ostreamObj;
}

Cost InternationalFlightSchedule::getFlightCost(string countryOfPassenger)
{
	Cost c("INT");
	double timeOfPassengerFlight = 0;
	for (int i = 0;; i++)
	{
		if (compareStrings(country[i], countryOfPassenger))
		{
			break;
		}
		timeOfPassengerFlight += flightDuration[i].getHoursOnly();
	}
	c.setFlightCost(timeOfPassengerFlight * 20000.0);
	this->cost = c;
	return c;
}

void InternationalFlightSchedule::setCity(string city,int index)
{
	this->city[index] = city;
}

void InternationalFlightSchedule::setCountry(string country, int index)
{
	this->country[index] = country;
}

int InternationalFlightSchedule::getCountOfStops()
{
	return countOfStops;
}

string InternationalFlightSchedule::getCountry(int index)
{
	return country[index];
}

InternationalFlightSchedule::~InternationalFlightSchedule()
{

}