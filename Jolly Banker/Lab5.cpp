// Lab5.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Bank.h"
using namespace std;
int main()
{
	Bank b1;
	b1.ReadTransactionFile("BankTransIn.txt");
	b1.ProccesTransactions();
	cout << endl;
	cout << "Processing Done. Final Balances." << endl;
	b1.DisplayAccountsBalances();
}

