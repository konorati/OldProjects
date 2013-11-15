#ifndef LIFE_H
#define LIFE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Life
{
	private:
	protected:
		double size;
		double rate;

	public:
		Life(double tSize = 0, double tRate = 0);
		~Life();

		double getSize() const;
		double getRate() const;
		void setSize(double newSize);
		void setRate(double newRate);
		void alterSize(double amount);

		void simulateWeek();
		void death();
		bool isAlive() const;
};


#endif