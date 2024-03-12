
#include"SkillsObject.h"

SkillObject::SkillObject() {
	coordinates.x = 0;
	coordinates.y = 0;
	coordinates.w = LIGHTNING_WIDTH;
	coordinates.h = LINGHTNING_HEIGHT;
	speed = 50;
	texture = nullptr;
	waitedTime = WAITING_TIME;
	usedSkill = false;
}

SkillObject::~SkillObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
}

void SkillObject::countdownSkill() {
	waitedTime--;
	if (waitedTime < 0)
		waitedTime++;
}

void SkillObject::setTextureSkill(SDL_Renderer* renderer) {
	texture = loadImage("lightningSkill.jpg", renderer);
}

void SkillObject::render(SDL_Renderer* renderer) {	
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}


