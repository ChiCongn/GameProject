#pragma once

#ifndef BULLET_OBJECT_H
#define BULLET_OBJECT_H

#include"Common.h"
#include"ObstacleObject.h"
#include"Defs.h"

class BulletObject : public ObstacleObject{
	Direction direction;	
	int speed;
public:
	void initialize(std::string path,int _speed,Direction _direction, SDL_Renderer* renderer);
	void destructBullet();
	~BulletObject();
	void setSizeBullet(int _w, int _h) { coordinates.w = _w, coordinates.h = _h; }
	void BulletMove();
	void renderBullet(SDL_Renderer* renderer);
};


#endif