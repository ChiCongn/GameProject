
#include"Support.h"

HpObject::~HpObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void HpObject::initialize(int _x, int _y, int _h, std::string path, SDL_Renderer* renderer) {
	coordinates.x = _x;
	coordinates.y = _y;
	coordinates.h = _h;
	texture = loadImage(path, renderer);
}

void HpObject::render(int hp, SDL_Renderer* renderer) {
	coordinates.w = hp;
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}

ExObject::~ExObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}