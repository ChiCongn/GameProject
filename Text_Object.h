#pragma once
#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H

#include"Common.h"
#include"Base_Object.h"
#include<string>

class textObject : public baseObject
{
	std::string text_;
	SDL_Colour color_;
	TTF_Font* font_;
public:
	textObject();
	~textObject();
	void setText(std::string text) { text_ = text; }
	void setColor(SDL_Color color) { color_ = color; }
	void setFont(TTF_Font* font) { font_ = font; }
	void showText();
};


#endif TEXT_OBJECT_H