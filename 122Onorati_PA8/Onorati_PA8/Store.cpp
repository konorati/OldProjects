#include "Store.h"

Store::Store(string storeName)
{
	mStoreName = storeName;
	mBulkDiscount = 0.0;
	mFacultyDiscount = 0.0;
	mStaffDiscount = 0.0;
	mStudentDiscount = 0.0;
	transactionID = 100000;
	loadInventory();
}
		
Store::~Store()
{
}

Store::Store(Store &copy)
{
	inventory = copy.inventory;
	mStoreName = copy.mStoreName;
	mBulkDiscount = copy.mBulkDiscount;
	mFacultyDiscount = copy.mFacultyDiscount;
	mStaffDiscount = copy.mStaffDiscount;
	mStudentDiscount = copy.mStudentDiscount;
}
		
//Getters & setters
vector<InventoryItem> Store::getInventory() const
{
	return inventory;
}

string Store::getStoreName() const
{
	return mStoreName;
}
		
double Store::getBulkDiscount() const
{
	return mBulkDiscount;
}

double Store::getFacultyDiscount() const
{
	return mFacultyDiscount;
}

double Store::getStaffDiscount() const
{
	return mStaffDiscount;
}

double Store::getStudentDiscount() const
{
	return mStudentDiscount;
}

int Store::getTransactionID() const
{
	return transactionID;
}

void Store::setStoreName(string newName)
{
	mStoreName = newName;
}

void Store::setBulkDiscount(double newDiscount)
{
	mBulkDiscount = newDiscount;
}

void Store::setFacultyDiscount(double newDiscount)
{
	mFacultyDiscount = newDiscount;
}

void Store::setStaffDiscount(double newDiscount)
{
	mStaffDiscount = newDiscount;
}

void Store::setStudentDiscount(double newDiscount)
{
	mStudentDiscount = newDiscount;
}

void Store::increaseTransactionID()
{
	transactionID++;
}

//Member functions
void Store::loadInventory()
{
	mInventoryFile.open("InventoryList.txt", ios::in);
	string tempStr;

	while(mInventoryFile.good())
	{
		InventoryItem newItem;
		getline(mInventoryFile, tempStr);
		newItem.setTitle(tempStr);
		getline(mInventoryFile, tempStr);
		newItem.setCategory(tempStr);
		getline(mInventoryFile, tempStr);
		newItem.setSubcategory(tempStr);
		getline(mInventoryFile, tempStr);
		newItem.setDescription(tempStr);
		getline(mInventoryFile, tempStr);
		newItem.setQuantity(atoi(tempStr.c_str()));
		getline(mInventoryFile, tempStr);
		newItem.setPrice(atof(tempStr.c_str()));
		getline(mInventoryFile, tempStr);
		newItem.setId(atoi(tempStr.c_str()));
		if(mInventoryFile.good())
		{
			getline(mInventoryFile, tempStr); //Gets blank line
		}
		inventory.push_back(newItem);
	}
	mInventoryFile.close();
}

void Store::saveInventory()
{
	mInventoryFile.open("InventoryList.txt", ios::out);
	vector<InventoryItem>::iterator iter = inventory.begin();
	for(iter; iter != inventory.end(); iter++)
	{
		mInventoryFile << (*iter).getTitle() << endl;
		mInventoryFile << (*iter).getCategory() << endl;
		mInventoryFile << (*iter).getSubcategory() << endl;
		mInventoryFile << (*iter).getDescription() << endl;
		mInventoryFile << (*iter).getQuantity() << endl;
		mInventoryFile << (*iter).getPrice() << endl;
		mInventoryFile << (*iter).getID() << endl;
		mInventoryFile << endl;
	}
	mInventoryFile.close();
}

//Prints all available inventory
void Store::printInventory()
{
	system("cls");
	cout << "*** Current Available Inventory ***" << endl;
	vector<InventoryItem>::iterator iter = inventory.begin();
	for(iter; iter != inventory.end(); iter++)
	{
		if((*iter).getQuantity() != 0)
		{
			cout << (*iter).getTitle() << endl;
			cout << (*iter).getCategory() << endl;
			cout << (*iter).getSubcategory() << endl;
			cout << (*iter).getDescription() << endl;
			cout << (*iter).getQuantity() << endl;
			cout << (*iter).getPrice() << endl;
			cout << (*iter).getID() << endl;
			cout << endl;
		}
	}
}
void Store::printInventory(string name, string type)
{
	system("cls");
	cout << "*** Current Available Inventory ***" << endl;
	vector<InventoryItem>::iterator iter = inventory.begin();
	for(iter; iter != inventory.end(); iter++)
	{
		if(((type == "name") && iter->getTitle() == name) || (type == "category" && iter->getCategory() == name) || (type == "subcategory" && iter->getSubcategory() == name))
		{
			cout << (*iter).getTitle() << endl;
			cout << (*iter).getCategory() << endl;
			cout << (*iter).getSubcategory() << endl;
			cout << (*iter).getDescription() << endl;
			cout << (*iter).getQuantity() << endl;
			cout << (*iter).getPrice() << endl;
			cout << (*iter).getID() << endl;
			cout << endl;
		}
	}
}

InventoryItem* Store::findInventoryItem(string name)
{
	InventoryItem *pItem = NULL;
	vector<InventoryItem>::iterator iter = inventory.begin();
	for(iter; iter != inventory.end(); iter++)
	{
		if(iter->getTitle() == name)
		{
			pItem = new InventoryItem;
			pItem->setTitle(iter->getTitle());
			pItem->setCategory(iter->getCategory());
			pItem->setSubcategory(iter->getSubcategory());
			pItem->setDescription(iter->getDescription());
			pItem->setId(iter->getID());
			pItem->setPrice(iter->getPrice());
			pItem->setQuantity(iter->getQuantity());
		}
	}
	return pItem;
}

void Store::updateInventory()
{
	string str;

	system("cls");
	_flushall();
	cout << "Enter name of inventory item to update: ";
	getline(cin, str);

	InventoryItem *pItem = NULL;

	vector<InventoryItem>::iterator iter = inventory.begin();
	for(iter; iter != inventory.end(); iter++)
	{
		if(iter->getTitle() == str)
		{
			pItem = &(*iter);
		}
	}
	if(pItem == NULL)
	{
		cout << "Item not found" << endl;
	}
	else
	{
		int choice = 0;
		do
		{
			_flushall();
			system("cls");
			cout << pItem->getTitle() << endl;
			cout << pItem->getCategory() << endl;
			cout << pItem->getSubcategory() << endl;
			cout << pItem->getDescription() << endl;
			cout << pItem->getQuantity() << endl;
			cout << pItem->getPrice() << endl;
			cout << pItem->getID() << endl;
			cout << endl;
		
			cout << "*** Inventory Update Options ***" << endl;
			cout << "1. Update title" << endl;
			cout << "2. Update category" << endl;
			cout << "3. Update subcategory" << endl;
			cout << "4. Update description" << endl;
			cout << "5. Update quantity" << endl;
			cout << "6. Update price" << endl;
			cout << "7. Update ID" << endl;
			cout << "8. Done editing inventory" << endl;
			cin >> choice;

			_flushall();

			switch(choice)
			{
				case 1: cout << "Enter new title: ";
					getline(cin, str);
					pItem->setTitle(str);
					break;
				case 2: cout << "Enter new category: ";
					getline(cin, str);
					pItem->setCategory(str);
					break;
				case 3: cout << "Enter new subcategory: ";
					getline(cin, str);
					pItem->setSubcategory(str);
					break;
				case 4: cout << "Enter new description: ";
					getline(cin, str);
					pItem->setSubcategory(str);
					break;
				case 5: cout << "Enter new quantity: ";
					getline(cin, str);
					pItem->setQuantity(atoi(str.c_str()));
					break;
				case 6: cout << "Enter new price: ";
					getline(cin, str);
					pItem->setPrice(atof(str.c_str()));
					break;
				case 7: cout << "Enter new ID: ";
					getline(cin, str);
					pItem->setId(atoi(str.c_str()));
					break;
				case 8: break;
				default: cout << "Invalid selection" << endl;
					break;
			}
		}while(choice != 8);
	}
}