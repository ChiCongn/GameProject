#pragma once
#include"BaseObject.h"

#ifndef SKILLSOBJECT_H
#define SKILLSOBJECT_H

const int BULLET_WIDTH = 10;
const int BULLET_HEIGHT = 10;
const int ROCKET_WIDTH = 20;
const int ROCKET_HEIGHT = 30;
const int BULLET = 10;
const int ROCKET = 8;

class SkillObject : public BaseObject {
	
	bool isFire;
	bool fireLeft;

public:
	
	SkillObject();
	~SkillObject();

	//void setTextureBullet(SDL_Renderer*renderer);
	//void setCoordinatesBullet(SDL_Renderer* renderer);

	void setFireLeft(bool direction) { fireLeft = direction; }
	void initializeBullet(SDL_Rect mainCoordinates, SDL_Renderer* renderer);
	void move();
	void renderBullet(SDL_Renderer* renderer);
};

#endif