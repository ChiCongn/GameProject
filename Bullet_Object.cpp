#include"Bullet_Object.h"


bulletObject::bulletObject() {
	coordinate.x = 0;
	coordinate.y = 0;
	texture_ = nullptr;
	x_val = 0;
	y_val = 0;
	is_move_ = false;
	bulletType_ = NONE;
}
bulletObject::~bulletObject() {
	;
}

void bulletObject::showBullet(figure aircraft) {
	if (bulletType_ == 1) {		
		texture_ = loadImage("bullet_.png", renderer);	
		SDL_RenderCopy(renderer, texture_, NULL, &coordinate);
		SDL_RenderPresent(renderer);
	}
	
}

void bulletObject::moveBullet() {

}