#pragma once
#ifndef THREAT_OBJECT_H
#define THREAT_OBJECT_H

#include"Common.h"
#include"Base_Object.h"

#define WIDTH_THREAT 200
#define HEIGHT_THREAT 150


class threatObject : public baseObject
{
public:
	int speed_;
	threatObject();
	~threatObject();

	void setSpeed(int speed) { speed_ = speed; }
	void show();
	void moveThreat(SDL_Rect rect);
};


#endif THREAT_OBJECT_H