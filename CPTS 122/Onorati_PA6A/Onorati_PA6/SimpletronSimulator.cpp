#include "SimpletronSimulator.h"


/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Constructor (overloads default)
* Input parameters: accumulator, instruction counter, instruction register, operation code, operand
* Returns: 
* Precondition: 
* Postcondition: New simpletronSimulator is created and data members are initialized
*************************************************************************/
SimpletronSimulator::SimpletronSimulator(int accum, int counter, int instructReg, int code, int oper)
{
	accumulator = accum;
	instructionCounter = counter;
	instructionRegister = instructReg;
	operationCode = code;
	operand = oper;
	program = new Simpletron();
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Destructor
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: 
*************************************************************************/
SimpletronSimulator::~SimpletronSimulator()
{
	delete program;
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Copy constructor (shallow)
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: 
*************************************************************************/
SimpletronSimulator::SimpletronSimulator(SimpletronSimulator &rhs)
{
	if(this != &rhs)
	{
		accumulator = rhs.accumulator;
		instructionCounter = rhs.instructionCounter;
		instructionRegister = rhs.instructionRegister;
		operationCode = rhs.operationCode;
		operand = rhs.operand;
		program = rhs.program;
	}
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Resets program data values and memory to 0
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: All data members and memory are reset to 0
*************************************************************************/
void SimpletronSimulator::resetComputer(void)
{
	accumulator = 0;
	instructionCounter = 000;
	instructionRegister = 00000;
	operationCode = 00;
	operand = 000;
	for(int i = 0; i < 1000; i++)
	{
		program->memory[i] = 00000;
	}
}

//Getters & setters
/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Retrieves or updates private data members
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: 
*************************************************************************/
int SimpletronSimulator::getAccumulator(void) const
{
	return accumulator;
}

int SimpletronSimulator::getInstructionCounter(void) const
{
	return instructionCounter;
}

int SimpletronSimulator::getInstructionRegister(void) const
{
	return instructionRegister;
}

int SimpletronSimulator::getOperationCode(void) const
{
	return operationCode;
}

int SimpletronSimulator::getOperand(void) const
{
	return operand;
}

void SimpletronSimulator::setAccumulator(int newAccumulator)
{
	accumulator = newAccumulator;
}

void SimpletronSimulator::setInstructionCounter(int newCounter)
{
	instructionCounter = newCounter;
}

void SimpletronSimulator::setInstructionRegister(int newRegister)
{
	instructionRegister = newRegister;
}

void SimpletronSimulator::setOperationCode(int newCode)
{
	operationCode = newCode;
}

void SimpletronSimulator::setOperand(int newOperand)
{
	operand = newOperand;
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Gets user input for SML program 
* Input parameters: 
* Returns:
* Precondition: User inputs a valid program
* Postcondition: Memory is updated with users program
*************************************************************************/
void SimpletronSimulator::getProgram()
{
	int instruction = 00000, counter = 000;

	cout << "*** Welcome to Simpletron ***" << endl;
	cout << "*** Please enter your program one instruction at a time ***" << endl;
	cout << "*** I will type the location number followed by a question mark ***" << endl;
	cout << "*** Then type the word for that memory location ***" << endl;
	cout << "*** Type -99999 to stop entering your program ***" << endl;

	while(instruction != -99999)
	{
		_flushall();
		cout << counter<< " ? ";
		cin >> instruction;
		if(instruction != -99999)
		{
			program->memory[counter] = instruction;
		}
		counter++;
	}
	cout << "*** Program loading completed ***" << endl;
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Runs program that has already been loaded into memory
* Input parameters: 
* Returns: 
* Precondition: Valid program exists in memory
* Postcondition: Valid result is printed to console
*************************************************************************/
void SimpletronSimulator::runProgram()
{
	setAccumulator(0);
	setInstructionCounter(0);
	instructionRegister = program->memory[instructionCounter];
	operationCode = program->getInstruction(instructionRegister);
	while(instructionCounter != -9999 && operationCode != 43)
	{
		operand = program->getLocation(instructionRegister);
		switch(operationCode)
		{
			case 10: // Read word from terminal into memory location
				program->read(operand);
				break;
			case 11: // Write a word from memory location to console
				program->write(operand);
				cout << endl;
				break;
			case 20: // Load a word from memory location into accumulator
				accumulator = program->load(operand);
				break;
			case 21: //Store a word from accumulator into memory location
				program->store(operand, accumulator);
				break;
			case 30: // Add a word from memory location to word in accumulator
				accumulator += program->memory[operand];
				break;
			case 31: // Subtract a word from memory location from word in accumulator
				accumulator -= program->memory[operand];
				break;
			case 32: // Divide a word from memory location into word in accumulator
				if(program->memory[operand] != 0)
				{
					accumulator /= program->memory[operand];
				}
				else
				{
					cout << "***Fatal Error: Attempt to divide by zero***" << endl;
					cout << "***Simpletron execution abnormally terminated***" << endl;
					instructionCounter = -9999;
				}
				break;
			case 33: // Multiply word from memory location with word in accumulator
				accumulator *= program->memory[operand];
				break;
			case 34: // Mod word from memory location into word in accumulator
				accumulator %= program->memory[operand];
				break;
			case 35: // Calculate accumulator to the power of word in memory location
				accumulator = (int)pow(accumulator, program->memory[operand]);
				break;
			case 40: // Branch to a specific location in memory
				instructionCounter = operand-1;
				break;
			case 41: // If accumulator is negative branch to memory location
				if(accumulator < 0)
				{
					instructionCounter = operand-1;
				}
				break;
			case 42: // If accumulator is zero branch to memory location
				if(accumulator == 0)
				{
					instructionCounter = operand-1;
				}
				break;
		}
		if(instructionCounter != -9999)
		{
			instructionCounter++;
			instructionRegister = program->memory[instructionCounter];
			operationCode = program->getInstruction(instructionRegister);
		}
	}
	if(instructionCounter != -9999)
	{
		cout << "***Simpletron Execution Terminated***" << endl;
	}
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Displays current contents of memory (first 100 slots) and registers to console
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Memory & register contents are printed to console
*************************************************************************/
void SimpletronSimulator::dump()
{
	cout << "REGISTERS:" << endl;
	cout << left << setw(25) << setfill(' ') << "Accumulator:" << accumulator << endl;
	cout << left << setw(25) << "Instruction Counter:" << instructionCounter << endl;
	cout << left << setw(25) << "Instruction Register:" << setw(5) << setfill('0') << instructionRegister << endl;
	cout << left << setw(25) << setfill(' ') << "Operation Code:";
	cout << right << setw(2) << setfill('0') << operationCode << endl;
	cout << left << setw(25) << setfill(' ') << "Operand:";
	cout << right << setw(2) << setfill('0') << operand << endl;

	cout << "MEMORY (first 100 slots):" << endl;

	for(int i = 0; i < 10; i++)
	{
		cout << "     " << setw(2) << setfill(' ') << i;
	}
	cout << endl;
	for(int j = 0; j < 10; j++)
	{
		cout << setw(2) << j*10 << "  ";
		for(int k = 0; k < 10; k++)
		{
			cout << setw(5) << setfill('0') << program->memory[(j*10) + k] << "  ";
		}
		cout << endl;
	}
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Set of functions to test functionality of all available operation codes
*		Should be used in conjunction with dump function to view store/read functionality.
*		Predetermined SML code is loaded into memory and printed to the console for user to view
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: Valid SML code is loaded into memory and displayed to console
*************************************************************************/
void SimpletronSimulator::loadTest1() //Compute sum of 2 numbers
{
	cout << "*** Simpletron Program Instructions ***" << endl;
	cout << " 00 ? +10007" << endl;
	program->store(0, 10007);
	cout << " 01 ? +10008" << endl;
	program->store(1, 10008);
	cout << " 02 ? +20007" << endl;
	program->store(2, 20007);
	cout << " 03 ? +30008" << endl;
	program->store(3, 30008);
	cout << " 04 ? +21009" << endl;
	program->store(4, 21009);
	cout << " 05 ? +11009" << endl;
	program->store(5, 11009);
	cout << " 06 ? +43000" << endl;
	program->store(6, 43000);
	cout << " 07 ? +00000" << endl;
	program->store(7, 00000);
	cout << " 08 ? +00000" << endl;
	program->store(8, 00000);
	cout << " 09 ? +00000" << endl;
	program->store(9, 00000);
	
}
void SimpletronSimulator::loadTest2() //Compute subtraction of 2 numbers
{
	cout << "*** Simpletron Program Instructions ***" << endl;
	cout << " 00 ? +10007" << endl;
	program->store(0, 10007);
	cout << " 01 ? +10008" << endl;
	program->store(1, 10008);
	cout << " 02 ? +20007" << endl;
	program->store(2, 20007);
	cout << " 03 ? +31008" << endl;
	program->store(3, 31008);
	cout << " 04 ? +21009" << endl;
	program->store(4, 21009);
	cout << " 05 ? +11009" << endl;
	program->store(5, 11009);
	cout << " 06 ? +43000" << endl;
	program->store(6, 43000);
	cout << " 07 ? +00000" << endl;
	program->store(7, 00000);
	cout << " 08 ? +00000" << endl;
	program->store(8, 00000);
	cout << " 09 ? +00000" << endl;
	program->store(9, 00000);
	
}
void SimpletronSimulator::loadTest3() //Compute multiplication of 2 numbers
{
	cout << "*** Simpletron Program Instructions ***" << endl;
	cout << " 00 ? +10007" << endl;
	program->store(0, 10007);
	cout << " 01 ? +10008" << endl;
	program->store(1, 10008);
	cout << " 02 ? +20007" << endl;
	program->store(2, 20007);
	cout << " 03 ? +33008" << endl;
	program->store(3, 33008);
	cout << " 04 ? +21009" << endl;
	program->store(4, 21009);
	cout << " 05 ? +11009" << endl;
	program->store(5, 11009);
	cout << " 06 ? +43000" << endl;
	program->store(6, 43000);
	cout << " 07 ? +00000" << endl;
	program->store(7, 00000);
	cout << " 08 ? +00000" << endl;
	program->store(8, 00000);
	cout << " 09 ? +00000" << endl;
	program->store(9, 00000);

}
void SimpletronSimulator::loadTest4() //Compute division of 2 numbers
{
	cout << "*** Simpletron Program Instructions ***" << endl;
	cout << " 00 ? +10007" << endl;
	program->store(0, 10007);
	cout << " 01 ? +10008" << endl;
	program->store(1, 10008);
	cout << " 02 ? +20007" << endl;
	program->store(2, 20007);
	cout << " 03 ? +32008" << endl;
	program->store(3, 32008);
	cout << " 04 ? +21009" << endl;
	program->store(4, 21009);
	cout << " 05 ? +11009" << endl;
	program->store(5, 11009);
	cout << " 06 ? +43000" << endl;
	program->store(6, 43000);
	cout << " 07 ? +00000" << endl;
	program->store(7, 00000);
	cout << " 08 ? +00000" << endl;
	program->store(8, 00000);
	cout << " 09 ? +00000" << endl;
	program->store(9, 00000);
	
}
void SimpletronSimulator::loadTest5() //Compute remainder of 2 numbers
{
	cout << "*** Simpletron Program Instructions ***" << endl;
	cout << " 00 ? +10007" << endl;
	program->store(0, 10007);
	cout << " 01 ? +10008" << endl;
	program->store(1, 10008);
	cout << " 02 ? +20007" << endl;
	program->store(2, 20007);
	cout << " 03 ? +34008" << endl;
	program->store(3, 34008);
	cout << " 04 ? +21009" << endl;
	program->store(4, 21009);
	cout << " 05 ? +11009" << endl;
	program->store(5, 11009);
	cout << " 06 ? +43000" << endl;
	program->store(6, 43000);
	cout << " 07 ? +00000" << endl;
	program->store(7, 00000);
	cout << " 08 ? +00000" << endl;
	program->store(8, 0000);
	cout << " 09 ? +00000" << endl;
	program->store(9, 00000);
	
}
void SimpletronSimulator::loadTest6() //Compute exponentiation of one number to another numbers power
{
	cout << "*** Simpletron Program Instructions ***" << endl;
	cout << " 00 ? +10007" << endl;
	program->store(0, 10007);
	cout << " 01 ? +10008" << endl;
	program->store(1, 10008);
	cout << " 02 ? +20007" << endl;
	program->store(2, 20007);
	cout << " 03 ? +35008" << endl;
	program->store(3, 35008);
	cout << " 04 ? +21009" << endl;
	program->store(4, 21009);
	cout << " 05 ? +11009" << endl;
	program->store(5, 11009);
	cout << " 06 ? +43000" << endl;
	program->store(6, 43000);
	cout << " 07 ? +00000" << endl;
	program->store(7, 00000);
	cout << " 08 ? +00000" << endl;
	program->store(8, 00000);
	cout << " 09 ? +00000" << endl;
	program->store(9, 00000);
	
}
void SimpletronSimulator::loadTest7() //Determines which of two numbers is largest
{
	cout << "*** Simpletron Program Instructions ***" << endl;
	cout << " 00 ? +10009" << endl;
	program->store(0, 10009);
	cout << " 01 ? +10010" << endl;
	program->store(1, 10010);
	cout << " 02 ? +20009" << endl;
	program->store(2, 20009);
	cout << " 03 ? +31010" << endl;
	program->store(3, 31010);
	cout << " 04 ? +41007" << endl;
	program->store(4, 41007);
	cout << " 05 ? +11009" << endl;
	program->store(5, 11009);
	cout << " 06 ? +43000" << endl;
	program->store(6, 43000);
	cout << " 07 ? +11010" << endl;
	program->store(7, 11010);
	cout << " 08 ? +43000" << endl;
	program->store(8, 43000);
	cout << "09 ? +00000" << endl;
	program->store(9, 00000);
	cout << " 10 ? +00000" << endl;
	program->store(9, 00000);
	
}
void SimpletronSimulator::loadTest8() //Determines if there is a remainder between two numbers (Test branch if 0)
{
	cout << "*** Simpletron Program Instructions ***" << endl;
	cout << " 00 ? +10009" << endl;
	program->store(0, 10009);
	cout << " 01 ? +10010" << endl;
	program->store(1, 10010);
	cout << " 02 ? +20009" << endl;
	program->store(2, 20009);
	cout << " 03 ? +34010" << endl;
	program->store(3, 34010);
	cout << " 04 ? +42007" << endl;
	program->store(4, 42007);
	cout << " 05 ? +11012" << endl;
	program->store(5, 11012);
	cout << " 06 ? +43000" << endl;
	program->store(6, 43000);
	cout << " 07 ? +11011" << endl;
	program->store(7, 11011);
	cout << " 08 ? +43000" << endl;
	program->store(8, 43000);
	cout << " 09 ? +00000" << endl;
	program->store(9, 00000);
	cout << " 10 ? +00000" << endl;
	program->store(10, 0000);
	cout << " 11 ? +00000" << endl;
	program->store(11, 00000);
	cout << " 12 ? +00001" << endl;
	program->store(12, 00001);

	cout << "Note: Program returns 1 if there is a remainder and 0 if no remainder" << endl;
}
