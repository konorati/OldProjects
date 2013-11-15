#include "CreditReport.h"

void run(CreditReport *pComp);

int main(void)
{
	CreditReport amtrack;
	run(&amtrack);
	return 0;
}

void run(CreditReport *pComp)
{
	string buffer = "";
	int choice = 0;
	while(choice != 4)
	{
		system("cls");
		cout << "Enter your option: " << endl;
		cout << "1. Add account" << endl;
		cout << "2. Update Report" << endl;
		cout << "3. Print Report" << endl;
		cout << "4. Exit Program" << endl;
		cin >> choice;

		switch(choice)
		{
		case 1: pComp->addAccount();
			break;
		case 2: pComp->updateReport();
			break;
		case 3: pComp->printReport();
			break;
		default: break;
		}
	}
}