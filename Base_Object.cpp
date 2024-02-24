#include"Base_Object.h"

baseObject::baseObject() {
	coordinate.x = 0;
	coordinate.y = 0;
	texture_ = nullptr;
}
baseObject::~baseObject() {
	delete[] texture_;
	texture_ = NULL;
	;
}
