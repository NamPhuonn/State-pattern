#pragma once
#include<iostream>
using namespace std;

class GateState;
class Gate {
private:
	GateState* closeState;
	GateState* swipeState;
	GateState* openState;
	GateState* currentState;
public:
	Gate();

	void CheckIDSuccessed();
	void CheckIDFailed();
	void Enter();
	void SwipingCard();
	string GateName();

	void SetState(GateState* s);
	GateState* GetCloseState() const;
	GateState* GetSwipeState() const;
	GateState* GetOpenState() const;

};
