#include "ImageHandler.h"
#include "Game.h"

ImageHandler* ImageHandler::pInstance = 0;

void ImageHandler::load(std::string fileName, std::string id)
{
	tex = IMG_LoadTexture(Game::Instance()->getRenderer(), fileName.c_str());
	texMap[id] = tex;
}

void ImageHandler::draw(int x, int y, int w, int h, std::string id, int frame, int row)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	//SDL_QueryTexture(texMap[id], 0, 0, &srcRect.w, &srcRect.h);

	srcRect.x = frame * 70;
	srcRect.y = row * 150;
	srcRect.w = w;	//70
	srcRect.h = h;	//150

	destRect.x = x;
	destRect.y = y;
	destRect.w = w;
	destRect.h = h;
	//if (ch != 0)
	//{
	//	TextDisplay::Instance()->load(ch);
	//}
	SDL_RenderCopyEx(Game::Instance()->getRenderer(), texMap[id], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}
