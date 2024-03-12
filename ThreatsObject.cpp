
#include"ThreatsObject.h"

ThreatsObject::ThreatsObject() {
	coordinates.x = 0;
	coordinates.y = 0;
	coordinates.w = ZOMBIE_WIDTH;
	coordinates.h = ZOMBIE_HEIGHT;
	texture = nullptr;
	speed = 8;
	hp = MAX_HP;
}

ThreatsObject::~ThreatsObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
}

void ThreatsObject::setTexture(SDL_Renderer* renderer) {
	texture = loadImage("zombie.jpg", renderer);
}

void ThreatsObject::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}

void ThreatsObject::autoMove(int x, int y) {
	int x_val= (coordinates.x - x)/20;
	coordinates.x -= x_val;
	int y_val= (y - coordinates.y)/20;
	coordinates.y -= y_val;
	if (coordinates.x + ZOMBIE_WIDTH > SCREEN_WIDTH) {
		coordinates.x = 0;
	}	
}

void ThreatsObject::renderAttack(SDL_Renderer* renderer) {
	;
}

void ThreatsObject::attackPlayer(SDL_Renderer* renderer) {
	;
}