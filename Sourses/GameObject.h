
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include"PlayerObject.h"
#include"Monster.h"
#include"Defs.h"
#include<fstream>
#include"Structure.h"
#include"Menu.h"
#include"SoundEffect.h"


class GameObject {	
public:
	void initializeGame();
	
	GameObject();
	~GameObject();

	void gameIntro();
	void gamePlay();
	void pauseGame();
	void gameOver();
	void renderGame();
	void Running();


	void hadleMovement();
	void handlePlayer();
	void handleBossMonster();
	void handleStructures();

	bool isOver();
	void updateTime();
	void newTurn();
	void countdown();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;

	Uint32 startTime;
	Uint32 currentTime;
	SoundManager* sounds;

	GameState gameState;

	MenuGame* menu;
	Texture* time;
	Texture* pause;
	Map* map;

	BossMonster* boss;
	Structure** tower;
	PlayerObject* player;
};

#endif