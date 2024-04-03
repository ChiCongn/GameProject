
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include"PlayerObject.h"
#include"ThreatObject.h"
#include"ObstacleObject.h"
#include"Defs.h"

#define AMOUNT_NORMAL_MONSTER  8
#define AMOUNT_LAZER_MONSTER  6
const std::string WINDOW_TITLE = "CCN";

void logSDLError(std::ostream& os,
	const std::string& msg, bool fatal)
{
	os << msg << " Error: " << SDL_GetError() << std::endl;
	if (fatal) {
		SDL_Quit();
		exit(1);
	}
}

class GameObject {	
	PlayerObject* player;
	NormalMonster* normalMonster=new NormalMonster[AMOUNT_NORMAL_MONSTER];
	ThreatObject* boss;
	LazerMonster* lazerMonster=new LazerMonster[AMOUNT_LAZER_MONSTER];
public:
	GameState gameState;
	SDL_Window* window;
	SDL_Renderer* renderer;

	void initSDL();
	void initializeGame();
	~GameObject();
	void gameIntro();
	void gamePlay();
	void gameOver();
};



#endif