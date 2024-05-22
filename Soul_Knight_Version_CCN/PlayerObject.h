#pragma once
#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include"Common.h"
#include"Texture.h"
#include"Defs.h"
#include<string>
#include<fstream>
#include"Skill.h"

class PlayerObject {
public:
	PlayerObject(SDL_Renderer* renderer);
	~PlayerObject();

	void setCoordinates(int x, int y) { animation->setCoordinates(x, y); }
	SDL_Rect getCoordinates() { return animation->getCoordinates(); }
	SDL_Point getPosition() { return { posX, posY }; }
	SDL_Point getDeltaPosition() { return { delta_x, delta_y }; }
	SDL_Rect getCoordinatesSkill(std::string id_skill);
	int getTimeActiveSkill(std::string id_skill);
	void setDeltaPosionsion(int x, int y);

	bool isDied() const { return hp <= 0; }
	void renderPlayer(SDL_Renderer* renderer);
	void newTurn();
	void move();

	void handleMoveAction();
	void handleSlash();
	void handleSkill(SDL_Event& e);

	void takeDamage(int _damage);
	int takeHighScore();
	void getScore(int score_plus);

	void cooldown();
	void updateScore(SDL_Renderer* renderer);
	void saveHighScore();

	
private:
	Animation* animation;
	Animation* slash_sword;

	Texture* Hp;
	Texture* Mana;
	Texture* Score;
	Texture* High_score;

	Skill* healing;
	Skill* shield;
	Skill* turbulent_slash;
	Skill* tornado;

	Direction direction = Direction::East;

	int posX = 300, posY = 300;
	int delta_x = 0, delta_y = 0;
	
	int hp = HP_PLAYER, mana = 200;
	int damage = DAMAGE_PLAYER;
	int speed = SPEED_PLAYER;
	int score = 0, high_score = 0;

	bool slash = false;
	bool up, down, left, right;
	int time_slash = 0, time_immortality = 8;

};

#endif