
#include"BaseObject.h"

static const int BULLET_WIDTH = 10;
static const int BULLET_HEIGHT = 10;

class BulletObject :public BaseObject {
	bool isFire;
	bool direction;
	
public:
	Mix_Chunk* sound;
	BulletObject();
	~BulletObject();
	void setCoordinatesBullet(SDL_Renderer* renderer);
	void setTextureBullet(SDL_Renderer* renderer);
	void setDirectionBullet(bool _direction) { direction = _direction; }
	void setAudio();
	void move();
	void render(SDL_Renderer* renderer) override;
};