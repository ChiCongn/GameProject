#pragma once
#ifndef SUPPORT_H
#define SUPPORT_H
#include"Common.h"
#include"Defs.h"

class HpObject {
public:
	SDL_Rect coordinates;
	SDL_Texture* texture;
	void initialize(int _x, int _y, int _h, std::string path, SDL_Renderer* renderer);
	HpObject();
	~HpObject();
	void render(int hp, SDL_Renderer* renderer);
};

class ExObject :public HpObject {
public:
	ExObject();
	~ExObject();
};

#endif