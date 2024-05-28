
#include"Monster.h"
#include"Common.h"
#include"Defs.h"
#include"Texture.h"

#ifndef STRUCTURE_H
#define STRUCTURE_H

class Structure {
public:
	Structure() = delete;
	Structure(Structure& other) = delete;
	Structure(int level, int posX, int posY, SDL_Renderer* renderer);
	~Structure();
	void render(SDL_Renderer* renderer);

	void setCoordinates(int x, int y);
	void handleMonsterMovement(SDL_Point pos);
	void handleTakeDamage(const SDL_Rect& position, int time_active, int damage);
	void handleAttack(const SDL_Rect& player);
	void moveFollowMap(int x, int y);

	int damageAttack(const SDL_Rect& player);
	int calculateScore();

	void regeneration();
	void cooldown();
	void newTurn();

private:
	Texture* Hp;
	Texture* structure;
	Animation** thorn;
	
	KnightMonster* knight_monster;
	AlienMonster** alien_monsters;
	NormalMonster** normal_monsters;

	int time_thorn_grow = 3, time_wait_grow = 8;
	int dangerous_zone = DANGEROUS_ZONE;
	int hp, amount;
	int time_immortality = 0, time_regeneration = 0;
	bool is_calculate;
};


#endif