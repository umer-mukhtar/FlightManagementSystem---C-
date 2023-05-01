#pragma once
#include <iostream>

using namespace std;

class Cost
{
	double flightCost;
	double tax;
	int taxPercent;
public:
	Cost();
	Cost(string);
	void setFlightCost(int);
	int getTotalCost();
	void calculateTax();
	int getFlightCost();
	void getTax();
	friend ostream& operator<<(ostream&, Cost&);
	~Cost();
};

