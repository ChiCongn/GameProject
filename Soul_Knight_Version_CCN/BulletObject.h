#pragma once

#ifndef BULLET_OBJECT_H
#define BULLET_OBJECT_H

#include"Common.h"
#include"BaseObject.h"

class BulletObject:public BaseObject{
	bool direction; // left==true;
public:
	void initialize(int _speed, std::string path, SDL_Renderer* renderer);
	~BulletObject();
};

#endif