#pragma once
#include <string>
#include <vector>
#include "Fund.h"
using namespace std;
const int FUND_TYPES = 10;
class Account
{
	friend ostream& operator<<(ostream &outStream, const Account &acc);
public:
	Account();
	Account(const string &FirstName,const string &LastName,const int &id);
	~Account();

	string getFirstName()const;
	string getLastName()const;
	int getID()const;

	bool Deposit(const int &fundType, const int &amount);
	bool Withdraw(const int &fundType, const int &amount);
	bool Transfer(const int &FundType, const int &amount, Account *&accB, const int &FundTypeB);
	void AccountHistory();
	void AccountHistoryByFund(const int &FundType);

	bool operator<(const Account &acc)const;
	bool operator>(const Account &acc)const;
	bool operator==(const Account &acc)const;
	bool operator!=(const Account &acc)const;

private:
	string FirstName;
	string LastName;
	int ID;
	vector<Fund> FundTypes;
	void setFundNames();
};

