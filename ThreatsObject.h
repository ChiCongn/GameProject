#pragma once

#ifndef THREATSOBJECT_H
#define THREATSOBJECT_H

#include"BaseObject.h"
#include<vector>
#include<ctime>
#include<cstdlib>

const int B52_WIDTH = 100;
const int B52_HEIGHT = 60;

class ThreatsObject :public BaseObject {
	const std::vector<int> RANDOMCOORDINATES_X={ 30, 50, 73, 974, 465, 874, 747, 36, 847, 135, 564 };
	const int sizeX = RANDOMCOORDINATES_X.size();
	const std::vector<int> RANDOMCOORDINATES_Y = { 0, 65, 73, 674, 474, 767, 636, 467, 476, 685, 494 };
	const int sizeY = RANDOMCOORDINATES_Y.size();
public:
	ThreatsObject();
	~ThreatsObject();	
	void setTexture(SDL_Renderer* renderer);
	void autoMove();
	void attackPlayer();
	
};
#endif