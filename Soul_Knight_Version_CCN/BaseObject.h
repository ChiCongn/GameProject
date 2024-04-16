
#pragma once

#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H
#include"Common.h"
#include"AnimatedSprite.h"

class BaseObject {
protected:
	int speed;
	SDL_Rect coordinates;
	AnimatedSprite* sprite;

public:
	BaseObject();
	virtual ~BaseObject();
	void setCoordinates(int _x, int _y) { coordinates.x = _x, coordinates.y = _y; }
	SDL_Rect getCoordinates() { return coordinates; }
};

#endif