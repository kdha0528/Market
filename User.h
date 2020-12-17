#pragma once
#include "Stdheader.h"

class User {
private:
	string id;
	string pw;
	string name;
	string phone;
	int money;
	bool logIn;
public:
	User();
	~User();
	User(string id, string pw, string name, string phone, int money, bool logIn);
	string getId();
	string getPw();
	string getName();
	string getPhone();
	int getMoney();
	bool getLogIn();
	void setId(string id);
	void setPw(string pw);
	void setName(string name);
	void setPhone(string phone);
	void setMoney(int money);
	void setLogIn(bool logIn);
};
