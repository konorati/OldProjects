/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 7
* Date: July 16th, 2013
* Description: Runs Simpletron Language programs (either pre-loaded, entered by user, or loaded from file), compiles simple
*			programs which generates Simple Machine Language program, Runs SML program
**************************************************************************************/

#include "Simpletron.h"
#include "SimpletronSimulator.h"
#include "Compiler.h"
#include "InfixToPostfix.h"
#include "Stack.h"

int main(void)
{
	SimpletronSimulator computer;
	Compiler compiler;
	Simpletron program;
	ifstream inFile;
	ofstream outFile;
	string fileName;
	

	int choice = 0, testChoice = 0;
	while(choice != 7)
	{
		do
		{
			system("cls");
			cout << "*** Simpletron Menu ***" << endl;
			cout << "1. Enter a Simpletron Language program" << endl;
			cout << "2. Load & compile a Simpletron Language program" << endl;
			cout << "3. Enter a Simpletron Machine Language program" << endl;
			cout << "4. Load a Simpletron Machine Language program" << endl;
			cout << "5. Run program" << endl;
			cout << "6. Computer dump" << endl;
			cout << "7. Exit simpletron" << endl;
			cout << "Enter your menu selection: ";
			cin >> choice;
		} while(choice < 1 || choice > 7);

		switch(choice)
		{
		case 1: cout << "Enter name of file to save Simple program to: ";
				cin >> fileName;
				outFile.open(fileName);
				compiler.EnterProgram(outFile);
				outFile.close();
				break;
			case 2: do
				{
					system("cls");
					_flushall();
					testChoice = 0;
					cout << "*** Test Program Options ***" << endl;
					cout << " 1. Input integer and sum values from 1 to that integer" << endl;
					cout << " 2. Determine and print sum of 2 integers" << endl;
					cout << " 3. Determine and print larger of 2 integers" << endl;
					cout << " 4. Calculate the square of several integers (until sentinel value of 0)" << endl;
					cout << " 5. Load other program" << endl;
					cout << "Which program would you like to load? ";
					cin >> testChoice;
					if(testChoice < 1 || testChoice > 5)
					{
							cout << "Invalid choice." << endl;
					}
				} while(testChoice < 1 || testChoice > 5);
				switch(testChoice)
				{
					case 1: fileName = "SimpleProgram.txt";
						break;
					case 2: fileName = "SimpleProgram2.txt";
						break;
					case 3: fileName = "SimpleProgram3.txt";
						break;
					case 4: fileName = "SimpleProgram4.txt";
						break;
					case 5:
						_flushall();
						cout << "Enter name of file you would like to load from: ";
						cin >> fileName;
						break;
				}
				inFile.open(fileName);
				if(inFile.is_open())
				{
					compiler.resetCompiler();
					compiler.compileFirstPass(inFile, program);
					inFile.close();
					cout << "Enter name of file you would like to save SML program to: ";
					cin >> fileName;
					outFile.open(fileName);
					compiler.compileSecondPass(outFile, program);
					outFile.close();
				}
				else
				{
					cout << "File not found" << endl;
				}
				break;
			case 3: system("cls"); // User enters a program
					computer.resetComputer(program);
					computer.getProgram(program);
				break;
			case 4: // User chooses a test program to load
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
					cout << " 9. Load other program from file" << endl;
					cout << "Which program would you like to load? ";
					cin >> testChoice;
					if(testChoice < 1 || testChoice > 9)
					{
							cout << "Invalid choice." << endl;
					}
				} while(testChoice < 1 || testChoice > 9);

				computer.resetComputer(program);
				switch(testChoice) // Test program is loaded into memory
				{
					case 1: computer.loadTest1(program);
						break;
					case 2: computer.loadTest2(program);
						break;
					case 3: computer.loadTest3(program);
						break;
					case 4: computer.loadTest4(program);
						break;
					case 5: computer.loadTest5(program);
						break;
					case 6: computer.loadTest6(program);
						break;
					case 7: computer.loadTest7(program);
						break;
					case 8: computer.loadTest8(program);
						break;
					case 9: cout << "Enter name of file to load SML program from: ";
						cin >> fileName;
						inFile.open(fileName);
						if(inFile.is_open())
						{
							computer.loadProgram(inFile, program);
							inFile.close();
						}
						else
						{
							cout << "File not found" << endl;
						}
						break;
					default:
						cout << "Invalid choice" << endl;
						break;
				}
				break;
			case 5: computer.runProgram(program); //Run currently loaded program
				break;
			case 6: system("cls");
				computer.dump(program); // Prints current registers and memory to console
				break;
			case 7: // Exit
				cout << "Thank you for using simpletron for your computing needs " << endl;
				
				break;
		}
		system("pause");
	}
	return 0;
}