#pragma once
#ifndef OBSTACLE_OBJECT_H
#define OBSTACLE_OBJECT_H

#include"Common.h"
#include"BaseObject.h"

class ObstacleObject :public BaseObject {
public:
	void initializeObstacle(SDL_Rect, SDL_Renderer* renderer);
	//ObstacleObject();//SDL_Renderer* renderer);
	~ObstacleObject();
	void renderObstacle(SDL_Renderer* renderer);
};

#endif