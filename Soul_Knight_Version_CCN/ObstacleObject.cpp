
#include"ObstacleObject.h"

void ObstacleObject::intialize(int _x, int _y, int _w, int _h, std::string path, SDL_Renderer* renderer) {
	coordinates.x = _x;
	coordinates.y = _y;
	coordinates.w = _w;
	coordinates.h = _h;
	texture = loadImage(path, renderer);
	speed = 0;
}

ObstacleObject::~ObstacleObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}