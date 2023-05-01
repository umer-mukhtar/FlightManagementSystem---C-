#pragma once
#include <string>

using namespace std;

class AccountDetails
{
	string accountNo;
	int balance;
	string creditCardNo;
	string cvc;
public:
	AccountDetails();
	string getAccNo();
	string getCCNo();
	string getCVC();
	int getBalance();
	void setBalance(int);
	void getAccountDetails();
	~AccountDetails();
};

