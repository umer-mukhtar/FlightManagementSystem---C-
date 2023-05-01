#include <iostream>
#include "Date.h"

using namespace std;

Date::Date()
{

}

void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setYear(int year)
{
	this->year = year;
}

void Date::setDay(int day)
{
	this->day = day;
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::setData(int day,int month,int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

istream& operator>>(istream& istreamObj, Date& dateObj)
{
	istreamObj >> dateObj.day >> dateObj.month >> dateObj.year;
	return istreamObj;
}

ostream& operator<<(ostream& ostreamObj, Date& dateObj)
{
	ostreamObj << dateObj.day << "-" << dateObj.month << "-" << dateObj.year;
	return ostreamObj;
}

Date::~Date()
{

 }
