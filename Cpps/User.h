#pragma once
#include <string>

using namespace std;

class User//abstract class
{
protected:
	string username;
	string password;
public:
	User();
	string takePasswordInput();
	virtual void userLogin() = 0;//pure virtual function
	virtual bool validateLoginInformation(string, string) = 0;//pure virtual
	~User();
};

