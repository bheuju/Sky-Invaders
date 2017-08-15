#include "InvadersObject.h"
#include "Game.h"

InvadersObject::InvadersObject(std::string id, int x, int y, int w, int h, int frame, int row) : PlayObject (id, x, y, w, h, frame, row)
{
	count = 0;
	deletable = true;
}

void InvadersObject::update()
{
	check();
	PlayObject::update();
}

void InvadersObject::render()
{
	PlayObject::render();
}

void InvadersObject::check()
{
	if (Game::Instance()->getScore() > 10)
	{
		yspeed = 5;
	}
	if (my > 450)
	{
		yspeed = 0;
		mframe = 1;
		count = 1;
		deletable = false;
	}
}
