#include "State.h"

EngineOff::EngineOff(Scooter* s)
{
	_S = s;
}

std::string EngineOff::ToString()
{
	return "Engine Off";
}

void EngineOff::UseKey()
{
	std::cout << "Key off!!!\n";
	_S->setState(_S->GetKeyOff());
}

void EngineOff::StartButton()
{
	_S->setState(_S->GetEngineOn());
	std::cout << "Engine is starting!!!\n";
	std::cout << "Engine started!!!\n";
}

void EngineOff::ThrottleHandle()
{
	std::cout << "Engine is off, nothing happen!!!\n";
}

void EngineOff::Brake()
{
	std::cout << "Engine is off, nothing happen!!!\n";
}

EngineOn::EngineOn(Scooter* s)
{
	_S = s;
}

std::string EngineOn::ToString()
{
	return "Engine On";
}

void EngineOn::UseKey()
{
	_S->setState(_S->GetKeyOff());
	std::cout << "Key off!!!\n";
}

void EngineOn::StartButton()
{
	std::cout << "Engine is already on, nothing happen!!!\n";
}

void EngineOn::ThrottleHandle()
{
	_S->setState(_S->GetRunning());
	std::cout << "Scooter start running!!!\n";
	std::cout << "Scooter running!!!\n";
}

void EngineOn::Brake()
{
	std::cout << "Scooter is not running, nothing happen!!!\n";
}

Running::Running(Scooter* s)
{
	_S = s;
}

std::string Running::ToString()
{
	return "Running";
}

void Running::UseKey()
{
	std::cout << "Scooter is running, Key locked!!!\n";
}

void Running::StartButton()
{
	std::cout << "Scooter is running, Nothing happen!!!\n";
}

void Running::ThrottleHandle()
{
	std::cout << "Scooter runs faster!!!\n";
}

void Running::Brake()
{
	std::cout << "Scooter slows down!!!\n";
	_S->setState(_S->GetEngineOn());
}

KeyOff::KeyOff(Scooter* s)
{
	_S = s;
}

std::string KeyOff::ToString()
{
	return "Key off";
}

void KeyOff::UseKey()
{
	std::cout << "Key on!!!\n";
	_S->setState(_S->GetEngineOff());
}

void KeyOff::StartButton()
{
	std::cout << "Key is off, can't start the engine!!!\n";
}

void KeyOff::ThrottleHandle()
{
	std::cout << "Key is off, nothing happen!!!\n";
}

void KeyOff::Brake()
{
	std::cout << "Key is off, nothing happen!!!\n";
}
