#include <iostream>
#include <string>
#include "AccountDetails.h"
#include "ErrorMessage.h"

using namespace std;

AccountDetails::AccountDetails()
{
	cvc = "0000";
	balance = 0;
	creditCardNo = "0000";
	accountNo = "0000";
}

void AccountDetails::getAccountDetails()
{
	cout << "Please enter Account No: ";
	getline(cin, accountNo);
	cout << "Please enter Credit Card No: ";
	getline(cin, creditCardNo);
	cout << "Please enter CVC number: ";
	getline(cin, cvc);
}

string AccountDetails::getAccNo()
{
	return accountNo;
}

int AccountDetails::getBalance()
{
	return balance;
}

string AccountDetails::getCCNo()
{
	return creditCardNo;
}

void AccountDetails::setBalance(int balance)
{
	this->balance = balance;
}

string AccountDetails::getCVC()
{
	return cvc;
}

AccountDetails::~AccountDetails()
{

}
