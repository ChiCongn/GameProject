
#pragma once

#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H
#include"Common.h"

class BaseObject {
protected:
	int speed;
	SDL_Rect coordinates;
	SDL_Texture* texture;

public:
	BaseObject();
	~BaseObject();
	void setSize(int _x, int _y) { coordinates.x = _x, coordinates.y = _y; }
	SDL_Rect getCoordinates() { return coordinates; }
	virtual void render(SDL_Renderer* renderer);
};

#endif