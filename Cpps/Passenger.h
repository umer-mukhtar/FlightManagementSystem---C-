#pragma once
#include "User.h"
#include "AccountDetails.h"
#include "InternationalFlightSchedule.h"
#include "TravelHistory.h"
#include "LocalFlightSchedule.h"
#include "Country.h"


class Passenger : public User
{
	bool registrationStatus;
	string cnic;
	int age;
	AccountDetails accountDetails;
	bool visaStatus;
	TravelHistory travelHist;
	int* reservedFlightID;
	bool discount;
	int reservedFlightCount;
public:
	Passenger();
	void userLogin();
	string mostVisitedCountry();
	void validateNewUsername(string);
	void validateNewPassword(string);
	bool validateLoginInformation(string, string);
	void registerUser();
	string getPassword();
	string getUsername();
	void bookFlight(string, LocalFlightSchedule&, Cost& , char);
	void displayReservedFlights(InternationalFlightSchedule[]);
	void assignRandomData(Country[]);
	void cancelFlight(int);
	bool getDiscount();
	void travelHistoryFrequent();
		//+Passenger()
		//+ userLogin() : void
		//+ validateLoginInformation(string, string) : bool
		//+ validateRegistrationInformation(string, string) : bool
		//+ getUsername() : int
		//+ setUsername(string) : void
		//+ setPassword(string) : void
		//+ setAge(int) : void
		//+ setVisaStatus(bool) : void
		//+ editDetails() : void
		//+ displayMostVisitedCountry() : void
		//+ checkForDiscount() : bool
	void bookFlight(string, InternationalFlightSchedule&, Cost&, char);
	bool getVisa();
		//+ cancelReservation(InternationalFlightSchedule[], localFlightSchedule[]) : void
	~Passenger();
};

