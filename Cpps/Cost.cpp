#include "Cost.h"
#include "GlobalFunctions.h"

Cost::Cost()
{

}

Cost::Cost(string type)
{
	if (compareStrings(type, "INT"))
	{
		taxPercent = 10;
	}
	else
	{
		taxPercent = 5;
	}
}

void Cost::setFlightCost(int flightCost)
{
	this->flightCost = flightCost;
	this->tax = (flightCost * taxPercent / 100);
}

int Cost::getTotalCost()
{
	return static_cast<int>(flightCost + tax);
}

void Cost::calculateTax()
{

}

int Cost::getFlightCost()
{
	return flightCost;
}

void Cost::getTax()
{
	
}

ostream& operator<<(ostream& ostreamObj, Cost& c)
{
	c.getTax();
	ostreamObj << "Flight Cost: " << static_cast<int>(c.flightCost) << "\nTax: " << static_cast<int>(c.tax) << " (" << c.taxPercent << "%)";
	ostreamObj << "\nTotal: " << c.getTotalCost() << endl;
	return ostreamObj;
}

Cost::~Cost()
{

}