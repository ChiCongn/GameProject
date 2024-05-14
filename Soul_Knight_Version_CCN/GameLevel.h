
#include"Monster.h"
#include"Common.h"
#include"Defs.h"
#include"Texture.h"

#ifndef STRUCTURE_H
#define STRUCTURE_H

class Structure {
public:
	Texture* Hp;
	Texture* structure;
	Animation** thorn;
	//Animation* regenerationEffect;
	int time_thorn_grow = 3, time_wait_grow = 8;
	int dangerousZone = DANGEROUS_ZONE;

	KnightMonster* knightMonster;
	AlienMonster** alienMonster;
	NormalMonster** normalMonster;
	int hp, amount;
	int time_undead = 0, time_regeneration = 0;
	
	Structure() = delete;
	Structure(Structure& other) = delete;
	Structure(int level, SDL_Renderer* renderer);
	~Structure();
	void render(SDL_Renderer* renderer);


	void handleMonsterMovement(int x, int y);
	void handleTakeDamage(const SDL_Rect& position, int damage);
	void handleAttack(const SDL_Rect& player);

	int damageAttack(const SDL_Rect& player);

	void regeneration();
	void cooldown();
	void newTurn();
};


#endif