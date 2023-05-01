#pragma once
#include <iostream>

using namespace std;

class Time
{
	int hours;
	int minutes;
	double hoursOnly;
public:
	Time();
	Time(int, int);
	void setHours(int);
	void setMinutes(int);
	int getHours();
	int getMinutes();
	double getHoursOnly();
	void setHoursOnly(double);
	void displayTime(); //this function displays time like 5:23 mins
	bool addTime(Time, Time);
	friend ostream& operator<<(ostream&, Time&);  //this function displays time like 12:23
	friend istream& operator>>(istream&, Time&); 
	Time& operator-(Time&);
	Time& operator+(Time&);
	~Time();
};

