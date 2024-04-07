
#include"BaseObject.h"

BaseObject::BaseObject() {
	speed = 0;
	coordinates.x = 0;
	coordinates.y = 0;
}

BaseObject::~BaseObject() {
	std::cout<<"start ~BaseObject\n->delete sprite*";
	//delete sprite;
	std::cout << "ok delete sprite* of BaseObject->ok~BaseObject\n";
}

