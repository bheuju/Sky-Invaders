#include "Game.h"

Game* Game::pInstance = new Game;
int Game::flag = 0;
int Game::total = 0;
int Game::score = 0;
int Game::delay = 7;
int Game::ch = 0;

void Game::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	win = SDL_CreateWindow("Sky Invaders", 30, 30, 1280, 680, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(ren, 255, 255, 100, 255);

	TTF_Init();

	ImageHandler::Instance()->load("img/background.jpg", "bg");
	ImageHandler::Instance()->load("img/cover.png", "cover");
	ImageHandler::Instance()->load("img/soldier2.png", "enemy");

	std::stringstream ss2;						//converting int to std::string type
	ss2 <<" Score: "<<score<<"   ";				//copied from www.cplusplus.com
	TextManager::Instance()->load(ss2.str(), "score");

	std::cout<<"Initialized Succesfully...\n";
	isRunning = true;
}

void Game::genRandom()
{
	if (ch == 1)
	{
		int random = rand() % 13;
		//std::cout<<random<<std::endl;

		int time = (SDL_GetTicks() / 100) % delay;		//sets delay by number after % (i.e. delay*100 ms in this case)

		if (time == 0 && flag == 1)
		{
			int n = rand() % 26;
			GOs.push_back(new InvadersObject("enemy", 100 * random, 10, 70, 150, 0, n));
			flag = 0;
		}
		else if (time > 0)
		{
			flag = 1;
		}
	}
}

void Game::update()
{
	if (ch == 1)
	{
		for (int i = 0; i< GOs.size(); i++)
		{
			total += GOs[i]->getCount();
			//std::cout<<"Count = "<<GOs[i]->getCount()<<"\n";
		}
		//std::cout<<"Total = "<<total<<"\n";

		std::stringstream ss1;		//converting int to std::string type
		ss1 <<"Escaped: "<<total<<"  Score: "<<score;				//copied from www.cplusplus.com
		TextManager::Instance()->load(ss1.str(), "kill");

		if (total == 10)
		{isRunning = false;}
		else
		{total = 0;}

		for (int i = 0; i < GOs.size(); i++)
		{
			GOs[i]->update();
		}
	}
}

void Game::render()
{


	SDL_RenderClear(ren);		//clear screen to set render clear color
	if (ch == 0)
	{
		ImageHandler::Instance()->draw(0, 0, 1280, 680, "cover", 0, 0);
	}
	else if (ch == 1)
	{
		ImageHandler::Instance()->draw(0, 0, 1280, 680, "bg", 0, 0);
		TextManager::Instance()->draw(700, 10, "kill");
		//TextManager::Instance()->draw(800, 80, "score");

		for (int i = 0; i < GOs.size(); i++)
		{
			GOs[i]->render();
		}
	}
	SDL_RenderPresent(ren);		//show to window
}

void Game::handleEvents()
{
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_KEYDOWN:
			keypress();
			break;

		default:
			break;
		}
	}
}

void Game::clean()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	SDL_Delay(500);
}

void Game::keypress()
{
	int n = 28;
	switch(event.key.keysym.sym)
	{
	case SDLK_RETURN:
		ch = 1;
		break;
	case SDLK_a:
		n = 0;
		break;
	case SDLK_b:
		n = 1;
		break;
	case SDLK_c:
		n = 2;
		break;
	case SDLK_d:
		n = 3;
		break;
	case SDLK_e:
		n = 4;
		break;
	case SDLK_f:
		n = 5;
		break;
	case SDLK_g:
		n = 6;
		break;
	case SDLK_h:
		n = 7;
		break;
	case SDLK_i:
		n = 8;
		break;
	case SDLK_j:
		n = 9;
		break;
	case SDLK_k:
		n = 10;
		break;
	case SDLK_l:
		n = 11;
		break;
	case SDLK_m:
		n = 12;
		break;
	case SDLK_n:
		n = 13;
		break;
	case SDLK_o:
		n = 14;
		break;
	case SDLK_p:
		n = 15;
		break;
	case SDLK_q:
		n = 16;
		break;
	case SDLK_r:
		n = 17;
		break;
	case SDLK_s:
		n = 18;
		break;
	case SDLK_t:
		n = 19;
		break;
	case SDLK_u:
		n = 20;
		break;
	case SDLK_v:
		n = 21;
		break;
	case SDLK_w:
		n = 22;
		break;
	case SDLK_x:
		n = 23;
		break;
	case SDLK_y:
		n = 24;
		break;
	case SDLK_z:
		n = 25;
		break;
	default:
		break;

	}
	check(n);
}

void Game::check(int n)
{
	for (int i = 0; i < GOs.size(); i++)
	{
		if (GOs[i]->getRow() == n && GOs[i]->canDelete())
		{
			GOs.erase(GOs.begin() + i);
			//std::cout<<"Deleted";
			score += 1;

			//std::cout<<score<<std::endl;
		}
	}
}
