// File: menu.cpp
// This program displays a menu and calculates total price based on user selection
// Input: Menu selection
// Output: Selection, selection price, tax, total amount due
// -------------------------------------------------------------------------------
// Class: Prog 111 Online Instructor: Robert Main
// Project: 6 Date assigned: 10/16/12
// Programmer: Kristin Onorati Date submitted: 10/22/12

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Creates a menu structure which isncludes the name of the item and the price
struct Menu {
	string menuItem;
	double menuPrice;

	string getMenuItem() const;
	double getMenuPrice() const;

};

void intro();
int displayMenu(const Menu&, const Menu&, const Menu&);
void printCheck(const Menu&);
void setData(Menu&, string, double);
void endingMessage();


int main() {
	
	//Constructs the menu items/prices using the menu structure
	Menu item1;
	setData(item1, "Milk", 1.25);

	Menu item2;
	setData(item2, "Coffee", 1.50);

	Menu item3;
	setData(item3, "Tea", 1.35);

	Menu item4;
	setData(item4, "No Beverage", 0);

	enum BeverageType {Milk = 1, Coffee, Tea, NoBeverage, Quit}; //Creates the enumerated data type BeverageType
	
	//Show intro
	intro();
	system("cls"); //clears screen
	int choice = displayMenu(item1, item2, item3);

	//Calculate bill based on user selection
	while (choice != 5) {
		switch (choice) {
			case Milk : printCheck(item1);
						break;

			case Coffee: printCheck(item2);
						 break;

			case Tea: printCheck(item3);
					break;

			case NoBeverage: 
							 break;
		}
		choice = displayMenu(item1, item2, item3);
	}
	endingMessage();
	system("pause");
	return 0;
}

//This function dislpays an introductory message
void intro() {
	cout << "This program will show you your total bill\nPlease enjoy our selections\n\t-Kristin Onorati\n\n";
	system("pause");
}
//This function displays the menu, allows user to select an item, validates the selection and returns the selected item
int displayMenu(const Menu& item1,  const Menu& item2, const Menu& item3) {
	system("cls"); //Clears screen
	//Display menu
	cout << left << setw(20) << "Bettie's Beverages" << "Price" << endl;
	cout << "-------------------------" << endl;
	cout << left << setw(20) << "1. Milk" << "$" << fixed << setprecision(2) << item1.getMenuPrice() << endl;
	cout << left << setw(20) << "2. Coffee" << "$" << fixed << setprecision(2) << item2.getMenuPrice() << endl;
	cout << left << setw(20) << "3. Tea" << "$" << fixed << setprecision(2) << item3.getMenuPrice() << endl;
	cout << "4. No beverage" << endl;
	cout << "5. Quit the Program" << endl;

	//Gets user selection 
	int choice;
	cin >> choice;

	//validates user choice
	while (choice < 1 || choice > 5) {
		cout << "\nThe only valid choices are 1-5.\nPlease re-enter a number between 1 and 5" << endl;;
		cin >> choice;
	}
	return choice;
}
//This function calculates the total amount due and displays the check
void printCheck(const Menu& item) {
	const double TAX_RATE = .088; //declares the tax rate constant

	double tax = item.menuPrice * TAX_RATE;
	double total = item.menuPrice + tax;

	//Displays the bill
	system("cls"); //clears the screen
	cout << "Bettie's Beverages Bill for today:\n"<< endl;
	cout << left << setw(15) << item.getMenuItem() << "$" << fixed << showpoint << setprecision(2) << item.getMenuPrice() << endl;
	cout << left << setw(15) << "Tax" << "$" << fixed << showpoint << setprecision(2) << tax << endl;
	cout << left << setw(15) << "Amount due" << "$" << fixed << showpoint << setprecision(2) << total << endl << endl;
	system("pause");


}
//This function sets the item name and item price for the instance of the structure
void setData(Menu& item, string beverage, double price) {
	item.menuItem = beverage;
	item.menuPrice = price;

}

void endingMessage() {
	cout << "Thank you for choosing Bettie's Beverages\nThe program will now end" << endl;
}

string Menu::getMenuItem() const{
	return menuItem;
}

double Menu::getMenuPrice() const{
	return menuPrice;
}