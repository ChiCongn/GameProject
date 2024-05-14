
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include"PlayerObject.h"
#include"Monster.h"
#include"Defs.h"
#include<fstream>
#include"GameLevel.h"


class GameObject {		
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;
	Uint32 startTime;
	Uint32 currentTime;

	MenuGame* menu = new MenuGame;
	Texture* time;
	Texture* pause;
	int highScore;
	Texture* HighScore;
	SDL_Texture* map;
	
	BossMonster* boss;
	Structure* tower;
	PlayerObject* player;

	Mix_Chunk* gameDefeatAudio;
	Mix_Chunk* gameVictoryAudio;
	Mix_Chunk* gameIntroAudio;

public:
	GameState gameState;
	void initializeGame();
	
	GameObject();
	~GameObject();

	void gameIntro();
	void gamePlay();
	void pauseGame();
	void gameOver();
	void renderGame();
	void Running();

	void updateTime();
	void newTurn();
	int takeHighScore();
	void renderHighScore();
	void countdown();
};

#endif