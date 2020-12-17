#include"Market.h"

void Market::run() {
	loadFile();
	if (!checkID("manager")) addManagerNode();
	showFirstMenu();
}

void Market::showFirstMenu() {
	char menu;
	while (true) {
		cout << "********** ���� **********" << endl;
		cout << "1. ȸ������\n";
		cout << "2. �α���\n";
		cout << "0. ����\n";
		cout << "�޴�: "; cin >> menu;
		cout << endl;

		switch (menu) {
			UserNode* tmp;
		case '1': addUserNode(); break;
		case '2':
			tmp = logIn();
			if (tmp == NULL) break;
			else {
				user = tmp;
				if (user->getData()->getId() == "manager" && user->getData()->getLogIn()) showManagerMenu(user);
				else if (user->getData()->getLogIn()) showUserMenu(user);
			}
			break;
		case '0':
			cout << "�����մϴ�.";
			saveFile();
			allDeleteUsers(userHead);
			allDeleteCategory(categoryHead);
			return;
		default: cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl << endl; break;
		}
	}
}

void Market::showUserMenu(UserNode* user) {
	char menu;
	bool checkLogOut;
	while (true) {
		cout << "********** ���� **********" << endl;
		cout << "1. ��������\n";
		cout << "2. �����ϱ�\n";
		cout << "3. ���ǻ��\n";
		cout << "0. �α׾ƿ�\n";
		cout << "�޴� : "; cin >> menu;
		cout << endl;

		switch (menu) {
		case '1': checkLogOut = manageMyInfo(user);
			if (checkLogOut == true) return;
			else break;
		case '2': chargeMoney(user); break;
		case '3': enterMarket(user); break;
		case '0': logOut(user); return;
		default:  cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl << endl; break;
		}
	}
}

bool Market::manageMyInfo(UserNode* user) {
	char menu;
	while (true) {
		cout << "********** �������� **********" << endl;
		cout << "1. �������� ����\n";
		cout << "2. �������� ����\n";
		cout << "3. ȸ��Ż��\n";
		cout << "0. �ڷΰ���\n";
		cout << "�޴� : "; cin >> menu;
		cout << endl;

		switch (menu) {
		case '1': viewMyInfo(user); break;
		case '2': modifyMyInfo(user); return true;
		case '3': deleteAccount(user); return true;
		case '0': return false;
		default: cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl << endl; break;
		}
	}
}

void Market::showManagerMenu(UserNode* user) {
	char menu;
	while (true) {
		cout << "********** ������ **********" << endl;
		cout << "1. ��ǰ ����\n";
		cout << "2. ī�װ� ����\n";
		cout << "3. ȸ������ ����\n";
		cout << "0. �α׾ƿ�\n";
		cout << "�޴� : "; cin >> menu;
		cout << endl;

		switch (menu) {
		case '1': manageProduct(); break;
		case '2': manageCategory(); break;
		case '3': manageUserInfo(); break;//�������� ����
		case '0': logOut(user); return;
		default: cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl << endl; break;
		}
	}
}

void Market::manageProduct() {
	char menu;
	while (true) {
		cout << "********** ��ǰ���� ***********" << endl;
		cout << "1. ��ǰ ã��\n";
		cout << "2. ��� ��ǰ ����Ʈ ����\n";
		cout << "3. ��ǰ ����\n";
		cout << "4. �� ǰ�� �߰�\n";
		cout << "5. ǰ�� ����\n";
		cout << "0. �ڷΰ���\n";
		cout << "�޴� : "; cin >> menu;
		cout << endl;

		switch (menu) {
		case '1': viewProduct(); break;
		case '2': viewAllProduct(); break;
		case '3': modifyProduct(); break;
		case '4': addNewProduct(); break;
		case '5': deleteProduct(); break;
		case '0': return;
		default: cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl << endl; break;
		}
	}
}

void Market::manageCategory() {
	char menu;
	while (true) {
		cout << "********** ī�װ����� **********" << endl;
		cout << "1. ī�װ� �߰�\n";
		cout << "2. ī�װ� ����\n";
		cout << "3. ī�װ� �̸�����\n";
		cout << "0. �ڷΰ���\n";
		cout << "�޴� : "; cin >> menu;
		cout << endl;

		switch (menu) {
		case '1': addCategory(); break;
		case '2': deleteCategory(); break;
		case '3': renameCategory(); break;
		case '0': return;
		default: cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl << endl; break;
		}
	}
}

void Market::manageUserInfo() {
	char menu;
	while (true) {
		cout << "********** ȸ������ ���� **********" << endl;
		cout << "1. ȸ������ ����\n";
		cout << "2. ��� ȸ������ ����\n";
		cout << "3. ȸ������ ����\n";
		cout << "4. ȸ������ ����\n";
		cout << "0. �ڷΰ���\n";
		cout << "�����ϰ� ���� ����� �������ּ���: "; cin >> menu;
		cout << endl;

		switch (menu) {
		case'1': viewUserInfo(); break;
		case'2': viewAllInfo(); break;
		case'3': modifyUserInfo(); break;
		case'4': deleteUser(); break;
		case'0': return;
		default: cout << "�߸� �Է��ϼ̽��ϴ�." << endl; break;
		}
	}
}

int Market::getCategorySize() {
	CategoryNode* ptr = categoryHead;
	int i = 0;
	while (ptr != NULL) {
		ptr = ptr->getNext();
		i++;
	}
	return i;
}

int Market::getProductSize(CategoryNode* category) {
	ProductNode* ptr = category->getProductHead();
	int i = 0;
	while (ptr != NULL) {
		ptr = ptr->getNext();
		i++;
	}
	return i;
}

CategoryNode* Market::getCategoryHead() {
	return categoryHead;
}

void Market::addManagerNode() {
	if (userSize == 0) {
		UserNode* user = new UserNode();
		user->setData("manager", "1234", "�赿��", "01075444357", 0, 0);
		userHead = userTail = user;
		userSize++;
	}
	else return;
}

void Market::addUserNode() {
	string id, pw, name, phone;

	cout << "********** ȸ������ **********" << endl;
	//ptr�� �ߺ� ���̵� �ִ��� �˻�
	while (true) {
		cout << "ID: "; cin >> id;
		cout << "PW: "; cin >> pw;
		cout << "NAME: "; cin >> name;
		cout << "PHONE: "; cin >> phone;
		if (!checkID(id)) {
			UserNode* user = new UserNode();
			user->setData(id, pw, name, phone, 0, 0);
			userTail->setNext(user);
			user->setPrev(userTail);
			userTail = user;
			break;
		}
		else {
			cout << "�ߺ��Ǵ� ID�� �ֽ��ϴ�." << endl << endl;
		}
	}
	cout << "���ϵ帳�ϴ�. ���������� ������ �����Ͽ����ϴ�." << endl << endl;
	userSize++;
}

bool Market::checkID(string id) {
	UserNode* ptr = userHead;
	while (ptr != NULL) {
		if (id == ptr->getData()->getId()) {
			return true;
		}
		ptr = ptr->getNext();
	}
	return false;
}

bool Market::checkPW(string pw) {
	UserNode* ptr = userHead;
	while (ptr != NULL) {
		if (pw == ptr->getData()->getPw()) {
			return true;
		}
		ptr = ptr->getNext();
	}
	return false;
}

UserNode* Market::logIn() {
	int i = 5;
	string id, pw;

	cout << "********** �α��� **********" << endl;
	while (i != 0) {
		cout << "ID: "; cin >> id;
		cout << "PW: "; cin >> pw;

		if (checkID(id) && checkPW(pw)) {
			UserNode* user = findID(id);
			user->getData()->setLogIn(1);
			cout << "�α��ο� �����Ͽ����ϴ�." << endl << endl;
			return user;
		}
		else {
			cout << 6 - i << "�� �α��ο� �����Ͽ����ϴ�." << endl;
			cout << i - 1 << "�� �α����� �õ��� �� �ֽ��ϴ�." << endl << endl;
		}
		i--;
	}
	return NULL;
}

UserNode* Market::findID(string id) {
	UserNode* ptr = userHead;
	while (ptr != NULL) {
		if (id == ptr->getData()->getId()) {
			return ptr;
		}
		ptr = ptr->getNext();
	}
	return NULL;
}

void Market::chargeMoney(UserNode* user) {
	int money;

	cout << "********** �����ϱ� **********" << endl;
	cout << "�ݾ�: "; cin >> money;
	user->getData()->setMoney(money);
	cout << endl;
}

void Market::logOut(UserNode* user) {
	user->getData()->setLogIn(0);
}

void Market::viewMyInfo(UserNode* user) {
	string id = user->getData()->getId();
	string name = user->getData()->getName();
	string phone = user->getData()->getPhone();
	int money = user->getData()->getMoney();
	cout << "ID:    " << id << endl;
	cout << "NAME:  " << name << endl;
	cout << "PHONE: " << phone << endl;
	cout << "MONEY: " << money << "��" << endl << endl;
}

void Market::modifyMyInfo(UserNode* user) {
	string id, pw, name, phone;

	cout << "������ ���̵� �Է��Ͻÿ�: "; cin >> id;
	cout << "������ ��й�ȣ�� �Է��Ͻÿ�: "; cin >> pw;
	cout << "������ �̸��� �Է��Ͻÿ�: "; cin >> name;
	cout << "������ ��ȭ��ȣ�� �Է��Ͻÿ�: "; cin >> phone;
	cout << endl << endl;

	if (!checkID(id)) {
		user->setData(id, pw, name, phone, user->getData()->getMoney(), 0);
		cout << "�������������� �Ϸ�Ǿ����ϴ�. �ٽ� �α��� ���ֽʽÿ�." << endl << endl;
	}
	else {
		cout << "���̵� �ߺ��˴ϴ�." << endl << endl;
	}
}

void Market::deleteAccount(UserNode* user) {
	char yn;
	cout << "���� �����Ͻðڽ��ϱ�?(y/n) "; cin >> yn;
	if (yn == 'y' || yn == 'Y') {
		if (user == userTail) {
			userTail = user->getPrev();
			delete user;
			userTail->setNext(NULL);
			userSize--;
			cout << "�����Ǿ����ϴ�." << endl << endl;
		}
		else {
			user->getPrev()->setNext(user->getNext());
			user->getNext()->setPrev(user->getPrev());
			delete user;
			userSize--;
		}
	}
	else if (yn == 'n' || yn == 'N') {
		cout << "����Ͽ����ϴ�.";
	}
	else {
		cout << "�߸� �Է��ϼ̽��ϴ�.";
	}
}

void Market::viewProduct() {
	string name;
	ProductNode* product;
	cout << "ã����� ��ǰ �Է��Ͻʽÿ�: "; cin >> name;
	if (checkProduct(name)) {
		product = findProduct(name);
		product->show();
	}
	else {
		cout << "�������� �ʴ� ��ǰ�Դϴ�." << endl;
	}
	cout << endl;
}

void Market::viewAllProduct() {
	ProductNode* product;
	CategoryNode* ctg = categoryHead;

	for (int i = 0; i < categorySize; i++) {
		product = ctg->getProductHead();
		ctg->show();
		for (int j = 0; j < getProductSize(ctg); j++) {
			product->show();
			product = product->getNext();
		}
		ctg = ctg->getNext();
		cout << endl;
	}
	cout << endl;
}

void Market::addNewProduct() {
	string name, category;
	int price, quantity;
	CategoryNode* ctg;
	cout << "********** ��ǰ ���� **********" << endl;

	while (true) {
		cout << "CATEGORY: "; cin >> category;
		if (checkCategory(category)) {
			ctg = findCategory(category);
			cout << "NAME: "; cin >> name;
			cout << "PRICE: "; cin >> price;
			cout << "QUANTITY: "; cin >> quantity;

			if (!checkProduct(name)) {
				ProductNode* product = new ProductNode();
				product->setData(name, category, price, quantity);

				if (ctg->getProductHead() == NULL) {
					ctg->setProductHead(product);
					ctg->setProductTail(product);
				}

				else {
					ctg->getProductTail()->setNext(product);
					product->setPrev(ctg->getProductTail());
					ctg->setProductTail(product);
				}

				cout << "���������� ǰ���� �����Ͽ����ϴ�." << endl << endl;
				ctg->getData()->setProductSize(ctg->getData()->getProductSize() + 1);
				break;
			}
			else {
				cout << "�̸��� �ߺ��˴ϴ�." << endl << endl;
			}
		}
		else { cout << "�������� �ʴ� ī�װ��Դϴ�." << endl << endl; return; }
	}
}

bool Market::checkProduct(string name) {
	CategoryNode* ctg = categoryHead;
	ProductNode* product;
	while (ctg != NULL) {
		product = ctg->getProductHead();
		while (product != NULL) {
			if (name == product->getData()->getName()) {
				return true;
			}
			product = product->getNext();
		}
		ctg = ctg->getNext();
	}
	return false;
}

bool Market::checkProduct(CategoryNode* ctg, string name) {
	ProductNode* product;
	product = ctg->getProductHead();
	while (product != NULL) {
		if (name == product->getData()->getName()) {
			return true;
		}
		product = product->getNext();
	}
	return false;
}

void Market::deleteProduct() {
	cout << "********** ��ǰ ���� **********" << endl;
	char yn;
	string name;

	cout << "�����ϰ���� ��ǰ�� �Է����ּ���: "; cin >> name;
	if (checkProduct(name)) {
		cout << "���� �����Ͻðڽ��ϱ�?(y/n) "; cin >> yn;
		if (yn == 'y' || yn == 'Y') {
			CategoryNode* ctg = categoryHead;
			ProductNode* q;
			ProductNode* product = findProduct(name);
			while (ctg != NULL) {
				if (checkProduct(ctg, name)) {
					if (product == ctg->getProductHead()) {
						if (product->getNext() == NULL) {
							delete product;
							ctg->setProductHead(NULL);
							ctg->setProductTail(NULL);
							ctg->getData()->setProductSize(ctg->getData()->getProductSize() - 1);
						}
						else {
							q = product->getNext();
							delete product;
							ctg->setProductHead(q);
							ctg->getData()->setProductSize(ctg->getData()->getProductSize() - 1);
						}
					}
					else {
						if (product == ctg->getProductTail()) {
							ctg->setProductTail(product->getPrev());
							delete product;
							ctg->getProductTail()->setNext(NULL);
							ctg->getData()->setProductSize(ctg->getData()->getProductSize() - 1);
						}
						else {
							product->getPrev()->setNext(product->getNext());
							product->getNext()->setPrev(product->getPrev());
							delete product;
							ctg->getData()->setProductSize(ctg->getData()->getProductSize() - 1);
						}
					}
				}
				else ctg = ctg->getNext();
			}
		}
		else if (yn == 'n' || yn == 'N') {
			cout << "����Ͽ����ϴ�." << endl << endl;
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl << endl;
		}
	}
	else {
		cout << "�������� �ʴ� ��ǰ�Դϴ�." << endl << endl;
	}
}

ProductNode* Market::findProduct(string name) {
	CategoryNode* ctg = categoryHead;
	ProductNode* product;

	while (ctg != NULL) {

		product = ctg->getProductHead();

		while (product != NULL) {
			if (name == product->getData()->getName()) {
				return product;
			}
			product = product->getNext();
		}
		ctg = ctg->getNext();
	}
	return NULL;
}

void Market::modifyProduct() {
	cout << "********** ǰ�� ���� **********" << endl;
	string name;
	char select;
	string pName;
	string pCategory;
	int pPrice;
	int pQuantity;
	ProductNode* product;

	cout << "������ ��ǰ�� �Է����ּ���: "; cin >> name;
	if (checkProduct(name)) {
		product = findProduct(name);
		cout << "1. ī�װ�\n";
		cout << "2. �̸�\n";
		cout << "3. ����\n";
		cout << "4. ����\n";
		cout << "5. �ڷΰ���\n";
		cout << "�����ϰ� ���� ����� �������ּ���: "; cin >> select;
		cout << endl;

		switch (select) {
		case'1':
			cout << "������ ī�װ�: "; cin >> pCategory;
			product->getData()->setCategory(pCategory);
			break;
		case'2':
			cout << "������ �̸�: "; cin >> pName;
			product->getData()->setName(pName);
			break;
		case'3':
			cout << "������ ����: "; cin >> pPrice;
			product->getData()->setPrice(pPrice);
			break;
		case'4':
			cout << "������ ����: "; cin >> pQuantity;
			product->getData()->setQuantity(pQuantity);
			break;
		case'5': return;
		default: cout << "�߸��Է��ϼ̽��ϴ�." << endl << endl; break;
		}
	}
	else {
		cout << "�������� �ʴ� ��ǰ�Դϴ�." << endl << endl; return;
	}
}

void Market::addCategory() {
	string name;

	cout << "********** ī�װ� �߰� **********" << endl;

	while (true) {
		cout << "NAME: "; cin >> name;
		if (!checkCategory(name)) {
			CategoryNode* category = new CategoryNode();
			category->getData()->setCtg(name);
			if (categoryHead == NULL) {
				categoryHead = categoryTail = category;
			}
			else {
				categoryTail->setNext(category);
				category->setPrev(categoryTail);
				categoryTail = category;
			}
			cout << "���������� ī�װ��� �����Ͽ����ϴ�." << endl << endl;
			categorySize++;
			break;
		}
		else {
			cout << "�̸��� �ߺ��˴ϴ�." << endl << endl;
		}
	}
}

bool Market::checkCategory(string name) {
	CategoryNode* ptr = categoryHead;
	while (ptr != NULL) {
		if (name == ptr->getData()->getCtg()) {
			return true;
		}
		ptr = ptr->getNext();
	}
	return false;
}

CategoryNode* Market::findCategory(string name) {
	CategoryNode* ptr = categoryHead;

	while (true) {
		if (name == ptr->getData()->getCtg()) return ptr;
		ptr = ptr->getNext();
	}
}

void Market::deleteCategory() {
	cout << "********** ī�װ� ���� **********" << endl;
	char yn;
	string name;

	cout << "�����ϰ���� ī�װ� �Է����ּ���: "; cin >> name;
	if (checkCategory(name)) {
		cout << "���� �����Ͻðڽ��ϱ�?(y/n) "; cin >> yn;
		if (yn == 'y' || yn == 'Y') {
			CategoryNode* category = findCategory(name);
			CategoryNode* q;
			if (category == categoryHead) {
				if (category->getNext() == NULL) {
					delete category;
					categoryHead = categoryTail = NULL;
					categorySize--;
				}
				else {
					q = category->getNext();
					delete category;
					categoryHead = q;
					categorySize--;
				}
			}
			else {
				if (category == categoryTail) {
					categoryTail = category->getPrev();
					delete category;
					categoryTail->setNext(NULL);
					categorySize--;
				}
				else {
					category->getPrev()->setNext(category->getNext());
					category->getNext()->setPrev(category->getPrev());
					delete category;
					categorySize--;
				}
			}
			cout << "ī�װ��� �����Ǿ����ϴ�." << endl << endl;
		}
		else if (yn == 'n' || yn == 'N') {
			cout << "����Ͽ����ϴ�." << endl << endl;
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl << endl;
		}
	}
	else {
		cout << "�������� �ʴ� ��ǰ�Դϴ�." << endl << endl;
	}
}

void Market::renameCategory() {
	cout << "********** ī�װ� �̸����� **********" << endl;
	string name;
	ProductNode* ptr = categoryHead->getProductHead();

	cout << "�̸��� �����ϰ���� ī�װ� �Է����ּ���: "; cin >> name;
	if (checkCategory(name)) {
		CategoryNode* category = findCategory(name);
		cout << "�����Ͻ� ī�װ��� �̸��� �Է����ּ���: "; cin >> name;
		category->getData()->setCtg(name);
		while (ptr != NULL) {
			ptr->getData()->setCategory(name);
			ptr = ptr->getNext();
		}
		cout << "���������� �����Ͽ����ϴ�." << endl << endl;
	}
	else {
		cout << "�������� �ʴ� ī�װ��Դϴ�." << endl << endl;
	}
}
void Market::viewUserInfo() {
	string id;
	UserNode* user;
	cout << "ã����� ID�� �Է��Ͻʽÿ�: "; cin >> id;;
	if (checkID(id)) {
		user = findID(id);
		user->show();
	}
	else {
		cout << "�������� �ʴ� id�Դϴ�." << endl;
	}
	cout << endl;
}

void Market::viewAllInfo() {
	UserNode* user = userHead->getNext();
	if (user == NULL) {
		cout << "ȸ���� �������� �ʽ��ϴ�." << endl << endl;
		return;
	}
	else {
		while (user != NULL) {
			user->show();
			user = user->getNext();
		}
		cout << endl;
	}
}

void Market::modifyUserInfo() {
	cout << "********** ȸ������ ���� **********" << endl;
	string id;
	string uId;
	string uPw;
	string uName;
	string uPhone;
	UserNode* user;
	cout << "ID: "; cin >> id;

	if (checkID(id)) {
		user = findID(id);
		user->show();
		cout << "\n������ ������ �Է����ּ���." << endl << endl;
		cout << "ID: "; cin >> uId;
		cout << "PW: "; cin >> uPw;
		cout << "NAME: "; cin >> uName;
		cout << "PHONE: "; cin >> uPhone;
		if (!checkID(uId)) {
			user->setData(uId, uPw, uName, uPhone);
			cout << "���������� �����Ͽ����ϴ�." << endl << endl;
		}
		else {
			cout << "�ߺ��Ǵ� ID�� �ֽ��ϴ�." << endl << endl;
		}
	}
	else {
		cout << "�������� �ʴ� id�Դϴ�." << endl << endl;
	}
}

void Market::deleteUser() {
	cout << "********** ȸ�� ���� **********" << endl;
	char yn;
	string id;
	UserNode* user;

	cout << "�����ϰ���� ID�� �Է����ּ���: "; cin >> id;
	if (checkID(id)) {
		cout << "���� �����Ͻðڽ��ϱ�?(y/n) "; cin >> yn;
		if (yn == 'y' || yn == 'Y') {
			user = findID(id);
			if (user == userTail) {
				userTail = user->getPrev();
				delete user;
				userTail->setNext(NULL);
				userSize--;
			}
			else {
				user->getPrev()->setNext(user->getNext());
				user->getNext()->setPrev(user->getPrev());
				delete user;
				userSize--;
			}
		}
		else if (yn == 'n' || yn == 'N') {
			cout << "����Ͽ����ϴ�." << endl << endl;
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl << endl;
		}
	}
	else {
		cout << "�������� �ʴ� ID�Դϴ�." << endl << endl;
	}
}

void Market::enterMarket(UserNode* user) {
	CategoryNode* category;
	ProductNode* product;
	int quantity;
	char yn;
	cout << "********** ���� **********" << endl;
	while (true) {
		while (true) {
			category = showCategoryList();
			if (category == NULL) return;
			product = showProductList(category);
			if (product != NULL) break;
		}
		while (true) {
			cout << "�����Ͻ� ������ ������ �Է����ּ���: "; cin >> quantity;
			if (user->getData()->getMoney() < product->getData()->getPrice() * quantity) {
				cout << "�ݾ��� �����մϴ�." << endl;
				cout << "������ �ٽ� �Է��Ͻðڽ��ϱ�?(y/n)"; cin >> yn;
				if (yn == 'y' || yn == 'Y') continue;
				else return;
			}
			else if (quantity <= product->getData()->getQuantity() && quantity >= 1) break;
			else cout << "�߸��Է��ϼ̽��ϴ�." << endl << endl;
		}

		cout << product->getData()->getName() << " " << quantity << "���� ������ " << product->getData()->getPrice() * quantity << "�� �Դϴ�. ���� �����Ͻðڽ��ϱ�?(y/n) "; cin >> yn; cout << endl << endl;

		while (true) {
			if (yn == 'y' || yn == 'Y') {
				buy(user, product, quantity);
				break;
			}
			else if (yn == 'n' || yn == 'N') {
				cout << "����Ͽ����ϴ�." << endl << endl;
				break;
			}
			else {
				cout << "�߸��Է��Ͽ����ϴ�. �ٽ� �Է����ֽʽÿ�." << endl << endl;
			}
		}
		cout << "�ٽ� �������� ���ư��ðڽ��ϱ�?(y/n) "; cin >> yn; cout << endl;

		while (true) {
			if (yn == 'y' || yn == 'Y') {
				break;
			}
			else if (yn == 'n' || yn == 'N') {
				cout << "�޴�ȭ������ ���ư��ϴ�." << endl << endl;
				return;
			}
			else {
				cout << "�߸��Է��Ͽ����ϴ�. �ٽ� �Է����ֽʽÿ�." << endl << endl;
			}
		}
	}
}

CategoryNode* Market::showCategoryList() {
	int menu;
	CategoryNode* category;
	while (true) {
		category = getCategoryHead();
		for (int i = 0; i < getCategorySize(); i++) {
			cout << i + 1 << ". " << category->getData()->getCtg() << endl;
			category = category->getNext();
		}
		cout << "0. ����" << endl;
		cout << endl;
		while (true) {
			cout << "�����Ͻ� ������ ī�װ� ��ȣ�� ����ּ���: "; cin >> menu;
			cout << endl;
			if (menu <= getCategorySize() && menu >= 0) break;
			else cout << "�߸��Է��ϼ̽��ϴ�." << endl << endl;
		}
		if (menu == 0) return NULL;
		category = getCategoryHead();
		for (int i = 0; i < menu - 1; i++) {
			category = category->getNext();
		}
		return category;
	}
}

ProductNode* Market::showProductList(CategoryNode* category) {
	ProductNode* product;
	int menu;

	product = category->getProductHead();
	for (int i = 0; i < getProductSize(category); i++) {
		cout << i + 1 << ". "; product->show();
		product = product->getNext();
	}
	cout << "0. �ڷΰ���";
	cout << endl;

	while (true) {
		cout << "�����Ͻ� ������ ����ּ���: "; cin >> menu;
		cout << endl;
		if (menu <= getProductSize(category) && menu >= 0) break;
		else cout << "�߸��Է��ϼ̽��ϴ�." << endl << endl;
	}
	if (menu == 0) return NULL;
	product = category->getProductHead();
	for (int i = 0; i < menu - 1; i++) {
		product = product->getNext();
	}
	return product;
}

void Market::buy(UserNode* user, ProductNode* product, int quantity) {
	if (user->getData()->getMoney() >= (product->getData()->getPrice() * quantity)) {
		user->getData()->setMoney(user->getData()->getMoney() - (product->getData()->getPrice() * quantity));
		product->getData()->setQuantity(product->getData()->getQuantity() - quantity);
		cout << "�ŷ��� �Ϸ��Ͽ����ϴ�. ���� ���� �ܾ��� " << user->getData()->getMoney() << "�� �Դϴ�." << endl << endl;
	}
	else cout << "�ܾ��� �����մϴ�." << endl << endl;
}

void Market::saveFile() {
	fstream myfile;
	CategoryNode* category = categoryHead;
	UserNode* user = userHead;
	ProductNode* product = category->getProductHead();
	myfile.open("Market.txt", ios::out);
	myfile << userSize << " " << categorySize << endl;
	while (user != NULL) {
		myfile << user->getData()->getId() << " " << user->getData()->getPw() << " " << user->getData()->getName() << " " << user->getData()->getPhone() << " " << user->getData()->getMoney() << endl;
		user = user->getNext();
	}
	while (category != NULL) {
		myfile << category->getData()->getCtg() << " " << getProductSize(category) << endl;
		while (product != NULL) {
			myfile << product->getData()->getName() << " " << product->getData()->getCategory() << " " << product->getData()->getPrice() << " " << product->getData()->getQuantity() << endl;
			product = product->getNext();
		}
		category = category->getNext();
		product = category->getProductHead();
	}
}

void Market::loadFile() {
	fstream myfile;
	myfile.open("Market.txt", ios::in);
	myfile >> userSize >> categorySize;
	UserNode* user = userHead;
	string q, w, e, r;
	int d, f;

	for (int i = 0; i < userSize; i++) {
		myfile >> q >> w >> e >> r >> d;
		if (userHead == NULL) {
			UserNode* user = new UserNode();
			user->setData(q, w, e, r, d, 0);
			userHead = userTail = user;
		}
		else {
			UserNode* user = new UserNode();
			user->setData(q, w, e, r, d, 0);
			userTail->setNext(user);
			user->setPrev(userTail);
			userTail = user;
		}
	}
	for (int i = 0; i < categorySize; i++) {
		myfile >> q >> d;
		CategoryNode* category = new CategoryNode();
		category->getData()->setCtg(q);
		category->getData()->setProductSize(d);
		if (categoryHead == NULL) {
			categoryHead = categoryTail = category;
		}
		else {
			categoryTail->setNext(category);
			category->setPrev(categoryTail);
			categoryTail = category;
		}
		for (int j = 0; j < category->getData()->getProductSize(); j++) {
			myfile >> q >> w >> d >> f;
			ProductNode* product = new ProductNode();
			product->setData(q, w, d, f);

			if (category->getProductHead() == NULL) {
				category->setProductHead(product);
				category->setProductTail(product);
			}

			else {
				category->getProductTail()->setNext(product);
				product->setPrev(category->getProductTail());
				category->setProductTail(product);
			}
		}
	}
}

void Market::allDeleteUsers(UserNode* user) {
	if (user == NULL) return;
	else {
		allDeleteUsers(user->getNext());
		delete user;
	}
}

void Market::allDeleteCategory(CategoryNode* category) {
	if (category == NULL) return;
	else {
		allDeleteCategory(category->getNext());
		delete category;
	}
}
