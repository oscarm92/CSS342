#pragma once
#include <string>
#include <queue>  
#include "BSTree.h"
#include "Account.h"
#include "Transaction.h"
using namespace std;
class Bank
{
public:
	Bank();
	~Bank();

	bool ReadTransactionFile(const string &fileName);
	bool ProccesTransactions();
	void DisplayAccountsBalances()const;

private:
	queue<Transaction> q;
	BSTree tree;
	
};

