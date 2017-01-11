#include "stdafx.h"
#include "Fund.h"
#include <iostream>

Fund::Fund()
{
	NameOfFund = "";
	ToatalMoney = 0;
}

Fund::Fund(const string & nameOfFund, const int & amount)
{
	this->NameOfFund = nameOfFund;
	Deposit(amount);
}

Fund::~Fund()
{
}

string Fund::getNameOfFund()const
{
	return NameOfFund;
}

bool Fund::setNameOfFund(const string & nameOfFund)
{
	this->NameOfFund = nameOfFund;
	return true;
}

int Fund::getBalance()const
{
	return ToatalMoney;
}

bool Fund::Withdraw(const int & amount)
{
	if (amount < 0)
	{
		cerr << "ERROR: Cannot Withdraw negative amount." << endl;
		return false;
	}
	else
	{
		if (ToatalMoney - amount < 0)
		{
			return false;
		}
		else
		{
			ToatalMoney -= amount;
			return true;
		}
	}
}

bool Fund::Deposit(const int & amount)
{
	if (amount < 0)
	{
		cerr << "ERROR: Cannot Deposit negative amount." << endl;
		return false;
	}
	else
	{
		ToatalMoney += amount;
		return true;
	}
}

void Fund::DisplayFundHistory()const
{
	for (int i = 0; i < FundRecords.size(); i++)
	{
		cout << FundRecords.at(i)<<endl;
	}
}

int Fund::RecordCount() const
{
	return FundRecords.size();
}

void Fund::Addrecord(const string & record)
{
	FundRecords.push_back(record);
}
