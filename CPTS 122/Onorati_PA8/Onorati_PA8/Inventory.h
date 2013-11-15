#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class InventoryItem
{
	public:
		InventoryItem();
		~InventoryItem();
		//InventoryItem(InventoryItem &copy);
		InventoryItem & operator=(InventoryItem &rhs);

		//Getters & setters
		string getTitle() const;
		string getDescription() const;
		string getCategory() const;
		string getSubcategory() const;
		int getQuantity() const;
		double getPrice() const;
		int getID() const;

		void setTitle(string newTitle);
		void setDescription(string newDescription);
		void setCategory(string newCategory);
		void setSubcategory(string newSub);
		void setQuantity(int newQuantity);
		void setPrice(double newPrice);
		void setId(int newID);

	private:
		string mTitle;
		string mDescription;
		string mCategory;
		string mSubcategory;
		int mQuantity;
		double mPricePerUnit;
		int mProductID;
};

#endif