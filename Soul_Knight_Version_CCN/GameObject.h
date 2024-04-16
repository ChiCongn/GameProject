
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include"PlayerObject.h"
#include"ThreatObject.h"
#include"ObstacleObject.h"
#include"Defs.h"

class GameObject {		
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;

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
	void initializeGame();
	GameObject();
	~GameObject();
	void gameIntro();
	void gamePlay();
	void gameOver();
	void renderGame();
	void Running();
};



#endif