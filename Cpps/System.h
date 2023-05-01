#pragma once
#include "Display.h"
#include "ErrorMessage.h"
#include "Passenger.h"
#include "AdminTeam.h"
#include "City.h"
#include "Country.h"
#include "InternationalFlightSchedule.h"
#include "LocalFlightSchedule.h"
#include "Route.h"
#include "IntFlightTime.h"
#include "LocalFlightSchedule.h"

class System
{
	static FlightSchedule* flightSchedule;
	static User* currentUser;
	static IntFlightTime* locFlightTime;
	static Passenger currentPassenger;
	static AdminTeam currentAdmin;
	static Route* locRoute;
	static Airport* airport;
	static Country* country;
	static City* city;
	static InternationalFlightSchedule* intFlightSch;
	static LocalFlightSchedule* locFlightSch;
	static Country mostVisitedCountry;
	static Route* route;
	static IntFlightTime* intFlightTime; //international flight time
public:
	System();
	void initializeData();
	static void centralControl();
	static void adminTeamControl();
	static void passengerControl();
	~System();
};