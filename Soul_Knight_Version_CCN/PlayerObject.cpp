
#include"PlayerObject.h"

void PlayerObject::intialize( SDL_Renderer* renderer) {
	texture = loadImage(IMAGE_PLAYER_RIGHT_PATH, renderer);
	textureLeft = loadImage(IMAGE_PLAYER_LEFT_PATH, renderer);
	hp = MAX_HP_PLAYER;
	damage = DEFAUT_DAMAGE_PLAYER;
	ex = 0;
	coordinates.x = 0;
	coordinates.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
	coordinates.w = PLAYER_WIDTH;
	coordinates.h = PLAYER_HEIGHT;
}

PlayerObject::~PlayerObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
	Mix_FreeChunk(attackAudio);
	Mix_FreeChunk(getDamageAudio);
	Mix_FreeChunk(levelUpAudio);
	Mix_FreeChunk(getExAudio);
	attackAudio = getDamageAudio = levelUpAudio = getExAudio = nullptr;
}

void PlayerObject::move(SDL_Event e) {
	switch (e.key.keysym.sym)
	{
	case SDLK_UP:
		coordinates.y -= speed;
		if (coordinates.y < 0) {
			coordinates.y += speed;
		}
		break;

	case SDLK_DOWN:
		coordinates.y += speed;
		if (coordinates.y +PLAYER_HEIGHT > SCREEN_HEIGHT) {
			coordinates.y -= speed;
		}
		break;

	case SDLK_LEFT:
		coordinates.x -= speed;
		if (coordinates.x < 0) {
			coordinates.x += speed;
		}
		break;

	case SDLK_RIGHT:
		coordinates.x += speed;
		if (coordinates.x + PLAYER_WIDTH > SCREEN_WIDTH) {
			coordinates.x -= speed;
		}
		break;

	default:
		break;
	}
}

void PlayerObject::levelUp() {
	if (ex >= 100) {
		ex -= 100;
		damage += ADD_DAMAGE;
		speed += ADD_SPEED;
	}
}

void PlayerObject::setUpNewTurn() {
	hp = MAX_HP_PLAYER;
	ex = 0;
	damage = DEFAUT_DAMAGE_PLAYER;
}