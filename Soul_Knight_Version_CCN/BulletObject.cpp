
#include"BulletObject.h"

void BulletObject::initialize(int _speed, std::string path, SDL_Renderer* renderer) {
	speed = _speed;
	texture = loadImage(path, renderer);
}

BulletObject::~BulletObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

