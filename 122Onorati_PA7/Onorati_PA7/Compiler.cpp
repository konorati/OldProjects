#include "stdafx.h"
#include "Compiler.h"

TableEntry::TableEntry()
{
	symbol = 0;
	type = '\0';
	location = -1;
}

TableEntry::~TableEntry()
{
}

TableEntry::TableEntry(const TableEntry &newEntry)
{
	symbol = newEntry.symbol;
	type = newEntry.type;
	location = newEntry.location;
}

TableEntry & TableEntry::operator=(TableEntry &rhs)
{
	if(this != &rhs)
	{
		symbol = rhs.symbol;
		type = rhs.type;
		location = rhs.location;
	}
	return *this;
}

Compiler::Compiler()
{
	for(int i = 0; i < 1000; i++)
	{
		flags[i] = -1;
	}
	newLine = "";
	linePiece = "";
	memBegin = 000;
	memEnd = 999;
}

Compiler::~Compiler()
{
}

Compiler::Compiler(Compiler &rhs)
{
	for(int i = 0; i < 1000; i++)
	{
		flags[i] = rhs.flags[i];
	}
	
	table = rhs.table;

	newLine = rhs.newLine;
}

//Does not check for end of file
void Compiler::getNewLine(ifstream &file)
{
	getline(file, newLine);
}
string Compiler::tokLine()
{
	int i = 0;
	for(i; i != newLine.length() && newLine.at(i) != ' '; i++);
	linePiece = newLine.substr(0, i);
	newLine.erase(0, i+1);
	return linePiece;
}

void Compiler::createEntry(char type)
{
	
	TableEntry *newEntry = new TableEntry();
	(*newEntry).type = type;

	// If it is a line number
	if(type == 'L')
	{
		(*newEntry).symbol = atoi(linePiece.c_str());
		(*newEntry).location = memBegin;
	}
	// if it is a constant or variable
	else
	{
		(*newEntry).location = memEnd--;
		if(isalpha(linePiece[0]))
		{
			(*newEntry).symbol = (int)linePiece.c_str()[0];
		}
		else
		{
			(*newEntry).symbol = atoi(linePiece.c_str());
		}
	}
	// Add entry to entry table
	table.push_back(*newEntry);
}


void Compiler::compileFirstPass(ifstream &file, Simpletron &SML)
{
	int tempLocation = -1;
	string cmpOp, strVar1, strVar2;
	int tempVar1 = 0, tempVar2 = 0;
	bool isConstant = false;
	//FIRST PASS

	// While not end of file read in line from file
	while(file.good())
	{
		//Read line
		getNewLine(file);

		//Token out line number & create table entry
		linePiece = tokLine();
		createEntry('L');

		//Get command & determine next step
		command = tokLine();

		if(command == "rem")
		{
			newLine.clear();
		}
		else if(command == "input") // Prompt user for integer and store integer into x
		{
				
			linePiece = tokLine();
			tempLocation = findVariable((int)linePiece.c_str()[0], 'V');
			if(tempLocation == -1)
			{
				createEntry('V');
				SML.store(memBegin, ((10000) + table.back().location));
			}
			else
			{
				SML.store(memBegin, (10000 + tempLocation));
			}
			memBegin++;			
		}
		else if(command == "goto")
		{
			linePiece = tokLine();
			tempLocation = findVariable(atoi(linePiece.c_str()), 'L');
			if(tempLocation != -1)
			{
				SML.store(memBegin, 40000 + tempLocation);
			}
			else
			{
				SML.store(memBegin, 40000);
				flags[memBegin] = atoi(linePiece.c_str());
			}
			memBegin++;
		}
		else if (command == "print")
		{
			linePiece = tokLine();
			tempLocation = findVariable((int)linePiece.c_str()[0], 'V');
			SML.store(memBegin, 11000 + tempLocation);
			memBegin++;
		}
		else if(command == "end")
		{
			SML.store(memBegin, 43000);
		}
		else if(command == "if")
		{
			//Find first variable
			strVar1 = tokLine();
			tempVar1 = (int)linePiece.c_str()[0];
			cmpOp = tokLine(); // Hold comparison operator
			strVar2 = tokLine(); //Get second variable
			if(isdigit(linePiece.c_str()[0]))
			{
				tempVar2 = atoi(linePiece.c_str());
				isConstant = true;
			}
			else
			{
				tempVar2 = (int)linePiece.c_str()[0];
				isConstant = false;
			}
			if(cmpOp == ">" || cmpOp == ">=")
			{
				if(!isConstant)
				{
					tempLocation = findVariable(tempVar2, 'V');
					if(tempLocation == -1)
					{
						linePiece = strVar2;
						createEntry('V');
						tempLocation = findVariable(tempVar2, 'V');
					}
				}
				else
				{
					tempLocation = findVariable(tempVar2, 'C');
					if(tempLocation == -1) // If still not found add constant to table
					{
						linePiece = strVar2;
						createEntry('C');
						tempLocation = findVariable(tempVar2, 'C');
						SML.memory[tempLocation] = atoi(strVar2.c_str());
					}
				}
				SML.store(memBegin, 20000 + tempLocation); // Load second variable into accumulator
				tempLocation = findVariable(tempVar1, 'V');
				if(tempLocation == -1)
				{
					linePiece = strVar1;
					createEntry('V');
					tempLocation = findVariable(tempVar2, 'V');
				}
				SML.store(memBegin, 31000 + tempLocation); // Subtract first variable from accumulator
			}
			else
			{
				tempLocation = findVariable(tempVar1, 'V');
				if(tempLocation == -1)
				{
					linePiece = strVar1;
					createEntry('V');
					tempLocation = findVariable(tempVar1, 'V');
				}
				SML.store(memBegin, 20000 + tempLocation); // Load first variable into accumulator
				memBegin++;
				if(!isConstant)
				{
					tempLocation = findVariable(tempVar2, 'V');
					if(tempLocation == -1)
					{
						linePiece = strVar2;
						createEntry('V');
						tempLocation = findVariable(tempVar2, 'V');
					}
				}
				else
				{
					tempLocation = findVariable(tempVar2, 'C');
					if(tempLocation == -1) // If still not found add constant to table
					{
						linePiece = strVar2;
						createEntry('C');
						tempLocation = findVariable(tempVar2, 'C');
						SML.memory[tempLocation] = atoi(strVar2.c_str());
					}
				}
				SML.store(memBegin, 31000 + tempLocation); // Subtract second variable from accumulator
				memBegin++;
			}

			tokLine(); // Remove goto statement
			linePiece = tokLine(); //Get location to goto
			tempLocation = findVariable(atoi(linePiece.c_str()), 'L'); //Determine if line number exists in table yet
			if(cmpOp == "==")
			{
				if(tempLocation == -1)
				{
					SML.store(memBegin, 42000);
					flags[memBegin] = atoi(linePiece.c_str());
				}
				else
				{
					SML.store(memBegin, 42000 + tempLocation);
				}
			}
			else if(cmpOp == "!=")
			{
				SML.store(memBegin, 42000 + memBegin + 2);
				memBegin++;
				if(tempLocation == -1)
				{
					SML.store(memBegin, 42000);
				}
				else
				{
					SML.store(memBegin, 40000 + tempLocation);
				}
			}
			else if(cmpOp == "<=" || cmpOp == ">=")
			{
				if(tempLocation == -1)
				{
					SML.store(memBegin, 41000);
					flags[memBegin] = atoi(linePiece.c_str());
					memBegin++;
					SML.store(memBegin, 42000);
					flags[memBegin] = atoi(linePiece.c_str());
				}
				else
				{
					SML.store(memBegin, 41000 + tempLocation);
					memBegin++;
					SML.store(memBegin, 42000 + tempLocation);
				}
			}
			else if(cmpOp == "<" || cmpOp == ">")
			{
				if(tempLocation == -1)
				{
					SML.store(memBegin, 42000);
					flags[memBegin] = atoi(linePiece.c_str());
				}
				else
				{
					SML.store(memBegin, 42000 + tempLocation);
				}
			}
			memBegin++;
		}
		else if(command == "let")
		{
			//Save variable result will be stored to
			strVar1 = tokLine();

			//Discard assignment operator
			tokLine();

			//Convert expression from infix to postfix
			InfixToPostfix *converter = new InfixToPostfix();
			(*converter).infixExpression = newLine;
					
			Stack<char> *stack1 = new Stack<char>();
			(*converter).convertToPostfix(*stack1);
			delete stack1;

			//Evaluate postfix expression
			PostfixEvaluator *evaluator = new PostfixEvaluator();
			(*evaluator).setExpression((*converter).postfixExpression);
			Stack<int> *stack2 = new Stack<int>();
			tempLocation = (*evaluator).evaluateExpression(*stack2, *this, SML);
			delete stack2;
			delete converter;
			delete evaluator;

			//Store result to variable
			SML.store(memBegin, 20000 + tempLocation);
			memBegin++;
				
			tempLocation = findVariable((int)strVar1.c_str()[0], 'V');
			if(tempLocation == -1)
			{
				linePiece = strVar1;
				createEntry('V');
				tempLocation = findVariable((int)linePiece.c_str()[0], 'V');
			}
			SML.store(memBegin, 21000 + tempLocation);
			memBegin++;
		}	
	}
}

void Compiler::compileSecondPass(ofstream & file, Simpletron &SML)
{
	//Search through flags array
	for(int i = 0; i < 999; i++)
	{
		if(flags[i] != -1)
		{
			SML.memory[i] += findVariable(flags[i], 'L');
		}
	}

	//Save SML to file
	for(int i = 0; i < 1000; i++)
	{
		file << SML.memory[i] << endl;
	}
}

//Returns location of variable in memory
int Compiler::findVariable(int var, char type)
{
	int tempLocation = -1;
	vector<TableEntry>::iterator iter = table.begin();
	for(iter; iter != table.end(); iter++)
	{
		if((*iter).symbol == var && (*iter).type == type)
		{
			 tempLocation = (*iter).location;
		}
	}
	return tempLocation;
}


