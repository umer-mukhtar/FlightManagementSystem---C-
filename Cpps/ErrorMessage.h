#pragma once
class ErrorMessage
{
public:
	ErrorMessage();
	static void outOfBoundsError();
	static void invalidUsername();
	static void invalidOption();
	static void loginFailed();
	static void registrationFailed(int);
	static void changeScheduleError();
	static void addRouteError();
	static void restrictPasswordEror();
	static void resumeFlightError();
	static void resetPasswordErrorAdmin();
	static void editDetailsErrorPassenger();
	static void balanceError();
	static void flightNotFound();
	static void visaError();
	static void outOfSeats();
	static void invalidCountryError();
	static void bookFlightError();
	static void blockFlightError();
	static void cancelFlightError();
	static void financialError();
	static void returnToMainMenu();
	~ErrorMessage();
};

