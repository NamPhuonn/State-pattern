#include "MusicPlayerState.h"
#include "MusicPlayer.h"


PausedState::PausedState(MusicPlayer* player)
{
	this->player = player;
}

void PausedState::Play()
{
	cout << "Bat nhac\n";
	MusicPlayerState* nextState = player->getPlayingState();
	player->setState(nextState);
}

void PausedState::Pause()
{
	cout << "Ban hien dang trong trang thai dung\n";
}

void PausedState::Stop()
{
	cout << "Tat nhac\n";
	MusicPlayerState* nextState = player->getStoppedState();
	player->setState(nextState);
}

string PausedState::toString()
{
	return "PausedState";
}

PlayingState::PlayingState(MusicPlayer* player)
{
	this->player = player;
}

void PlayingState::Play()
{
	cout << "Ban hien dang trong trang thai mo nhac\n";
}

void PlayingState::Pause()
{
	cout << "Dung lai\n";
	MusicPlayerState* nextState = player->getPausedState();
	player->setState(nextState);
}

void PlayingState::Stop()
{
	cout << "Tat nhac\n";
	MusicPlayerState* nextState = player->getStoppedState();
	player->setState(nextState);
}

string PlayingState::toString()
{
	return "PlayingState";
}

StoppedState::StoppedState(MusicPlayer* player)
{
	this->player = player;
}

void StoppedState::Play()
{
	cout << "Bat nhac\n";
	MusicPlayerState* nextState = player->getPlayingState();
	player->setState(nextState);
}

void StoppedState::Pause()
{
	cout << "May da tat khong the thuc hien thao tac dung lai\n";
}

void StoppedState::Stop()
{
	cout << "May nghe nhac da duoc tat\n";
}

string StoppedState::toString()
{
	return "StoppedState";
}
