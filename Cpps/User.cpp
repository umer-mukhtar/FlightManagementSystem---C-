#include <iostream>
#include <string>
#include <conio.h>
#include "GlobalFunctions.h"
#include "User.h"

using namespace std;

//abstract class

User::User()
{

}

string User::takePasswordInput()
{
	char passwordInputArr[50]{}; //character array is needed for **** display
	for (int i = 0;;)
	{
		char tempChr = _getch(); //gets the keystroke and saves it in tempChr
		if (tempChr == '\r') //if enter key is pressed the loop breaks
		{
			break;
		}
		else if (tempChr == 8) //if backspace is pressed then we need to remove the latest character
		{
			if (i == 0)
			{
				//do nothing
			}
			else
			{
				cout << "\b \b"; //covers up the latest * with black space
				passwordInputArr[lengthOfString(passwordInputArr) - 1] = NULL; //clears te latest element in char array
				i--;
			}
		}
		else
		{
			passwordInputArr[i] = tempChr;
			cout << "*";
			i++;
		}
	}
	cout << endl;
	string passwordInput(passwordInputArr);
	return passwordInput;
}

User::~User()
{

}