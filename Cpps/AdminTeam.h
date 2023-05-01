#pragma once
#include "User.h"
class AdminTeam : public User
{
	//no private members
public:
	AdminTeam();
	void userLogin();
	bool validateLoginInformation(string, string);
		//+AdminTeam()
		//+ userLogin() : void
		//+ validateLoginInformation(string, string) : bool
		//+ changeSchedule(InternationalFlightSchedule[], localFlightSchedule[]) : void
		//+ addRouteLocalFlight(localFlightSchedule[], City[]) : void
		//+ addRouteInternationalFlight(InternationalFlightSchedule[], Country[]) : void
		//+ restrictNumberOfPassengers(InternationalFlightSchedule[], localFlightSchedule[]) : void
		//+ blockFlight(InternationalFlightSchedule[]) : void
		//+ resumeFlight(InternationalFlightSchedule[]) : void
		//+ resetPassword() : void
		//+ ~AdminTeam()
	~AdminTeam();
};

