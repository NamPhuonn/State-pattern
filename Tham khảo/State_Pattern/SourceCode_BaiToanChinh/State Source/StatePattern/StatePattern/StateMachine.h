#pragma once
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include<iostream>
using namespace std;

class State;
class StateMachine {
private:
	State* orderState;
	State* receiveState;
	State* transactionState;
	State* currentState;
public:
	StateMachine();

	void paySuccess();
	void payFailed();
	void receiveProduct();

	State* getOrderState() const;
	State* getReceiveState() const;
	State* getTransactionState() const;

	void setState(State* s);
	string getState();
};
#endif 
