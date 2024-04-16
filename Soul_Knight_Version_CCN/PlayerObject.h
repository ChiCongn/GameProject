#pragma once
#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include"Common.h"
#include"BaseObject.h"
#include"Support.h"
#include"Defs.h"
//#include"ThreatObject.h"

class PlayerObject :public BaseObject {
	//int x_val, y_val;
	bool attack;
	int hp, ex, damage;
	SupportObject* Hp;
	SupportObject* Ex;
	//SupportObject HighScore, Score;
	Direction direction;
	AnimatedSprite* playerSkill;
	/*Mix_Chunk* getDamageAudio;
	Mix_Chunk* levelUpAudio;
	Mix_Chunk* attackAudio;
	Mix_Chunk* getExAudio;*/
	
public:
	void initPlayer(SDL_Renderer* renderer);
	///PlayerObject();
	SDL_Rect getCoordinatesAnimatedSprite() { return playerSkill->getCoordinates(); }
	~PlayerObject();
	bool isDead() { return hp <= 0; }
	//void handleMoveAction(SDL_Event& e);
	void playerMove(SDL_Event& e, const SDL_Rect obstaclePos[]);
	void attackThreat(SDL_Event e);
	void getDamge(int _damage) { hp -= _damage; }
	void getExperience(int _ex) { ex += _ex; }
	void levelUp();
	void renderPlayer(SDL_Renderer* renderer);
	void setUpNewTurn();
};

#endif