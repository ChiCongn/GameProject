#pragma once
#ifndef SUPPORT_H
#define SUPPORT_H

#include"Common.h"
#include"Defs.h"
#include<vector>
#include<fstream>

class Texture {	
public:	
	Texture(int _x, int _y, int _w, int _h);
	~Texture();	
	void render(SDL_Renderer* renderer);

	void setCoordinates(int x, int y) { coordinates.x = x, coordinates.y = y; }
	void setImageTexture(std::string imagePath, SDL_Renderer* renderer);
	void setText(const std::string text, const SDL_Color color, const std::string fontPath, SDL_Renderer* renderer);
	void setWidth(int w) { coordinates.w = w; }

	SDL_Rect getCoordinates() { return coordinates; }
	SDL_Point getPosition() { return { coordinates.x, coordinates.y }; }
	void move(int x, int y);

private:
	SDL_Rect coordinates;
	SDL_Texture* texture;

};
 

class Map {	
public:
	Map(const std::string& path, SDL_Renderer* renderer);
	~Map();
	void render(SDL_Renderer* renderer);

	void takeTileMapMatrix();
	void move(int& x, int& y);
	void newTurn();

	bool isBoundary();
	SDL_Point getDelta() { return { deltaX, deltaY }; }

private:
	SDL_Texture* map;
	SDL_Rect camera;
	int deltaX, deltaY;

	int tile_map[MAP_ROW][MAP_COL];
};

#endif