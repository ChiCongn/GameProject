#pragma once
#pragma once
#ifndef THREAT_OBJECT_H
#define THREAT_OBJECT_H

#include"Common.h"
#include"Defs.h"
#include"Skill.h"
#include<vector>
#include<cmath>

enum class TypeMonster {
	Normal,
	Poison,
	Alien,
	Knight,
	Boss,
	None
};

class Monster{
public:
	bool isDied() const { return hp <= 0; }
	Monster(const int width, const int height, const int health, const int clips[][4], const int frames,
		const std::string& imageLeft, const std::string& imageRight, SDL_Renderer* renderer);
	virtual ~Monster();
	void render(SDL_Renderer* renderer);

	void setCoordinates(int x, int y);
	SDL_Rect getCoordinates() { return animation->getCoordinates(); }
	SDL_Point getPosition() { return animation->getPosition(); }
	void takeDamage(int damage);
	void defenceStructure(const SDL_Rect& position);
	void cooldown();
	void moveFollowMap(int x, int y);
	void newTurn();

	int calculateScore();

	virtual int damageAttack(const SDL_Rect& player) = 0;
	virtual void move(int x, int y) = 0;
	virtual void attack(int x, int y) = 0;

protected:
	Animation* animation;
	TypeMonster type;
	bool is_calculate = false;
	int speed = 0;
	double angle = 0.0;
	bool defence = false;
	int attack_distance = 0;
	int hp, time_immortality = 3;

	Texture* Hp;
	Skill* skill;
	Direction direction;
};


class NormalMonster : public Monster {
public:
	NormalMonster() = delete;
	NormalMonster(const NormalMonster* other) = delete;
	NormalMonster(SDL_Renderer* renderer); 
	~NormalMonster();

	void move(int x, int y) override;
	void attack(int x, int y) override;
	int damageAttack(const SDL_Rect& player) override;

	//void render(SDL_Renderer* renderer) override;
};

class AlienMonster : public Monster {
public:

	AlienMonster(SDL_Renderer* renderer);
	~AlienMonster();

	void move(int x, int y) override;
	void attack(int x, int y) override;

	int damageAttack(const SDL_Rect& player) override;

};

class PoisonMonster : public Monster {
public:
	PoisonMonster(SDL_Renderer* renderer);
	~PoisonMonster();

	void move(int x, int y) override;
	void attack(int x, int y) override;
	int damageAttack(const SDL_Rect& player) override;
};

class KnightMonster : public Monster {
public:

	KnightMonster(SDL_Renderer* renderer); 
	~KnightMonster();

	void move(int x, int y) override;
	void attack(int x, int y) override;
	int damageAttack(const SDL_Rect& player) override;

private:
	int time_teleport = TIME_TELEPORT;
};

class BossMonster : public Monster {
public:

	BossMonster(SDL_Renderer* renderer);
	~BossMonster();

	void move(int x, int y) override;
	void attack(int x, int y) override;
	void countdown();

	int damageAttack(const SDL_Rect& player) override;

	void showRender(SDL_Renderer* renderer);

private:
	int time_teleport = 10;
	Skill* black_hole;
	Skill* fire_explodesion;
};


class MonsterFactory {
public:
	Monster* createMonster(const std::string& type, SDL_Renderer* renderer);
};

#endif
