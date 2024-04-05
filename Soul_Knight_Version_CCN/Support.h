#pragma once
#ifndef SUPPORT_H
#define SUPPORT_H
#include"Common.h"
#include"Defs.h"

class SupportObject {
public:
	SDL_Rect coordinates;
	SDL_Texture* texture;
	void initialize(int _x, int _y, int _h);
	SupportObject();
	~SupportObject();
	void setImageSupport(std::string imagePath, SDL_Renderer* renderer);
	void setTextSupport(std::string text, std::string fontPath, SDL_Renderer* renderer);
	void render(int hp, SDL_Renderer* renderer);
};


#endif