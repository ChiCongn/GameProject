#pragma once
#ifndef OBSTACLE_OBJECT_H
#define OBSTACLE_OBJECT_H

#include"Common.h"
#include"BaseObject.h"

class ObstacleObject{
protected:
	SDL_Texture* texture;
	SDL_Rect coordinates;
public:
	void setCoordinates(int _x, int _y) { coordinates.x = _x, coordinates.y = _y; }
	SDL_Rect getCoordinates() { return coordinates; }
	void initializeObstacle(SDL_Rect, SDL_Renderer* renderer);
	//ObstacleObject();//SDL_Renderer* renderer);
	~ObstacleObject();
	void renderObstacle(SDL_Renderer* renderer);
};

#endif