
#include"BaseObject.h"

BaseObject::BaseObject() {
	speed = 0;
	coordinates.x = 0;
	coordinates.y = 0;
}

BaseObject::~BaseObject() {
	sprite->~AnimatedSprite();
}

