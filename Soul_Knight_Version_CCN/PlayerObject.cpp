
#include"PlayerObject.h"

void PlayerObject::initializePlayer(SDL_Renderer* renderer) {
	sprite->initAnimatedSprite(IMAGE_PLAYER_PATH, PLAYER_FRAMES, PLAYER_CLIPS, renderer);
	hp = MAX_HP_PLAYER;
	damage = DEFAUT_DAMAGE_PLAYER;
	ex = 0;
	speed = DEFAULT_SPEED_PLAYER;
	direction = Direction::East;
	coordinates.x = 0;
	coordinates.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
	coordinates.w = PLAYER_WIDTH;
	coordinates.h = PLAYER_HEIGHT;
	Hp->initialize(0, 0, 10);
	Hp->setImageSupport(IMAGE_HP_PATH, renderer);
	Ex->initialize(0, 10, 10);
	Ex->setImageSupport(IMAGE_EX_PATH, renderer);
}

PlayerObject::PlayerObject() {
	//textureLeft = nullptr;
	hp = MAX_HP_PLAYER;
	damage = DEFAUT_DAMAGE_PLAYER;
	ex = 0;
	direction = Direction::East;
	coordinates.x = 0;
	coordinates.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
	coordinates.w = PLAYER_WIDTH;
	coordinates.h = PLAYER_HEIGHT;
	//Hp.initialize(0, 0, 10);
	//Ex.initialize(0, 10, 10);

	/*getDamageAudio = loadAudio(GET_DAMAGE_AUDIO_PATH);
	levelUpAudio = loadAudio(LEVEL_UP_AUDIO_PATH);
	attackAudio = loadAudio(ATTACK_AUDIO_PATH);
	getExAudio = loadAudio(GET_EX_AUDIO_PATH);*/
	std::cout<<"init dafault playerObject\n";
}

PlayerObject::~PlayerObject() {
	sprite->~AnimatedSprite();
	delete Hp;
	delete Ex;
	/*Mix_FreeChunk(attackAudio);
	Mix_FreeChunk(getDamageAudio);
	Mix_FreeChunk(levelUpAudio);
	Mix_FreeChunk(getExAudio);*/
	//attackAudio = getDamageAudio = levelUpAudio = getExAudio = nullptr;
}

void PlayerObject::playerMove(SDL_Event e, const SDL_Rect obstacle[]) {
	//std::cout << "PlayerMove\n";
	switch (e.key.keysym.sym)
	{
	case SDLK_UP:
		coordinates.y -= speed;
		if (coordinates.y < 50) {
			coordinates.y = 50;
		}
		for (int i = 0; i < 12; i++) {
			if (checkCollision(obstacle[i], coordinates)) {
				coordinates.y = obstacle[i].y + obstacle[i].h;
				break;
			}
		}
		break;

	case SDLK_DOWN:
		coordinates.y += speed;
		if (coordinates.y +PLAYER_HEIGHT > SCREEN_HEIGHT) {
			coordinates.y = SCREEN_HEIGHT-PLAYER_HEIGHT;
		}
		for (int i = 0; i < 12; i++) {
			if (checkCollision(obstacle[i], coordinates)) {
				coordinates.y = obstacle[i].y - PLAYER_HEIGHT;
				break;
			}
		}
		break;

	case SDLK_LEFT:
		direction = Direction::West;
		coordinates.x -= speed;
		if (coordinates.x < 0) {
			coordinates.x = 0;
		}
		for (int i = 0; i < 12; i++) {
			if (checkCollision(obstacle[i], coordinates)) {
				coordinates.x = obstacle[i].x + obstacle[i].w;
				break;
			}
		}
		break;

	case SDLK_RIGHT:
		direction = Direction::East;
		coordinates.x += speed;
		if (coordinates.x + PLAYER_WIDTH > SCREEN_WIDTH) {
			coordinates.x = SCREEN_WIDTH - PLAYER_WIDTH;
		}
		for (int i = 0; i < 12; i++) {
			if (checkCollision(obstacle[i], coordinates)) {
				coordinates.x = obstacle[i].x - PLAYER_WIDTH;
				break;
			}
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

void PlayerObject::renderPlayer(SDL_Renderer* renderer) {
	if (direction == Direction::West) {
		sprite->renderAnimatedSprite(renderer, coordinates,SDL_FLIP_HORIZONTAL);
	}
	else {
		sprite->renderAnimatedSprite(renderer, coordinates, SDL_FLIP_NONE);
	}
	
	Hp->render(hp,renderer);
	Ex->render(ex, renderer);
}

void PlayerObject::setUpNewTurn() {
	hp = MAX_HP_PLAYER;
	ex = 0;
	damage = DEFAUT_DAMAGE_PLAYER;
}

//void PlayerObject::collisionWithThreat(BossMonster* boss, NormalMonster* normalMonster, LazerMonster* lazerMonster) {
//	if (checkCollision(coordinates, boss->getCoordinates())) {
//		getDamge(DAMAGE_BOSS_MONSTER);
//	}
//	for (int i = 0; i < AMOUNT_BULLET_BOSS_MONSTER; i++) {
//		if(checkCollision(coor))
//	}
//	if (checkCollision(coordinates, normalMonster->getCoordinates())) {
//		getDamge(DAMAGE_NORMAL_MONSTER);
//	}
//}