#include"Market.h"

void Market::run() {
	loadFile();
	if (!checkID("manager")) addManagerNode();
	showFirstMenu();
}

void Market::showFirstMenu() {
	char menu;
	while (true) {
		cout << "********** 마켓 **********" << endl;
		cout << "1. 회원가입\n";
		cout << "2. 로그인\n";
		cout << "0. 종료\n";
		cout << "메뉴: "; cin >> menu;
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
			cout << "종료합니다.";
			saveFile();
			allDeleteUsers(userHead);
			allDeleteCategory(categoryHead);
			return;
		default: cout << "잘못 입력하셨습니다. 다시 입력해주세요." << endl << endl; break;
		}
	}
}

void Market::showUserMenu(UserNode* user) {
	char menu;
	bool checkLogOut;
	while (true) {
		cout << "********** 마켓 **********" << endl;
		cout << "1. 개인정보\n";
		cout << "2. 충전하기\n";
		cout << "3. 물건사기\n";
		cout << "0. 로그아웃\n";
		cout << "메뉴 : "; cin >> menu;
		cout << endl;

		switch (menu) {
		case '1': checkLogOut = manageMyInfo(user);
			if (checkLogOut == true) return;
			else break;
		case '2': chargeMoney(user); break;
		case '3': enterMarket(user); break;
		case '0': logOut(user); return;
		default:  cout << "잘못 입력하셨습니다. 다시 입력해주세요." << endl << endl; break;
		}
	}
}

bool Market::manageMyInfo(UserNode* user) {
	char menu;
	while (true) {
		cout << "********** 개인정보 **********" << endl;
		cout << "1. 개인정보 열람\n";
		cout << "2. 개인정보 수정\n";
		cout << "3. 회원탈퇴\n";
		cout << "0. 뒤로가기\n";
		cout << "메뉴 : "; cin >> menu;
		cout << endl;

		switch (menu) {
		case '1': viewMyInfo(user); break;
		case '2': modifyMyInfo(user); return true;
		case '3': deleteAccount(user); return true;
		case '0': return false;
		default: cout << "잘못 입력하셨습니다. 다시 입력해주세요." << endl << endl; break;
		}
	}
}

void Market::showManagerMenu(UserNode* user) {
	char menu;
	while (true) {
		cout << "********** 관리자 **********" << endl;
		cout << "1. 물품 관리\n";
		cout << "2. 카테고리 관리\n";
		cout << "3. 회원정보 관리\n";
		cout << "0. 로그아웃\n";
		cout << "메뉴 : "; cin >> menu;
		cout << endl;

		switch (menu) {
		case '1': manageProduct(); break;
		case '2': manageCategory(); break;
		case '3': manageUserInfo(); break;//유저정보 관리
		case '0': logOut(user); return;
		default: cout << "잘못 입력하셨습니다. 다시 입력해주세요." << endl << endl; break;
		}
	}
}

void Market::manageProduct() {
	char menu;
	while (true) {
		cout << "********** 물품관리 ***********" << endl;
		cout << "1. 제품 찾기\n";
		cout << "2. 모든 제품 리스트 보기\n";
		cout << "3. 제품 관리\n";
		cout << "4. 새 품목 추가\n";
		cout << "5. 품목 삭제\n";
		cout << "0. 뒤로가기\n";
		cout << "메뉴 : "; cin >> menu;
		cout << endl;

		switch (menu) {
		case '1': viewProduct(); break;
		case '2': viewAllProduct(); break;
		case '3': modifyProduct(); break;
		case '4': addNewProduct(); break;
		case '5': deleteProduct(); break;
		case '0': return;
		default: cout << "잘못 입력하셨습니다. 다시 입력해주세요." << endl << endl; break;
		}
	}
}

void Market::manageCategory() {
	char menu;
	while (true) {
		cout << "********** 카테고리관리 **********" << endl;
		cout << "1. 카테고리 추가\n";
		cout << "2. 카테고리 삭제\n";
		cout << "3. 카테고리 이름변경\n";
		cout << "0. 뒤로가기\n";
		cout << "메뉴 : "; cin >> menu;
		cout << endl;

		switch (menu) {
		case '1': addCategory(); break;
		case '2': deleteCategory(); break;
		case '3': renameCategory(); break;
		case '0': return;
		default: cout << "잘못 입력하셨습니다. 다시 입력해주세요." << endl << endl; break;
		}
	}
}

void Market::manageUserInfo() {
	char menu;
	while (true) {
		cout << "********** 회원정보 관리 **********" << endl;
		cout << "1. 회원정보 열람\n";
		cout << "2. 모든 회원정보 열람\n";
		cout << "3. 회원정보 수정\n";
		cout << "4. 회원정보 삭제\n";
		cout << "0. 뒤로가기\n";
		cout << "관리하고 싶은 목록을 선택해주세요: "; cin >> menu;
		cout << endl;

		switch (menu) {
		case'1': viewUserInfo(); break;
		case'2': viewAllInfo(); break;
		case'3': modifyUserInfo(); break;
		case'4': deleteUser(); break;
		case'0': return;
		default: cout << "잘못 입력하셨습니다." << endl; break;
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
		user->setData("manager", "1234", "김동하", "01075444357", 0, 0);
		userHead = userTail = user;
		userSize++;
	}
	else return;
}

void Market::addUserNode() {
	string id, pw, name, phone;

	cout << "********** 회원가입 **********" << endl;
	//ptr로 중복 아이디가 있는지 검사
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
			cout << "중복되는 ID가 있습니다." << endl << endl;
		}
	}
	cout << "축하드립니다. 성공적으로 계정을 생성하였습니다." << endl << endl;
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

	cout << "********** 로그인 **********" << endl;
	while (i != 0) {
		cout << "ID: "; cin >> id;
		cout << "PW: "; cin >> pw;

		if (checkID(id) && checkPW(pw)) {
			UserNode* user = findID(id);
			user->getData()->setLogIn(1);
			cout << "로그인에 성공하였습니다." << endl << endl;
			return user;
		}
		else {
			cout << 6 - i << "번 로그인에 실패하였습니다." << endl;
			cout << i - 1 << "번 로그인을 시도할 수 있습니다." << endl << endl;
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

	cout << "********** 충전하기 **********" << endl;
	cout << "금액: "; cin >> money;
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
	cout << "MONEY: " << money << "원" << endl << endl;
}

void Market::modifyMyInfo(UserNode* user) {
	string id, pw, name, phone;

	cout << "변경할 아이디를 입력하시오: "; cin >> id;
	cout << "변경할 비밀번호를 입력하시오: "; cin >> pw;
	cout << "변경할 이름을 입력하시오: "; cin >> name;
	cout << "변경할 전화번호를 입력하시오: "; cin >> phone;
	cout << endl << endl;

	if (!checkID(id)) {
		user->setData(id, pw, name, phone, user->getData()->getMoney(), 0);
		cout << "개인정보수정이 완료되었습니다. 다시 로그인 해주십시오." << endl << endl;
	}
	else {
		cout << "아이디가 중복됩니다." << endl << endl;
	}
}

void Market::deleteAccount(UserNode* user) {
	char yn;
	cout << "정말 삭제하시겠습니까?(y/n) "; cin >> yn;
	if (yn == 'y' || yn == 'Y') {
		if (user == userTail) {
			userTail = user->getPrev();
			delete user;
			userTail->setNext(NULL);
			userSize--;
			cout << "삭제되었습니다." << endl << endl;
		}
		else {
			user->getPrev()->setNext(user->getNext());
			user->getNext()->setPrev(user->getPrev());
			delete user;
			userSize--;
		}
	}
	else if (yn == 'n' || yn == 'N') {
		cout << "취소하였습니다.";
	}
	else {
		cout << "잘못 입력하셨습니다.";
	}
}

void Market::viewProduct() {
	string name;
	ProductNode* product;
	cout << "찾고싶은 물품 입력하십시오: "; cin >> name;
	if (checkProduct(name)) {
		product = findProduct(name);
		product->show();
	}
	else {
		cout << "존재하지 않는 물품입니다." << endl;
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
	cout << "********** 물품 생성 **********" << endl;

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

				cout << "성공적으로 품목을 생성하였습니다." << endl << endl;
				ctg->getData()->setProductSize(ctg->getData()->getProductSize() + 1);
				break;
			}
			else {
				cout << "이름이 중복됩니다." << endl << endl;
			}
		}
		else { cout << "존재하지 않는 카테고리입니다." << endl << endl; return; }
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
	cout << "********** 물품 삭제 **********" << endl;
	char yn;
	string name;

	cout << "삭제하고싶은 물품을 입력해주세요: "; cin >> name;
	if (checkProduct(name)) {
		cout << "정말 삭제하시겠습니까?(y/n) "; cin >> yn;
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
			cout << "취소하였습니다." << endl << endl;
		}
		else {
			cout << "잘못 입력하셨습니다." << endl << endl;
		}
	}
	else {
		cout << "존재하지 않는 물품입니다." << endl << endl;
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
	cout << "********** 품목 관리 **********" << endl;
	string name;
	char select;
	string pName;
	string pCategory;
	int pPrice;
	int pQuantity;
	ProductNode* product;

	cout << "관리할 물품을 입력해주세요: "; cin >> name;
	if (checkProduct(name)) {
		product = findProduct(name);
		cout << "1. 카테고리\n";
		cout << "2. 이름\n";
		cout << "3. 가격\n";
		cout << "4. 수량\n";
		cout << "5. 뒤로가기\n";
		cout << "관리하고 싶은 목록을 선택해주세요: "; cin >> select;
		cout << endl;

		switch (select) {
		case'1':
			cout << "변경할 카테고리: "; cin >> pCategory;
			product->getData()->setCategory(pCategory);
			break;
		case'2':
			cout << "변경할 이름: "; cin >> pName;
			product->getData()->setName(pName);
			break;
		case'3':
			cout << "변경할 가격: "; cin >> pPrice;
			product->getData()->setPrice(pPrice);
			break;
		case'4':
			cout << "변경할 수량: "; cin >> pQuantity;
			product->getData()->setQuantity(pQuantity);
			break;
		case'5': return;
		default: cout << "잘못입력하셨습니다." << endl << endl; break;
		}
	}
	else {
		cout << "존재하지 않는 물품입니다." << endl << endl; return;
	}
}

void Market::addCategory() {
	string name;

	cout << "********** 카테고리 추가 **********" << endl;

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
			cout << "성공적으로 카테고리를 생성하였습니다." << endl << endl;
			categorySize++;
			break;
		}
		else {
			cout << "이름이 중복됩니다." << endl << endl;
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
	cout << "********** 카테고리 삭제 **********" << endl;
	char yn;
	string name;

	cout << "삭제하고싶은 카테고리 입력해주세요: "; cin >> name;
	if (checkCategory(name)) {
		cout << "정말 삭제하시겠습니까?(y/n) "; cin >> yn;
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
			cout << "카테고리가 삭제되었습니다." << endl << endl;
		}
		else if (yn == 'n' || yn == 'N') {
			cout << "취소하였습니다." << endl << endl;
		}
		else {
			cout << "잘못 입력하셨습니다." << endl << endl;
		}
	}
	else {
		cout << "존재하지 않는 물품입니다." << endl << endl;
	}
}

void Market::renameCategory() {
	cout << "********** 카테고리 이름변경 **********" << endl;
	string name;
	ProductNode* ptr = categoryHead->getProductHead();

	cout << "이름을 변경하고싶은 카테고리 입력해주세요: "; cin >> name;
	if (checkCategory(name)) {
		CategoryNode* category = findCategory(name);
		cout << "변경하실 카테고리의 이름을 입력해주세요: "; cin >> name;
		category->getData()->setCtg(name);
		while (ptr != NULL) {
			ptr->getData()->setCategory(name);
			ptr = ptr->getNext();
		}
		cout << "성공적으로 변경하였습니다." << endl << endl;
	}
	else {
		cout << "존재하지 않는 카테고리입니다." << endl << endl;
	}
}
void Market::viewUserInfo() {
	string id;
	UserNode* user;
	cout << "찾고싶은 ID를 입력하십시오: "; cin >> id;;
	if (checkID(id)) {
		user = findID(id);
		user->show();
	}
	else {
		cout << "존재하지 않는 id입니다." << endl;
	}
	cout << endl;
}

void Market::viewAllInfo() {
	UserNode* user = userHead->getNext();
	if (user == NULL) {
		cout << "회원이 존재하지 않습니다." << endl << endl;
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
	cout << "********** 회원정보 수정 **********" << endl;
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
		cout << "\n수정할 정보를 입력해주세요." << endl << endl;
		cout << "ID: "; cin >> uId;
		cout << "PW: "; cin >> uPw;
		cout << "NAME: "; cin >> uName;
		cout << "PHONE: "; cin >> uPhone;
		if (!checkID(uId)) {
			user->setData(uId, uPw, uName, uPhone);
			cout << "성공적으로 변경하였습니다." << endl << endl;
		}
		else {
			cout << "중복되는 ID가 있습니다." << endl << endl;
		}
	}
	else {
		cout << "존재하지 않는 id입니다." << endl << endl;
	}
}

void Market::deleteUser() {
	cout << "********** 회원 삭제 **********" << endl;
	char yn;
	string id;
	UserNode* user;

	cout << "삭제하고싶은 ID를 입력해주세요: "; cin >> id;
	if (checkID(id)) {
		cout << "정말 삭제하시겠습니까?(y/n) "; cin >> yn;
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
			cout << "취소하였습니다." << endl << endl;
		}
		else {
			cout << "잘못 입력하셨습니다." << endl << endl;
		}
	}
	else {
		cout << "존재하지 않는 ID입니다." << endl << endl;
	}
}

void Market::enterMarket(UserNode* user) {
	CategoryNode* category;
	ProductNode* product;
	int quantity;
	char yn;
	cout << "********** 마켓 **********" << endl;
	while (true) {
		while (true) {
			category = showCategoryList();
			if (category == NULL) return;
			product = showProductList(category);
			if (product != NULL) break;
		}
		while (true) {
			cout << "구매하실 물건의 수량을 입력해주세요: "; cin >> quantity;
			if (user->getData()->getMoney() < product->getData()->getPrice() * quantity) {
				cout << "금액이 부족합니다." << endl;
				cout << "수량을 다시 입력하시겠습니까?(y/n)"; cin >> yn;
				if (yn == 'y' || yn == 'Y') continue;
				else return;
			}
			else if (quantity <= product->getData()->getQuantity() && quantity >= 1) break;
			else cout << "잘못입력하셨습니다." << endl << endl;
		}

		cout << product->getData()->getName() << " " << quantity << "개의 가격은 " << product->getData()->getPrice() * quantity << "원 입니다. 정말 구매하시겠습니까?(y/n) "; cin >> yn; cout << endl << endl;

		while (true) {
			if (yn == 'y' || yn == 'Y') {
				buy(user, product, quantity);
				break;
			}
			else if (yn == 'n' || yn == 'N') {
				cout << "취소하였습니다." << endl << endl;
				break;
			}
			else {
				cout << "잘못입력하였습니다. 다시 입력해주십시오." << endl << endl;
			}
		}
		cout << "다시 마켓으로 돌아가시겠습니까?(y/n) "; cin >> yn; cout << endl;

		while (true) {
			if (yn == 'y' || yn == 'Y') {
				break;
			}
			else if (yn == 'n' || yn == 'N') {
				cout << "메뉴화면으로 돌아갑니다." << endl << endl;
				return;
			}
			else {
				cout << "잘못입력하였습니다. 다시 입력해주십시오." << endl << endl;
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
		cout << "0. 종료" << endl;
		cout << endl;
		while (true) {
			cout << "구매하실 물건의 카테고리 번호를 골라주세요: "; cin >> menu;
			cout << endl;
			if (menu <= getCategorySize() && menu >= 0) break;
			else cout << "잘못입력하셨습니다." << endl << endl;
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
	cout << "0. 뒤로가기";
	cout << endl;

	while (true) {
		cout << "구매하실 물건을 골라주세요: "; cin >> menu;
		cout << endl;
		if (menu <= getProductSize(category) && menu >= 0) break;
		else cout << "잘못입력하셨습니다." << endl << endl;
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
		cout << "거래를 완료하였습니다. 현재 남은 잔액은 " << user->getData()->getMoney() << "원 입니다." << endl << endl;
	}
	else cout << "잔액이 부족합니다." << endl << endl;
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
