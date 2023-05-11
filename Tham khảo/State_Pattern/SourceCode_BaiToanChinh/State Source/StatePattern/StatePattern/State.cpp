#include "StateMachine.h"
#include "State.h"

OrderState::OrderState(StateMachine* s)
{
	this->s = s;
}

void OrderState::paySuccess()
{
	cout << "Viec thanh toan cua ban dang trong qua trinh kiem tra\n";
	State* nextState = s->getTransactionState();
	s->setState(nextState);
}

void OrderState::payFailed()
{
	cout << "Viec thanh toan cua ban da that bai\n";
}

void OrderState::receiveProduct()
{
	cout << "Ban khong the nhan duoc san pham khi dang o trang thai dat hang\n";
}

string OrderState::toString()
{
	return "OrderState";
}

TransactionState::TransactionState(StateMachine* s)
{
	this->s = s;
}

void TransactionState::paySuccess()
{
	cout << "Ban da thanh toan thanh cong\n";
	State* nextState = s->getReceiveState();
	s->setState(nextState);
}

void TransactionState::payFailed()
{
	cout << "Thanh toan that bai, hay thuc hien thanh toan lai\n";
	State* nextState = s->getOrderState();
	s->setState(nextState);
}

void TransactionState::receiveProduct()
{
	cout << "Dang thuc hien chuyen khoang, vui long doi xac nhan thanh cong\n";
}

string TransactionState::toString()
{
	return "TransactionState";
}

ReceiveState::ReceiveState(StateMachine* s)
{
	this->s = s;
}

void ReceiveState::paySuccess()
{
	cout << "Ban khong the thuc hien thanh toan, hien tai khong co don hang nao\n";
}

void ReceiveState::payFailed()
{
	cout << "Ban khong the thuc hien thanh toan, hien tai khong co don hang nao\n";
}

void ReceiveState::receiveProduct()
{
	cout << "Ban da nhan duoc hang, hay dat hang...\n";
	State* nextState = s->getOrderState();
	s->setState(nextState);
}

string ReceiveState::toString()
{
	return "ReceiveState";
}
