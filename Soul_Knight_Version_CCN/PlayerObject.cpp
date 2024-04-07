
#include"PlayerObject.h"

void PlayerObject::initPlayer(SDL_Renderer* renderer) {
	std::cout << "start init Player\n";
	hp = MAX_HP_PLAYER, ex = 0;
	damage = DEFAUT_DAMAGE_PLAYER;
	speed = DEFAULT_SPEED_PLAYER;
	coordinates.x = 0;
	coordinates.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
	coordinates.w = PLAYER_WIDTH;
	coordinates.h = PLAYER_HEIGHT;

	attack = false;
	direction = Direction::East;
	std::cout << "start init AnimatedSpirte*\n";
	sprite = new AnimatedSprite(IMAGE_PLAYER_PATH, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_FRAMES, PLAYER_CLIPS, renderer);
	std::cout << "ok init AnimatedSprite* -> start init playerSkill*\n";
	playerSkill = new AnimatedSprite(IMAGE_PLAYER_SKILL_PATH, PLAYER_SKILL_WIDTH, PLAYER_SKILL_HEIGHT, PLAYER_SKILL_FRAMES, PLAYER_SKILL_CLIPS, renderer);
	std::cout << "ok init playerSkill*-> start init Hp*\n";
	Hp->initSupportObject(0, 0, 20);
	Hp->setImageSupport(IMAGE_HP_PATH, renderer);
	std::cout << "ok init Hp*->start init Ex*\n";
	Ex->initSupportObject(0, 10, 20);
	Ex->setImageSupport(IMAGE_EX_PATH, renderer);
	std::cout << "ok init Player\n";
}

//PlayerObject::PlayerObject() {	
//	std::cout<<"init dafault playerObject\n";
//	//initPlayer(renderer);
//	std::cout << "ok constructor PlayeObject\n";
//}

PlayerObject::~PlayerObject() {
	delete sprite;
	//delete playerSkill;
	delete Hp;
	delete Ex;
	delete playerSkill;
	/*Mix_FreeChunk(attackAudio);
	Mix_FreeChunk(getDamageAudio);
	Mix_FreeChunk(levelUpAudio);
	Mix_FreeChunk(getExAudio);*/
	//attackAudio = getDamageAudio = levelUpAudio = getExAudio = nullptr;
}

void PlayerObject::renderPlayer(SDL_Renderer* renderer) {
	sprite->setCoordinates(coordinates.x, coordinates.y);
	if (direction == Direction::West) {
		sprite->renderAnimatedSprite(renderer, SDL_FLIP_HORIZONTAL);
	}
	else {
		sprite->renderAnimatedSprite(renderer, SDL_FLIP_NONE);
	}
	if (attack) {	
		if (direction == Direction::East) {
			playerSkill->setCoordinates(coordinates.x, coordinates.y - 18);
			playerSkill->renderAnimatedSprite(renderer, SDL_FLIP_HORIZONTAL);
		}
		else {
			playerSkill->setCoordinates(coordinates.x - 15, coordinates.y-18);
			playerSkill->renderAnimatedSprite(renderer, SDL_FLIP_NONE);
		}
	}
	Hp->render(hp, renderer);
	Ex->render(ex, renderer);
	attack = false;
	playerSkill->setCoordinates(0, 0);
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

void PlayerObject::attackThreat(SDL_Event e) {
	if (e.key.keysym.sym==SDLK_SPACE) {
		attack = true;
	}
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