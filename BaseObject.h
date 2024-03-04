#pragma once
#ifndef BASEOBJECT_H
#define BSEOBJECT_H
#include"Common.h"


class BaseObject {
protected:
	SDL_Rect coordinates;
	SDL_Texture* texture;
	int speed;

public:
	BaseObject();
	~BaseObject();
	void setCoordinates(int _x, int _y) { coordinates.x = _x, coordinates.y = _y; }
	SDL_Rect getCoordinates() { return coordinates; }
	void setSpeed(int _speed) { speed = _speed; }
	void render(SDL_Renderer* renderer);
};


#endif