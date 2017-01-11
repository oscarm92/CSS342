#pragma once
#include <string>
#include <vector>
using namespace std;
class Fund
{
public:
	Fund();
	Fund(const string & nameOfFund, const int & amount);
	~Fund();
	string getNameOfFund()const;
	int getBalance()const;
	bool setNameOfFund(const string & nameOfFund);
	bool Withdraw(const int & amount);
	bool Deposit(const int & amount);
	void DisplayFundHistory()const;
	int RecordCount()const;
	void Addrecord(const string & record);

private:
	string NameOfFund;
	int ToatalMoney;
	vector<string> FundRecords;
};

