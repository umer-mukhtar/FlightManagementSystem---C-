#pragma once
#include "FlightSchedule.h"
#include "IntFlightTime.h"
#include "Route.h"
#include <string>

using namespace std;

class InternationalFlightSchedule :public FlightSchedule
{
	string* country; //these are the countries where the flight takes stops
	string* city;
	int routeCategory; //route 1,2,3,4,5
	//Route route;
public:
	InternationalFlightSchedule();
	void setCity(string, int);
	int getCountOfStops();
	Cost getFlightCost(string);
	string getCountry(int);
	void setCountry(string, int);
	int getRouteCat();
	void setCountOfStops(int);
	friend istream& operator>>(istream&, InternationalFlightSchedule&);
	friend ostream& operator<<(ostream&, InternationalFlightSchedule&);
	void makeCalculations(IntFlightTime[]);
	~InternationalFlightSchedule();
};

