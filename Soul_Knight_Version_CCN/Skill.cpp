
#include"Skill.h"


Skill::Skill(const std::string& image_path, const std::string& animationPath, int width, int height, 
	const int& frames, const int clips[][4], SDL_Renderer* renderer) {

	animation = new Animation(animationPath, animationPath, width, height, frames, clips, renderer);	
	image_skill = new Texture(0, 0, 40, 40);
	image_skill->setImageTexture(image_path, renderer);
}

Skill::~Skill() {
	delete animation;
	delete image_skill;
}

void Skill::render(SDL_Renderer* renderer) {
	if (time_wait == 0) {
		image_skill->render(renderer);
	}
	if (time_active > 0) {
		animation->renderAnimation(renderer, Direction::East);
	}
}

void Skill::setCoordinates(int x, int y) {
	animation->setCoordinates(x, y);
}


void Skill::cooldown() {
	if (time_wait > 0) {
		time_wait--;
	}
	if (time_active > 0) {
		time_active--;
	}
}

void Skill::setTime(int _time_wait, int _time_active) {
	time_wait = _time_wait;
	time_active = _time_active;
}