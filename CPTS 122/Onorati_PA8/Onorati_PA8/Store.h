#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Inventory.h"
#include "Employee.h"
#include "Manager.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;

class Store
{
	public:
		Store(string storeName = "");
		~Store();
		Store(Store &copy);
		
		//Getters & setters
		vector<InventoryItem> getInventory() const;
		string getStoreName() const;
		double getBulkDiscount() const;
		double getFacultyDiscount() const;
		double getStaffDiscount() const;
		double getStudentDiscount() const;
		ofstream getReceipts() const;
		int getTransactionID() const;

		void setStoreName(string newName);
		void setBulkDiscount(double newDiscount);
		void setFacultyDiscount(double newDiscount);
		void setStaffDiscount(double newDiscount);
		void setStudentDiscount(double newDiscount);
		void increaseTransactionID();

		//Member Functions
		void loadInventory();
		void saveInventory();
		void printInventory();
		void printInventory(string name, string type);
		InventoryItem * findInventoryItem(string name);
		void updateInventory();

		ofstream mReceipts;
		fstream mInventoryFile;
		vector<InventoryItem> inventory; //List of all inventory

	private:
		
		string mStoreName;
		double mBulkDiscount;
		double mFacultyDiscount;
		double mStaffDiscount;
		double mStudentDiscount;
		int transactionID;
};


#endif