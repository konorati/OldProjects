#ifndef CREDIT_REPORT_H
#define CREDIT_REPORT_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef struct profile
{
	double realEstateDebt;
	double ccDebt;
}Profile;

typedef struct account
{
	string type;
	int age;
	double amount;
	double limit;
}Account;

class CreditReport
{
private:
	int mScore;
	Profile mDebt;
	Account mAccounts[10];
	int mInquiries;
	int mNumAccounts;
	double mAveAge;
	double mCreditAge;

public:
	CreditReport();
	~CreditReport();

	//get functions
	int getScore();
	double getRealEstateDebt();
	double getCCDebt();
	string getAccountType(int accountNum);
	int getAccountAge(int accountNum);
	double getAccountAmount(int accountNum);
	double getAccountLimit(int accountNum);
	double getAveAge();
	double getCreditAge();
	int getNumAccounts();
	int getNumInquiries();

	//set functions
	void editAccount();
	void addAccount();


	void printReport();
	void updateReport();

};



#endif