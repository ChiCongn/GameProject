#pragma once
#pragma once
#ifndef THREAT_OBJECT_H
#define THREAT_OBJECT_H

#include"Common.h"
#include"BaseObject.h"
#include"BulletObject.h"
#include"Defs.h"
#include"Skill.h"
#include<vector>
#include<cmath>

enum class TypeMonster {
	Normal,
	Poison,
	Alien,
	Knight,
	Boss
};

class Monster{
protected:
	int speed = 0;
	double angle = 0.0;
	bool defence = false;
	int time_wait_attack = 0, time_attack = 0;
	int attackDistance = 0;
	int hp , time_undead = 3;

	Texture* Hp;
	Texture* skill ;	
	Direction direction;
public:
	Animation* animation;

	bool isDied() const { return hp <= 0; }
	Monster(const int width, const int height, const int health, const int clips[][4], const int frames,
		const std::string& imageLeft, const std::string& imageRight, SDL_Renderer* renderer);
	virtual ~Monster();

	void takeDamage(int damage);
	void defenceStructure(const SDL_Rect& position);
	void render(SDL_Renderer* renderer);
	void cooldown();

	virtual int damageAttack(const SDL_Rect& player) = 0;
	virtual void move(int x, int y) = 0;
	virtual void attack(int x, int y) = 0;
	virtual void newTurn() = 0;
};


class NormalMonster : public Monster {
public:
	NormalMonster() = delete;
	NormalMonster(const NormalMonster* other) = delete;
	NormalMonster(SDL_Renderer* renderer); 
	//~NormalMonster();
	void move(int x, int y) override;
	void attack(int x, int y) override;
	int damageAttack(const SDL_Rect& player) override;

	void newTurn() override;
	//void render(SDL_Renderer* renderer) override;
};

class AlienMonster : public Monster {
public:
	AlienMonster(SDL_Renderer* renderer);
	void move(int x, int y) override;
	void attack(int x, int y) override;
	int damageAttack(const SDL_Rect& player) override;

	void newTurn() override;

};

class PoisonMonster : public Monster {
public:
	PoisonMonster(SDL_Renderer* renderer);
	void move(int x, int y) override;
	void attack(int x, int y) override;
	//int damageAttack(const SDL_Rect& player) override;

	void newTurn() override;
	//void render(SDL_Renderer* renderer) override;
};

class KnightMonster : public Monster {
	int time_teleport = TIME_TELEPORT;
public:
	KnightMonster(SDL_Renderer* renderer); 
	void move(int x, int y) override;
	void attack(int x, int y) override;
	int damageAttack(const SDL_Rect& player) override;

	void newTurn() override;
	//void render(SDL_Renderer* renderer) override;
};

class BossMonster : public Monster {
	int time_teleport = 10;
	Skill* black_hole;
	Skill* fire_explodesion;
public:
	BossMonster(SDL_Renderer* renderer);
	void move(int x, int y) override;
	void attack(int x, int y) override;
	void blackHole(int& x, int& y);
	void countdown();
	int damageAttack(const SDL_Rect& player) override;

	void newTurn() override;
	void showRender(SDL_Renderer* renderer);
	//void render(SDL_Renderer* renderer) override;
};


#endif
