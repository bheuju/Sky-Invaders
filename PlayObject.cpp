#include "PlayObject.h"
#include "ImageHandler.h"

//int PlayObject::xspeed = 0;
//int PlayObject::yspeed = 3;

PlayObject::PlayObject(std::string id, int x, int y, int w, int h, int frame, int row)
{
	texID = id;
	mx = x;
	my = y;
	mw = w;
	mh = h;
	xspeed = 0;
	yspeed = 2;
	mframe = frame;
	mrow = row;
}

void PlayObject::update()
{
	mx += xspeed;
	my += yspeed;
}

void PlayObject::render()
{
	ImageHandler::Instance()->draw(mx, my, mw, mh, texID, mframe, mrow);
}