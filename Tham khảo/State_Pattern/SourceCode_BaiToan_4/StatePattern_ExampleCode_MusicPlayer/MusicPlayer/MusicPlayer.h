#ifndef MUSICPLAYER_H_
#define MUSICPLAYER_H_
#include <iostream>
#include <string>
using namespace std;

class MusicPlayerState;
class MusicPlayer {
private:
	MusicPlayerState* pausedState;
	MusicPlayerState* playingState;
	MusicPlayerState* stoppedState;
	MusicPlayerState* currentState;
public:
	MusicPlayer();

	void Play();
	void Pause();
	void Stop();

	MusicPlayerState* getPausedState() const;
	MusicPlayerState* getPlayingState() const;
	MusicPlayerState* getStoppedState() const;

	void setState(MusicPlayerState* player);
	string getState();
};

#endif /* MUSICPLAYER_H_ */