#ifndef MUSICPLAYERSTATE_H_
#define MUSICPLAYERSTATE_H_
#include <iostream>
#include <string>
using namespace std;

class MusicPlayer;
class MusicPlayerState {
public:
	virtual void Play() = 0;
	virtual void Pause() = 0;
	virtual void Stop() = 0;
	virtual string toString() = 0;
};


class PausedState : public MusicPlayerState {
private:
	MusicPlayer* player;
public:
	PausedState(MusicPlayer* player);
	void Play();
	void Pause();
	void Stop();
	string toString();
};

class PlayingState : public MusicPlayerState {
private:
	MusicPlayer* player;
public:
	PlayingState(MusicPlayer* player);
	void Play();
	void Pause();
	void Stop();
	string toString();
};

class StoppedState : public MusicPlayerState {
private:
	MusicPlayer* player;
public:
	StoppedState(MusicPlayer* player);
	void Play();
	void Pause();
	void Stop();
	string toString();
};

#endif /* MUSICPLAYERSTATE_H_ */