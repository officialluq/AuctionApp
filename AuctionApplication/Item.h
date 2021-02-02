#pragma once
#include <string>
#include <ctime>

class Item
{
private:
	std::string name;
	float priceNow; // buy now price 
	float priceAuc; // auction price
	int photoID[2];
	tm* expDate;
	bool auc;
	int ID; // unique ID of every item which was set 
	bool sold;

public:



protected:
	Item(std::string name, float priceNow, float priceAuc,bool auc, int photoID[]);
	void setPrice(float price, int choice); // setter 
	float getPrice(int choice);  // get price, 1 = buyNow, 2= AucDate
	void ProExpDate(tm* expDate); // prolongue expiration date
};
