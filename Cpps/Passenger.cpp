#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Passenger.h"
#include "ErrorMessage.h"
#include "Cost.h"
#include "GlobalFunctions.h"
#include "TravelHistory.h"
#include "Display.h"

using namespace std;

Passenger::Passenger() //default constructor
{
	discount = false;
	registrationStatus = false;
	reservedFlightID = new int[20]{};
}

void Passenger::userLogin() //logs in user or returns to main menu in case of invalid username/password
{
	discount = false;
	reservedFlightCount = 1;
	reservedFlightID[0] = 100 + rand() % 49;
	registrationStatus = false;
	string usernameInput;
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, usernameInput);
	cout << "Please enter your password: ";
	//getline(cin, passwordInput);
	string passwordInput = takePasswordInput();
	if (validateLoginInformation(usernameInput, passwordInput)) //checking if valid
	{
		cout << "\nLogged in successfully" << endl << endl; //login successful
		registrationStatus = true;
		username = usernameInput;
		password = passwordInput;
	}
	else
	{
		ErrorMessage::loginFailed(); //login failed
	}
	int toss = 0 + rand() % 2;
	switch (toss)
	{
	case 0:
		visaStatus = false;
		break;
	case 1:
		visaStatus = true;
		break;
	}
}

bool Passenger::validateLoginInformation(string usernameInput, string passwordInput) //checks if the username and password taken input by user are correct or not
{
	ifstream loginData;
	loginData.open("Passengers.txt");
	bool loginStatus = false;
	string tempUsername;
	string tempPassword;
	for (int i = 0; !loginData.eof(); i++)
	{
		if (!(i % 2)) //usernames are placed at even spaces in file
		{
			loginData >> tempUsername;
			if (compareStrings(tempUsername, usernameInput))
			{
				loginData >> tempPassword;
				if (compareStrings(tempPassword, passwordInput))
				{
					loginStatus = true;
				}
			}
		}
	}
	loginData.close();
	return loginStatus;
}

void Passenger::registerUser()
{
	discount = false;
	int toss = 0 + rand() % 2;
	switch (toss)
	{
	case 0:
		visaStatus = false;
		break;
	case 1:
		visaStatus = true;
		break;
	}
	reservedFlightCount = 1;
	reservedFlightID[0] = 100 + rand() % 49;
	registrationStatus = false;
	string usernameInput;
	string cnicInput;
	int ageInput;
	cout << "Please enter a username (Only alphabets, numerics and underscores are allowed): ";
	cin.ignore();
	getline(cin, usernameInput);
	for (int i = 0; usernameInput[i] != '\0'; i++) //usernameInput validation
	{
		if (!((usernameInput[i] >= 48 && usernameInput[i] <= 57) || (usernameInput[i] >= 65 && usernameInput[i] <= 90) || (usernameInput[i] >= 97 && usernameInput[i] <= 122 || usernameInput[i] == 95)))
		{//validation check for usernameInput
			ErrorMessage::registrationFailed(1);
		}
	}
	//now checking if username is already in use
	ifstream usernames;
	usernames.open("Passengers.txt");
	bool usernameAlreadyInUse = false;
	string tempUsername;
	for (int i = 0; !usernames.eof(); i++)
	{
		if (!(i % 2)) //usernames are placed at even spaces in file
		{
			usernames >> tempUsername;
			if (compareStrings(tempUsername, usernameInput))
			{
				usernameAlreadyInUse = true;
			}
		}
	}
	usernames.close();
	if (usernameAlreadyInUse)
	{
		ErrorMessage::registrationFailed(3);
	}
	//else continue
	//password verification:
	cout << "Please enter a password \n(Password must be 8 characters long and use of minimum one \nspecial character, uppercase, lowercase, and numeric digit is a must): ";
	//getline(cin, passwordInput);
	string passwordInput = takePasswordInput();
	if (lengthOfString(passwordInput) != 8) //password validation
	{
		ErrorMessage::registrationFailed(2);
	}
	//counter variable for password verification:
	int lowerCase = 0;
	int upperCase = 0;
	int numericDigit = 0;
	int specChar = 0; //special characters
	for (int i = 0; passwordInput[i] != '\0'; i++)
	{
		if (passwordInput[i] >= 48 && passwordInput[i] <= 57)  //numeric digits
		{
			numericDigit++;
		}
		else if (passwordInput[i] >= 65 && passwordInput[i] <= 90)//uppercase letters
		{
			upperCase++;
		}
		else if (passwordInput[i] >= 97 && passwordInput[i] <= 122)//lowercase leter
		{
			lowerCase++;
		}
		else if ((passwordInput[i] >= 33 && passwordInput[i] <= 46) || (passwordInput[i] >= 58 && passwordInput[i] <= 64) || (passwordInput[i] >= 123 && passwordInput[i] <= 126)) //special characters
		{
			specChar++;
		}
		else //invalid password characters
		{
			ErrorMessage::registrationFailed(2);
		}
	}
	if (lowerCase == 0 || upperCase == 0 || specChar == 0 || numericDigit == 0)
	{
		ErrorMessage::registrationFailed(2);
	}
	cout << "Please re-enter your password: ";
	//getline(cin, passwordInput2);
	string passwordInput2 = takePasswordInput();
	if (lengthOfString(passwordInput2) != 8)
	{
		ErrorMessage::registrationFailed(11);
	}
	int count = 0;
	for (int i = 0; passwordInput[i] != '\0'; i++)
	{
		if (passwordInput[i] == passwordInput2[i])
		{
			count++;
		}
	}
	if (!(lengthOfString(passwordInput) == count))
	{
		ErrorMessage::registrationFailed(11);
	}
	//age validation:
	cout << "Please enter your age (in years): ";
	cin >> ageInput;
	if (ageInput < 0 || ageInput>150)
	{
		ErrorMessage::registrationFailed(4);
	}
	//CNIC validation
	cin.ignore();
	if (ageInput < 18)
	{
		cout << "Please enter CNIC of an adult (without dashes): ";
		getline(cin, cnicInput);
		int digits = 0;
		for (int i = 0; cnicInput[i] != '\0'; i++)
		{
			digits++;
		}
		if (digits != 13) //check for digits
		{
			ErrorMessage::registrationFailed(5);
		}
		//no check for repetition
	}
	else
	{
		cout << "Please enter your CNIC (without dashes): ";
		getline(cin, cnicInput);
		int digits = 0;
		for (int i = 0; cnicInput[i] != '\0'; i++)
		{
			digits++;
		}
		if (digits != 13) //check for digits
		{
			ErrorMessage::registrationFailed(5);
		}
		// now checking for repetition
		ifstream cnics;
		cnics.open("CNIC.txt");
		bool cnicAlreadyInUse = false;
		string tempCnic;
		for (int i = 0; !cnics.eof(); i++)
		{
			if (i % 2) //cnics are placed at odd spaces in file
			{
				cnics >> tempCnic;
				if (compareStrings(tempCnic, cnicInput))
				{
					cnicAlreadyInUse = true;
				}
			}
		}
		cnics.close();
		if (cnicAlreadyInUse)
		{
			ErrorMessage::registrationFailed(6);
		}
	}
	registrationStatus = true;
	username = usernameInput;
	password = passwordInput;
	age = ageInput;
	cnic = cnicInput;
	//registration complete
	//saving the information in the respective files
	//username psswd
	ofstream loginData;
	loginData.open("Passengers.txt", ios::app);
	loginData << endl << username << " " << password;
	loginData.close();
	//cnic
	ofstream cnics;
	cnics.open("CNIC.txt", ios::app);
	cnics << endl << username << " " << cnic;
	cnics.close();
	//age
	ofstream ageFile;
	ageFile.open("PassengersAge.txt", ios::app);
	ageFile << endl << username << " " << age;
	ageFile.close();
}

bool Passenger::getVisa()
{
	return visaStatus;
}

void Passenger::assignRandomData(Country c[])
{
	travelHist.setCountries(c);
}

void Passenger::displayReservedFlights(InternationalFlightSchedule intFLightSchd[])
{
	for (int i = 0; i < reservedFlightCount; i++)
	{
		if (reservedFlightID != 0)
		{
			for (int j = 0; j < 50; j++)
			{
				if (intFLightSchd[j].getFlightID() == reservedFlightID[i])
				{
					cout << intFLightSchd[j];
				}
			}
		}
	}
}

void Passenger::cancelFlight(int id)
{
	int countx = 0;
	for (int i = 0; i < reservedFlightCount; i++)
	{
		if (id == reservedFlightID[i])
		{
			reservedFlightID[i] = 0;
			reservedFlightCount--;
			countx++;
		}
	}
	if (countx)
	{

	}
	else
	{
		ErrorMessage::cancelFlightError();
	}
}

void Passenger::travelHistoryFrequent()
{
	int count = 0;
	for (int i = 0; i < travelHist.getCountOfFlights(); i++)
	{
		if (travelHist.getDate(i).getMonth() == 6 || travelHist.getDate(i).getMonth() == 5)
		{
			count++;
		}
	}
	if (count)
	{
		discount = true;
	}
}

bool Passenger::getDiscount()
{
	return discount;
}

void Passenger::bookFlight(string country, InternationalFlightSchedule& intFlightSchd, Cost& costOfFlight, char seatType)
{
	accountDetails.getAccountDetails();
	if (VerifyFinancialDetails(accountDetails))
	{
		if (accountDetails.getBalance() >= costOfFlight.getTotalCost())
		{
			
			accountDetails.setBalance(accountDetails.getBalance() - costOfFlight.getTotalCost());
			if (seatType == 'E')
			{
				intFlightSchd.setRemainingEcoSeats(intFlightSchd.getRemainingEcoSeats() - 1);
			}
			else
			{
				intFlightSchd.setRemainingBusinessSeats(intFlightSchd.getRemainingBusinessSeats() - 1);
			}
			reservedFlightCount++;
			reservedFlightID[reservedFlightCount - 1] = intFlightSchd.getFlightID();
			//now overwriting the file
			//ifstream accDts;
			//accDts.open("AccountDetails.txt");
			//string accNos[20]{};
			//int balances[20]{};
			//string ccNos[20]{};
			//string cvcs[20]{};
			//int counts = 0;
			//while (!accDts.eof())	
			//{
			//	accDts >> accNos[counts];
			//	accDts >> balances[counts];
			//	accDts >> ccNos[counts];
			//	accDts >> cvcs[counts];
			//	counts++;
			//}
			//for (int i = 0; i < counts; i++)
			//{
			//	if (compareStrings(accNos[i], (accountDetails.getAccNo())))
			//	{
			//		balances[i] = accountDetails.getBalance();
			//	}
			//}
			//accDts.close();
			//ofstream accDts2;
			//accDts2.open("AccountDetails.txt");
			//for (int i = 0; i < counts; i++)
			//{
			//	accDts2 << accNos[counts] << " " << balances[counts] << " " << ccNos[counts] << " " << cvcs[counts] << endl;
			//}
			//accDts2.close();
			Display::seatBookedSuccessfully();
		}
		else
		{
			ErrorMessage::balanceError();
		}
	}
	else
	{
		return;
	}
}

void Passenger::bookFlight(string country, LocalFlightSchedule& locFlightSchd, Cost& costOfFlight, char seatType)
{
	accountDetails.getAccountDetails();
	if (VerifyFinancialDetails(accountDetails))
	{
		if (accountDetails.getBalance() >= costOfFlight.getTotalCost())
		{

			accountDetails.setBalance(accountDetails.getBalance() - costOfFlight.getTotalCost());
			if (seatType == 'E')
			{
				locFlightSchd.setRemainingEcoSeats(locFlightSchd.getRemainingEcoSeats() - 1);
			}
			else
			{
				locFlightSchd.setRemainingBusinessSeats(locFlightSchd.getRemainingBusinessSeats() - 1);
			}
			reservedFlightCount++;
			reservedFlightID[reservedFlightCount - 1] = locFlightSchd.getFlightID();
			Display::seatBookedSuccessfully();
		}
		else
		{
			ErrorMessage::balanceError();
		}
	}
	else
	{
		return;
	}
}


void Passenger::validateNewUsername(string newUsername)
{
	for (int i = 0; newUsername[i] != '\0'; i++) //newUsername validation
	{
		if (!((newUsername[i] >= 48 && newUsername[i] <= 57) || (newUsername[i] >= 65 && newUsername[i] <= 90) || (newUsername[i] >= 97 && newUsername[i] <= 122 || newUsername[i] == 95)))
		{//validation check for newUsername
			ErrorMessage::registrationFailed(1);
		}
	}
	//now checking if username is already in use
	ifstream usernames;
	usernames.open("Passengers.txt");
	bool usernameAlreadyInUse = false;
	string tempUsername;
	for (int i = 0; !usernames.eof(); i++)
	{
		if (!(i % 2)) //usernames are placed at even spaces in file
		{
			usernames >> tempUsername;
			if (compareStrings(tempUsername, newUsername))
			{
				usernameAlreadyInUse = true;
			}
		}
	}
	usernames.close();
	if (usernameAlreadyInUse)
	{
		ErrorMessage::registrationFailed(3);
	}
	//else
	//now changing data in file
	string usernames2[20];
	string passwords2[20];
	int count = 0;
	ifstream info;
	info.open("Passengers.txt");
	while (!info.eof())
	{
		info >> usernames2[count];
		info >> passwords2[count];
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		if (username == usernames2[i])
		{
			usernames2[i] = newUsername;
		}
	}
	info.close();
	ofstream info2;
	info2.open("Passengers.txt");
	for (int i = 0; i < count; i++)
	{
		info2 << usernames2[i];
		info2 << " ";
		info2 << passwords2[i];
		info2 << endl;
	}
	info2.close();
	Display::usernameChanged();

}

void Passenger::validateNewPassword(string newPassword)
{
	if (lengthOfString(newPassword) != 8) //password validation
	{
		ErrorMessage::registrationFailed(2);
	}
	//counter variable for password verification:
	int lowerCase = 0;
	int upperCase = 0;
	int numericDigit = 0;
	int specChar = 0; //special characters
	for (int i = 0; newPassword[i] != '\0'; i++)
	{
		if (newPassword[i] >= 48 && newPassword[i] <= 57)  //numeric digits
		{
			numericDigit++;
		}
		else if (newPassword[i] >= 65 && newPassword[i] <= 90)//uppercase letters
		{
			upperCase++;
		}
		else if (newPassword[i] >= 97 && newPassword[i] <= 122)//lowercase leter
		{
			lowerCase++;
		}
		else if ((newPassword[i] >= 33 && newPassword[i] <= 46) || (newPassword[i] >= 58 && newPassword[i] <= 64) || (newPassword[i] >= 123 && newPassword[i] <= 126)) //special characters
		{
			specChar++;
		}
		else //invalid password characters
		{
			ErrorMessage::registrationFailed(2);
		}
	}
	if (lowerCase == 0 || upperCase == 0 || specChar == 0 || numericDigit == 0)
	{
		ErrorMessage::registrationFailed(2);
	}
	cout << "Please re-enter your password: ";
	//getline(cin, newPassword2);
	string newPassword2 = takePasswordInput();
	if (lengthOfString(newPassword2) != 8)
	{
		ErrorMessage::registrationFailed(11);
	}
	int count = 0;
	for (int i = 0; newPassword[i] != '\0'; i++)
	{
		if (newPassword[i] == newPassword2[i])
		{
			count++;
		}
	}
	if (!(lengthOfString(newPassword) == count))
	{
		ErrorMessage::registrationFailed(11);
	}
	//now changing data in file
	string usernames2[20];
	string passwords2[20];
	int count2 = 0;
	ifstream info;
	info.open("Passengers.txt");
	while (!info.eof())
	{
		info >> usernames2[count2];
		info >> passwords2[count2];
		count2++;
	}
	for (int i = 0; i < count2; i++)
	{
		if (username == usernames2[i])
		{
			passwords2[i] = newPassword;
		}
	}
	info.close();
	ofstream info2;
	info2.open("Passengers.txt");
	for (int i = 0; i < count2; i++)
	{
		info2 << usernames2[i];
		info2 << " ";
		info2 << passwords2[i];
		info2 << endl;
	}
	info2.close();
	Display::passwordChanged();
}

string Passenger::getPassword()
{
	return password;
}

string Passenger::getUsername()
{
	return username;
}


string Passenger::mostVisitedCountry()
{
	return travelHist.mostVisitedCtr();
}

Passenger::~Passenger()
{

}

//char passwordInputArr[50]{}; //character array is needed for **** display
//for (int i = 0;;)
//{
//	char tempChr = _getch(); //gets the keystroke and saves it in tempChr
//	if (tempChr == '\r') //if enter key is pressed the loop breaks
//	{
//		break;
//	}
//	else if (tempChr == 8) //if backspace is pressed then we need to remove the latest character
//	{
//		if (i == 0)
//		{
//			//do nothing
//		}
//		else
//		{
//			cout << "\b \b"; //covers up the latest * with black space
//			passwordInputArr[lengthOfString(passwordInputArr) - 1] = NULL; //clears te latest element in char array
//			i--;
//		}
//	}
//	else
//	{
//		passwordInputArr[i] = tempChr;
//		cout << "*";
//		i++;
//	}
//}
