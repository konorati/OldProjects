#include "BankAccount.h"

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Account constructor (overloads default constructor)
* Input parameters: Account balance, account number, name of account holder, creation date
* Returns: 
* Precondition: 
* Postcondition: New account is created
*************************************************************************/
Account::Account(double bal, int actNum, string name, string date)
{
	if(bal < 0)
	{
		mBalance = 0;
		cout << "Balance cannot be less than 0" << endl;
		system("pause");
	}
	else
	{
		mBalance = bal;
	}
	mAccountNum = actNum;
	mName.assign(name);
	mDate.assign(date);
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Account copy constructor (overloads default copy constructor)
* Input parameters: Account to copy
* Returns: 
* Precondition: 
* Postcondition: Copy of original account is made
*************************************************************************/
Account::Account(Account &rhs)
{
	mBalance = rhs.mBalance;
	mAccountNum = rhs.mAccountNum;
	mName.assign(rhs.mName);
	mDate.assign(rhs.mDate);
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Sets balance of account
* Input parameters: new balance
* Returns: 
* Precondition: 
* Postcondition: Account balance is updated
*************************************************************************/
void Account::setBalance(double bal)
{
	mBalance = bal;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Sets account number
* Input parameters: new account number
* Returns: 
* Precondition: 
* Postcondition: account number is updated
*************************************************************************/
void Account::setAccountNum(int actNum)
{
	mAccountNum = actNum;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Sets account name
* Input parameters: new account holder name
* Returns: 
* Precondition: 
* Postcondition: Account holder name is updated
*************************************************************************/
void Account::setName(string name)
{
	mName.assign(name);
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Sets account creation date
* Input parameters: new creation date
* Returns: 
* Precondition: 
* Postcondition: account creation date is updated
*************************************************************************/
void Account::setDate(string date)
{
	mDate.assign(date);
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Gets account balance
* Input parameters: 
* Returns: Account balance
* Precondition: 
* Postcondition: Account balance is returned
*************************************************************************/
double Account::getBalance()
{
	return mBalance;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Gets account number
* Input parameters: 
* Returns: Account number
* Precondition: 
* Postcondition: Account number is returned
*************************************************************************/
int Account::getAccountNum()
{
	return mAccountNum;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Gets account name
* Input parameters: 
* Returns: Account name
* Precondition: 
* Postcondition: Account name is returned
*************************************************************************/
string Account::getName()
{
	return mName;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Gets account creation date
* Input parameters: 
* Returns: Account creation date
* Precondition: 
* Postcondition: Account creation date is returned
*************************************************************************/
string Account::getDate()
{
	return mDate;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Adds money to the account balance
* Input parameters: Amount to add to balance
* Returns: 
* Precondition: 
* Postcondition: Account balance is updated
*************************************************************************/
void Account::credit(double amt)
{
	mBalance += amt;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Subtracts amount from current balance, gives error if debit would
*	cause account to go negative (and balance is left unchanged)
* Input parameters: amount to be debited
* Returns:
* Precondition: 
* Postcondition: Account balance is updated
*************************************************************************/
void Account::debit(double amt)
{
	if((mBalance - amt) < 0)
	{
		cout << "Insufficient funds" << endl;
		system("pause");
	}
	else
	{
		mBalance -= amt;
	}
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Prints individual account info for single account
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Account info is printed to console
*************************************************************************/
void Account::printAccountInfo()
{
	cout << "*** Account Info ***" << endl;
	cout << "Customer Name: " << mName << endl;
	cout << "Account Number: " << mAccountNum << endl;
	cout << "Balance: $" << mBalance << endl;
	cout << "Date Account Opened: " << mDate << endl;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Constructor for bank object (overloads default constructor)
* Input parameters:  Pointer to beginning of new list of accounts
* Returns: 
* Precondition: 
* Postcondition: New bank object is instantiated
*************************************************************************/
Bank::Bank(Account *newList)
{
	pList = newList;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Default destructor, destroys entire bank and contents of bank
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Bank and account info is deleteed and memory is freed
*************************************************************************/
Bank::~Bank()
{
	Account *pTemp = NULL;
	pTemp = pList;
	while(pList != NULL)
	{
		pList = pList->mpNext;
		delete(pTemp);
	}
}
/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Sets new value for start of list
* Input parameters: New pointer to start of account list
* Returns: 
* Precondition: 
* Postcondition: Start of account list is updated
*************************************************************************/
void Bank::setList(Account *list)
{
	pList = list;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Gets pointer to start of account list
* Input parameters: 
* Returns: pointer to start of account list
* Precondition: 
* Postcondition: Pointer to start of account list is returned
*************************************************************************/
Account * Bank::getList()
{
	return pList;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Displays banking option menu
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Banking option menu is displayed to console
*************************************************************************/
void Bank::displayMenu()
{
	cout << "*** Bank Menu ***" << endl;
	cout << "1. Add Account" << endl;
	cout << "2. Modify Account Info" << endl;
	cout << "3. Make a deposit" << endl;
	cout << "4. Make a withdrawal" << endl;
	cout << "5. View Account" << endl;
	cout << "6. Delete Account" << endl;
	cout << "7. Exit Bank" << endl;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Gets and validates users menu choice
* Input parameters: 
* Returns: Menu choice
* Precondition: 
* Postcondition: Valid menu choice is returned
*************************************************************************/
int Bank::getMenuChoice()
{
	int choice = 0;
	do
	{
		cout << "Enter your menu choice: " ;
		cin >> choice;
		if(choice < 1 || choice > 7)
		{
			cout << "Invalid selection" << endl;
		}
	}while(choice < 1 || choice > 7);

	return choice;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Adds a new bank account to list of accounts, gets user input for account info
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: New account is added to list
*************************************************************************/
void Bank::addAccount()
{
	Account *pMem = NULL;
	char tempStr[50];
	string tempName;
	int tempActNum;
	double tempBalance;
	string tempDate;
	cout << "Enter Name: ";
	gets(tempStr);
	tempName.assign(tempStr);
	cout << "Enter Account Number: ";
	cin >> tempActNum;
	cout << "Enter Account Balance: ";
	cin >> tempBalance;
	cout << "Enter Account Creation Date <mm/dd/yy>: ";
	cin >> tempDate;
	pMem = new Account(tempBalance, tempActNum, tempName, tempDate);
	pMem->mpNext = pList;
	pList = pMem;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Deletes a user specified account from account list
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Account is deleted and memory is freed
*************************************************************************/
void Bank::deleteAccount()
{
	int tmpActNum;
	Account *conductor = NULL, *previous = NULL;
	_flushall();
	cout << "Enter account number you would like to delete: ";
	cin >> tmpActNum;

	conductor = pList;
	while(conductor != NULL && conductor->mAccountNum != tmpActNum)
	{
		if(conductor->mAccountNum != tmpActNum)
		{
			previous = conductor;
			conductor = conductor->mpNext;
		}
	}
	if(conductor == NULL) //account number not found
	{
		cout << "Invalid account number" << endl;
	}
	else if(previous == NULL) //delete from front of list
	{
		pList = conductor->mpNext;
		delete(conductor);
	}
	else
	{
		previous->mpNext = conductor->mpNext;
		delete(conductor);
	}

}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Modifies a user specified account
* Input parameters: 
* Returns:
* Precondition: 
* Postcondition: Account field specified by user is modified
*************************************************************************/
void Bank::modifyAccount()
{
	Account *pTemp = NULL;
	int choice = 0;
	char tempName[50];
	system("cls");
	pTemp = findAccount();
	if(pTemp != NULL)
	{
		while(choice < 1 || choice > 4)
		{
			flushall();
			cout << "Which field would you like to modify? " << endl;
			cout << "1. Name" << endl;
			cout << "2. Account Number" << endl;
			cout << "3. Balance" << endl;
			cout << "4. Creation Date" << endl;
			cin >> choice;
			if(choice < 1 || choice > 4)
			{
				cout << "Invalid choice "<< endl;
			}
		}
		_flushall();
		switch(choice)
		{
			case 1: cout << "Current Name: " << (*pTemp).mName << endl;
				cout << "Enter new name: ";
				gets(tempName);
				(*pTemp).mName.assign(tempName);
				break;
			case 2: cout << "Current Account Number: " << (*pTemp).mAccountNum << endl;
				cout << "Enter new account number: ";
				cin >> (*pTemp).mAccountNum;
				break;
			case 3: cout << "Current Balance: " << (*pTemp).mBalance << endl;
				cout << "Enter new balance: ";
				cin >> (*pTemp).mBalance;
				break;
			case 4: cout << "Current Creation Date: " << (*pTemp).mDate << endl;
				cout << "Enter new creation date: ";
				gets(tempName);
				(*pTemp).mName.assign(tempName);
				break;
		}
	}
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Displays info for a user specified account
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Account info is displayed to console
*************************************************************************/
void Bank::displayAccount()
{
	Account *pTemp = NULL;
	pTemp = findAccount();
	if(pTemp != NULL)
	{
	(*pTemp).printAccountInfo();
	}
	system("pause");
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Finds an account based on account number specified by user
* Input parameters: 
* Returns: Pointer to user specified account (or null if no matching account was found)
* Precondition: 
* Postcondition: Pointer to valid account or null pointer is returned
*************************************************************************/
Account *Bank::findAccount()
{
	int tmpActNum;
	Account *conductor = NULL;
	cout << "Enter the Account Number for the account you would like to access: ";
	cin >> tmpActNum;

	conductor = pList;
	while(conductor != NULL && conductor->mAccountNum != tmpActNum)
	{
		if(conductor->mAccountNum != tmpActNum)
		{
			conductor = conductor->mpNext;
		}
	}

	if(conductor == NULL) //Account not found
	{
		cout << "Invalid account number" << endl;
		system("pause");
	}
	return conductor;
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Deposits money into user specified account
* Input parameters: deposit amount
* Returns: 
* Precondition: 
* Postcondition: Account balance is updated
*************************************************************************/
void Bank::deposit(double amt)
{
	Account *pTemp = NULL;
	pTemp = findAccount();
	if(pTemp != NULL)
	{
		(*pTemp).credit(amt);
		cout << "New Account Balance: $" << pTemp->mBalance << endl;
		system("pause");
	}
}

/*************************************************************************
* Date last modified: July 1st, 2013
* Description: Withdraws money from user specified account (unless insufficient funds)
* Input parameters: Amount to withdraw
* Returns: 
* Precondition: 
* Postcondition: Account balance is updated or error message is printed
*************************************************************************/
void Bank::withdrawal(double amt)
{
	Account *pTemp = NULL;
	pTemp = findAccount();
	if(pTemp != NULL)
	{
		(*pTemp).debit(amt);
		cout << "New Account Balance: $" << pTemp->mBalance << endl;
		system("pause");
	}
}