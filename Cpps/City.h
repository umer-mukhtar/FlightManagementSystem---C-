#pragma once
#include "Airport.h"
class City : public Airport
{
public:
	friend istream& operator>>(istream&, City&);
};

