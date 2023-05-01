#include <iostream>
#include <string>
#include <cstdlib>
#include "Country.h"
#include "TravelHistory.h"
#include "Date.h"

using namespace std;

TravelHistory::TravelHistory()
{
	countOfFlights = 0 + rand() % 5;//0-5 random no of flights
	date = new Date[countOfFlights];
	country = new string[countOfFlights];
}

int TravelHistory::getCountOfFlights()
{
	return countOfFlights;
}

string TravelHistory::getCountry(int index)
{
	return country[index];
}

Date TravelHistory::getDate(int index)
{
	return date[index];
}

void TravelHistory::setCountries(Country passedCountries[])
{
	for (int i = 0; i < countOfFlights; i++)
	{
		int randNum = 0 + rand() % 24;
		date[i].setData(1 + rand() % 29, 1 + rand() % 6, 2021);
		//date[i].setData(1 + rand() % 29, 6, 2021);
		country[i] = passedCountries[randNum].getCountry();
	}
}

string TravelHistory::mostVisitedCtr()
{
	int count[5]{};
	for (int x = 0; x < countOfFlights; x++)
	{
		for (int i = 0; i < countOfFlights; i++)
		{
			if (country[x] == country[i])
			{
				count[x]++;
				//mostVisitedIndex = x;
			}
		}
	}
	int mostVisitedIndex = 0;
	for (int i = 0; i < countOfFlights; i++)
	{
		if (count[i] > count[mostVisitedIndex])
		{
			mostVisitedIndex = i;
		}
	}
	return country[mostVisitedIndex];
}


TravelHistory::~TravelHistory()
{

}