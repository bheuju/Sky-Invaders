#pragma once
#include "SDL_ttf.h"
#include <string>
#include <map>

class TextManager
{
public:
	static TextManager* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new TextManager;
		}
		return pInstance;
	}

	void load(std::string text, std::string id);
	void draw(int x, int y, std::string id);
	void update();

private:
	static TextManager* pInstance;

	TTF_Font* font;

	SDL_Surface* surf;
	SDL_Texture* tex;

	std::map<std::string, SDL_Texture*> texMap;
};

