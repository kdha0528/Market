#pragma once
#include "Stdheader.h"

class Product {
private:
	string name;
	string category;
	int price = 0;
	int quantity = 0;
public:
	Product();
	Product(string name, string category, int price, int quantity);
	string getName();
	string getCategory();
	int getPrice();
	int getQuantity();
	void setName(string name);
	void setCategory(string category);
	void setPrice(int price);
	void setQuantity(int quantity);
};