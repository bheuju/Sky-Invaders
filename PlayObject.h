#pragma once
#include <iostream>
#include <string>

class PlayObject
{
public:
	PlayObject(std::string id, int x, int y, int w, int h, int frame, int row);
	
	virtual void update();
	virtual void render();

	virtual int getCount(){return 0;}
	virtual int getRow(){return 0;}
	virtual bool canDelete(){return 0;}

protected:
	int mx, my;
	int mw, mh;
	int mframe, mrow;
	std::string texID;
	bool deletable;
	int xspeed, yspeed;

};

