#include"Header.h"


DummyState::DummyState() {
	state = ORDER;
}
void DummyState::paySuccess() {
	if (state == ORDER) {
		cout << "Viec thanh toan cua ban dang trong qua trinh kiem tra\n";
		state = TRANSACTION;
	}
	else if (state == RECIEVE) {
		cout << "Ban khong the thuc hien thanh toan, hien tai khong co don hang nao\n";
	}
	else if (state == TRANSACTION) {
		cout << "Ban da thanh toan thanh cong\n";
		state = RECIEVE;
	}
}
void  DummyState::payFailed() {
	if (state == ORDER) {
		cout << "Viec thanh toan cua ban da that bai\n";
	}
	else if (state == RECIEVE) {
		cout << "Ban khong the thuc hien thanh toan, hien tai khong co don hang nao\n";
	}
	else if (state == TRANSACTION) {
		cout << "Thanh toan that bai, hay thuc hien thanh toan lai\n";
		state = ORDER;
	}
}
void  DummyState::receiveProduct() {
	if (state == ORDER) {
		cout << "Ban khong the nhan duoc san pham khi dang o trang thai dat hang\n";
	}
	else if (state == RECIEVE) {
		cout << "Ban da nhan duoc hang, hay dat hang...\n";
		state = ORDER;
	}
	else if (state == TRANSACTION) {
		cout << "Dang thuc hien chuyen khoang, vui long doi xac nhan thanh cong\n";
	}
}

string DummyState::getState()
{
	return state;
}
s