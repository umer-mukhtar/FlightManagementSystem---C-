#pragma once
#include <string>

using namespace std;

class Airport
{
protected:
	string id;
	string city;
public:
	Airport();
	void setID(string);
	string getID();
	void setCity(string);
	string getCity();
	~Airport();
		//+ setCost(int) : void
		//+ getCost() : void
};

