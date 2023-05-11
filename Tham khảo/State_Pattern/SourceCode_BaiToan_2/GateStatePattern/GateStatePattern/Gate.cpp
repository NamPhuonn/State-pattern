#include "GateState.h"
#include "Gate.h"

Gate::Gate()
{
	closeState = new CloseState(this);
	openState = new OpenState(this);
	swipeState = new ProcessState(this);
	currentState = closeState;
}

void Gate::CheckIDSuccessed()
{
	currentState->CheckIDSuccessed();
}

void Gate::CheckIDFailed()
{
	currentState->CheckIDFailed();
}

void Gate::Enter()
{
	currentState->Enter();
}

void Gate::SwipingCard()
{
	currentState->SwipingCard();
}

GateState* Gate::GetCloseState() const
{
	return closeState;
}

GateState* Gate::GetSwipeState() const
{
	return swipeState;
}

GateState* Gate::GetOpenState() const
{
	return openState;
}

void Gate::SetState(GateState* s)
{
	currentState = s;
}

string Gate::GateName()
{
	return currentState->GateName();
}
