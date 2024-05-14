
#include"Common.h"
#include"Animation.h"

#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

class BaseObject {
protected:
	int speed;
	//Animation* animation;
	SDL_Rect coordinates;
	
public:
	BaseObject();
	virtual ~BaseObject();
	void setCoordinates(int _x, int _y) { coordinates.x = _x, coordinates.y = _y; }
	SDL_Rect getCoordinates() { return coordinates; }
};

#endif