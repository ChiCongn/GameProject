
#include"BulletObject.h"

BulletObject::BulletObject() {
	coordinates.x = 0;
	coordinates.y = 0;
	coordinates.w = BULLET_WIDTH;
	coordinates.h = BULLET_HEIGHT;
	speed = 30;
	isFire = false;
	direction =DIRECTON_LEFT;
	texture = nullptr;
	sound = nullptr;
}

BulletObject::~BulletObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
	if (sound) {
		Mix_FreeChunk(sound);
		sound = nullptr;
	}
}

void BulletObject::setTextureBullet(SDL_Renderer* renderer) {
	texture = loadImage("Bullet.jpg", renderer);
}

void BulletObject::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}

void BulletObject::setAudio() {
	sound = loadAudio("tiengDanBan.wav");
}

void BulletObject::move() {
	if (direction == DIRECTON_LEFT) {
		coordinates.x -= speed;
	}
	else coordinates.x += speed;
}