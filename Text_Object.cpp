#include"Text_Object.h"

textObject::textObject() {
	coordinate.x = 0;
	coordinate.y = 0;
	texture_ = nullptr;
	text_ = "";
	color_ = DEFAULT_COLOR;
	font_ = nullptr;
}

textObject::~textObject() {
	;
}


void textObject::showText() {
	texture_ = loadText(text_, font_, color_, renderer);

}