/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 6
* Date: July 9th, 2013
* Description: Runs Simpletron Machine Language (SML) programs (either pre-loaded or entered by user)
**************************************************************************************/

#include "Simpletron.h"
#include "SimpletronSimulator.h"

int main(void)
{
	SimpletronSimulator computer;
	int choice = 0, testChoice = 0;
	while(choice != 5)
	{
		do
		{
			system("cls");
			cout << "*** Simpletron Menu ***" << endl;
			cout << "1. Enter a program" << endl;
			cout << "2. Load a test program" << endl;
			cout << "3. Run program" << endl;
			cout << "4. Computer dump" << endl;
			cout << "5. Exit simpletron" << endl;
			cout << "Enter your menu selection: ";
			cin >> choice;
		} while(choice < 1 || choice > 5);

		switch(choice)
		{
			case 1: system("cls"); // User enters a program
					computer.resetComputer();
					computer.getProgram();
				break;
			case 2: // User chooses a test program to load
				do
				{
					system("cls");
					_flushall();
					testChoice = 0;
					cout << "*** Test Program Options ***" << endl;
					cout << " 1. Sum 2 numbers" << endl;
					cout << " 2. Subtract 2 numbers" << endl;
					cout << " 3. Multiply 2 numbers" << endl;
					cout << " 4. Divide 2 numbers" << endl;
					cout << " 5. Determine remainder of 2 numbers" << endl;
					cout << " 6. Exponentiation of 2 numbers" << endl;
					cout << " 7. Determine which of 2 numbers is largest" << endl;
					cout << " 8. Determine if a remainder exists between two numbers" << endl;
					cout << "Which program would you like to load? ";
					cin >> testChoice;
					if(testChoice < 1 || testChoice > 8)
					{
							cout << "Invalid choice." << endl;
					}
				} while(testChoice < 1 || testChoice > 8);

				computer.resetComputer();
				switch(testChoice) // Test program is loaded into memory
				{
					case 1: computer.loadTest1();
						break;
					case 2: computer.loadTest2();
						break;
					case 3: computer.loadTest3();
						break;
					case 4: computer.loadTest4();
						break;
					case 5: computer.loadTest5();
						break;
					case 6: computer.loadTest6();
						break;
					case 7: computer.loadTest7();
						break;
					case 8: computer.loadTest8();
						break;
					default:
						cout << "Invalid choice" << endl;
						break;
				}
				break;
			case 3: computer.runProgram(); //Run currently loaded program
				break;
			case 4: system("cls");
				computer.dump(); // Prints current registers and memory to console
				break;
			case 5: // Exit
				cout << "Thank you for using simpletron for your computing needs " << endl;
				
				break;
		}
		system("pause");
	}
	return 0;
}