#pragma once
#include"BaseObject.h"
#include"ThreatsObject.h"
#include<vector>

#ifndef SKILLSOBJECT_H
#define SKILLSOBJECT_H

const int LIGHTNING_WIDTH = 40;
const int LINGHTNING_HEIGHT = 80;
const int WAITING_TIME = 400;

class SkillObject : public BaseObject {
	int waitedTime;
	
public:
	bool usedSkill;
	SkillObject();
	~SkillObject();

	void setCoordinatesBullet(SDL_Renderer* renderer);
	void setTextureSkill(SDL_Renderer* renderer);
	void countdownSkill();
	bool readySkill() { return (waitedTime == 0); }
	void render(SDL_Renderer* renderer) override;
};

#endif