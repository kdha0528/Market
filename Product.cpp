#include "Product.h"

Product::Product() {}

Product::Product(string name, string category, int price, int quantity) {
	this->name = name;
	this->category = category;
	this->price = price;
	this->quantity = quantity;
}

string Product::getName() {
	return name;
}

string Product::getCategory() {
	return category;
}

int Product::getPrice() {
	return price;
}

int Product::getQuantity() {
	return quantity;
}

void Product::setName(string name) {
	this->name = name;
}

void Product::setCategory(string category) {
	this->category = category;
}

void Product::setPrice(int price) {
	this->price = price;
}

void Product::setQuantity(int quantity) {
	this->quantity = quantity;
}