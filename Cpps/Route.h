#pragma once
#include <string>

using namespace std;

class Route
{
	string baseCountry; //base country is the first country after takeoff from pakistan
	string lastCountry;
	string* route;
	int count; //of countries in route
public:
	Route();
	void displayRoute();
	void setBaseCountry(string);
	void setLastCountry(string);
	string getCountry(int);
	void setCount(int);
	void setRoute(string*);
	friend istream& operator>>(istream&, Route&);
	~Route();
};

