#pragma once
#include "PlayObject.h"

class InvadersObject : public PlayObject
{
public:
	InvadersObject(std::string id, int x, int y, int w, int h, int frame, int row);

	void update();
	void render();

	void check();

	int getX(){return mx;}
	int getY(){return my;}
	int getRow(){return mrow;}
	int getCount(){return count;}

	bool canDelete(){return deletable;}

private:
	int count;
};

