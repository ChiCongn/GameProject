#pragma once
#ifndef FIGUREOBJECT_H
#define FIGUREOBJECT_H

#include<vector>
#include"SkillsObject.h"

const int FIGURE_WIDTH = 100;
const int FIGURE_HEIGHT = 80;
const int DIED = -1;
const int VICTORY = 0;

class FigureObject :public BaseObject {
	int status;
	bool directionLeft;
	std::vector<SkillObject> bullet;
	bool isFire;
public:
	FigureObject();
	~FigureObject();	
	void updateTexture(SDL_Renderer* renderer);
	void handleMoveAction(SDL_Event&e);
	void attackThreats(SDL_Event&e, SDL_Renderer* renderer);
	void renderAttack(SDL_Renderer* renderer);
	
};

#endif