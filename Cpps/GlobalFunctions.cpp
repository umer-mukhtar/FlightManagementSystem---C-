#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "AccountDetails.h"
#include "GlobalFunctions.h"

using namespace std;


int lengthOfString(const string str) //calculates length of a string
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

bool compareStrings(const string str1, const string str2) //compares 2 strings
{
    int count = 0;
    for (int i = 0; ; i++)
    {
        if (str1[i] == '\0' && str2[i] == '\0')
        {
            break;
        }
        else if (str1[i] == '\0' || str2[i] == '\0')
        {
            return false; //both strings have different length i.e. also unequal
        }
        if (str1[i] == str2[i])
        {
            count++;
        }
    }
    if (count == lengthOfString(str2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool VerifyFinancialDetails(AccountDetails& accDt)
{
    string accNo;
    string ccNo;
    int balance;
    string cvc;
    ifstream accDetails;
    accDetails.open("AccountDetails.txt");
    while (!accDetails.eof())
    {
        accDetails >> accNo;
        accDetails >> balance;
        accDetails >> ccNo;
        accDetails >> cvc;
        if (compareStrings(accNo, accDt.getAccNo()) && compareStrings(ccNo, accDt.getCCNo()) && compareStrings(cvc, accDt.getCVC()))
        {
            accDetails.close();
            accDt.setBalance(balance);
            return true;
        }
    }
    accDetails.close();
    return false;
}

string intToString(int num)
{
    string stringNum;
    //stringNum = num+48;
    //stringNum += 4 + 48;
    int tempNum = num;
    int digits = 0;
    do {
        tempNum /= 10;
        digits++;
    } while (tempNum != 0);
    int m = 0;
    do {
        tempNum = (num / pow(10, digits - 1)) - (10 * static_cast<int>(num / pow(10, digits)));
        stringNum += tempNum + 48;
        digits--;
        m++;
    } while (digits != 0);
    return stringNum;
}
