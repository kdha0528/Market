#include "UserNode.h"

UserNode::UserNode() {
	this->data = new User();
	this->next = NULL;
	this->prev = NULL;
}

User* UserNode::getData() {
	return data;
}

UserNode* UserNode::getPrev() {
	return prev;
}

UserNode* UserNode::getNext() {
	return next;
}

void UserNode::setData(string id, string pw, string name, string phone, int money, bool logIn) {
	data->setId(id);
	data->setPw(pw);
	data->setName(name);
	data->setPhone(phone);
	data->setMoney(money);
	data->setLogIn(logIn);
}

void UserNode::setData(string id, string pw, string name, string phone, int money) {
	data->setId(id);
	data->setPw(pw);
	data->setName(name);
	data->setPhone(phone);
	data->setMoney(money);
}

void UserNode::setData(string id, string pw, string name, string phone) {
	data->setId(id);
	data->setPw(pw);
	data->setName(name);
	data->setPhone(phone);
}

void UserNode::setData(User* data) {
	this->data = data;
}

void UserNode::setPrev(UserNode* user) {
	prev = user;
}

void UserNode::setNext(UserNode* user) {
	next = user;
}

void UserNode::show() {
	cout << "ID: " << data->getId() << " / PW: " << data->getPw() << " / NAME: " << data->getName() << " / PHONE: " << data->getPhone() << endl;
}

