
#include"BulletObject.h"

void BulletObject::initialize(std::string path,int _speed, Direction _direction, SDL_Renderer* renderer) {
	direction = _direction;
	speed = _speed;
	texture = loadImage(path, renderer);
}

void BulletObject::destructBullet() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

BulletObject::~BulletObject() {
	destructBullet();
}

void BulletObject::BulletMove() {
	switch (direction)
	{
	case Direction::North:
		coordinates.y -= speed;
		break;
	case Direction::South:
		coordinates.y += speed;
		break;
	case Direction::West:
		coordinates.x -= speed;
		break;
	case Direction::East:
		coordinates.x += speed;
		break;
	case Direction::NorthWest:
		coordinates.x -= speed;
		coordinates.y -= speed;
		break;
	case Direction::SouthWest:
		coordinates.x -= speed;
		coordinates.y += speed;
		break;
	case Direction::SouthEast:
		coordinates.x += speed;
		coordinates.y += speed;
		break;
	case Direction::NorthEast:
		coordinates.x += speed;
		coordinates.y -= speed;
		break;
	default:
		break;
	}
	
}


void BulletObject::renderBullet(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}
