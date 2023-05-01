#include <iostream>
#include <stdlib.h>
#include "windows.h"
#include "ErrorMessage.h"
#include "System.h"

using namespace std;

ErrorMessage::ErrorMessage()
{

}

void ErrorMessage::outOfBoundsError()
{
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::invalidUsername()
{
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::invalidOption()
{
	cout << "You have picked an invalid option." << endl;
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::loginFailed()
{
	cout << "The username or password you entered is incorrect." << endl;
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::registrationFailed(int type)
{
	cout << "Registration Failed" << endl;
	cout << "It occured due to the following reason:" << endl;
	switch (type)
	{
	case 1:
		cout << "The username you entered is invalid";
		break;
	case 2:
		cout << "The password you entered is invalid";
		break;
	case 3:
		cout << "The username you entered is already in use";
		break;
	case 4:
		cout << "The age you entered is invalid";
		break;
	case 5:
		cout << "The CNIC you entered is invalid";
		break;
	case 6:
		cout << "The CNIC you entered is already in use";
		break;
	case 11:
		cout << "The passwords you entered do not match";
		break;
	}
	cout << endl;
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::changeScheduleError()
{
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::addRouteError()
{
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::restrictPasswordEror()
{
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::blockFlightError()
{
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::balanceError()
{
	cout << "Sorry! You don't have enought balance in your account. ";
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::resumeFlightError()
{
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::visaError()
{
	cout << "Sorry! You don't have VISA stamp to proceed. ";
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::resetPasswordErrorAdmin()
{
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::editDetailsErrorPassenger()
{
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::flightNotFound()
{
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::outOfSeats()
{
	cout << "Sorry! There are no available seats. ";
	returnToMainMenu();
	System::centralControl();

}

void ErrorMessage::bookFlightError()
{
	cout << "Invalid Flight ID.";
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::invalidCountryError()
{
	cout << "Invalid Country. ";
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::cancelFlightError()
{
	cout << "Invalid flight ID. ";
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::financialError()
{
	cout << "The account details you provided are incorrect. ";
	returnToMainMenu();
	System::centralControl();
}

void ErrorMessage::returnToMainMenu()
{
	cout << "Returning to main menu in ";
	for (int i = 10; i > 0; i--)
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
	system("CLS");
}

ErrorMessage::~ErrorMessage()
{

}