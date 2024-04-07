
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include"PlayerObject.h"
#include"ThreatObject.h"
#include"ObstacleObject.h"
#include"Defs.h"

class GameObject {		
	SDL_Texture* map;
	MenuGame* menu = new MenuGame;
	PlayerObject* player = new PlayerObject;
	ObstacleObject* obstacle = new ObstacleObject[12];
	NormalMonster* normalMonster=new NormalMonster[AMOUNT_NORMAL_MONSTER];
	BossMonster* boss=new BossMonster;
	LazerMonster* lazerMonster=new LazerMonster[AMOUNT_LAZER_MONSTER];

	Mix_Chunk* gameDefeatAudio;
	Mix_Chunk* gameVictoryAudio;
	Mix_Chunk* gameIntroAudio;
	Mix_Chunk* chibichibiAudio; /// :))

public:
	GameState gameState;
	void initializeGame(SDL_Renderer* renderer);
	GameObject(SDL_Renderer* renderer);
	~GameObject();
	void gameIntro(SDL_Event& e, SDL_Renderer* renderer);
	void gamePlay(SDL_Event& e, SDL_Renderer* renderer);
	void gameOver(SDL_Event& e, SDL_Renderer* renderer);
	void renderGame(SDL_Renderer* renderer);
	void Running(SDL_Event& e, SDL_Renderer* renderer);
};



#endif