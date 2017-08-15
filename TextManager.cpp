#include "TextManager.h"
#include "Game.h"
#include <cstring>

TextManager* TextManager::pInstance = 0;

void TextManager::load(std::string text, std::string id)
{
	font = TTF_OpenFont("fonts/SourceSansPro-Black.ttf", 30);
	SDL_Color color = {255, 255, 255};

	surf = TTF_RenderText_Blended(font, text.c_str(), color);
	tex = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), surf);
	texMap[id] = tex;

	SDL_FreeSurface(surf);
}

void TextManager::update()
{

}

void TextManager::draw(int x, int y, std::string id)
{
	//surf = TTF_RenderText_Solid(font, ch, color);
	//tex = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), surf);

	//SDL_FreeSurface(surf);

	SDL_Renderer* ren = Game::Instance()->getRenderer();
	SDL_Rect srcRect;
	SDL_Rect destRect;

	SDL_QueryTexture(tex, 0, 0, &srcRect.w, &srcRect.h);

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	destRect.x = x;
	destRect.y = y;
	
	//SDL_RenderDrawRect(ren, &destRect);
	//SDL_RenderFillRect(ren, &destRect);
	SDL_RenderCopy(ren, texMap[id], 0, &destRect);
}
