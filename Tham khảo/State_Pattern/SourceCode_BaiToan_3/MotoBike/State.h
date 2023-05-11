#pragma once
#include "Scooter.h"
#include <iostream>
#include <string>

class Scooter;
class State
{
private:

public:

	virtual std::string ToString() = 0;

	virtual void UseKey() = 0;
	virtual void StartButton() = 0;
	virtual void ThrottleHandle() = 0;
	virtual void Brake() = 0;
};

class EngineOff :
	public State
{
private:
	Scooter *_S;

public:

	EngineOff(Scooter* s);

	std::string ToString();

	void UseKey();
	void StartButton();
	void ThrottleHandle();
	void Brake();

};

class EngineOn :
	public State
{
private:
	Scooter* _S;

public:

	EngineOn(Scooter* s);

	std::string ToString();

	void UseKey();
	void StartButton();
	void ThrottleHandle();
	void Brake();

};

class Running :
	public State
{
private:
	Scooter* _S;

public:

	Running(Scooter* s);

	std::string ToString();

	void UseKey();
	void StartButton();
	void ThrottleHandle();
	void Brake();

};

class KeyOff :
	public State
{
private:
	Scooter* _S;

public:

	KeyOff(Scooter* s);

	std::string ToString();

	void UseKey();
	void StartButton();
	void ThrottleHandle();
	void Brake();

};


