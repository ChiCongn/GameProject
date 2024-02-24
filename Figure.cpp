#include"Figure.h"


figure::figure() {
	coordinate.x = 0;
	coordinate.y = 0;
	coordinate.w = WIDTH_FIGURE;
	coordinate.h = HEIGHT_FIGURE;
	texture_ = nullptr;
	speed_ = 0;
	x_val = 0;
	y_val = 0;
}
figure::~figure() {
	;
}

void figure::show() {
	texture_ = loadImage("aircraft.png", renderer);
	SDL_RenderCopy(renderer, texture_, NULL, &coordinate);
	SDL_RenderPresent(renderer);
}

void figure::handleInputAction(SDL_Event event, int& speed) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_UP: 
			y_val -= speed;
			break;
		case SDLK_DOWN: 
			y_val += speed;
			break;
		case SDLK_RIGHT:
			x_val += speed;
			break;
		case SDLK_LEFT:
			x_val -= speed;			
			break;

		case SDLK_SPACE:
			bulletObject* bullet = new bulletObject();
			bullet->setBulletType(bulletObject::BULLET);
			bullet->setWidthHeight(WIDTH_BULLET, HEIGHT_BULLET);
			bullet->setCoordinate(this->coordinate.x + WIDTH_FIGURE, this->coordinate.y + HEIGHT_FIGURE);
			break;

		case SDLK_8:


		default:
			break;
		}		
	}
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			y_val += speed;			
			break;
		case SDLK_DOWN:
			y_val -= speed;
			break;
		case SDLK_RIGHT:
			x_val -= speed;
			break;
		case SDLK_LEFT:
			x_val += speed;
			break;
		default:
			break;
		}
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN) {
		;
	}
	else if (event.type == SDL_MOUSEBUTTONUP) {
		;
	}
	else {
		;
	}
}

void figure::handleMove() {
	coordinate.x += x_val;
	if (coordinate.x < 0 || coordinate.x + WIDTH_FIGURE > SCREEN_WIDTH)
		coordinate.x -= x_val;

	coordinate.y += y_val;
	if (coordinate.y <0 || coordinate.y + HEIGHT_FIGURE > SCREEN_HEIGHT)
		coordinate.y -= y_val;
}