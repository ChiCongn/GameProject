
#include"Skill.h"


Skill::Skill(const std::string& animationPath, int width, int height, const int& frames, const int clips[][4], SDL_Renderer* renderer) {
	skill = new Animation(animationPath, animationPath, width, height, frames, clips, renderer);	
}

Skill::~Skill() {
	delete skill;
}

void Skill::render(SDL_Renderer* renderer) {
	if(time_active>0)
		skill->renderAnimation(renderer, Direction::East);
}

void Skill::setCoordinates(int x, int y) {
	skill->coordinates.x = x;
	skill->coordinates.y = y;
}

void Skill::setTarget(int x, int y) {
	if (time_wait <= 0) {
		target.x = x;
		target.y = y;
		time_wait = TIME_WAIT_SKILL;
		time_active = TIME_ATTACK;
	}
}

void Skill::moveToTarget() {
	if (time_wait<=0 ) {
		int deltaX = skill->coordinates.x + skill->coordinates.w / 2 - target.x;
		int deltaY = skill->coordinates.y + skill->coordinates.h / 2 - target.y;
		float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
		if (distance <5 ) {
			time_wait = TIME_WAIT_SKILL;
			return;
		}
		deltaX = static_cast<int>((deltaX / distance) * 5.0);
		deltaY = static_cast<int>((deltaY / distance) * 5.0);

		skill->coordinates.x -= deltaX;
		skill->coordinates.y -= deltaY;		
	}
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