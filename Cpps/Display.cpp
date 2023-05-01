#include <iostream>
#include "windows.h"
#include "System.h"
#include "Display.h"

using namespace std;

Display::Display()
{

}

void Display::displayMainMenu() //displays the main menu of the system
{
	system("CLS");
	cout << "********************WELCOME TO NPASF*********************" << endl << endl;
	cout << "1) Login/Register\n2) View basic details\n3) Exit\nOption: ";
}

void Display::displaySecondaryMenu()
{
	system("CLS");
	cout << "********************NPAFS*********************" << endl << endl;
	cout << "1) Login as Admin\n2) Login as Passenger\n3) Don't have an account? Register\n4) Return to main menu\nOption: ";
}

void  Display::displayLoginMenu()
{

}

void Display::displayRegistrationForm()
{
	cout << "\nYou will need to pick a username that has not been used and a password. Your age and CNIC number will\nalso be required. An adult passenger can register for passengers under 18\n" << endl;
}

void  Display::displayAdminMenu()
{
	system("CLS");
	cout << "********************NPAFS ADMIN CONTROL*********************" << endl << endl;
	cout << "1) Change schedule\n2) Add route to flight\n3) Restrict number of passengers in a flight\n4) Restrict travel to country\n5) Resume travel to country\n6) Return to main menu\nOption: ";
}

void  Display::displayInformationPanel()
{

}

void Display::usernameChanged()
{
	cout << "Username changed successful. Please wait. You will be redirected in ";
	Display::successful();
}

void Display::passwordChanged()
{
	cout << "Password changed successful. Please wait. You will be redirected in ";
	Display::successful();
}

void Display::flightCancelled()
{
	cout << "Sorry the flight has been cancelled. You will be redirected in ";
	Display::successful();
}


void  Display::displayChangeScheduleMenu()
{

}

void  Display::displayFlightSchedule(InternationalFlightSchedule[])
{

}

void  Display::displayFlightSchedule(LocalFlightSchedule[])
{

}

void  Display::displayCountries(Country[])
{

}

void  Display::displayCities(City[])
{

}

void  Display::displayRestrictPassengersMenu()
{

}

void  Display::displayPassengerMenu()
{
	system("CLS");
	cout << "********************NPAFS*********************" << endl << endl;
	cout << "1) View flight schedule\n2) View most visited country\n3) Book a flight \n4) Cancel reservation\n5) Edit account info\n6) Log out";
}

void Display::registrationSuccessfulMessage()
{
	cout << "Registration successful. Please wait. You will be redirected in ";
	Display::successful();
}

void Display::displayFlightTypeMenu()
{
	system("CLS");
	cout << "********************INFORMATION PANEL*********************" << endl << endl;
	cout << "\n1) Local Flights\n2) International Flights\nOption: ";
}

void  Display::displayEditDetailsMenu()
{

}

void Display::successful()
{
	for (int i = 3; i > 0; i--)
	{
		cout << i;
		cout << " second(s)";
		Sleep(1000);
		cout << "\b ";
		if (i == 10)
		{
			cout << "\b\b\b\b\b\b\b\b\b\b\b\b";
		}
		else
		{
			cout << "\b\b\b\b\b\b\b\b\b\b\b";
		}
	}
	cout << "0 second(s)" << endl << endl;
	System::passengerControl();
}

void Display::successful2()
{
	for (int i = 3; i > 0; i--)
	{
		cout << i;
		cout << " second(s)";
		Sleep(1000);
		cout << "\b ";
		if (i == 10)
		{
			cout << "\b\b\b\b\b\b\b\b\b\b\b\b";
		}
		else
		{
			cout << "\b\b\b\b\b\b\b\b\b\b\b";
		}
	}
	cout << "0 second(s)" << endl << endl;
	System::adminTeamControl();
}


void  Display::displayBookFlightMenu()
{
	system("CLS");
	cout << "********************FLIGHT BOOKING*********************" << endl << endl;
	cout << "\n1) Local Flights\n2) International Flights\nOption: ";
}

void  Display::displayBookFlightSecondaryMenu()
{
	system("CLS");
	cout << "********************FLIGHT BOOKING*********************" << endl << endl;
}

void Display::seatBookedSuccessfully()
{
	cout << "Seat Booked Successfully. Please wait. You will be redirected in ";
	Display::successful();
}

Display::~Display()
{

}