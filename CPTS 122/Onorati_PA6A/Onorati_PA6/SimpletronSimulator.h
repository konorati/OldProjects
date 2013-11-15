/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 6
* Date: July 9th, 2013
* Description: Executes programs written in SML and contains predetermined SML test code
**************************************************************************************/

#ifndef SIMPLETRON_SIMULATOR_H
#define SIMPLETRON_SIMULATOR_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Simpletron.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setfill;
using std::left;
using std::right;
using std::setprecision;

class SimpletronSimulator
{
	

	public:
		SimpletronSimulator(int accum = 0, int counter = 0, int instructReg = 0, int code = 0, int operand = 0);
		~SimpletronSimulator();
		SimpletronSimulator(SimpletronSimulator &rhs);

		//Getters & setters
		int getAccumulator(void) const;
		int getInstructionCounter(void) const;
		int getInstructionRegister(void) const;
		int getOperationCode(void) const;
		int getOperand(void) const;
		void setAccumulator(int newAccumulator);
		void setInstructionCounter(int newCounter);
		void setInstructionRegister(int newRegister);
		void setOperationCode(int newCode);
		void setOperand(int newOperand);
		void resetComputer();

		//Member functions
		void getProgram();
		void runProgram();
		void dump();
		void loadTest1(); //Compute sum of 2 numbers
		void loadTest7(); //Determine which of 2 numbers is largest (test break if negative)
		void loadTest2(); //Compute subtraction of 2 numbers
		void loadTest3(); //Compute multiplication of 2 numbers
		void loadTest4(); //Compute division of 2 numbers
		void loadTest5(); //Compute remainder of 2 numbers
		void loadTest6(); //Compute exponentiation of one number to another numbers power
		void loadTest8(); //Determines if there is a remainder between two numbers (Test branch if 0);
		




	private:
		int accumulator;
		int instructionCounter;
		int instructionRegister;
		int operationCode;
		int operand;
		Simpletron *program;
};




#endif