#include "User.h"

User::User() {}

User::~User() {}

User::User(string id, string pw, string name, string phone, int money, bool logIn) {
	this->id = id;
	this->pw = pw;
	this->name = name;
	this->phone = phone;
	this->money = money;
	this->logIn = logIn;
}

string User::getId() {
	return id;
}

string User::getPw() {
	return pw;
}

string User::getName() {
	return name;
}

string User::getPhone() {
	return phone;
}

int User::getMoney() {
	return money;
}

bool User::getLogIn() {
	return logIn;
}

void User::setId(string id) {
	this->id = id;
}

void User::setPw(string pw) {
	this->pw = pw;
}

void User::setName(string name) {
	this->name = name;
}

void User::setPhone(string phone) {
	this->phone = phone;
}

void User::setMoney(int money) {
	this->money = money;
}

void User::setLogIn(bool logIn) {
	this->logIn = logIn;
}
