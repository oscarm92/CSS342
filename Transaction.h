#pragma once
#include <vector>
#include "Account.h"
using namespace std;
class Transaction 
{
	friend ostream& operator<<(ostream &outStream, const Transaction &tran);
public:
	Transaction();
	Transaction(const string &key,const string &firstName,const string &lastName,const int &id);
	Transaction(const string &key,const int &id,const int &fundType,const int &amount);
	Transaction(const string &key,const int &id);
	Transaction(const string &key,const int &id,const int &fundType);
	Transaction(const string &key,const int &id,const int &amount,const int &fundtype,const int &idtrans,const int &fundtypetrans);

	~Transaction();

	string getKey()const;
	string getFirstName()const;
	string getLastName()const;
	int getID()const;
	int getIDTrans()const;
	int getFundType()const;
	int getFundTypeTrans()const;
	int getAmount()const;
	
private:
	string key;
	string FirstName;
	string LastName;
	int ID;
	int IDTrans;
	int FundType;
	int FundTypeTrans;
	int Amount;

};

