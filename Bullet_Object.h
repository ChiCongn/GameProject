#pragma once
#ifndef BULLET_OBJECT_H
#define BULLET_OBJECT_H

#include"Common.h"
#include"Base_Object.h"
#include"Figure.h"

#define WIDTH_ROCKET 40
#define HEIGHT_ROCKET 30
#define WIDTH_BULLET 5
#define HEIGHT_BULLET 5

class bulletObject :public baseObject
{
private:
	bool is_move_;
	int bulletType_;
	int x_val;
	int y_val;
public:
	enum bulletType {
		NONE = 0,
		ROCKET = 2,
		BULLET = 1
	};
	bulletObject();
	~bulletObject();
	void setWidthHeight(int width, int height) { coordinate.w = width; coordinate.h = height; }
	void setBulletType(int type) { bulletType_= type; }
	void showBullet(figure aircraft);
	void moveBullet();
		
};


#endif BULLET_OBJECT_H