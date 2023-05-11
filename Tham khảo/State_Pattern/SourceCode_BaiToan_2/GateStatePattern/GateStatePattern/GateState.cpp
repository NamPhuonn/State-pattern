#include "Gate.h"
#include "GateState.h"

CloseState::CloseState(Gate* s)
{
	state = s;
}

void CloseState::CheckIDSuccessed()
{
	cout << "Closed gate, can't check your ID card!\n";
}

void CloseState::CheckIDFailed()
{
	cout << "Closed gate, can't check your ID card!\n";
}

void CloseState::Enter()
{
	cout << "Closed gate, can't pass!\n";
}

void CloseState::SwipingCard()
{
	cout << "Let's swipe your card!\n";
	state->SetState(state->GetSwipeState());
}

string CloseState::GateName()
{
	return "Close state";
}

OpenState::OpenState(Gate* s)
{
	state = s;
}

void OpenState::CheckIDSuccessed()
{
	cout << "There isn't any swiped card!\n";
}

void OpenState::CheckIDFailed()
{
	cout << "There isn't any swiped card!\n";
}

void OpenState::Enter()
{
	cout << "Entered the gate!\n";
	state->SetState(state->GetCloseState());
}

void OpenState::SwipingCard()
{
	cout << "There isn't any swiped card!\n";
}

string OpenState::GateName()
{
	return "Open State";
}

ProcessState::ProcessState(Gate* s)
{
	state = s;
}

void ProcessState::CheckIDSuccessed()
{
	cout << "ID check successful! Opened Gate\n";
	state->SetState(state->GetOpenState());
}

void ProcessState::CheckIDFailed()
{
	cout << "ID check failed! Still closed Gate (please check the card before swiping)\n";
	state->SetState(state->GetCloseState());
}

void ProcessState::Enter()
{
	cout << "Waiting! Your ID is still being checked!\n";
}

void ProcessState::SwipingCard()
{
	cout << "Waiting! The previous swiping card is being checked\n";
}

string ProcessState::GateName()
{
	return "Process State";
}