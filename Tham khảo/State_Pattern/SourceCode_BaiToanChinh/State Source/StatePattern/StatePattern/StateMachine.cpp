#include "State.h"
#include "StateMachine.h"

StateMachine::StateMachine()
{
	orderState = new OrderState(this);
	transactionState = new TransactionState(this);
	receiveState = new ReceiveState(this);

	//default state
	currentState = orderState;
}

void StateMachine::paySuccess()
{
	currentState->paySuccess();
}

void StateMachine::payFailed()
{
	currentState->payFailed();
}

void StateMachine::receiveProduct()
{
	currentState->receiveProduct();
}

State* StateMachine::getOrderState() const
{
	return orderState;
}

State* StateMachine::getReceiveState() const
{
	return receiveState;
}

State* StateMachine::getTransactionState() const
{
	return transactionState;
}

void StateMachine::setState(State* s)
{
	currentState = s;
}

string StateMachine::getState()
{
	return currentState->toString();
}
