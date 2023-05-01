#pragma once
#include "Time.h"
#include "Date.h"
#include "Cost.h"
#include <string>

using namespace std;

class FlightSchedule {
protected:
	int flightID;
	string id;
	Time* flightDuration;
	Time departureTime;
	Date departureDate;
	int availableSeatsEco;
	int availableSeatsBusiness;
	int countOfStops;
	const int totalSeatsEco;
	const int totalSeatsBusiness;
	string flightStatus;
	string baseCity;
	Cost cost;
	Time totalFlightTime;
public:
	FlightSchedule();
	string getFlightStatus();
	int getFlightID();
	int getRemainingEcoSeats();
	void setFlightID(int);
	void setID(string);
	void setRemainingEcoSeats(int);
	void setRemainingBusinessSeats(int);
	void setFlightStatus(string);
	int getRemainingBusinessSeats();
		//+ setDepartureTime(int, int) : void
		//+ calculateArrivalTime(int, int) : void
		//+ calculateFlightDuration() : void
		//+ addToRoute(int id) : void
		//+ setID(int) : void
		//+ getID() : void
		//+ setDepartureDate(int) : void
		//+ getDepartureDate() : Date
		//+ setAvailableSeatsEco(int) : void
		//+ getAvailableSeatsEco() : int
		//+ setAvailableSeatsBusiness(int) : void
		//+ getAvailableSeatsBusiness() : int
		//+ setCountOfStops(int) : void
	~FlightSchedule();
};