
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include"PlayerObject.h"
#include"ThreatObject.h"
#include"ObstacleObject.h"
#include"Defs.h"

class GameObject {		
	SDL_Texture* map;
	PlayerObject* player=new PlayerObject;
	ObstacleObject* obstacle = new ObstacleObject[12];
	NormalMonster* normalMonster=new NormalMonster[AMOUNT_NORMAL_MONSTER];
	//ThreatObject* boss;
	LazerMonster* lazerMonster=new LazerMonster[AMOUNT_LAZER_MONSTER];
public:
	GameState gameState;
	void initializeGame(SDL_Renderer* renderer);
	GameObject(SDL_Renderer* renderer);
	~GameObject();
	void gameIntro();
	void gamePlay(SDL_Event& e, SDL_Renderer* renderer);
	void gameOver();
	void renderGame(SDL_Renderer* renderer);
};



#endif