
#include"SkillsObject.h"

SkillObject::SkillObject() {
	coordinates.x = 0;
	coordinates.y = 0;
	coordinates.w = BULLET_WIDTH;
	coordinates.h = BULLET_HEIGHT;
	speed = 50;
	isFire = false;
	fireLeft = false;
	texture = nullptr;
}

SkillObject::~SkillObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
}

//void SkillObject::renderBullet(SDL_Renderer* renderer) {
//	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
//	SDL_RenderPresent(renderer);
//}


void SkillObject::renderBullet(SDL_Renderer* renderer) {
	texture = loadImage("Bullet.jpg", renderer);
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
	SDL_RenderPresent(renderer);
}

void SkillObject::move() {
	if (fireLeft) {
		coordinates.x -= speed;
	}
	else coordinates.x += speed;
	coordinates.y -= 28;
}
//
//void SkillObject::setTextureBullet(SDL_Renderer* renderer) {
//	bulletTexture= loadImage("", renderer);
//}
//
//void SkillObject::fireBullet(SDL_Event& e, SDL_Rect MainCoordinates,SDL_Renderer* renderer) {	
//	if (e.type == SDLK_SPACE) {
//		bulletCoordinates.push_back(MainCoordinates);
//		bulletTexture.push_back(setTextureBullet(renderer));		
//	}
//}
//
//void SkillObject::updatePositionAndRender(SDL_Renderer* renderer) {
//	for (auto it : bulletCoordinates) {
//		it.x += 30;		
//	}
//	
//}

