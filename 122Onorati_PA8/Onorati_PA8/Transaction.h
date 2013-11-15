#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Inventory.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;

class Store;
class Transaction
{
	friend class Employee;
	public:
		Transaction();
		~Transaction();
		Transaction (Transaction &copy);

		//Member functions
		void setType();
		void sale(Store &store);
		void retrn(Store &store);
		void printReceipt();
		void saveReceipt(Store &store);
		void calculateTotal();
		void addDiscount(Store &store);
		void reduceInventory(Store &store, string item, int quantity);


	private:
		vector<InventoryItem> mItems;
		int mType;
		int mID;
		double mTotal;
		double mDiscount;
};





#endif