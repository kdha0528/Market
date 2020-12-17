#pragma once
#include "Stdheader.h"
#include "User.h"

class UserNode {
private:
	User* data;
	UserNode* prev;
	UserNode* next;
public:
	UserNode();
	User* getData();
	UserNode* getPrev();
	UserNode* getNext();
	void setData(string id, string pw, string name, string phone, int money, bool logIn);
	void setData(User* data);
	void setData(string id, string pw, string name, string phone);
	void setData(string id, string pw, string name, string phone, int money);
	void setPrev(UserNode* user);
	void setNext(UserNode* user);
	void show();
};
