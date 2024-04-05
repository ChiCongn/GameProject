
#include"BaseObject.h"

BaseObject::BaseObject() {
	speed = 0;
	coordinates.x = 0;
	coordinates.y = 0;
	texture = nullptr;
}

BaseObject::~BaseObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

