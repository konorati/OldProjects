#ifndef SIMPLETRON_H
#define SIMPLETRON_H
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

class SimpletronSimulator;
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

	public:
		Simpletron();
		Simpletron(Simpletron &rhs);
		~Simpletron();

		void read(int location);
		void write(int location);
		int getInstruction(int location);
		int getLocation(int data);
		void store(int location, int data);
		
	
	private:
		int memory[1000];
		int load(int location);
		



};


#endif