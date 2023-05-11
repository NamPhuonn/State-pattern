#pragma once
#include "State.h"
#include <string>

class State;
class Scooter
{
private:
	State* _keyOff;
	State* _engineOff;
	State* _engineOn;
	State* _running;

	State* _state;
public:
	Scooter();

	std::string ToString();

	void UseKey();
	void StartButton();
	void ThrottleHandle();
	void Brake();

	State* GetKeyOff() const;
	State* GetEngineOff() const;
	State* GetEngineOn() const;
	State* GetRunning() const;

	void setState(State* s);

};


