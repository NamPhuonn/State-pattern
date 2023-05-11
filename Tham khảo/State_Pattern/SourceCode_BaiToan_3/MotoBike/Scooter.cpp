#include "Scooter.h"
#include "State.h"

Scooter::Scooter()
{
	_keyOff = new KeyOff(this);
	_engineOff = new EngineOff(this);
	_engineOn = new EngineOn(this);
	_running = new Running(this);

	_state = _keyOff;
}

std::string Scooter::ToString()
{
	return	"Scooter is in "+_state->ToString()+" state!!!\n";
}

void Scooter::UseKey()
{
	std::cout << "Use key.\n";
	_state->UseKey();
}

void Scooter::StartButton()
{
	std::cout << "Use start button.\n";
	_state->StartButton();
}

void Scooter::ThrottleHandle()
{
	std::cout << "Use throttle handle.\n";
	_state->ThrottleHandle();
}

void Scooter::Brake()
{
	std::cout << "Use brake.\n";
	_state->Brake();
}

State* Scooter::GetKeyOff() const
{
	return _keyOff;
}

State* Scooter::GetEngineOff() const
{
	return _engineOff;
}

State* Scooter::GetEngineOn() const
{
	return _engineOn;
}

State* Scooter::GetRunning() const
{
	return _running;
}

void Scooter::setState(State* s)
{
	_state = s;
}
