#pragma once

#include <iostream>
using namespace std;

class Gate;
class GateState {
public:
	virtual void CheckIDSuccessed() = 0;
	virtual void CheckIDFailed() = 0;
	virtual void Enter() = 0;
	virtual void SwipingCard() = 0;
	virtual string GateName() = 0;
};

class CloseState : public GateState {
private:
	Gate* state;
public:
	CloseState(Gate* s);
	void CheckIDSuccessed();
	void CheckIDFailed();
	void Enter();
	void SwipingCard();
	string GateName();
};

class OpenState : public GateState {
private:
	Gate* state;
public:
	OpenState(Gate* s);
	void CheckIDSuccessed();
	void CheckIDFailed();
	void Enter();
	void SwipingCard();
	string GateName();
};

class ProcessState : public GateState {
private:
	Gate* state;
public:
	ProcessState(Gate* s);
	void CheckIDSuccessed();
	void CheckIDFailed();
	void Enter();
	void SwipingCard();
	string GateName();
};