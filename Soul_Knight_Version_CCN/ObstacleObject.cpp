
#include"ObstacleObject.h"

void ObstacleObject::initializeObstacle(SDL_Rect rect, SDL_Renderer* renderer) {
	coordinates.x = rect.x;
	coordinates.y = rect.y;
	coordinates.w = rect.w;
	coordinates.h = rect.h;
	texture = loadImage("./Image\\Obstacle.png",renderer);
}

ObstacleObject::~ObstacleObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void ObstacleObject::renderObstacle(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}
