#pragma once

#ifndef THREATSOBJECT_H
#define THREATSOBJECT_H

#include"BaseObject.h"
#include"SkillsObject.h"
#include<vector>
#include<ctime>
#include<cstdlib>

const int ZOMBIE_WIDTH = 80;
const int ZOMBIE_HEIGHT = 120;
const int MAX_HP = 10;

class ThreatsObject :public BaseObject {
	int hp;
public:
	ThreatsObject();
	~ThreatsObject();	
	bool isDied() { return hp == 0; }
	void setTexture(SDL_Renderer* renderer);
	void render(SDL_Renderer* renderer) override;
	void autoMove(int x, int y);
	void attackPlayer(SDL_Renderer* renderer);
	void renderAttack(SDL_Renderer* renderer);
	void getDamage() { hp--; }
	void getDamageLightning() { hp -= MAX_HP; }
	void recover() { hp = MAX_HP; }
};
#endif