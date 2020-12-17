#include "ProductNode.h"

ProductNode::ProductNode() {
	this->data = new Product;
	this->prev = NULL;
	this->next = NULL;
}
Product* ProductNode::getData() { return data; }

ProductNode* ProductNode::getPrev() { return prev; }

ProductNode* ProductNode::getNext() { return next; }

void ProductNode::setData(string name, string category, int price, int quantity) {
	data->setName(name);
	data->setCategory(category);
	data->setPrice(price);
	data->setQuantity(quantity);
}

void ProductNode::setData(Product* data) {
	this->data = data;
}

void ProductNode::setPrev(ProductNode* product) {
	prev = product;
}

void ProductNode::setNext(ProductNode* product) {
	next = product;
}

void ProductNode::show() {
	cout << "CATEGORY: " << data->getCategory() << " / Name: " << data->getName() << " / PRICE: " << data->getPrice() << " / QUANTITY: " << data->getQuantity() << endl;
}
