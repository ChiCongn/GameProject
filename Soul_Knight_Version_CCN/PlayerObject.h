#pragma once
#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include"Common.h"
#include"BaseObject.h"
#include"Support.h"
#include"Defs.h"

class PlayerObject :public BaseObject {
	int hp, ex, damage;
	bool direction;
	Mix_Chunk* getDamageAudio;
	Mix_Chunk* levelUpAudio;
	Mix_Chunk* attackAudio;
	Mix_Chunk* getExAudio;
	SDL_Texture* textureLeft;
public:
	void intialize(SDL_Renderer* renderer);
	~PlayerObject();
	bool isDead() { return hp <= 0; }
	void move(SDL_Event e);
	void attackThreat();
	void getDamge(int _damage) { hp -= _damage; }
	void getExperience(int _ex) { ex += _ex; }
	void levelUp();
	void setUpNewTurn();
};

#endif