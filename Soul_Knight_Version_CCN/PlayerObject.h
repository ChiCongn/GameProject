#pragma once
#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include"Common.h"
#include"BaseObject.h"
#include"Texture.h"
#include"Defs.h"
#include<string>
#include"Tile.h"

class PlayerObject :public BaseObject {
	int x_val, y_val;
	Uint32 preTimeSkill;
	int hp, mana, damage, score;
	Texture* Hp;
	Texture* Mana;
	Texture* Score;
	Direction direction;

	Mix_Chunk* attackAudio;
	/*Mix_Chunk* getDamageAudio;
	Mix_Chunk* levelUpAudio;	
	Mix_Chunk* getExAudio;*/
	
public:
	Animation* playerSkill;

	bool attack;
	PlayerObject(SDL_Renderer* renderer);
	///PlayerObject();
	SDL_Rect getCoordinatesAnimation() { return playerSkill->getCoordinates(); }
	~PlayerObject();
	bool isDead() const { return hp <= 0; }
	void handleMoveAction(Map* map);
	void move();
	void attackThreat(SDL_Event e);
	void getDamge(int _damage) { hp -= _damage; }
	void updateScore(const int _score, SDL_Renderer* renderer);

	void renderPlayer(SDL_Renderer* renderer);
	void setUpNewTurn();
};

#endif