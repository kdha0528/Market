#pragma once
#include "Stdheader.h"
#include "Product.h"

class ProductNode {
private:
	Product* data;
	ProductNode* prev;
	ProductNode* next;
public:
	ProductNode();
	Product* getData();
	ProductNode* getPrev();
	ProductNode* getNext();
	void setData(string name, string category, int price, int quantity);
	void setData(Product* data);
	void setPrev(ProductNode* product);
	void setNext(ProductNode* product);
	void show();
};

