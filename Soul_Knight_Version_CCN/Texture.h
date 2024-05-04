#pragma once
#ifndef SUPPORT_H
#define SUPPORT_H
#include"BaseObject.h"
#include"Common.h"
#include"Defs.h"

class Texture {
	SDL_Rect coordinates;
	SDL_Texture* texture;
public:	
	Texture(int _x, int _y, int _w, int _h);
	~Texture();	
	void setImageTexture(std::string imagePath, SDL_Renderer* renderer);
	void setText(const std::string text, const SDL_Color color, const std::string fontPath, SDL_Renderer* renderer);
	void render(int width, SDL_Renderer* renderer);
};
 

class MenuGame {
	SDL_Texture* gameIntro;
	SDL_Texture* gameInstruction;
	SDL_Texture* gameVictory;
	SDL_Texture* gameDefeat;
	Animation* chibichibi;

public:
	void initMenuGame(SDL_Renderer* renderer);
	void renderMenuGame(SDL_Renderer* renderer, GameState gameState);
	~MenuGame();
};

#endif