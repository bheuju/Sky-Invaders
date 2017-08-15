#pragma once
#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "ImageHandler.h"
#include "PlayObject.h"
#include "InvadersObject.h"
#include "TextManager.h"
#include <sstream>

class Game
{
public:
	static Game* Instance()		//Making a singleton
	{
		if (pInstance == 0)
		{
			pInstance = new Game;
		}
		return pInstance;
	}

	void init();
	void update();
	void render();
	void handleEvents();
	void clean();

	void genRandom();
	void keypress();
	void check(int n);

	void quit()
	{
		isRunning = false;
	}

	bool running()
	{
		return isRunning;
	}

	SDL_Renderer* getRenderer()
	{
		return ren;
	}

	int getScore()
	{
		return score;
	}

private:
	Game(){}
	static Game* pInstance;

	SDL_Window* win;
	SDL_Renderer* ren;
	SDL_Event event;

	bool isRunning;
	static int flag;
	static int delay;

	static int total;
	static int score;
	static int ch;

	//TextManager* TX1;
	//TextManager* TX2;

	std::vector <PlayObject*> GOs;
	
};

