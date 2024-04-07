#pragma once
#pragma once
#ifndef THREAT_OBJECT_H
#define THREAT_OBJECT_H

#include"Common.h"
#include"BaseObject.h"
#include"BulletObject.h"
#include"Defs.h"
#include<vector>

class ThreatObject :public BaseObject {
protected:
	Direction direction;
	int hp, damage;
	Mix_Chunk* DeadAudio;
	Mix_Chunk* AttackPlayerAudio;
public:
	bool isDead() { return hp <= 0; }
	void getDamage(int _damage) { hp -= _damage; }
	//void intialize(SDL_Rect rect, int _speed,int _damage, std::string path, SDL_Renderer* renderer);
	ThreatObject();
	//virtual~ThreatObject();
	void setUpNewTurn();
	void destructThreat();
	//virtual void render(SDL_Renderer* renderer);
};

class NormalMonster :public ThreatObject {	
public:
	BulletObject* normalMonsterBullet = new BulletObject[AMOUNT_BULLET_NORMAL_MONSTER];
	~NormalMonster();
	void initNormalMonster(int _x, int _y,std::string bulletPath, SDL_Renderer* renderer);
	void normalMonsterMove(const SDL_Rect obstaclePos[]);
	void render(SDL_Renderer* renderer);
	void getDamage(int _damage) { hp -= damage; }
	void setNewTurnBullet();
};

class LazerMonster :public ThreatObject {
public:
	~LazerMonster();
	void initLazerMonster(int _x, int _y, SDL_Renderer* renderer);
	void lazerMonsterMove();
	void render(SDL_Renderer* renderer);
};

class BossMonster :public ThreatObject {
public:
	BulletObject* bulletBossMonster = new BulletObject[AMOUNT_BULLET_BOSS_MONSTER];
	void initBossMonster(int _x, int _y, std::string bulletPath, SDL_Renderer* renderer);
	//BossMonster();
	~BossMonster();
	void BossMove();
	void renderBossMonster(SDL_Renderer* renderer);
	void setNewTurnBullet();
};

#endif