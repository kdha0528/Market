#pragma once
#include "Stdheader.h"

class Category {
private:
	string ctg;
	int productSize = 0;
public:
	Category();
	Category(string ctg, int productSize);
	string getCtg();
	int getProductSize();
	void setCtg(string ctg);
	void setProductSize(int productSize);
};
