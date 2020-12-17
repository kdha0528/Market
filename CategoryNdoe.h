#pragma once
#include "Stdheader.h"
#include "Category.h"
#include "ProductNode.h"

class CategoryNode {
private:
	Category* data;
	CategoryNode* prev;
	CategoryNode* next;
	ProductNode* productHead;
	ProductNode* productTail;
public:
	CategoryNode();
	Category* getData();
	CategoryNode* getPrev();
	CategoryNode* getNext();
	ProductNode* getProductHead();
	ProductNode* getProductTail();
	void setData(Category* date);
	void setPrev(CategoryNode* ctg);
	void setNext(CategoryNode* ctg);
	void setProductHead(ProductNode* product);
	void setProductTail(ProductNode* product);
	void show();
};
