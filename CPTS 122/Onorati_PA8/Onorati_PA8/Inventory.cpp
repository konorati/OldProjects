#include "Inventory.h"

InventoryItem::InventoryItem()
{
	mTitle = "";
	mDescription = "";
	mCategory = "";
	mQuantity = 0;
	mPricePerUnit = 0.0;
	mProductID = 0;
}
InventoryItem::~InventoryItem()
{
}

/*InventoryItem::InventoryItem(InventoryItem &copy)
{
	mTitle = copy.mTitle;
	mDescription = copy.mDescription;
	mCategory = copy.mCategory;
	mQuantity = copy.mQuantity;
	mPricePerUnit = copy.mPricePerUnit;
	mProductID = copy.mProductID;
}*/

InventoryItem & InventoryItem::operator=(InventoryItem &rhs)
{
	if(this != &rhs)
	{
		mTitle = rhs.mTitle;
		mDescription = rhs.mDescription;
		mCategory = rhs.mCategory;
		mQuantity = rhs.mQuantity;
		mPricePerUnit = rhs.mPricePerUnit;
		mProductID = rhs.mProductID;
	}
	return *this;
}

//Getters & setters
string InventoryItem::getTitle() const
{
	return mTitle;
}

string InventoryItem::getDescription() const
{
	return mDescription;
}

string InventoryItem::getCategory() const
{
	return mCategory;
}

string InventoryItem::getSubcategory() const
{
	return mSubcategory;
}

int InventoryItem::getQuantity() const
{
	return mQuantity;
}

double InventoryItem::getPrice() const
{
	return mPricePerUnit;
}

int InventoryItem::getID() const
{
	return mProductID;
}

void InventoryItem::setTitle(string newTitle)
{
	mTitle = newTitle;
}

void InventoryItem::setDescription(string newDescription)
{
	mDescription = newDescription;
}

void InventoryItem::setCategory(string newCategory)
{
	mCategory = newCategory;
}

void InventoryItem::setSubcategory(string newSub)
{
	mSubcategory = newSub;
}

void InventoryItem::setQuantity(int newQuantity)
{
	mQuantity = newQuantity;
}

void InventoryItem::setPrice(double newPrice)
{
	mPricePerUnit = newPrice;
}

void InventoryItem::setId(int newID)
{
	mProductID = newID;
}