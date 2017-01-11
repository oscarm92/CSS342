#include "stdafx.h"
#include "Account.h"
#include <iostream>


Account::Account()
{
	FirstName = "";
	LastName = "";
	ID = 0000;
	FundTypes.resize(FUND_TYPES);
	setFundNames();
}

Account::Account(const string &FirstName,const string &LastName,const int &id)
{
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->ID = id;
	FundTypes.resize(FUND_TYPES);
	setFundNames();
}

Account::~Account()
{
}

string Account::getFirstName()const
{
	return FirstName;
}
string Account::getLastName()const
{
	return LastName;
}
int Account::getID()const
{
	return ID;
}

bool Account::Deposit(const int &fundType, const int &amount)
{
	FundTypes[fundType].Deposit(amount);
	FundTypes[fundType].Addrecord("Deposited $" + to_string(amount) + ".");
	return true;
}

bool Account::Withdraw(const int &fundType, const int &amount)
{
	bool result=FundTypes[fundType].Withdraw(amount);
	if (result)
	{
		FundTypes[fundType].Addrecord("Withdrew $" + to_string(amount) + ".");
		return true;
	}
	else
	{
		if (fundType == 0)
		{
			int fundamount = FundTypes[0].getBalance();
			bool result = FundTypes[1].Withdraw(amount - FundTypes[0].getBalance());
			if (result)
			{
				FundTypes[1].Addrecord("Withdrew $" + to_string(amount - FundTypes[0].getBalance()) + ".");
				FundTypes[0].Withdraw(FundTypes[0].getBalance());
				FundTypes[0].Addrecord("Withdrew $" + to_string(fundamount) + ".");
				return true;
			}
			else
			{
				cerr << "ERROR: Not enough funds to withdraw $" << amount << " from " << FirstName << " " << LastName << " " << FundTypes[fundType].getNameOfFund() << endl;
				FundTypes[fundType].Addrecord("Withdral of $" + to_string(amount) + " from " + FundTypes[fundType].getNameOfFund() + " failed (Insufficient Funds).");
				return false;
			}

		}
		else if (fundType == 1)
		{
			int fundamount = FundTypes[1].getBalance();
			bool result = FundTypes[0].Withdraw(amount - FundTypes[1].getBalance());
			if (result)
			{
				FundTypes[0].Addrecord("Withdrew $" + to_string(amount - FundTypes[1].getBalance()) + ".");
				FundTypes[1].Withdraw(FundTypes[1].getBalance());
				FundTypes[1].Addrecord("Withdrew $" + to_string(fundamount) + ".");
				return true;
			}
			else
			{
				cerr << "ERROR: Not enough funds to withdraw $" << amount << " from " << FirstName << " " << LastName << " " << FundTypes[fundType].getNameOfFund() << endl;
				FundTypes[fundType].Addrecord("Withdral of $" + to_string(amount) + " from " + FundTypes[fundType].getNameOfFund() + " failed (Insufficient Funds).");
				return false;
			}
		}
		else if (fundType == 2)
		{
			int fundamount = FundTypes[2].getBalance();
			bool result = FundTypes[3].Withdraw(amount - FundTypes[2].getBalance());
			if (result)
			{
				FundTypes[3].Addrecord("Withdrew $" + to_string(amount - FundTypes[2].getBalance()) + ".");
				FundTypes[2].Withdraw(FundTypes[2].getBalance());
				FundTypes[2].Addrecord("Withdrew $" + to_string(fundamount) + ".");
				return true;
			}
			else
			{
				cerr << "ERROR: Not enough funds to withdraw $" << amount << " from " << FirstName << " " << LastName << " " << FundTypes[fundType].getNameOfFund() << endl;
				FundTypes[fundType].Addrecord("Withdral of $" + to_string(amount) + " from " + FundTypes[fundType].getNameOfFund() + " failed (Insufficient Funds).");
				return false;
			}
		}
		else if (fundType == 3)
		{
			int fundamount = FundTypes[3].getBalance();
			bool result = FundTypes[2].Withdraw(amount - FundTypes[3].getBalance());
			if (result)
			{
				FundTypes[2].Addrecord("Withdrew $" + to_string(amount - FundTypes[3].getBalance()) + ".");
				FundTypes[3].Withdraw(FundTypes[3].getBalance());
				FundTypes[3].Addrecord("Withdrew $" + to_string(fundamount) + ".");
				return true;
			}
			else
			{
				cerr << "ERROR: Not enough funds to withdraw $" << amount << " from " << FirstName << " " << LastName << " " << FundTypes[fundType].getNameOfFund() << endl;
				FundTypes[fundType].Addrecord("Withdral of $" + to_string(amount) + " from " + FundTypes[fundType].getNameOfFund() + " failed (Insufficient Funds).");
				return false;
			}
		}
		else
		{
			cerr << "ERROR: Not enough funds to withdraw $" << amount << " from " << FirstName << " " << LastName << " " << FundTypes[fundType].getNameOfFund() << endl;
			FundTypes[fundType].Addrecord("Withdral of $" + to_string(amount) + " from " + FundTypes[fundType].getNameOfFund() + " failed (Insufficient Funds).");
			return false;
		}
	}
	return true;
}
bool Account::Transfer(const int & FundType, const int & amount, Account *& accB, const int & FundTypeB)
{
	if (*this == *accB)
	{
		bool result=FundTypes[FundType].Withdraw(amount);
		if (!result)
		{
			cerr << "Transfer of $" + to_string(amount) + " from " + FundTypes[FundType].getNameOfFund() +
				" to " + FundTypes[FundTypeB].getNameOfFund() + " failed (insufficient funds)." << endl;
			FundTypes[FundType].Addrecord("Transfer of $" + to_string(amount) + " from " + FundTypes[FundType].getNameOfFund() +
				" to " + FundTypes[FundTypeB].getNameOfFund() + " failed (insufficient funds).");
			return false;
		}
		else
		{
			FundTypes[FundTypeB].Deposit(amount);
			FundTypes[FundType].Addrecord("Transfered $" + to_string(amount) + " from " + FundTypes[FundType].getNameOfFund() +
				" to " + FundTypes[FundTypeB].getNameOfFund() + ".");
			FundTypes[FundTypeB].Addrecord("Transfered $" + to_string(amount) + " from " + FundTypes[FundType].getNameOfFund() +
				" to " + FundTypes[FundTypeB].getNameOfFund() + ".");
			return true;
		}
		
	}
	else
	{
		bool result = FundTypes[FundType].Withdraw(amount);
		if (!result)
		{
			cerr << "Transfer of $" + to_string(amount) + " from Account " + to_string(ID) + " fund " + FundTypes[FundType].getNameOfFund() +
				" to Account " + to_string(accB->getID()) + " fund " + FundTypes[FundTypeB].getNameOfFund() + " failed (insufficient funds)." << endl;
			accB->FundTypes[FundType].Addrecord("Transfer of $" + to_string(amount) + " from Account " + to_string(ID) + " fund " + FundTypes[FundType].getNameOfFund() +
				" to Account " + to_string(accB->getID()) + " fund " + FundTypes[FundTypeB].getNameOfFund() + " failed (insufficient funds).");
			return false;
		}
		else
		{
			accB->FundTypes[FundTypeB].Deposit(amount);
			FundTypes[FundType].Addrecord("Transfered $" + to_string(amount) + " from Account " + to_string(ID) + " fund " + FundTypes[FundType].getNameOfFund() +
				" to Account " + to_string(accB->getID()) + " fund " + FundTypes[FundTypeB].getNameOfFund() + ".");
			accB->FundTypes[FundTypeB].Addrecord("Transfered $" + to_string(amount) + " from Account " + to_string(ID) + " fund " + FundTypes[FundType].getNameOfFund() +
				" to Account " + to_string(accB->getID()) + " fund " + FundTypes[FundTypeB].getNameOfFund() + ".");
			return true;
		}
	}
}


void Account::AccountHistory()
{

	string str = "Transaction History for " + FirstName + ", " + LastName + ". ID " + to_string(ID) + " by Fund.";
	for (int i = 1; i <= str.size(); i++)
		cout << "_";
	cout << endl;
	cout << str << endl;
	for (int i = 1; i <= str.size(); i++)
		cout << "_";
	cout << endl;
	
	for (int i = 0; i < FundTypes.size(); i++)
	{
		if (FundTypes[i].RecordCount() != 0)
		{
			cout <<"Fund"<<"["<<i<<"] "<< FundTypes[i].getNameOfFund() << " Balance: $" << FundTypes[i].getBalance() << endl;
			FundTypes.at(i).DisplayFundHistory();
		}
		if (FundTypes[i].RecordCount() != 0)
		{
			for (int i = 1; i <= str.size(); i++)
				cout << "-";
			cout << endl;
		}
		
	}
}

void Account::AccountHistoryByFund(const int &FundType)
{

	cout << "Transaction History for " << FirstName << " " << LastName << " " << FundTypes[FundType].getNameOfFund() << ": $" << FundTypes[FundType].getBalance() << endl;
	FundTypes[FundType].DisplayFundHistory();
}

bool Account::operator==(const Account & acc) const
{
	return ID==acc.getID();
}

bool Account::operator!=(const Account & acc) const
{
	return ID != acc.getID();;
}


ostream& operator<<(ostream &outStream, const Account &acc)
{
	outStream << acc.getFirstName() << " " << acc.getLastName() << " Account ID: " << acc.getID()<<endl;
	for (int i = 0; i < acc.FundTypes.size(); i++)
	{
		outStream <<"	" << acc.FundTypes[i].getNameOfFund() << ": $" << acc.FundTypes[i].getBalance() << endl;
	}
	return outStream;
}

bool Account::operator<(const Account &acc)const
{
	return ID<acc.getID();
}

bool Account::operator>(const Account &acc)const
{
	return ID > acc.getID();
}

void Account::setFundNames()
{
	FundTypes[0].setNameOfFund("Money Market");
	FundTypes[1].setNameOfFund("Prime Money Market");
	FundTypes[2].setNameOfFund("Long-Term Bond");
	FundTypes[3].setNameOfFund("Short-Term Bond");
	FundTypes[4].setNameOfFund("500 Index Fund");
	FundTypes[5].setNameOfFund("Capital Value Fund");
	FundTypes[6].setNameOfFund("Growth Equity Fund");
	FundTypes[7].setNameOfFund("Growth Index Fund");
	FundTypes[8].setNameOfFund("Value Fund");
	FundTypes[9].setNameOfFund("Value Stock Index");
}