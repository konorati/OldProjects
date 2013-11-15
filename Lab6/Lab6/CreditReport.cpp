#include "CreditReport.h"

CreditReport::CreditReport() //Constructor
{
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		mAccounts[i].age = 0;
		mAccounts[i].amount = 0.0;
		mAccounts[i].limit = 0.0;
		mAccounts[i].type = string("none");
	}
	mScore = 0;
	mDebt.ccDebt = 0.0;
	mDebt.realEstateDebt = 0.0;
	mInquiries = 0;
	mNumAccounts = 0;
	mAveAge = 0.0;
	mCreditAge = 0.0;
}

CreditReport::~CreditReport()
{
}
 
//Get functions
int CreditReport::getScore()
{
	return mScore;
}

double CreditReport::getRealEstateDebt()
{
	return mDebt.realEstateDebt;
}

double CreditReport::getCCDebt()
{
	return mDebt.ccDebt;
}

string CreditReport::getAccountType(int accountNum)
{
	return mAccounts[accountNum].type;
}

int CreditReport::getAccountAge(int accountNum)
{
	return mAccounts[accountNum].age;
}

double CreditReport::getAccountAmount(int accountNum)
{
	return mAccounts[accountNum].amount;
}

double CreditReport::getAccountLimit(int accountNum)
{
	return mAccounts[accountNum].limit;
}

double CreditReport::getAveAge()
{
	return mAveAge;
}

double CreditReport::getCreditAge()
{
	return mCreditAge;
}

int CreditReport::getNumAccounts()
{
	return mNumAccounts;
}

int CreditReport::getNumInquiries()
{
	return mInquiries;
}

//Set functions


//Other functions
void CreditReport::printReport()
{
	int i = 0;
	mInquiries++;
	cout << "Credit Report Number " << mInquiries << ":" << endl;
	cout << "Credit Score: " << mScore << endl;
	for(i = 0; i < mNumAccounts; i++)
	{
		cout << endl << "Account " << i+1 << ":" << endl;
		cout << "Type: " << mAccounts[i].type << endl;
		cout << "Age: " << mAccounts[i].age << endl;
		cout << "Debt: " << mAccounts[i].amount << endl;
		cout << "Limit: " << mAccounts[i].limit << endl;
	}
	cout << endl << "Total Credit Debt: " << mDebt.ccDebt << endl;
	cout << "Total Real Estate Debt: " << mDebt.realEstateDebt << endl;
	cout << "Credit History Age: " << mCreditAge << endl;
	cout << "Average Account Age: " << mAveAge << endl;
}

void CreditReport::updateReport()
{
	double totAge = 0.0, totLimit =  0.0, creditDebt = 0.0, realEstateDebt = 0.0;
	int i = 0;
	
	mScore = 330;
	
	for(i = 0; i < mNumAccounts; i++)
	{
		totAge += mAccounts[i].age;
		if(mAccounts[i].type == "Real Estate")
		{
			realEstateDebt += mAccounts[i].amount;
		}
		else
		{
			creditDebt += mAccounts[i].amount;
		}
		totLimit += mAccounts[i].limit;
		mScore += abs(mAccounts[i].amount - mAccounts[i].limit)/10;
		if(mScore > 830)
		{
			mScore = 830;
		}
		if(mAccounts[i].age > mCreditAge)
		{
			mCreditAge = mAccounts[i].age;
		}
	}
	if(mNumAccounts != 0)
	{
		mAveAge = totAge / mNumAccounts;
	}
	mDebt.ccDebt = creditDebt;
	mDebt.realEstateDebt = realEstateDebt;
}

void CreditReport::editAccount()
{
	int num = 0, choice = 0;

	cout << "Enter account number between 1 and " << mNumAccounts << ": ";
	cin >> num;
	while(choice != 5)
	{
		system("cls");
		cout << "1. Type" << endl << "2. Age" << endl << "3. Debt" << endl << "4. Limit" << endl << "5. Main Menu" << endl;
		switch(choice)
		{
		case 1: cout << "Enter new type: ";
				getline(cin, mAccounts[num-1].type);
				break;
		case 2: cout << "Enter new account age: ";
				cin >> mAccounts[num-1].age;
				break;
		case 3: cout << "Enter new debt: ";
				cin >> mAccounts[num-1].amount;
				break;
		case 4: cout << "Enter new limit: ";
				cin >> mAccounts[num-1].amount;
				break;
		default: break;
		}
	}
}

void CreditReport::addAccount()
{
	mNumAccounts++;
	cout << "Enter account type: ";
	getline(cin, mAccounts[mNumAccounts-1].type);
	cout << "Enter account age: ";
	cin >> mAccounts[mNumAccounts-1].age;
	cout << "Enter account debt: ";
	cin >> mAccounts[mNumAccounts-1].amount;
	cout << "Enter account limit: ";
	cin >> mAccounts[mNumAccounts-1].limit;
}