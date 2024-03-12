#pragma once
#ifndef BASEOBJECT_H
#define BSEOBJECT_H
#include"Common.h"

const bool DIRECTON_LEFT = true;
const bool DIRECTION_RIGHT = false;

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
	virtual void render(SDL_Renderer* renderer);
};


#endif