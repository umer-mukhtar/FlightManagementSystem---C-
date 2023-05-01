#pragma once
#include <iostream>
#include <string>
#include "IntFlightTime.h"
#include "FlightSchedule.h"

using namespace std;

class LocalFlightSchedule :
    public FlightSchedule
{
	string* city;
public:
	LocalFlightSchedule();
	void setCity(string, int);
	int getCountOfStops();
	Cost getFlightCost(string);
	void setBaseCity(string);
	//void setCity(string, int);
	int getRouteCat();
	string getCity(int);
	void setCountOfStops(int);
	friend istream& operator>>(istream&, LocalFlightSchedule&);
	friend ostream& operator<<(ostream&, LocalFlightSchedule&);
	void makeCalculations(IntFlightTime[]);
	~LocalFlightSchedule();

};

