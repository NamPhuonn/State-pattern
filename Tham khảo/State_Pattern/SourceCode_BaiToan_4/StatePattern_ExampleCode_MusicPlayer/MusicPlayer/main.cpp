#include "MusicPlayer.h"

int main()
{
	MusicPlayer* player = new MusicPlayer;

	player->Play();
	cout << "State: " << player->getState() << endl;
	cout << "\n-----------\n";

	player->Pause();
	cout << "State: " << player->getState() << endl;
	cout << "\n-----------\n";

	player->Stop();
	player->Stop();
	cout << "State: " << player->getState() << endl;
	cout << "\n-----------\n";

	return 0;
}