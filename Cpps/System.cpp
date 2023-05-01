#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "System.h"
#include "GlobalFunctions.h"

using namespace std;

Airport* System::airport = 0;
FlightSchedule* System::flightSchedule = 0;
User* System:: currentUser = 0;
Passenger System::currentPassenger;
AdminTeam System::currentAdmin;
Country* System::country = 0;
City* System::city = 0;
InternationalFlightSchedule* System::intFlightSch = 0;
LocalFlightSchedule* System::locFlightSch = 0;
Country System::mostVisitedCountry;
Route* System::route = 0;
Route* System::locRoute = 0;
IntFlightTime* System::locFlightTime = 0;
IntFlightTime* System::intFlightTime = 0;

System::System()
{
	//Country mostVisitedCountry;
	//now inializing arrays
	route = new Route[5];
	country = new Country[25];
	locRoute = new Route[20];
	city = new City[10];
	intFlightSch = new InternationalFlightSchedule[100];
	locFlightTime = new IntFlightTime[20];
	locFlightSch = new LocalFlightSchedule[100];
	intFlightTime = new IntFlightTime[154];
	initializeData();
}

void System::initializeData()
{
	//initializing cities
	ifstream cities;
	cities.open("City.txt");
	for (int i = 0; !cities.eof(); i++)
	{
		cities >> city[i];
	}
	cities.close();
	//initializing countries
	ifstream countries;
	countries.open("Country.txt");
	for (int i = 0; !countries.eof(); i++)
	{
		countries >> country[i];
	}
	countries.close();
	//initializing routes (refer to picture for the five routes i made)
	ifstream routes;
	routes.open("Route.txt");
	for (int i = 0; i < 5; i++)
	{
		int count;
		routes >> count;
		string* tempString = new string[count];
		for (int j = 0; j < count; j++)
		{
			routes >> tempString[j];
		}
		route[i].setCount(count);
		route[i].setRoute(tempString);
		delete[] tempString;
	}
	routes.close();
	//for (int i = 0; i < 5; i++)
	//{
	//	route[i].displayRoute();
	//	cout << endl;
	//}
	//initializing flight times
	ifstream intFlightTimes;
	intFlightTimes.open("IntFlightTime.txt");

	for (int i = 0; !intFlightTimes.eof(); i += 2)
	{
		string country1; string country2; Time flightTime;
		intFlightTimes >> country1 >> country2 >> flightTime;
		intFlightTime[i].setFlightTime(country1, country2, flightTime);
		intFlightTime[i + 1].setFlightTime(country2, country1, flightTime); //to create exact copies with just the destination and source countries swapped
	}
	intFlightTimes.close();
	//initializing flight data
	for (int i = 0, x = 100; i < 50; i++, x++)
	{
		intFlightSch[i].setFlightID(x);
		intFlightSch[i].setID("NPA-" + intToString(x));
		int routeID = 0 + rand() % 5;
		int countOfStops = 0;
		switch (routeID)
		{
		case 0:
		{
			do {
				for (int k = 0, j = 1; k < 4; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						string tempCtr = route[routeID].getCountry(k);
						if (compareStrings(tempCtr, "Dubai"))
						{

						}
						else
						{
							intFlightSch[i].setCountry(tempCtr, j);
							//cout << intFlightSch[i].getCountry(j) << endl;
							j++;
							countOfStops++;
						}
					}
					break;
					}
				}
			} while (countOfStops == 0);
		}
		break;
		case 1:
		{
			do {
				for (int k = 0, j = 1; k < 6; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						intFlightSch[i].setCountry(route[routeID].getCountry(k), j);
						//cout << intFlightSch[i].getCountry(j) << endl;
						j++;
						countOfStops++;
					}
					break;
					}
				}
			} while (countOfStops == 0);
		}
		break;
		case 2:
		{
			do {
				for (int k = 0, j = 1; k < 5; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						intFlightSch[i].setCountry(route[routeID].getCountry(k), j);
						//cout << intFlightSch[i].getCountry(j) << endl;
						j++;
						countOfStops++;
					}
					break;
					}
				}
			} while (countOfStops == 0);
		}
		break;
		case 3:
		{
			do {
				for (int k = 0, j = 1; k < 4; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						intFlightSch[i].setCountry(route[routeID].getCountry(k), j);
						//cout << intFlightSch[i].getCountry(j) << endl;
						j++;
						countOfStops++;
					}
					break;
					}
				}
			} while (countOfStops == 0);
		}
		break;
		case 4:
		{
			do {
				for (int k = 0, j = 1; k < 6; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						intFlightSch[i].setCountry(route[routeID].getCountry(k), j);
						//cout << intFlightSch[i].getCountry(j) << endl;
						j++;
						countOfStops++;
					}
					break;
					}
				}
			} while (countOfStops == 0);
			break;
		}
		}
		intFlightSch[i].setCountOfStops(countOfStops);
		for (int j = 1; j < intFlightSch[i].getCountOfStops() + 1; j++)
		{
			string tempCountry = intFlightSch[i].getCountry(j);
			for (int k = 0; k < 25; k++)
			{
				if (compareStrings(tempCountry, country[k].getCountry()))
				{
					intFlightSch[i].setCity(country[k].getCity(), j);
				}
			}
		}
		intFlightSch[i].makeCalculations(intFlightTime);

		//for (int j = 1; j < intFlightSch[i].getCountOfStops() + 1; j++)
		//{
		//	string tempCountry = intFlightSch[i].getCountry(j);
		//	for (int k = 0; k < 25; k++)
		//	{
		//		if (compareStrings(tempCountry, country[k].getCountry()))
		//		{
		//			intFlightSch[i].setCity(country[k].getCity(), j);
		//		}
		//	}
		//}
		//intFlightSch[i].makeCalculations(intFlightTime);
	}
	////initializing international flight schedule
	//ifstream intScheduleFile;
	//intScheduleFile.open("IntFlightSched.txt");
	//for (int i = 0; i < 5; i++)
	//{
	//	intScheduleFile >> intFlightSch[i];
		//for (int j = 1; j < intFlightSch[i].getCountOfStops() + 1; j++)
		//{
		//	string tempCountry = intFlightSch[i].getCountry(j);
		//	for (int k = 0; k < 25; k++)
		//	{
		//		if (tempCountry == country[k].getCountry())
		//		{
		//			intFlightSch[i].setCity(country[k].getCity(), j);
		//		}
		//	}
		//}
		//intFlightSch[i].makeCalculations(intFlightTime);
	//intScheduleFile.close();
		//initializing cities
	//initializing routes (refer to picture for the five routes i made)
	// 	   
	// 
	// 
	// 
	// 
	//now moving on to local flights
	ifstream routes2;
	routes2.open("LocRoute.txt");
	for (int i = 0; i < 7; i++)
	{
		int count;
		routes2 >> count;
		string* tempString = new string[count];
		for (int j = 0; j < count; j++)
		{
			routes2 >> tempString[j];
		}
		locRoute[i].setCount(count);
		locRoute[i].setRoute(tempString);
		delete[] tempString;
	}
	routes2.close();
	ifstream locFlightTimes;
	locFlightTimes.open("LocFlightTime.txt");

	for (int i = 0; !locFlightTimes.eof(); i += 2)
	{
		string country1; string country2; Time flightTime;
		locFlightTimes >> country1 >> country2 >> flightTime;
		locFlightTime[i].setFlightTime(country1, country2, flightTime);
		locFlightTime[i + 1].setFlightTime(country2, country1, flightTime); //to create exact copies with just the destination and source countries swapped
	}
	for (int i = 0; i < 100; i++)
	{
		int toss2 = 0 + rand() % 7;
		switch (toss2)
		{
		case 0:
			locFlightSch[i].setBaseCity(locRoute[0].getCountry(0));
			break;
		case 1:
			locFlightSch[i].setBaseCity(locRoute[1].getCountry(0));
			break;
		case 2:
			locFlightSch[i].setBaseCity(locRoute[2].getCountry(0));
			break;
		case 3:
			locFlightSch[i].setBaseCity(locRoute[3].getCountry(0));
			break;
		case 4:
			locFlightSch[i].setBaseCity(locRoute[4].getCountry(0));
			break;
		case 5:
			locFlightSch[i].setBaseCity(locRoute[5].getCountry(0));
			break;
		case 6:
			locFlightSch[i].setBaseCity(locRoute[6].getCountry(0));
			break;
		}
	}




	////////////////////
	for (int i = 0, x = 300; i < 100; i++, x++)
	{
		locFlightSch[i].setFlightID(x);
		locFlightSch[i].setID("NPA-" + intToString(x));
		int routeID = 0 + rand() % 7;
		int countOfStops = 0;
		switch (routeID)
		{
		case 0:
		{
			do {
				for (int k = 1, j = 1; k < 5; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						string tempCtr = locRoute[routeID].getCountry(k);
						locFlightSch[i].setCity(tempCtr, j);
						j++;
						countOfStops++;
					}
					break;
					}
				}
			} while (countOfStops == 0);
		}
		break;
		case 1:
		{
			do {
				for (int k = 1, j = 1; k < 4; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						string tempCtr = locRoute[routeID].getCountry(k);
						locFlightSch[i].setCity(tempCtr, j);
						j++;
						countOfStops++;
					}
					break;
					}
				}
			} while (countOfStops == 0);
		}
		break;
		case 2:
		{
			do {
				for (int k = 1, j = 1; k < 3; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						string tempCtr = locRoute[routeID].getCountry(k);
						locFlightSch[i].setCity(tempCtr, j);
						j++;
						countOfStops++;
					}
					break;
					}
				}
			} while (countOfStops == 0);
		}
		break;
		case 3:
		{
			do {
				for (int k = 1, j = 1; k < 3; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						string tempCtr = locRoute[routeID].getCountry(k);
						locFlightSch[i].setCity(tempCtr, j);
						j++;
						countOfStops++;
					}
					break;
					}
				}
			} while (countOfStops == 0);
		}
		break;
		case 4:
		{
			do {
				for (int k = 1, j = 1; k < 4; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						string tempCtr = locRoute[routeID].getCountry(k);
						locFlightSch[i].setCity(tempCtr, j);
						j++;
						countOfStops++;
					}
					break;
					}
				}
			} while (countOfStops == 0);
			break;
		}
		case 5:
		{
			do {
				for (int k = 1, j = 1; k < 2; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						string tempCtr = locRoute[routeID].getCountry(k);
						locFlightSch[i].setCity(tempCtr, j);
						j++;
						countOfStops++;
					}
					break;
					}
				}
			} while (countOfStops == 0);
		}
			break;
		case 6:
		{
			do {
				for (int k = 1, j = 1; k < 5; k++)
				{
					int toss = 0 + rand() % 2;
					switch (toss)
					{
					case 0:
					{//do nothing

					}
					break;
					default:
					{
						string tempCtr = locRoute[routeID].getCountry(k);
						locFlightSch[i].setCity(tempCtr, j);
						j++;
						countOfStops++;
					}
					break;
					}
				}
			} while (countOfStops == 0);
		}
			break;
		}
		locFlightSch[i].setCountOfStops(countOfStops);
		locFlightSch[i].makeCalculations(locFlightTime);
	}
}

void System::centralControl() //this is the central control function. It is sort of a driver for the whole flight system
{
	Display::displayMainMenu();
	int option;
	cin >> option; // a single variable will be used for options throughout i.e. memory efficient plus less time consuming
	switch (option)//main menu
	{
	case 1: //login/signup
	{
		Display::displaySecondaryMenu();
		cin >> option;
		switch (option)//secondary menu
		{
		case 1://login as admin
		{
			currentUser = &currentAdmin; //polymorphism
			currentUser->userLogin();
			adminTeamControl();
		}
		break;
		case 2: //login as passenger
		{
			currentUser = &currentPassenger; //polymorphism
			currentUser->userLogin();
			passengerControl();
		}
		break;
		case 3://register (as passenger)
		{
			currentUser = &currentPassenger; //polymorphism
			Display::displayRegistrationForm();
			currentPassenger.registerUser();
			Display::registrationSuccessfulMessage();
			passengerControl();
		}
		break;
		case 4: //return to main menu
			System::centralControl();
			break;
		default: //error
			ErrorMessage::invalidOption();
			break;
		}
	}
		break;
	case 2://leads to information panel
	{
		Display::displayFlightTypeMenu();
		cin >> option;
		switch (option)//flight type menu
		{
		case 1:
			for (int i = 0; i < 100; i++)
			{
				cout << locFlightSch[i];
			}
			cin.ignore();
			cout << "\n1) Return to main menu\nOption: ";
			cin.get();
			break;
		case 2:
			for (int i = 0; i < 50; i++)
			{
				cout << intFlightSch[i] << endl << endl;
			}
			cin.ignore();
			cout << "\n1) Return to main menu\nOption: ";
			cin.get();
			break;
		default:
			ErrorMessage::invalidOption();
		}
	}
		break;
	case 3://exit
		return;
		break;
	default://error
		ErrorMessage::invalidOption();
		break;
	}
	System::centralControl();
}

void System::adminTeamControl()
{
	int option;
	Display::displayAdminMenu();
	cin >> option;
	switch (option)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
	{
		system("CLS");
		cout << "********************PASSENGER RESTRICTION*********************" << endl << endl;
		cout << "Enter flight ID: ";
		int id2;
		cin >> id2;
		for (int i = 0; i < 50; i++)
		{
			if (id2 == intFlightSch[i].getFlightID())
			{
				intFlightSch[i].setRemainingBusinessSeats(0);
				intFlightSch[i].setRemainingEcoSeats(0);
			}
		}
		for (int i = 0; i < 100; i++)
		{
			if (id2 == locFlightSch[i].getFlightID())
			{
				locFlightSch[i].setRemainingBusinessSeats(0);
				locFlightSch[i].setRemainingEcoSeats(0);
			}
		}
		cout << "Passengers restricted successfully. Returning in ";
		Display::successful2();
	}
	System::adminTeamControl();
		break;
	case 4:
	{
		system("CLS");
		cout << "********************COUNTRY RESTRICTION*********************" << endl << endl;
		cout << "Enter country name: ";
		string countryName;
		cin.ignore();
		getline(cin, countryName);
		for (int i = 0; i < 50; i++)
		{
			for (int j = 1; j < intFlightSch[i].getCountOfStops() + 1; j++)
			{
				if (compareStrings(countryName, intFlightSch[i].getCountry(j)))
				{
					intFlightSch[i].setFlightStatus("Cancelled");
				}
			}
		}
		cout << "Country restricted successfully. Returning in ";
		Display::successful2();
	}
	System::adminTeamControl();
		break;
	case 5:
	{
		system("CLS");
		cout << "********************COUNTRY RESUMPTION*********************" << endl << endl;
		cout << "Enter country name: ";
		string countryName;
		cin.ignore();
		getline(cin, countryName);
		for (int i = 0; i < 50; i++)
		{
			for (int j = 1; j < intFlightSch[i].getCountOfStops() + 1; j++)
			{
				if (compareStrings(countryName, intFlightSch[i].getCountry(j)))
				{
					intFlightSch[i].setFlightStatus("Expected");
				}
			}
		}
		cout << "Country travel resumed successfully. Returning in ";
		Display::successful2();
	}
	System::adminTeamControl();
		break;
	case 6:
		break;
	case 7:
		System::centralControl();
		break;
	default:
		ErrorMessage::invalidOption();
		break;
	}
}

void System::passengerControl()
{
	int option;
	Display::displayPassengerMenu();
	cout << endl << endl;
	cout << "(VISA Status: ";
	if (currentPassenger.getVisa())
	{
		cout << "True)" << endl;
	}
	else
	{
		cout << "False)" << endl;
	}
	cout << "\nOption: ";
	currentPassenger.assignRandomData(country);
	cin >> option;
	switch (option)
	{
	case 1:
	{
		Display::displayFlightTypeMenu();
		cin >> option;
		switch (option)//flight type menu
		{
		case 1:
			for (int i = 0; i < 100; i++)
			{
				cout << locFlightSch[i];
			}
			cin.ignore();
			cout << "\n1) Return to main menu\nOption: ";
			cin.get();
			break;
		case 2:
			for (int i = 0; i < 50; i++)
			{
				cout << intFlightSch[i] << endl << endl;
			}
			cin.ignore();
			cout << "\n1) Return to main menu\nOption: ";
			cin.get();
			break;
		default:
			ErrorMessage::invalidOption();
		}
	}
		break;
	case 2:
	{
		system("CLS");
		cout << "********************MOST VISITED COUNTRY*********************" << endl << endl;
		string tempCtr = currentPassenger.mostVisitedCountry();
		cout << "Most visited country: " << tempCtr << endl;
		Cost costOfMostVisitedCountry;
		costOfMostVisitedCountry.setFlightCost(99999999);
		int minCost = 0;
		int flightid2 = 0;
		for (int i = 0; i < 50; i++)
		{
			for (int j = 1; j < intFlightSch[i].getCountOfStops() + 1; j++)
			{
				if (compareStrings(tempCtr, intFlightSch[i].getCountry(j)))
				{
					if (costOfMostVisitedCountry.getTotalCost() > intFlightSch[i].getFlightCost(tempCtr).getTotalCost())
					{
						if (intFlightSch[i].getRemainingBusinessSeats() == 0 && intFlightSch[i].getRemainingEcoSeats() == 0)
						{
							continue;
						}
						else if (compareStrings(intFlightSch[i].getFlightStatus(), "Cancelled"))
						{
							continue;
						}
						else
						{
							costOfMostVisitedCountry = intFlightSch[i].getFlightCost(tempCtr);
							flightid2 = intFlightSch[i].getFlightID();
						}
					}
				}
			}
		}
		if (flightid2 == 0)
		{
			//do nothing
		}
		else
		{
			for (int i = 0; i < 50; i++)
			{
				if (flightid2 == intFlightSch[i].getFlightID())
				{
					cout << "\nYou can travel there at lowest price\n" << endl;
					cout << intFlightSch[i];
					cout << endl << "Cost: " << costOfMostVisitedCountry << endl;
				}
			}
		}
		cout << "\n1) Back\nOption: ";
		cin >> option;
		switch (option)
		{
		case 1:
			System::passengerControl();
			break;
		default:
			ErrorMessage::invalidOption();
			break;
		}
		break;
	}
	case 3:
	{
		Display::displayBookFlightMenu();
		cin >> option;
		switch (option)
		{
		case 1:
		{
			Display::displayBookFlightSecondaryMenu();
			for (int i = 0; i < 100; i++)
			{
				cout << locFlightSch[i] << endl << endl;
			}
			cout << "\n\nPlease enter the flight ID: ";
			int flightId;
			cin >> flightId;
			for (int i = 0; i < 100; i++)
			{
				if (locFlightSch[i].getFlightID() == flightId)
				{
					if (compareStrings(locFlightSch[i].getFlightStatus(), "Cancelled"))
					{
						Display::flightCancelled();
					}
					cout << "Enter 'E' for Economy and 'B' for Business class: ";
					char tempChr;
					cin >> tempChr;
					switch (tempChr)
					{
					case 'E':
						if (intFlightSch[i].getRemainingEcoSeats() != 0)
						{
							//proceed
						}
						else
						{
							ErrorMessage::outOfSeats();
						}
						break;
					case 'B':
						if (intFlightSch[i].getRemainingBusinessSeats() != 0)
						{
							//proceed
						}
						else
						{
							ErrorMessage::outOfSeats();
						}
						break;
					default:
						ErrorMessage::invalidOption();
						break;
					}
					string tempCountry;
					cout << "Please enter the city name: ";
					cin.ignore();
					getline(cin, tempCountry);
					for (int j = 0; j < 100; j++)
					{
						for (int k = 1; k < locFlightSch[j].getCountOfStops() + 1; k++)
						{
							if (compareStrings(locFlightSch[j].getCity(k), tempCountry))
							{
								Cost costOfFlight;
								currentPassenger.travelHistoryFrequent();
								costOfFlight = locFlightSch[i].getFlightCost(tempCountry);
								cout << costOfFlight;
								currentPassenger.bookFlight(tempCountry, locFlightSch[i], costOfFlight, tempChr);
								ErrorMessage::financialError();
							}
						}
					}
					ErrorMessage::invalidCountryError();
				}
			}
			ErrorMessage::bookFlightError();
			break;
		}
		break;
		case 2:
		{
			if (currentPassenger.getVisa())
			{
				//proceed
			}
			else
			{
				ErrorMessage::visaError();
			}
			Display::displayBookFlightSecondaryMenu();
			for (int i = 0; i < 50; i++)
			{
				cout << intFlightSch[i] << endl << endl;
			}
			cout << "\n\nPlease enter the flight ID: ";
			int flightId;
			cin >> flightId;
			for (int i = 0; i < 50; i++)
			{
				if (intFlightSch[i].getFlightID() == flightId)
				{
					if (compareStrings(intFlightSch[i].getFlightStatus(), "Cancelled"))
					{
						Display::flightCancelled();
					}
					cout << "Enter 'E' for Economy and 'B' for Business class: ";
					char tempChr;
					cin >> tempChr;
					switch (tempChr)
					{
					case 'E':
						if (intFlightSch[i].getRemainingEcoSeats() != 0)
						{
							//proceed
						}
						else
						{
							ErrorMessage::outOfSeats();
						}
						break;
					case 'B':
						if (intFlightSch[i].getRemainingBusinessSeats() != 0)
						{
							//proceed
						}
						else
						{
							ErrorMessage::outOfSeats();
						}
						break;
					default:
						ErrorMessage::invalidOption();
						break;
					}
					string tempCountry;
					cout << "Please enter the country name: ";
					cin.ignore();
					getline(cin, tempCountry);
					for (int j = 0; j < 50; j++)
					{
						for (int k = 1; k < intFlightSch[j].getCountOfStops() + 1; k++)
						{
							if (compareStrings(intFlightSch[j].getCountry(k), tempCountry))
							{
								Cost costOfFlight;
								currentPassenger.travelHistoryFrequent();
								costOfFlight = intFlightSch[i].getFlightCost(tempCountry);
								if (currentPassenger.getDiscount())
								{
									cout << "You are a frequent traveller. You have been awarded 10% discount" << endl;
									cout << "\nBefore Discount:\n" << endl;
									cout << costOfFlight;
									cout << "\nAfter Discount:\n " << endl;
									costOfFlight.setFlightCost(costOfFlight.getFlightCost() - ((10.0 / 100.0) * costOfFlight.getFlightCost()));
								}
								else
								{
									//do nothing
								}
								cout << costOfFlight;
								currentPassenger.bookFlight(tempCountry, intFlightSch[i], costOfFlight, tempChr);
								ErrorMessage::financialError();
							}
						}
					}
					ErrorMessage::invalidCountryError();
				}
			}
			ErrorMessage::bookFlightError();
			break;
		}
		default:
			ErrorMessage::invalidOption();
			break;
		}
	}
		break;
	case 4:
		{
		system("CLS");
		cout << "********************FLIGHT CANCELLATION*********************" << endl << endl;
		currentPassenger.displayReservedFlights(intFlightSch);
		cout << "\nYou will be charged 25% of cost to cancel flight\nEnter flight ID to cancel the flight: ";
		int id2;
		cin >> id2;
		currentPassenger.cancelFlight(id2);
		System::passengerControl();
		}
		break;
	case 5:
		system("CLS");
		cout << "********************EDIT ACCOUNT INFO*********************" << endl << endl;
		cout << "1) Change Username\n2) Change Password\nOption: ";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			string newUsername;
			string newPassword;
			newUsername = currentPassenger.getUsername();
			newPassword = currentPassenger.getPassword();
			cout << "Please enter new username: ";
			cin.ignore();
			getline(cin, newUsername);
			currentPassenger.validateNewUsername(newUsername);
			break;
		}
		case 2:
		{
			string newUsername;
			string newPassword;
			newUsername = currentPassenger.getUsername();
			newPassword = currentPassenger.getPassword();
			cout << "Please enter new password \n(Password must be 8 characters long and use of minimum one \nspecial character, uppercase, lowercase, and numeric digit is a must): ";
			newPassword = currentUser->takePasswordInput();
			currentPassenger.validateNewPassword(newPassword);
			break;
		}
		default:
			ErrorMessage::invalidOption();
			break;
		}
		break;
	case 6:
		System::centralControl();
		break;
	default:
		ErrorMessage::invalidOption();
		break;
	}
}

System::~System()
{

}