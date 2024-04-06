
#include"Support.h"

SupportObject::~SupportObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void SupportObject::initialize(int _x, int _y, int _h) {
	coordinates.x = _x;
	coordinates.y = _y;
	coordinates.h = _h;
}

void SupportObject::setImageSupport(std::string imagePath, SDL_Renderer* renderer) {
	texture = loadImage(imagePath, renderer);
}

void SupportObject::setTextSupport(std::string text,std::string fontPath, SDL_Renderer* renderer) {
	texture = loadText(text,fontPath,renderer);
}

void SupportObject::render(int width, SDL_Renderer* renderer) {
	coordinates.w = width*5;
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}
