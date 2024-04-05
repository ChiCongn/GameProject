#pragma once
#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include"Common.h"
#include"BaseObject.h"
#include"Support.h"
#include"Defs.h"

class PlayerObject :public BaseObject {
	int hp, ex, damage;
	SDL_Texture* textureLeft;
	//SupportObject Hp, Ex;
	//SupportObject HighScore, Score;
	Direction direction;

	Mix_Chunk* getDamageAudio;
	Mix_Chunk* levelUpAudio;
	Mix_Chunk* attackAudio;
	Mix_Chunk* getExAudio;
	
public:
	void initializePlayer(SDL_Renderer* renderer);
	PlayerObject();
	~PlayerObject();
	bool isDead() { return hp <= 0; }
	void playerMove(SDL_Event e, const SDL_Rect obstaclePos[]);
	void attackThreat();
	void getDamge(int _damage) { hp -= _damage; }
	void getExperience(int _ex) { ex += _ex; }
	void levelUp();
	void renderPlayer(SDL_Renderer* renderer);
	void setUpNewTurn();
};

#endif