#pragma once
#include <iostream>

using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	void setMonth(int);
	void setYear(int);
	void setDay(int);
	void setData(int, int, int);
	int getDay();
	int getMonth();
	int getYear();
	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, Date&);
	~Date();
};

