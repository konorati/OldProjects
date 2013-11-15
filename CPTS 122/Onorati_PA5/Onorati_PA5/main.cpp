/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 5
* Date: July 1st, 2013
* Description: Simulates a bank with associated transactions
**************************************************************************************/

#include "BankAccount.h"


int main(void)
{
	int choice = 0;
	double amt = 0.0;
	Bank wsecu;

	while(choice != 7)
	{
		system("cls");
		wsecu.displayMenu();
		choice = wsecu.getMenuChoice();

		switch(choice)
		{
			case 1:
				_flushall();
				wsecu.addAccount();
				break;
			case 2:
				_flushall();
				wsecu.modifyAccount();
				break;
			case 3:
				_flushall();
				cout << "Enter amount to deposit: ";
				cin >> amt;
				wsecu.deposit(amt);
				break;
			case 4:
				_flushall();
				cout << "Enter the amount to withdraw: ";
				cin >> amt;
				wsecu.withdrawal(amt);
				break;
			case 5:
				_flushall();
				wsecu.displayAccount();
				break;
			case 6:
				_flushall();
				wsecu.deleteAccount();
				break;
			default:
				break;
		}
	}
	wsecu.~Bank();
	cout << "Thankyou for using the bank" << endl;

	return 0;
}