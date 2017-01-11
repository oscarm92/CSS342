#include "stdafx.h"
#include "Bank.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;


Bank::Bank()
{
}

Bank::~Bank()
{
}

bool Bank::ReadTransactionFile(const string &fileName)
{
	ifstream fin;
	fin.open(fileName); 
	if (!fin.good())
	{
		return false;
	}
	string line;
	while (!fin.eof())
	{ 
		getline(fin, line);
		istringstream ss(line);
		while (!ss.eof())         
		{
			string TransType;               
			getline(ss, TransType, ' ');  
			if (TransType == "O")
			{
				string FirstName;
				getline(ss, FirstName, ' '); 
				string LastName;
				getline(ss, LastName, ' ');
				string ID;
				getline(ss, ID, ' ');
				if (ID.size() !=4 || (atoi(ID.c_str())<1000)|| (atoi(ID.c_str())>9999))
				{
					cerr << "ERROR: Not a valid ID number "<<ID<<"." << endl;
				}
				else
				{
					Transaction openT(TransType, FirstName, LastName, atoi(ID.c_str()));
					q.push(openT);
				}
			}
			else if (TransType == "D")
			{
				string idandfund;
				getline(ss, idandfund, ' ');
				if (idandfund.size() != 5)
				{
					cerr << "ERROR: Not a valid ID or Fund number " << idandfund << "." << endl;
				}
				else
				{
					string id = idandfund.substr(0, 4);
					string fund = idandfund.substr(4, 1);
					string amount;
					getline(ss, amount, ' ');
					if (atoi(amount.c_str()) < 0)
					{
						cerr << "ERROR: Cannot diposite a negative amount." << endl;
					}
					else
					{
						Transaction depositeT(TransType, atoi(id.c_str()), atoi(fund.c_str()), atoi(amount.c_str()));
						q.push(depositeT);
					}
				}
				
			}
			else if (TransType == "W")
			{
				string idandfund;
				getline(ss, idandfund, ' ');
				if (idandfund.size() != 5)
				{
					cerr << "ERROR: Not a valid ID or Fund number " << idandfund << "." << endl;
				}
				else
				{
					string id = idandfund.substr(0, 4);
					string fund = idandfund.substr(4, 1);
					string amount;
					getline(ss, amount, ' ');
					if (atoi(amount.c_str()) < 0)
					{
						cerr << "ERROR: Cannot withdraw a negative amount." << endl;
					}
					else
					{
						Transaction depositeT(TransType, atoi(id.c_str()), atoi(fund.c_str()), atoi(amount.c_str()));
						q.push(depositeT);
					}
				}
			}
			else if (TransType == "T")
			{
				string idandfund;
				getline(ss, idandfund, ' ');
				if (idandfund.size() != 5)
				{
					cerr << "ERROR: Not a valid ID or Fund number " << idandfund << "." << endl;
				}
				else
				{
					string id = idandfund.substr(0, 4);
					string fund = idandfund.substr(4, 1);

					string amount;
					getline(ss, amount, ' ');
					if (atoi(amount.c_str()) < 0)
					{
						cerr << "ERROR: Cannot transfer a negative amount." << endl;
					}
					else
					{

						string idandfundTrans;

						getline(ss, idandfundTrans, ' ');
						if (idandfundTrans.size() != 5)
						{
							cerr << "ERROR: Not a valid ID or Fund number " << idandfundTrans << "." << endl;
						}
						else
						{
							string idTrans = idandfundTrans.substr(0, 4);
							string fundTrans = idandfundTrans.substr(4, 1);


							Transaction TransferT(TransType, atoi(id.c_str()), atoi(fund.c_str()), atoi(amount.c_str()), atoi(idTrans.c_str()), atoi(fundTrans.c_str()));
							q.push(TransferT);
						}
					}
					
				}
			}
			else if (TransType == "H")
			{
				string idandfund;
				getline(ss, idandfund, ' ');
				if (idandfund.size() <4|| idandfund.size() >5)
				{
					cerr << "ERROR: Not a valid ID or Fund number " << idandfund << "." << endl;
				}
				else
				{

					string id = idandfund.substr(0, 4);
					string fund = "-1";
					if (idandfund.size() > 4)
					{
						fund = idandfund.substr(4, 1);
					}
					Transaction HistoryT(TransType, atoi(id.c_str()), atoi(fund.c_str()));
					q.push(HistoryT);
				}
			}
		}
	}
	fin.close(); 
	return true;
}

bool Bank::ProccesTransactions()
{
	while (!q.empty())
	{
		Transaction t = q.front();
		if (t.getKey() == "O")
		{	
			string firstName = t.getFirstName();
			string lastName = t.getLastName();
			int ID = t.getID();
			Account *acc= new Account(firstName, lastName, ID);
			if (tree.Retrieve(ID,acc))
			{
				cerr << "ERROR: Account "<< ID << " already open. Transaction refused."<<endl;
			}
			else
			{
				tree.Insert(acc);
			}
		}
		else if (t.getKey()=="D")
		{
			int ID = t.getID();
			int Fund = t.getFundType();
			int amount = t.getAmount();
			Account *acc;
			bool result=tree.Retrieve(ID, acc);
			if (!result)
			{
				cerr << "ERROR: Account " <<ID<<" does not exist." << endl;
			}
			else
			{
				acc->Deposit(Fund, amount);
			}
		}
		else if (t.getKey() == "W")
		{
			int ID = t.getID();
			int Fund = t.getFundType();
			int amount = t.getAmount();
			Account *acc;
			bool result = tree.Retrieve(ID, acc);
			if (!result)
			{
				cerr << "ERROR: Account " << ID << " does not exist." << endl;
			}
			else
			{
				acc->Withdraw(Fund, amount);
			}
		}
		else if (t.getKey() == "T")
		{
			int ID = t.getID();
			int Fund = t.getFundType();
			int amount = t.getAmount();

			int IDTransfer = t.getIDTrans();
			int FundTransfer = t.getFundTypeTrans();
			
			Account *acc;
			Account *accTransfer;
			bool result = tree.Retrieve(ID, acc);
			bool resultTransfer = tree.Retrieve(IDTransfer, accTransfer);
			if (!result|| !resultTransfer)
			{
				cerr << "ERROR: Account "<< IDTransfer <<" not found. Transferal refused." << endl;
			}
			else
			{
				acc->Transfer(Fund, amount, accTransfer, FundTransfer);
			}

		}
		else if (t.getKey() == "H")
		{
			int ID = t.getID();
			int Fund = t.getFundType();
			Account *acc;
			bool result = tree.Retrieve(ID, acc);
			if (!result)
			{
				cerr << "ERROR: Account history does not exist for "<<ID<<"." << endl;
			}
			else
			{
				if (Fund == -1)
				{
					acc->AccountHistory();
				}
				else
				{
					acc->AccountHistoryByFund(Fund);
				}
			}
		}
		q.pop();
	}
	return true;
}

void Bank::DisplayAccountsBalances()const
{
	tree.Display();
}

