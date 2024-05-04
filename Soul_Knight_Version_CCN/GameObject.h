
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include"PlayerObject.h"
#include"ThreatObject.h"
#include"Tile.h"
#include"Defs.h"
#include<fstream>
#include"Tile.h"

class GameObject {		
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;
	Uint32 startTime;

	Map* map;
	MenuGame* menu = new MenuGame;
	Texture* pause;
	int highScore;
	Texture* HighScore;

	PlayerObject* player;
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
	int takeHighScore();
	void renderHighScore();
	GameObject();
	~GameObject();
	void gameIntro();
	void gamePlay();
	void pauseGame();
	void countdown();
	void gameOver();
	void renderGame();

	void Running();
	void handleNormalMonster(); // check collision and is died of normal monster
	void handleLazerMonster(); // ... 
	void handleBossMonster(); //... 

	bool isOver();
	void newTurn();
	void nextTurnMonsterAttack();
};



#endif