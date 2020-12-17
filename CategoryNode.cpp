#include "CategoryNdoe.h"

CategoryNode::CategoryNode() {
	this->data = new Category;
	this->prev = NULL;
	this->next = NULL;
	this->productHead = NULL;
	this->productTail = NULL;
}

Category* CategoryNode::getData() {
	return data;
}

CategoryNode* CategoryNode::getPrev() {
	return prev;
}

CategoryNode* CategoryNode::getNext() {
	return next;
}

ProductNode* CategoryNode::getProductHead() {
	return productHead;
}

ProductNode* CategoryNode::getProductTail() {
	return productTail;
}

void CategoryNode::setData(Category* date) {
	this->data = data;
}

void CategoryNode::setPrev(CategoryNode* ctg) {
	prev = ctg;
}

void CategoryNode::setNext(CategoryNode* ctg) {
	next = ctg;
}

void CategoryNode::setProductHead(ProductNode* product) {
	productHead = product;
}

void CategoryNode::setProductTail(ProductNode* product) {
	productTail = product;
}

void CategoryNode::show() {
	cout << "CATEGORY " << "[" << this->data->getCtg() << "]" << endl;
}
