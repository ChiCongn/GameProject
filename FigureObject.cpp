
#include"FigureObject.h"

FigureObject::FigureObject() {
	coordinates.x = 200;
	coordinates.y = 405;
	coordinates.w = FIGURE_WIDTH;
	coordinates.h = FIGURE_HEIGHT;
	speed = 30;
	status = 0;
	isFire = false;
	directionLeft = true;
	texture = nullptr;
}

FigureObject::~FigureObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
}

void FigureObject::updateTexture(SDL_Renderer* renderer) {
	if (directionLeft) {
		texture = loadImage("TankLeft.jpg", renderer);
	}
	else texture = loadImage("TankRight.jpg", renderer);
	
}

void FigureObject::handleMoveAction(SDL_Event&e) {
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym) {
		case SDLK_RIGHT:
			directionLeft = false;
			coordinates.x += speed;
			if (coordinates.x + FIGURE_WIDTH > SCREEN_WIDTH)
				coordinates.x -= speed;
			break;

		case SDLK_LEFT:
			directionLeft = true;
			coordinates.x -= speed;
			if (coordinates.x <0)
				coordinates.x += speed;
			break;

		default:
			break;
		}
	}
	
}


void FigureObject::renderAttack(SDL_Renderer* renderer) {		
	if (isFire) {
		for (int i = 0; i < bullet.size(); ++i) {
			bullet[i].renderBullet(renderer);
			bullet[i].move();			
			if (bullet[i].getCoordinates().x+BULLET_WIDTH > SCREEN_WIDTH || bullet[i].getCoordinates().x<0 || bullet[i].getCoordinates().y<0) {
				bullet.erase(bullet.begin() + i);
			}
		}
	}
}

void FigureObject::attackThreats(SDL_Event&e, SDL_Renderer* renderer) {
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_SPACE) {
			isFire = true;
			SkillObject newBullet;
			//newBullet.setCoordinates(30, 300);
			if (directionLeft) {
				newBullet.setCoordinates(getCoordinates().x, getCoordinates().y);
				newBullet.setFireLeft(true);
			}
			else {
				newBullet.setCoordinates(getCoordinates().x + FIGURE_WIDTH, getCoordinates().y);
				newBullet.setFireLeft(false);
			}
			bullet.push_back(newBullet);
		}
	}	
}
