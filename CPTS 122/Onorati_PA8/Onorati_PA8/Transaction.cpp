#include "Transaction.h"
#include "Store.h"

Transaction::Transaction()
{
	mTotal = 0.0;
	mDiscount = 0.0;
}

Transaction::~Transaction()
{
}

Transaction::Transaction (Transaction &copy)
{
}

//Member functions
void Transaction::setType()
{
	do
	{
		system("cls");
		cout << "*** Transaction ***" << endl;
		cout << "1. Sale" << endl;
		cout << "2. Return" << endl;
		cout << "Enter your selection: ";
		cin >> mType;
		if(mType < 1 || mType > 2)
		{
			cout << "Invalid selection" << endl;
		}
	}while (mType < 1 || mType > 2);
}

void Transaction::sale(Store &store)
{
	int choice = 0, quantity = 0;
	string tempStr;
	InventoryItem *tempItem = NULL;
	do
	{
	do
	{
		_flushall();
		system("cls");
		cout << "*** Sale Menu ***" << endl;
		cout << "1. View all inventory" << endl;
		cout << "2. View category of inventory" << endl;
		cout << "3. View subcategory of inventory" << endl;
		cout << "4. View specific inventory item" << endl;
		cout << "5. Sell item" << endl;
		cout << "6. Apply discount" << endl;
		cout << "7. View receipt" << endl;
		cout << "8. Complete sale" << endl;
		cout << "Enter your menu choice: ";
		cin >> choice;
		if(choice < 1 || choice > 8)
		{
			cout << "Invalid selection" << endl;
		}
	}while (choice < 1 || choice > 8);

	_flushall();
	switch(choice)
	{
		case 1: store.printInventory();
			break;
		case 2: cout << "Enter category: ";
			getline(cin, tempStr);
			store.printInventory(tempStr, "category");
			break;
		case 3: cout << "Enter subcategory: ";
			getline(cin, tempStr);
			store.printInventory(tempStr, "subcategory");
		case 4: cout << "Enter item name: ";
			getline(cin, tempStr);
			store.printInventory(tempStr, "name");
			break;
		case 5: cout << "Enter item name: ";
			getline(cin, tempStr);
			tempItem = store.findInventoryItem(tempStr);
			if(tempItem == NULL)
			{
				cout << "Item not found" << endl;
			}
			else if(tempItem->getQuantity() == 0)
			{
				cout << "Item currently out of stock" << endl;
			}
			else
			{
				do
				{
					cout << "Quantity available: " << tempItem->getQuantity() << endl;
					cout << "Enter number sold: ";
					cin >> quantity;
					if(quantity < 1 || quantity > tempItem->getQuantity())
					{
						cout << "Invalid Quantity" << endl;
					}
				}while(quantity < 1 || quantity > tempItem->getQuantity());

				//Set item to list of transaction items
				tempItem->setQuantity(quantity);
				mItems.push_back(*tempItem);

				//Reduce number of available items
				reduceInventory(store, tempItem->getTitle(), quantity);
			}
			break;
		case 6: addDiscount(store);
			break;
		case 7: calculateTotal();
			printReceipt();
			break;
		case 8: calculateTotal();
			saveReceipt(store);
			break;
	}
	system("pause");
	}while(choice != 8);
}

void Transaction::retrn(Store &store)
{
	int choice = 0, quantity = 0;
	string tempStr;
	InventoryItem *tempItem = NULL;
	do
	{
		_flushall();
		system("cls");
		cout << "*** Return Menu ***" << endl;
		cout << "1. Return Item" << endl;
		cout << "2. View receipt" << endl;
		cout << "3. Complete return" << endl;
		cin >> choice;

		_flushall();
		switch(choice)
		{
			case 1: cout << "Enter item name: ";
			getline(cin, tempStr);
			tempItem = store.findInventoryItem(tempStr);
			if(tempItem == NULL)
			{
				cout << "Item not found" << endl;
			}
			else
			{
				do
				{
					cout << "Enter quantity returning: ";
					cin >> quantity;
					if(quantity < 1)
					{
						cout << "Invalid Quantity" << endl;
					}
				}while(quantity < 1);

				//Set item to list of transaction items
				tempItem->setQuantity(quantity);
				mItems.push_back(*tempItem);

				//Reduce number of available items
				reduceInventory(store, tempItem->getTitle(), (quantity*-1));
			}
				break;
			case 2: calculateTotal(); 
				printReceipt();
				system("pause");
				break;
			case 3: calculateTotal();
				saveReceipt(store);
				break;
			default: cout << "Invalid selection" << endl;
				break;
		}
	}while(choice != 3);
}

void Transaction::printReceipt()
{
	cout << "*** Transaction Receipt ***" << endl;
	cout << "Transaction type: ";
	if(mType == 1)
	{
		cout << "Sale" << endl;
	}
	else
	{
		cout << "Return" << endl;
	}
	cout << "Transaction ID: " << mID << endl;
	cout << "Transaction Items: " << endl;
	vector<InventoryItem>::iterator iter = mItems.begin();
	for(iter; iter != mItems.end(); iter++)
	{
		cout << "\tItem: " << iter->getTitle() << endl;
		cout << "\tQuantity: " << iter->getQuantity() << endl;
		cout << "\tPrice Per Item: $" << fixed << setprecision(2) << iter->getPrice() << endl;
	}
	if(mType == 1)
	{
		cout << "Discount " << fixed << setprecision(2) << mDiscount << "%" << endl;
	}
	cout << "Total: $";
	if(mType == 1)
	{
		cout << fixed << setprecision(2) << mTotal << endl;
	}
	else
	{
		cout << "<" << fixed << setprecision(2) << mTotal << ">" << endl;
	}

}

void Transaction::saveReceipt(Store &store)
{
	store.mReceipts.open("StoreReceipts.txt", ios::app);
	store.mReceipts << "*** Transaction Receipt ***" << endl;
	store.mReceipts << "Transaction type: ";
	if(mType == 1)
	{
		store.mReceipts << "Sale" << endl;
	}
	else
	{
		store.mReceipts << "Return" << endl;
	}
	store.mReceipts << "Transaction ID: " << mID << endl;
	store.mReceipts << "Transaction Items: " << endl;
	vector<InventoryItem>::iterator iter = mItems.begin();
	for(iter; iter != mItems.end(); iter++)
	{
		store.mReceipts << "\tItem: " << iter->getTitle() << endl;
		store.mReceipts << "\tQuantity: " << iter->getQuantity() << endl;
		store.mReceipts << "\tPrice Per Item: $" << fixed << setprecision(2) << iter->getPrice() << endl;
	}
	if(mType == 1)
	{
		store.mReceipts << "Discount " << fixed << mDiscount << "%" << endl;
	}
	store.mReceipts << "Total: $";
	if(mType == 1)
	{
		store.mReceipts << fixed << mTotal << endl;
	}
	else
	{
		store.mReceipts << "<" << fixed << mTotal << ">" << endl;
	}
	store.mReceipts << endl;
	store.mReceipts.close();
}

void Transaction::calculateTotal()
{
	mTotal = 0.0;
	vector<InventoryItem>::iterator iter = mItems.begin();
	for(iter; iter != mItems.end(); iter++)
	{
		mTotal += (iter->getQuantity() * iter->getPrice());
	}
	mTotal -= (mTotal * (mDiscount/100));
}

void Transaction::addDiscount(Store &store)
{
	int discount = 0;
	do
	{
		cout << "*** Discount Options ***" << endl;
		cout << "1. Bulk discount" << endl;
		cout << "2. Faculty discount" << endl;
		cout << "3. Staff discount" << endl;
		cout << "4. Student discount" << endl;
		cout << "5. No discount" << endl;
		cout << "Enter discount selection: ";
		cin >> discount;
		if(discount < 1 || discount > 5)
		{
			cout << "Invalid selection" << endl;
		}
	}while(discount < 1 || discount > 5);
	switch(discount)
	{
		case 1: mDiscount = store.getBulkDiscount();
			break;
		case 2: mDiscount = store.getFacultyDiscount();
			break;
		case 3: mDiscount = store.getStaffDiscount();
			break;
		case 4: mDiscount = store.getStudentDiscount();
			break;
		case 5: mDiscount = 0.0;
	}
}

void Transaction::reduceInventory(Store &store, string item, int quantity)
{
	vector<InventoryItem>::iterator iter = store.inventory.begin();
	for(iter; iter != store.inventory.end(); iter++)
	{
		if(iter->getTitle() == item)
		{
			iter->setQuantity(iter->getQuantity() - quantity);
		}
	}
}