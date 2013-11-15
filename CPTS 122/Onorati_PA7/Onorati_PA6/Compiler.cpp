#include "Compiler.h"

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Table Entry constructor
* Input parameters: 
* Returns:
* Precondition: 
* Postcondition: 
*************************************************************************/
TableEntry::TableEntry()
{
	symbol = 0;
	type = '\0';
	location = -1;
}

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: TableEntry destructor
* Input parameters: 
* Returns:
* Precondition: 
* Postcondition: 
*************************************************************************/
TableEntry::~TableEntry()
{
}

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: TableEntry copy constructor (shallow)
* Input parameters: 
* Returns:
* Precondition: 
* Postcondition:
*************************************************************************/
TableEntry::TableEntry(const TableEntry &newEntry)
{
	symbol = newEntry.symbol;
	type = newEntry.type;
	location = newEntry.location;
}

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Overloads assignment operator for tableEntry
* Input parameters: 
* Returns:
* Precondition:
* Postcondition: 
*************************************************************************/
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

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Compiler constructor
* Input parameters: 
* Returns:
* Precondition: 
* Postcondition: 
*************************************************************************/
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

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Compiler destructor
* Input parameters: 
* Returns:
* Precondition: 
* Postcondition: 
*************************************************************************/
Compiler::~Compiler()
{
}

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Compiler copy constructor
* Input parameters: 
* Returns:
* Precondition: 
* Postcondition: 
*************************************************************************/
Compiler::Compiler(Compiler &rhs)
{
	for(int i = 0; i < 1000; i++)
	{
		flags[i] = rhs.flags[i];
	}
	
	table = rhs.table;

	newLine = rhs.newLine;
}


/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Gets next line from file (DOES NOT CHECK FOR END OF FILE)
* Input parameters: input file
* Returns:
* Precondition: file must be open and there must be more file to read
* Postcondition: line from file is saved as newline
*************************************************************************/
void Compiler::getNewLine(ifstream &file)
{
	getline(file, newLine);
}
/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Breaks off next piece of newLine
* Input parameters: 
* Returns: LinePiece that has been broken off front of newLine string
* Precondition: 
* Postcondition: 
*************************************************************************/
string Compiler::tokLine()
{
	int i = 0;
	for(i; i != newLine.length() && newLine.at(i) != ' '; i++);
	linePiece = newLine.substr(0, i);
	newLine.erase(0, i+1);
	return linePiece;
}

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Creates new table entry and adds it to table
* Input parameters: type of entry ('L' = line number, 'V' = variable, 'C' = constant)
* Returns:
* Precondition: 
* Postcondition: New entry is created
*************************************************************************/
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

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Runs first pass of compiler, translates each line into machine code and creates entry table
* Input parameters: input file, Simpletron program (for storing memory)
* Returns:
* Precondition: file is open, program is valid
* Postcondition: 
*************************************************************************/
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

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Runs second pass of compiler, associates previously unknown line numbers with line numbers in table 
*		and adds instruction locations. Saves machine language to specified file
* Input parameters: Output file, Simpletron program
* Returns:
* Precondition: File is open, first pass has already been completed
* Postcondition: Complete SML program is now loaded into simpletron memory
*************************************************************************/
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
/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Finds specified variable/character/line number in entry table
* Input parameters: Variable to look for, type of variable ('L', 'V', or 'C')
* Returns: location of variable in memory or -1 if variable not found
* Precondition: 
* Postcondition: 
*************************************************************************/
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

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: User enters Simple program which is saved to specified file
* Input parameters: Output file
* Returns:
* Precondition: File is open
* Postcondition: 
*************************************************************************/
void Compiler::EnterProgram(ofstream &file)
{
	string tempStr = "";
	cout << "Enter line number followed by instruction term and instructions" << endl;
	cout << "Each part should be separated by spaces" << endl;
	cout << "End each line by pressing enter" << endl;
	cout << "Enter -9999 when finished entering the program" << endl;

	while(tempStr != "-9999")
	{
		_flushall();
		getline(cin, tempStr);
		if(tempStr != "-9999")
		{
			file << tempStr << endl;
		}
	}
	
}

/*************************************************************************
* Date last modified: July 16th, 2013
* Description: Resets compiler data members to original starting values
* Input parameters: 
* Returns:
* Precondition: 
* Postcondition: 
*************************************************************************/
void Compiler::resetCompiler()
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


