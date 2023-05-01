#include <iostream>
#include "City.h"

using namespace std;

istream& operator>>(istream& istreamObj, City& cityObj)
{
	istreamObj >> cityObj.id >> cityObj.city;
	return istreamObj;
}