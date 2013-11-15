/*************************************************************************************
* Programmer: Kristin Onorati
* Class: CPTS 122, Summer 2013
* Programming Assignment: 6
* Date: July 9th, 2013
* Description: Compiles programs written in SL, translating program so SML
**************************************************************************************/

#ifndef COMPILER_H
#define COMPILER_H

#include "Simpletron.h"
#include "SimpletronSimulator.h"
#include "Stack.h"
#include "InfixToPostfix.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::getline;


class Compiler;
template <class T>
class Stack;
class PostfixEvaluator;
class InfixToPostfix;

class TableEntry
{
	friend class Compiler;
	friend class PostfixEvaluator;

	public:
		TableEntry();
		~TableEntry();
		TableEntry(const TableEntry &newEntry);
		TableEntry & operator=(TableEntry &rhs);

	private:
		int symbol;
		char type; // 'C' (constant), 'L' (line number), or 'V' (variable)
		int location; // 000 to 999
};

class Compiler
{
	friend class PostfixEvaluator;
	public:
		Compiler();
		~Compiler();
		Compiler(Compiler &rhs);

		void getNewLine(ifstream &file);
		void createEntry(char type);
		string tokLine();
		void compileFirstPass(ifstream &file, Simpletron &SML);
		void compileSecondPass(ofstream &file, Simpletron &SML);
		int findVariable(int var, char type);
		void EnterProgram(ofstream &file);
		void resetCompiler();
	
		

	private:
		int flags[1000];
		vector<TableEntry> table;
		string newLine;
		string linePiece;
		int memBegin;
		int memEnd;
		string command;
		
};



#endif