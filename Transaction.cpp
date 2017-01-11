#include "stdafx.h"
#include "Transaction.h"


Transaction::Transaction()
{
	key = -1;
	FirstName = "";
	LastName="";
	ID=-1;
	IDTrans=-1;
	FundType=-1;
	FundTypeTrans=-1;
	Amount=-1;
}

Transaction::Transaction(const string &key,const string &firstName,const string &lastName,const int &id)
{
	this->key = key;
	this->FirstName = firstName;
	this->LastName = lastName;
	this->ID = id;
}
Transaction::Transaction(const string &key,const int &id,const int &fundType,const int &amount)
{
	this->key = key;
	this->ID = id;
	this->FundType = fundType;
	this->Amount = amount;
}
Transaction::Transaction(const string &key,const int &id)
{
	this->key = key;
	this->ID = id;
	this->FundType = -1;
}
Transaction::Transaction(const string &key,const int &id,const int &fundType)
{
	this->key = key;
	this->ID = id;
	this->FundType = fundType;
}

Transaction::Transaction(const string &key,const int &id,const int &fundtype,const int &amount,const int &idtrans,const int &fundtypetrans)
{
	this->key = key;
	this->ID = id;
	this->Amount = amount;
	this->FundType = fundtype;
	this->IDTrans = idtrans;
	this->FundTypeTrans = fundtypetrans;
}

Transaction::~Transaction()
{
}

string Transaction::getKey()const
{
	return key;
}
string Transaction::getFirstName()const
{
	return FirstName;
}
string Transaction::getLastName()const
{
	return LastName;
}
int Transaction::getID()const
{
	return ID;
}
int Transaction::getIDTrans()const
{
	return IDTrans;
}
int Transaction::getFundType()const
{
	return FundType;
}
int Transaction::getFundTypeTrans()const
{
	return FundTypeTrans;
}
int Transaction::getAmount()const 
{
	return Amount;
}

ostream& operator<<(ostream &outStream, const Transaction &tran)
{
	outStream <<"Transaction type: " <<tran.key << endl;
	outStream << "First Name: "<<tran.FirstName << endl;
	outStream << "Last Name: "<<tran.LastName << endl;
	outStream <<"ID: "<< tran.ID<<endl;
	outStream << "Transer ID: " << tran.IDTrans <<endl;
	outStream << "Fund Type: " << tran.FundType << endl;
	outStream << "Transfer Fund Type: " << tran.FundTypeTrans << endl;
	outStream << "Amount: $" << tran.Amount;
	return outStream;
}