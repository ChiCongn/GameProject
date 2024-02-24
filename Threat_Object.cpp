#include"Threat_Object.h"

threatObject::threatObject() {
	coordinate.x = 0;
	coordinate.y = 0;
	coordinate.w = WIDTH_THREAT;
	coordinate.h = HEIGHT_THREAT;
	speed_ = 0;
	texture_ = NULL;
}

threatObject::~threatObject() {
	;
}

void threatObject::show() {
	texture_= loadImage("UFO_.png", renderer);
	SDL_RenderCopy(renderer, texture_, NULL, &coordinate);
	SDL_RenderPresent(renderer);
}
void threatObject::moveThreat(SDL_Rect rect) {	
		coordinate.x += speed_ + rect.x;
		if (coordinate.x < SCREEN_WIDTH / 2 || coordinate.x + WIDTH_THREAT > SCREEN_WIDTH)
			coordinate.x -= speed_/4;

		coordinate.y += speed_+rect.y/4;
		if (coordinate.y <0 || coordinate.y + HEIGHT_THREAT > SCREEN_HEIGHT)
			coordinate.y -= speed_;	
}
