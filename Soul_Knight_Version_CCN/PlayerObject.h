#pragma once
#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include"Common.h"
#include"BaseObject.h"
#include"Texture.h"
#include"Defs.h"
#include<string>
#include"Skill.h"

class PlayerObject {
	int speed;	
	Texture* Hp;
	Texture* Mana;
	Texture* Score;
	Direction direction;

	bool slash = false;
	int timeSlash = 0, time_undead = 2;
	Mix_Chunk* attackAudio;
	/*Mix_Chunk* getDamageAudio;
	Mix_Chunk* levelUpAudio;	
	Mix_Chunk* getExAudio;*/	
public:
	int hp, mana, damage, score;
	int posX = 0, posY = 0;
	Animation* animation;
	int x_val, y_val;

	Animation* slashSword;
	Skill* fireBall;
	Skill* tornado;
	PlayerObject(SDL_Renderer* renderer);
	///PlayerObject();
	~PlayerObject();
	bool isDead() const { return hp <= 0; }
	void renderPlayer(SDL_Renderer* renderer);
	void setUpNewTurn();

	void handleMoveAction();
	void move();
	void handleSlash();
	void handleSkill(SDL_Event& e);
	void handleAttackMovement();


	void takeDamage(int _damage);
	void cooldown();
	void getDamge(int _damage) { hp -= _damage; }
	void updateScore(const int _score, SDL_Renderer* renderer);

	
};

#endif