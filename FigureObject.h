#pragma once
#ifndef FIGUREOBJECT_H
#define FIGUREOBJECT_H

#include<vector>
#include"SkillsObject.h"
#include"BulletObject.h"

const int FIGURE_WIDTH = 120;
const int FIGURE_HEIGHT = 100;
const int DIED = -1;
const int VICTORY = 0;

class FigureObject :public BaseObject {
	int status;
	bool directionLeft;	
	bool isFire;
	SDL_Texture* textureRight;	
public:
	SkillObject lightning;
	std::vector<BulletObject> bullet;
	FigureObject();
	~FigureObject();	

	void setTextureFigure(SDL_Renderer* renderer);
	void render(SDL_Renderer* renderer) override;
	void handleMoveAction(SDL_Event&e);
	void attackThreats(SDL_Event&e, SDL_Renderer* renderer);
	void renderAttack(SDL_Renderer* renderer);
	void setCoordinatesSkill(SDL_Event& e);
	void renderSkill(SDL_Renderer* renderer);
};

#endif