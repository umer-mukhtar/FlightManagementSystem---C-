#pragma once
#include "InternationalFlightSchedule.h"
#include "LocalFlightSchedule.h"
#include "Country.h"
#include "City.h"

class Display
{
public:
	Display();
	static void displayMainMenu();
	static void displaySecondaryMenu();
	static void displayLoginMenu();
	static void displayRegistrationForm();
	static void displayAdminMenu();
	static void registrationSuccessfulMessage();
	static void displayInformationPanel();
	static void displayFlightTypeMenu();
	static void successful();
	static void successful2();
	static void displayChangeScheduleMenu();
	static void usernameChanged();
	static void flightCancelled();
	static void passwordChanged();
	static void displayBookFlightSecondaryMenu();
	static void seatBookedSuccessfully();
	static void displayFlightSchedule(InternationalFlightSchedule []);
	static void displayFlightSchedule(LocalFlightSchedule []);
	static void displayCountries(Country []);
	static void displayCities(City []);
	static void displayRestrictPassengersMenu();
	static void displayPassengerMenu();
	static void displayEditDetailsMenu();
	static void displayBookFlightMenu();
	~Display();
};

