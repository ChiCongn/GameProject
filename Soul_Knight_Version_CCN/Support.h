#pragma once
#ifndef SUPPORT_H
#define SUPPORT_H
#include"BaseObject.h"
#include"Common.h"
#include"Defs.h"

class SupportObject {
public:
	SDL_Rect coordinates;
	SDL_Texture* texture;
	SupportObject(int _x, int _y, int _h);
	//SupportObject();
	~SupportObject();
	void setImageSupport(std::string imagePath, SDL_Renderer* renderer);
	void setTextSupport(std::string text, std::string fontPath, SDL_Renderer* renderer);
	void render(int width, SDL_Renderer* renderer);
};
 
class MenuGame {
	SDL_Texture* gameIntro;
	SDL_Texture* gameInstruction;
	SDL_Texture* gameVictory;
	SDL_Texture* gameDefeat;
	AnimatedSprite* chibichibi;

public:
	void initMenuGame(SDL_Renderer* renderer);
	void renderMenuGame(SDL_Renderer* renderer, GameState gameState);
	~MenuGame();
};

#endif