#pragma once
#ifndef OBSTACLE_OBJECT_H
#define OBSTACLE_OBJECT_H

#include"Common.h"
#include"BaseObject.h"

class ObstacleObject :public BaseObject {
public:
	void intialize(int _x, int _y, int _w, int _h, std::string path, SDL_Renderer* renderer);
	ObstacleObject();
	~ObstacleObject();
};

#endif