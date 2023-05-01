#include <iostream>
#include "Time.h"

using namespace std;


Time::Time()
{

}

Time::Time(int hours, int minutes)
{
	this->hours = hours;
	this->minutes = minutes;
	this->hoursOnly = hours + (minutes / 60.0);
}

void Time::setHours(int hours)
{
	this->hours = hours;
}

void Time::setMinutes(int minutes)
{
	this->minutes = minutes;
	double hours2 = hours;
	double minutes2 = minutes;
	minutes2 /= 60.0;
	this->hoursOnly = hours2 + minutes2;
}

int Time::getHours()
{
	return hours;
}

int Time::getMinutes()
{
	return minutes;
}

void Time::setHoursOnly(double hoursOnly)
{
	this->hoursOnly = hoursOnly;
	hours = hoursOnly;
	minutes = (hoursOnly - hours) * 60;
}

Time& Time::operator-(Time& t)
{
	static Time temp;
	temp.setHoursOnly(hoursOnly - t.hoursOnly);
	return temp;
}

Time& Time::operator+(Time& t)
{
	static Time temp;
	temp.setHoursOnly(hoursOnly + t.hoursOnly);
	return temp;
}

void Time::displayTime() //displays time like 13:30 etc
{
	cout << hours << ":" << minutes;
}

bool Time::addTime(Time t1, Time t2) //adds 2 times such that they are in the 12:30 etc format
{//returns true if date has to be changed. otherwise returns false
	bool returnValue = false;
	if (t1.hours + t2.hours >= 24)
	{
		this->hours = t1.hours + t2.hours;
		this->hours -= 24;
		returnValue = true;
	}
	else
	{
		this->hours = t1.hours + t2.hours;
	}
	if (t1.minutes + t2.minutes >= 60)
	{
		this->hours += 1;
		if (this->hours >= 24)
		{
			this->hours -= 24;
			returnValue = true;
		}
		this->minutes = t1.minutes + t2.minutes;
		this->minutes -= 60;
	}
	else
	{
		this->minutes = t1.minutes + t2.minutes;
	}
	return returnValue;
}

double Time::getHoursOnly()
{
	return hoursOnly;
}

ostream& operator<<(ostream& ostreamObj, Time& timeObj)
{
	ostreamObj << timeObj.hours << " hrs " << timeObj.minutes << " mins";
	return ostreamObj;
}

istream& operator>>(istream& istreamObj, Time& timeObj)
{
	//istreamObj >> timeObj.hours >> timeObj.minutes;
	istreamObj >> timeObj.hoursOnly;
	timeObj.hours = timeObj.hoursOnly;
	timeObj.minutes = (timeObj.hoursOnly - timeObj.hours) * 60;
	return istreamObj;
}

Time::~Time()
{

}