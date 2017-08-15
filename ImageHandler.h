#pragma once
#include "SDL_image.h"
#include <iostream>
#include <string>			//Standard Template Library
#include <map>				//Standard Template Library
#include <vector>			//Standard Template Library

class ImageHandler
{
public:
	static ImageHandler* Instance()
	{
		if(pInstance == 0)
		{
			pInstance = new ImageHandler;
		}
		return pInstance;
	}
	void load(std::string fileName, std::string id);
	void draw(int x, int y, int w, int h, std::string id, int frame, int row);

private:
	ImageHandler(){}
	static ImageHandler* pInstance;
	SDL_Texture* tex;
	std::map<std::string, SDL_Texture*> texMap;
};

