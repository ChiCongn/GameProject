
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
	textureRight = nullptr;
}

FigureObject::~FigureObject() {
	for (auto it : bullet) {
		it.~BulletObject();
	}
	lightning.~SkillObject();
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
	if (textureRight != nullptr) {
		SDL_DestroyTexture(textureRight);
	}
}

void FigureObject::setTextureFigure(SDL_Renderer* renderer) {	
	texture = loadImage("catLeft.jpg", renderer);	
	textureRight = loadImage("catRight.jpg", renderer);	
	lightning.setTextureSkill(renderer);
}

void FigureObject::render(SDL_Renderer* renderer) {
	if (directionLeft) {
		SDL_RenderCopy(renderer, texture, NULL, &coordinates);
	}
	else {
		SDL_RenderCopy(renderer, textureRight, NULL, &coordinates);
	}
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

		case SDLK_UP:
			coordinates.y -= speed;
			if (coordinates.y < 0)
				coordinates.y += speed;
			break;

		case SDLK_DOWN:
			coordinates.y += speed;
			if (coordinates.y+FIGURE_HEIGHT > SCREEN_HEIGHT)
				coordinates.y -= speed;
			break;

		default:
			break;
		}
	}
	
}


void FigureObject::renderAttack(SDL_Renderer* renderer) {		
	if (isFire) {
		for (int i = 0; i < bullet.size(); ++i) {
			bullet[i].setTextureBullet( renderer);
			bullet[i].render(renderer);			
			bullet[i].move();			
			if (bullet[i].getCoordinates().x+BULLET_WIDTH > SCREEN_WIDTH || bullet[i].getCoordinates().x<0 || bullet[i].getCoordinates().y<0) {				
				Mix_FreeChunk(bullet[i].sound);
				bullet.erase(bullet.begin() + i);
			}
		}
	}
}

void FigureObject::attackThreats(SDL_Event&e, SDL_Renderer* renderer) {
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_SPACE) {
			isFire = true;
			BulletObject newBullet;
			
			if (directionLeft) {
				newBullet.setCoordinates(getCoordinates().x, getCoordinates().y+39);
				newBullet.setDirectionBullet(DIRECTON_LEFT);
			}
			else {
				newBullet.setCoordinates(getCoordinates().x + FIGURE_WIDTH, getCoordinates().y+39);
				newBullet.setDirectionBullet(DIRECTION_RIGHT);
			}
			//newBullet.setAudio();
			//Mix_PlayChannel(-1,newBullet.sound, 0);
			bullet.push_back(newBullet);
		}
	}	
}

void FigureObject::setCoordinatesSkill(SDL_Event& e) {	
	lightning.countdownSkill();
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		int mouseX, mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);
		lightning.setCoordinates(mouseX, mouseY-LINGHTNING_HEIGHT/2);
	}			
}

void FigureObject::renderSkill(SDL_Renderer* renderer) {
	//if (lightning.usedSkill) {
		lightning.render(renderer);
	//}
}