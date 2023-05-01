#include <string>
#include <cstdlib>
#include "FlightSchedule.h"

using namespace std;

FlightSchedule::FlightSchedule() : totalSeatsEco(50), totalSeatsBusiness(10) {
	availableSeatsBusiness = 0 + rand() % 11;
	availableSeatsEco = 0 + rand() % 51;
}

string FlightSchedule::getFlightStatus()
{
	return flightStatus;
}

void FlightSchedule::setRemainingEcoSeats(int seats)
{
	this->availableSeatsEco = seats;
}

void FlightSchedule::setFlightStatus(string status)
{
	this->flightStatus = status;
}

void FlightSchedule::setRemainingBusinessSeats(int seats)
{
	this->availableSeatsBusiness = seats;
}

int FlightSchedule::getFlightID()
{
	return flightID;
}

int FlightSchedule::getRemainingEcoSeats()
{
	return availableSeatsEco;
}

int FlightSchedule::getRemainingBusinessSeats()
{
	return availableSeatsBusiness;
}

FlightSchedule::~FlightSchedule()
{

}

void FlightSchedule::setFlightID(int flightID)
{
	this->flightID = flightID;
}

void FlightSchedule::setID(string id)
{
	this->id = id;
}


//Time* flightDuration;
//Time departureTime;
//Date departureDate;
//int availableSeatsEco;
//int availableSeatsBusiness;
//int countOfStops;
//const int totalSeatsEco;
//const int totalSeatsBusiness;
//string flightStatus;
//string baseCity;
//Cost cost;
//Time totalFlightTime;
