#pragma once

#ifndef BULLET_OBJECT_H
#define BULLET_OBJECT_H

#include"Common.h"
#include"Texture.h"
#include"Defs.h"

class BulletObject {
	SDL_Rect coordinates;
	SDL_Texture* texture;
	Direction direction;	
	int speed;
public:
	void initialize(std::string path,int _speed,Direction _direction, SDL_Renderer* renderer);
	~BulletObject();
	void setCoordinates(int x, int y) { coordinates.x = x, coordinates.y = y; }
	SDL_Rect getCoordinates() { return coordinates; }
	void setSizeBullet(int _w, int _h) { coordinates.w = _w, coordinates.h = _h; }
	void BulletMove();
	void renderBullet(SDL_Renderer* renderer);
};


#endif