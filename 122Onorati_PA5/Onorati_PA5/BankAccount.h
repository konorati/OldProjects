/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 4
* Date: June 25th, 2013
* Description: Account class simulates an individual bank account for which money can be
*	added or removed. Bank class simulates entire bank with multiple bank accounts connected
*	as a linked list
**************************************************************************************/

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

class Bank;
class Account
{
	friend class Bank;

	private:
		double mBalance;
		int mAccountNum;
		string mName;
		string mDate;
		Account *mpNext;

	public:
		Account(double bal = 0.00, int actNum = 0, string name = "", string date = "");
		Account(Account &rhs);


		//Getters & setters
		void setBalance(double bal);
		void setAccountNum(int actNum);
		void setName(string name);
		void setDate(string date);
		double getBalance();
		int getAccountNum();
		string getName();
		string getDate();

		//Member functions
		void credit(double amt);
		void debit(double amt);
		void printAccountInfo();
};

class Bank
{
	private:
		Account *pList;
		void insertAccount(Account *newAccount);

	public:
		Bank(Account *newList = NULL);
		~Bank();

		//Get/Set functions
		void setList(Account *list);
		Account * getList();

		//Member functions
		void displayMenu();
		int getMenuChoice();
		void addAccount();
		void deleteAccount();
		void modifyAccount();
		void displayAccount();
		Account *findAccount();
		void deposit(double amt);
		void withdrawal(double amt);
};


#endif