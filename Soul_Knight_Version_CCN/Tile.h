#pragma once
#ifndef TILE_H
#define TILE_H

#include"Common.h"
#include"Defs.h"
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include"ThreatObject.h"

class Tile{
protected:
	SDL_Texture* texture;
	SDL_Rect coordinates;
public:
	void initTile(const std::string path, SDL_Renderer* renderer);
	void setCoordinates(int _x, int _y) { coordinates.x = _x, coordinates.y = _y; }
	SDL_Rect getCoordinates() { return coordinates; }
	~Tile();
	void renderTile(SDL_Renderer* renderer);
};

class Map {
    int x, y;
	SDL_Rect camera;
	SDL_Texture* texture;
public:
	std::vector<std::vector<int>> grid;
	Map(SDL_Renderer* renderer);
	std::vector<std::vector<int>> getTileMatrix();
    void handleCamera(int x_val, int y_val);
	void updateCamera();
	void renderMap(SDL_Renderer* renderer);
};

class levelGame {
	bool pass;
	SDL_Texture* texture;
	
};

#endif