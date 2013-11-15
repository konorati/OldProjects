#ifndef RESTAURANTCHECK_H
#define RESTAURANTCHECK_H
#include <string>

using namespace std;

//Function prototypes for restaurant check class
class RestaurantCheck
{
private:
	const static double DEFAULT_TAX, DEFAULT_TIP, 
		LOW_TAX, HIGH_TAX, LOW_TIP, HIGH_TIP;
	double taxRate, tip, totalTax, totalTip, subtotal, billTotal;
	static const int NUM_ITEMS = 10, MAX_ITEMS = 5;
	const static string itemDescription[NUM_ITEMS];
	const static double itemCost[NUM_ITEMS];
	int numItemsOrdered;
	int selectedItems[MAX_ITEMS];
	

	void presentMenu();
	double calculateTax(double);
	double calculateTip(double);

public:
	RestaurantCheck(double, double);
	RestaurantCheck();
	void placeOrder(RestaurantCheck&);
	void issueCheck(RestaurantCheck);
	~RestaurantCheck();
};
#endif