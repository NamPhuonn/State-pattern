#pragma once
#ifndef STATE_H
#define STATE_H

#include<iostream>
using namespace std;

class StateMachine;
class State {
public:
	virtual void paySuccess() = 0;
	virtual void payFailed() = 0;
	virtual void receiveProduct() = 0;
	virtual string toString() = 0;
};

class OrderState : public State {
private: 
	StateMachine* s;
public:
	OrderState(StateMachine* s);
	void paySuccess();
	void payFailed();
	void receiveProduct();
	string toString();
};

class TransactionState : public State {
private:
	StateMachine* s;
public:
	TransactionState(StateMachine* s);
	void paySuccess();
	void payFailed();
	void receiveProduct();
	string toString();
};

class ReceiveState : public State {
private:
	StateMachine* s;
public:
	ReceiveState(StateMachine* s);
	void paySuccess();
	void payFailed();
	void receiveProduct();
	string toString();
};

#endif