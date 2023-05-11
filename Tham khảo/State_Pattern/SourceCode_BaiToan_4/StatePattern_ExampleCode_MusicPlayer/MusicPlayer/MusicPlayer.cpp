#include "MusicPlayer.h"
#include "MusicPlayerState.h"


MusicPlayer::MusicPlayer()
{
	pausedState = new PausedState(this);
	playingState = new PlayingState(this);
	stoppedState = new StoppedState(this);

	currentState = stoppedState;
}

void MusicPlayer::Play()
{
	currentState->Play();
}

void MusicPlayer::Pause()
{
	currentState->Pause();
}

void MusicPlayer::Stop()
{
	currentState->Stop();
}

MusicPlayerState* MusicPlayer::getPausedState() const
{
	return pausedState;
}

MusicPlayerState* MusicPlayer::getPlayingState() const
{
	return playingState;
}

MusicPlayerState* MusicPlayer::getStoppedState() const
{
	return stoppedState;
}

void MusicPlayer::setState(MusicPlayerState* player)
{
	currentState = player;
}

string MusicPlayer::getState()
{
	return currentState->toString();
}


