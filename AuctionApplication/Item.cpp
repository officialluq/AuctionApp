#include "Item.h"

Item::Item(std::string name, float priceNow, float priceAuc, bool auc, int photoID[])
{
	time_t now = time(0);
	this->name = name;
	for (int i = 0; i <= 2; i++)
	{
		this->photoID[i] = photoID[i];
	}
	if (auc == false)
		this->priceNow = priceNow;
	else if (auc == true)
		this->priceAuc = priceAuc;
		this->priceNow = priceNow;
		//this->expDate = localtime(&now);
}

void Item::setPrice(float price, int choice) 
{
	if (choice == 1)
		priceNow = price;
	else if (choice == 2)
		priceAuc = price;
}
float Item::getPrice(int choice)
{
	if (choice == 1)
		return priceNow;
	else if (choice == 2)
		return priceAuc;
}
void Item::ProExpDate(tm* expDate)
{
	expDate->tm_mon = expDate->tm_mon + 1;
}