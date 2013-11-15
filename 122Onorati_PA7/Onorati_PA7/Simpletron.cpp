#include "stdafx.h"
#include "Simpletron.h"

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Simpletron constructor
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: New simpletron is created and all available memory is set to 0
*************************************************************************/
Simpletron::Simpletron()
{
	for(int i = 0; i < 1000; i++)
	{
		memory[i] = 00000;
	}
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Copy constructor, creates shallow copy
* Input parameters: Simpletron to copy from
* Returns: 
* Precondition: 
* Postcondition: Duplicate copy is created
*************************************************************************/
Simpletron::Simpletron(Simpletron &rhs)
{
	for(int i = 0; i < 1000; i++)
	{
		memory[i] = rhs.memory[i];
	}
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Simpletron Destructor 
* Input parameters: 
* Returns: 
* Precondition: 
* Postcondition: 
*************************************************************************/
Simpletron::~Simpletron()
{
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Loads value from specified location in memory array
* Input parameters: Location (array index) of memory to load
* Returns: Value from specified location
* Precondition: location exists
* Postcondition: Value is returned
*************************************************************************/
int Simpletron::load(int location)
{
	int num = memory[location];
	return num;
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Stores given data value to given location in memory array
* Input parameters: Location (array index), data value
* Returns: 
* Precondition: location exists
* Postcondition: memory location is updated with given value
*************************************************************************/
void Simpletron::store(int location, int data)
{
	memory[location] = data;
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Reads user input value from console and saves it to given memory location
* Input parameters: Location (array index) of memory
* Returns: 
* Precondition: location exists, user input is valid
* Postcondition: User value is saved to memory location
*************************************************************************/
void Simpletron::read(int location)
{
	_flushall();
	cout << "Enter number: ";
	cin >> memory[location];
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Writes value saved at given location to console
* Input parameters: Location (array index) of memory
* Returns: 
* Precondition: location exists
* Postcondition: Value is printed to console
*************************************************************************/
void Simpletron::write(int location)
{
	cout << "Result = " << memory[location];
}

/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Decodes word to return operation code (first 2 digits)
* Input parameters: Word to decode (5 digit integer)
* Returns: Operation code
* Precondition: 
* Postcondition: Operation code is returned
*************************************************************************/
int Simpletron::getInstruction(int data)
{
	int instruction = data/1000;
	return instruction;
}


/*************************************************************************
* Date last modified: July 9th, 2013
* Description: Decodes word to return memory location (last 3 digits)
* Input parameters: Word to decode (5 digit integer)
* Returns: Memory location
* Precondition: 
* Postcondition: Memory location is returned
*************************************************************************/
int Simpletron::getLocation(int data)
{
	int location = data % 1000;
	return location;
}

string Simpletron::getDialogue(void)
{
	return dialogue;
}

void Simpletron::setDialogue(string newDialogue)
{
	dialogue = newDialogue;
}

int Simpletron::getTempNum(void)
{
	return tempNum;
}

void Simpletron::setTempNum(int newNum)
{
	tempNum = newNum;
}

