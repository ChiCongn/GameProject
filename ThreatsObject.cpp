
#include"ThreatsObject.h"

ThreatsObject::ThreatsObject() {
	coordinates.x = 0;
	coordinates.y = 0;
	coordinates.w = B52_WIDTH;
	coordinates.h = B52_HEIGHT;
	texture = nullptr;
	speed = B52_WIDTH/4;
}

ThreatsObject::~ThreatsObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
}

void ThreatsObject::setTexture(SDL_Renderer* renderer) {
	texture = loadImage("B52Right.jpg", renderer);
}


void ThreatsObject::autoMove() {
	//coordinates.x = RANDOMCOORDINATES_X[rand()%sizeX];
	//coordinates.y = RANDOMCOORDINATES_Y[rand() % sizeY];	
	coordinates.x += speed;
	if (coordinates.x + B52_WIDTH > SCREEN_WIDTH) {
		coordinates.x = 2;
	}	
}


void ThreatsObject::attackPlayer() {
	;
}