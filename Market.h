#pragma once
#include "Stdheader.h"
#include "UserNode.h"
#include "ProductNode.h"
#include "CategoryNdoe.h"

class Market {
private:
	UserNode* userHead = NULL;
	UserNode* userTail = NULL;
	UserNode* user;
	CategoryNode* categoryHead;
	CategoryNode* categoryTail;
	int userSize = 0;
	int categorySize = 0;
public:
	void run();
	void showFirstMenu();
	void showUserMenu(UserNode* user);
	bool manageMyInfo(UserNode* user);
	void showManagerMenu(UserNode* user);
	void manageProduct();
	void manageCategory();
	void manageUserInfo();
	int getCategorySize();
	int getProductSize(CategoryNode* category);
	CategoryNode* getCategoryHead();
	void addManagerNode();
	void addUserNode();
	bool checkID(string id);
	bool checkPW(string pw);
	UserNode* logIn();
	UserNode* findID(string id);
	void chargeMoney(UserNode* user);
	void logOut(UserNode* user);
	void viewMyInfo(UserNode* user);
	void modifyMyInfo(UserNode* user);
	void deleteAccount(UserNode* user);
	void viewProduct();
	void viewAllProduct();
	void addNewProduct();
	bool checkProduct(string name);
	bool checkProduct(CategoryNode* ctg, string name);
	void deleteProduct();
	ProductNode* findProduct(string name);
	void modifyProduct();
	void addCategory();
	bool checkCategory(string name);
	CategoryNode* findCategory(string name);
	void deleteCategory();
	void renameCategory();
	void viewUserInfo();
	void viewAllInfo();
	void modifyUserInfo();
	void deleteUser();
	void enterMarket(UserNode* user);
	CategoryNode* showCategoryList();
	ProductNode* showProductList(CategoryNode* category);
	void buy(UserNode* user, ProductNode* product, int quantity);
	void saveFile();
	void loadFile();
	void allDeleteUsers(UserNode* user);
	void allDeleteCategory(CategoryNode* category);
};
