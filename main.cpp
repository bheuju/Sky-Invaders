#include "Game.h"
#include <ctime>

int main(int argc, char** argv)
{
	srand(time(NULL));

	Game::Instance()->init();

	int delay = 1000/30;

	while (Game::Instance()->running())
	{
		Uint32 start = SDL_GetTicks();

		Game::Instance()->genRandom();
		Game::Instance()->update();
		Game::Instance()->handleEvents();
		Game::Instance()->render();

		if ((SDL_GetTicks()-start) < delay )
		{
			SDL_Delay(int (delay - (SDL_GetTicks()-start)));
		}

	}

	Game::Instance()->clean();
	return 0;
}