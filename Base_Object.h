#pragma once

#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include"Common.h"

class baseObject 
{
protected:
	SDL_Rect coordinate;
	SDL_Texture* texture_;

public:
	baseObject();
	~baseObject();
	void setCoordinate(int x, int y) { coordinate.x = x; coordinate.y = y; }
	SDL_Rect getCoordinate() const { return coordinate; }
};

#endif