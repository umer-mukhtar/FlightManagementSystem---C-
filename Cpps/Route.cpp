#include <iostream>
#include <string>
#include "Route.h"

using namespace std;

Route::Route()
{
//	string baseCountry;
//	string lastCountry;
//	string* route;
//	int count; //of countries in route
//public:
//	Route();
//	friend istream& operator>>(istream&, Route&);
//	~Route();

}

istream& operator>>(istream& istreamObj, Route& routeObj)
{
	return istreamObj;
}

void Route::setBaseCountry(string baseCountry)
{
	this->baseCountry = baseCountry;
}

void Route::setLastCountry(string lastCountry)
{
	this->lastCountry = lastCountry;
}

void Route::setCount(int count)
{
	this->count = count;
	route = new string[count];
}

void Route::setRoute(string* route)
{
	baseCountry = route[0];
	lastCountry = route[count - 1];
	for (int i = 0; i < count; i++)
	{
		this->route[i] = route[i];
	}
	//for (int i = 0; i < count ; i++)
	//{
	//	cout << route[i] << " ";
	//}
	//cout<<endl;
}

void Route::displayRoute()
{
	for (int i = 0; i < count; i++)
	{
		cout << route[i] << " ";
	}
}

string Route::getCountry(int index)
{
	return route[index];
}

Route::~Route()
{

}
