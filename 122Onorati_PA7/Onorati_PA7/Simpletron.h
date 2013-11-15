#ifndef SIMPLETRON_H
#define SIMPLETRON_H
#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class SimpletronSimulator;
class Compiler;
class PostfixEvaluator;
/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 6
* Date: July 9th, 2013
* Description: Simple computer class which holds machine language code memory
**************************************************************************************/

class Simpletron
{
	friend class SimpletronSimulator;
	friend class Compiler;
	friend class PostfixEvaluator;

	public:
		Simpletron();
		Simpletron(Simpletron &rhs);
		~Simpletron();

		void read(int location);
		void write(int location);
		int getInstruction(int location);
		int getLocation(int data);
		void store(int location, int data);
		string getDialogue(void);
		void setDialogue(string newDialogue);
		int getTempNum(void);
		void setTempNum(int newNum);
		
	
	private:
		int memory[1000];
		int load(int location);
		string dialogue;
		int tempNum;
		



};


#endif