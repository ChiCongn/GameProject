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
	SDL_Texture* textureRight;
	Direction direction;
	int hp, damage;
	Mix_Chunk* DeadAudio;
	Mix_Chunk* AttackPlayerAudio;
	//std::vector<BulletObject*> bullet;
public:
	bool isDead() { return hp <= 0; }
	void getDamage(int _damage) { hp -= _damage; }
	//void intialize(SDL_Rect rect, int _speed,int _damage, std::string path, SDL_Renderer* renderer);
	ThreatObject();
	~ThreatObject();
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
	~BossMonster();
	void initBossMonster(int _x, int _y, SDL_Renderer* renderer);
	void BossMove();
	void renderBossMonster(SDL_Renderer* renderer);
};

#endif