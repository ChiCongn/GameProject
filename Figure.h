#pragma once
#include"Common.h"
#include"base_object.h"
#include"Bullet_Object.h"
#include<vector>

#define WIDTH_FIGURE 120
#define HEIGHT_FIGURE 100

class figure : public baseObject
{
private:		
	int x_val;
	int y_val;
	std::vector<bulletObject*> bullet_;
public:
	int speed_;
	figure();
	~figure();
	void show();
	void setSpeed(int speed) { speed_ = speed; }
	void handleInputAction(SDL_Event event, int& speed);
	void handleMove();
	void SetBullet(std::vector<bulletObject*> bullet)
	{
		bullet_ = bullet;
	}
};