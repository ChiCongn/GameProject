
#pragma once

#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H
#include"Common.h"
#include"Animation.h"

class BaseObject {
protected:
	int speed;
	SDL_Rect coordinates;
	Animation* animation;

public:
	BaseObject();
	virtual ~BaseObject();
	void setCoordinates(int _x, int _y) { coordinates.x = _x, coordinates.y = _y; }
	SDL_Rect getCoordinates() { return coordinates; }
};

#endif