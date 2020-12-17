#include "Category.h"

Category::Category() {}

Category::Category(string ctg, int productSize) {
	this->ctg = ctg;
	this->productSize = productSize;
}

string Category::getCtg() {
	return ctg;
}

int Category::getProductSize() {
	return productSize;
}

void Category::setCtg(string ctg) {
	this->ctg = ctg;
}

void Category::setProductSize(int productSize) {
	this->productSize = productSize;
}