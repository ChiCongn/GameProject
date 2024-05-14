#pragma once
#ifndef SUPPORT_H
#define SUPPORT_H
#include"BaseObject.h"
#include"Common.h"
#include"Defs.h"

class Texture {	
	SDL_Texture* texture;
public:	
	SDL_Rect coordinates;
	Texture(int _x, int _y, int _w, int _h);
	~Texture();	
	void setCoordinates(int x, int y) { coordinates.x = x, coordinates.y = y; }
	//void setSize(int w, int h) { coordinates.w = w, coordinates.h = h; }
	void setImageTexture(std::string imagePath, SDL_Renderer* renderer);
	void setText(const std::string text, const SDL_Color color, const std::string fontPath, SDL_Renderer* renderer);
	void render(SDL_Renderer* renderer);
	void renderEx(SDL_Renderer* renderer, double angle);
	void setWidth(int w) { coordinates.w = w; }
	void move(int x, int y);
};
 

class MenuGame {
	SDL_Texture* gameIntro;
	SDL_Texture* gameInstruction;
	SDL_Texture* gameVictory;
	SDL_Texture* gameDefeat;

public:
	void initMenuGame(SDL_Renderer* renderer);
	void renderMenuGame(SDL_Renderer* renderer, GameState gameState);
	~MenuGame();
};

#endif