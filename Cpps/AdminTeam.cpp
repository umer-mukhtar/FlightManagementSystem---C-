#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "AdminTeam.h"
#include "ErrorMessage.h"

using namespace std;

AdminTeam::AdminTeam()
{

}

void AdminTeam::userLogin()
{
	string usernameInput;
	cout << "Please enter your username: ";
	cin.ignore();
	getline(cin, usernameInput);
	cout << "Please enter your password: ";
	string passwordInput = takePasswordInput();
	if (validateLoginInformation(usernameInput, passwordInput)) //checking if valid
	{
		cout << "\nLogged in successfully" << endl << endl; //login successful
		username = usernameInput;
		password = passwordInput;
	}
	else
	{
		ErrorMessage::loginFailed(); //login failed
	}
}

bool AdminTeam::validateLoginInformation(string usernameInput, string passwordInput)
{
	ifstream loginData;
	loginData.open("Admin.txt");
	bool loginStatus = false;
	string tempUsername;
	string tempPassword;
	for (int i = 0; !loginData.eof(); i++)
	{
		if (!(i % 2)) //usernames are placed at even spaces in file
		{
			loginData >> tempUsername;
			if (tempUsername == usernameInput)
			{
				loginData >> tempPassword;
				if (tempPassword == passwordInput)
				{
					loginStatus = true;
				}
			}
		}
	}
	loginData.close();
	return loginStatus;

}

AdminTeam::~AdminTeam()
{

}
