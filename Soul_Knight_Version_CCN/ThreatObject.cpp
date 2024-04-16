
#include"ThreatObject.h"

 ThreatObject::ThreatObject() {
	preTimeCollision = SDL_GetTicks();
	currentTimeCollision = preTimeCollision + NEXT_TIME_CAUSE_DAMAGE;
	coordinates.x = 0;
	coordinates.y = 0;
	coordinates.w = 0;
	coordinates.h = 0;
	//sprite =new AnimatedSprite;
	direction = Direction::West;
	speed = 0;
	damage = 0;
	hp = 0;
	DeadAudio = nullptr;
	AttackPlayerAudio = nullptr;
}


void ThreatObject::destroyThreat() {
	std::cout << "start destructThreat\n";
	delete sprite;
	std::cout << "ok delete sprite*\n";
	if (AttackPlayerAudio != nullptr) {
		Mix_FreeChunk(AttackPlayerAudio);
		AttackPlayerAudio = nullptr;
	}
	if (DeadAudio != nullptr) {
		Mix_FreeChunk(DeadAudio);
		DeadAudio = nullptr;
	}
	std::cout << "ok destructThreat\n";
}

void ThreatObject::setUpNewTurn(int _hp, int x, int y) {
	hp = _hp;
	coordinates.x = x;
	coordinates.y = y;
}

void NormalMonster::initNormalMonster(int _x, int _y,std::string bulletPath, SDL_Renderer* renderer) {
	hp = HP_NORMAL_MONSTER;
	damage = DAMAGE_NORMAL_MONSTER;
	speed = SPEED_NORMAL_MONSTER;
	direction = Direction::West;
	coordinates.x = _x, coordinates.y = _y;
	coordinates.w = NORMAL_MONSTER_WIDTH;
	coordinates.h = NORMAL_MONSTER_HEIGHT;
	sprite=new AnimatedSprite(IMAGE_NORMAL_MONSTER_PATH,NORMAL_MONSTER_WIDTH,NORMAL_MONSTER_HEIGHT, NORMAL_MONSTER_FRAMES, NORMAL_MONSTER_CLIPS, renderer);
	for (int i = 0; i < AMOUNT_BULLET_NORMAL_MONSTER/4 ; i++) {
		normalMonsterBullet[i].initialize(IMAGE_BULLET_NORMAL_MONSTER_PATH, SPEED_NORMAL_MONSTER_BULLET,Direction::NorthWest, renderer);
		normalMonsterBullet[i].setCoordinates(coordinates.x, coordinates.y);
		normalMonsterBullet[i].setSizeBullet(BULLET_NORMAL_MONSTER_WIDTH, BULLET_NORMAL_MONSTER_HEIGHT);
		//std::cout << "ok setCoordinates Bullet\n";
	}
	for (int i = AMOUNT_BULLET_NORMAL_MONSTER / 4; i < AMOUNT_BULLET_NORMAL_MONSTER / 2; i++) {
		normalMonsterBullet[i].initialize(IMAGE_BULLET_NORMAL_MONSTER_PATH, SPEED_NORMAL_MONSTER_BULLET, Direction::NorthEast, renderer);
		normalMonsterBullet[i].setCoordinates(coordinates.x + NORMAL_MONSTER_WIDTH, coordinates.y);
		normalMonsterBullet[i].setSizeBullet(BULLET_NORMAL_MONSTER_WIDTH, BULLET_NORMAL_MONSTER_HEIGHT);
	}
	for (int i = AMOUNT_BULLET_NORMAL_MONSTER / 2; i < 3*AMOUNT_BULLET_NORMAL_MONSTER / 4; i++) {
		normalMonsterBullet[i].initialize(IMAGE_BULLET_NORMAL_MONSTER_PATH, SPEED_NORMAL_MONSTER_BULLET, Direction::SouthEast, renderer);
		normalMonsterBullet[i].setCoordinates(coordinates.x + NORMAL_MONSTER_WIDTH, coordinates.y+ NORMAL_MONSTER_HEIGHT);
		normalMonsterBullet[i].setSizeBullet(BULLET_NORMAL_MONSTER_WIDTH, BULLET_NORMAL_MONSTER_HEIGHT);

	}
	for (int i = 3*AMOUNT_BULLET_NORMAL_MONSTER / 4; i < AMOUNT_BULLET_NORMAL_MONSTER; i++) {
		normalMonsterBullet[i].initialize(IMAGE_BULLET_NORMAL_MONSTER_PATH, SPEED_NORMAL_MONSTER_BULLET, Direction::SouthWest, renderer);
		normalMonsterBullet[i].setCoordinates(coordinates.x, coordinates.y + NORMAL_MONSTER_HEIGHT);
		normalMonsterBullet[i].setSizeBullet(BULLET_NORMAL_MONSTER_WIDTH, BULLET_NORMAL_MONSTER_HEIGHT);
	}
}

NormalMonster::~NormalMonster() {
	delete[] normalMonsterBullet;
	//std::cout << "delete normalMonsterBullet pointer\n";
	destroyThreat();
}

void NormalMonster::normalMonsterMove(const SDL_Rect obstaclePos[]) {
	if (direction == Direction::West) {
		coordinates.x -= SPEED_NORMAL_MONSTER;
		for (int i = 0; i < 12; i++) {
			if (checkCollision(obstaclePos[i], coordinates) || coordinates.x<0) {
				direction = Direction::East;
				coordinates.x += SPEED_NORMAL_MONSTER;
				break;
			}
		}
	}
	else {
		coordinates.x += SPEED_NORMAL_MONSTER;
		for (int i = 0; i < 12; i++) {
			if (checkCollision(obstaclePos[i], coordinates) || coordinates.x + NORMAL_MONSTER_WIDTH>SCREEN_WIDTH) {
				direction = Direction::West;
				coordinates.x -= SPEED_NORMAL_MONSTER;
				break;
			}
		}
	}
}

void NormalMonster::render(SDL_Renderer* renderer) {
	sprite->setCoordinates(coordinates.x, coordinates.y);
	if (direction == Direction::West) {
		sprite->renderAnimatedSprite(renderer, SDL_FLIP_HORIZONTAL);
	}
	else {
		sprite->renderAnimatedSprite(renderer, SDL_FLIP_NONE);
	}
	for (int i = 0; i < AMOUNT_BULLET_NORMAL_MONSTER / 4; i++) {
		normalMonsterBullet[i].renderBullet(renderer);
		//std::cout << "OK render Normal Monster's Bullet\n";
	}
	for (int i = AMOUNT_BULLET_NORMAL_MONSTER / 4; i < AMOUNT_BULLET_NORMAL_MONSTER / 2; i++) {
		normalMonsterBullet[i].renderBullet(renderer);
	}
	for (int i = AMOUNT_BULLET_NORMAL_MONSTER / 2; i < 3 * AMOUNT_BULLET_NORMAL_MONSTER / 4; i++) {
		normalMonsterBullet[i].renderBullet(renderer);
	}
	for (int i = 3 * AMOUNT_BULLET_NORMAL_MONSTER / 4; i < AMOUNT_BULLET_NORMAL_MONSTER; i++) {
		normalMonsterBullet[i].renderBullet(renderer);
	}
}

void NormalMonster::setNewTurnBullet() {
	for (int i = 0; i < AMOUNT_BULLET_NORMAL_MONSTER / 4; i++) {
		normalMonsterBullet[i].setCoordinates(coordinates.x, coordinates.y);	
	}
	for (int i = AMOUNT_BULLET_NORMAL_MONSTER / 4; i < AMOUNT_BULLET_NORMAL_MONSTER / 2; i++) {
		normalMonsterBullet[i].setCoordinates(coordinates.x + NORMAL_MONSTER_WIDTH, coordinates.y);
	}
	for (int i = AMOUNT_BULLET_NORMAL_MONSTER / 2; i < 3 * AMOUNT_BULLET_NORMAL_MONSTER / 4; i++) {
		normalMonsterBullet[i].setCoordinates(coordinates.x + NORMAL_MONSTER_WIDTH, coordinates.y + NORMAL_MONSTER_HEIGHT);
	}
	for (int i = 3 * AMOUNT_BULLET_NORMAL_MONSTER / 4; i < AMOUNT_BULLET_NORMAL_MONSTER; i++) {
		normalMonsterBullet[i].setCoordinates(coordinates.x, coordinates.y + NORMAL_MONSTER_HEIGHT);
	}
}

// ==========================================================================

void LazerMonster::initLazerMonster(int _x, int _y, SDL_Renderer* renderer) {
	hp = HP_NORMAL_MONSTER;
	damage = DAMAGE_NORMAL_MONSTER;
	direction = Direction::West;
	speed = SPEED_LAZER_MONSTER;
	coordinates.x = _x, coordinates.y = _y;
	coordinates.w = LAZER_MONSTER_WIDTH;
	coordinates.h = LAZER_MONSTER_HEIGHT;
	sprite=new AnimatedSprite(IMAGE_LAZER_MONSTER_PATH,LAZER_MONSTER_WIDTH,LAZER_MONSTER_HEIGHT, LAZER_MONSTER_FRAMES, LAZER_MONSTER_CLIPS, renderer);

}

LazerMonster::~LazerMonster() {
	destroyThreat();
}

void LazerMonster::render(SDL_Renderer* renderer) {
	sprite->setCoordinates(coordinates.x, coordinates.y);
	if (direction == Direction::West) {
		sprite->renderAnimatedSprite(renderer, SDL_FLIP_HORIZONTAL);		
	}
	else {
		sprite->renderAnimatedSprite(renderer,SDL_FLIP_NONE);	
	}

}

void LazerMonster::lazerMonsterMove() {
	if (direction == Direction::West) {
		coordinates.x -= SPEED_NORMAL_MONSTER;
		for (int i = 0; i < 12; i++) {
			if (checkCollision(obstaclePos[i], coordinates) || coordinates.x < 0) {
				direction = Direction::East;
				coordinates.x += SPEED_LAZER_MONSTER;
				//std::cout << "chanceDirection-> East\n";
				break;
			}
		}
	}
	else {
		coordinates.x += SPEED_LAZER_MONSTER;
		for (int i = 0; i < 12; i++) {
			if (checkCollision(obstaclePos[i], coordinates) || coordinates.x + NORMAL_MONSTER_WIDTH > SCREEN_WIDTH) {
				direction = Direction::West;
				coordinates.x -= SPEED_NORMAL_MONSTER;
				//std::cout << "chance DirectionWest\n";
				break;
			}
		}
	}
}

// ================================================================

BossMonster::~BossMonster() {
	std::cout << " start ~BossMonster\n";
	delete[] bulletBossMonster;
	std::cout << "ok delete bulletBossMonster*[]\n";
	destroyThreat();
	std::cout << "ok ~BossMonster\n";
}

void BossMonster::initBossMonster(int _x, int _y,std::string bulletPath, SDL_Renderer* renderer) {
	hp = HP_BOSS_MONSTER;
	damage = DAMAGE_BOSS_MONSTER;
	direction = Direction::East;
	speed = SPEED_BOSS_MONSTER;
	coordinates.x = _x, coordinates.y = _y;
	coordinates.w = BOSS_MONSTER_WIDTH;
	coordinates.h = BOSS_MONSTER_HEIGHT;
	sprite=new AnimatedSprite(IMAGE_BOSS_MONSTER_PATH, BOSS_MONSTER_WIDTH, BOSS_MONSTER_HEIGHT, BOSS_MONSTER_FRAMES, BOSS_MONSTER_CLIPS, renderer);

	for (int i = 0; i < AMOUNT_BULLET_BOSS_MONSTER / 4; i++) {
		bulletBossMonster[i].initialize(IMAGE_BULLET_BOSS_MONSTER_PATH, SPEED_BOSS_MONSTER_BULLET, Direction::NorthEast, renderer);
		bulletBossMonster[i].setCoordinates(coordinates.x+ BOSS_MONSTER_WIDTH, coordinates.y + i*50);
		bulletBossMonster[i].setSizeBullet(BULLET_BOSS_MONSTER_WIDTH, BULLET_BOSS_MONSTER_HEIGHT);		
	}
	for (int i = AMOUNT_BULLET_BOSS_MONSTER / 4; i < AMOUNT_BULLET_BOSS_MONSTER/2; i++) {
		bulletBossMonster[i].initialize(IMAGE_BULLET_BOSS_MONSTER_PATH, SPEED_BOSS_MONSTER_BULLET, Direction::SouthEast, renderer);
		bulletBossMonster[i].setCoordinates(coordinates.x, coordinates.y + (i - AMOUNT_BULLET_BOSS_MONSTER / 4) * 50);
		bulletBossMonster[i].setSizeBullet(BULLET_BOSS_MONSTER_WIDTH, BULLET_BOSS_MONSTER_HEIGHT);
	}
	for (int i = AMOUNT_BULLET_BOSS_MONSTER / 2; i < 3*AMOUNT_BULLET_BOSS_MONSTER/4; i++) {
		bulletBossMonster[i].initialize(IMAGE_BULLET_BOSS_MONSTER_PATH, SPEED_BOSS_MONSTER_BULLET, Direction::NorthWest, renderer);
		bulletBossMonster[i].setCoordinates(coordinates.x, coordinates.y + (i - AMOUNT_BULLET_BOSS_MONSTER / 2) * 50);
		bulletBossMonster[i].setSizeBullet(BULLET_BOSS_MONSTER_WIDTH, BULLET_BOSS_MONSTER_HEIGHT);
	}
	for (int i = 3*AMOUNT_BULLET_BOSS_MONSTER / 4; i < AMOUNT_BULLET_BOSS_MONSTER; i++) {
		bulletBossMonster[i].initialize(IMAGE_BULLET_BOSS_MONSTER_PATH, SPEED_BOSS_MONSTER_BULLET, Direction::SouthWest, renderer);
		bulletBossMonster[i].setCoordinates(coordinates.x, coordinates.y + (i-3*AMOUNT_BULLET_BOSS_MONSTER/4)*50 );
		bulletBossMonster[i].setSizeBullet(BULLET_BOSS_MONSTER_WIDTH, BULLET_BOSS_MONSTER_HEIGHT);		
	}
}

void BossMonster::renderBossMonster(SDL_Renderer* renderer) {
	sprite->setCoordinates(coordinates.x, coordinates.y);
	if (direction == Direction::West) {
		sprite->renderAnimatedSprite(renderer,SDL_FLIP_HORIZONTAL);
	}
	else {
		sprite->renderAnimatedSprite(renderer,SDL_FLIP_NONE);
	}
}

void BossMonster::BossMove() {
	switch (direction)
	{
	case Direction::North:
		coordinates.y -= speed;
		if (coordinates.y <= 240) {
			direction = Direction::East;
		}
		break;	
	case Direction::West:
		coordinates.x -= speed;
		if (coordinates.x <= 700) {
			direction = Direction::North;
		}
		break;
	case Direction::East:
		coordinates.x += speed;
		if (coordinates.x >=1080) {
			direction = Direction::South;
		}
		break;
	case Direction::South:
		coordinates.y += speed;
		if (coordinates.y >= 360) {
			direction = Direction::West;
		}
		break;	
	default:
		break;
	}
}

void BossMonster::setNewTurnBullet() {
	for (int i = 0; i < AMOUNT_BULLET_BOSS_MONSTER / 4; i++) {
		bulletBossMonster[i].setCoordinates(coordinates.x + BOSS_MONSTER_WIDTH, coordinates.y + i * 50);
	}
	for (int i = AMOUNT_BULLET_BOSS_MONSTER / 4; i < AMOUNT_BULLET_BOSS_MONSTER / 2; i++) {
		bulletBossMonster[i].setCoordinates(coordinates.x, coordinates.y + (i - AMOUNT_BULLET_BOSS_MONSTER / 4) * 50);
	}
	for (int i = AMOUNT_BULLET_BOSS_MONSTER / 2; i < 3 * AMOUNT_BULLET_BOSS_MONSTER / 4; i++) {
		bulletBossMonster[i].setCoordinates(coordinates.x, coordinates.y + (i - AMOUNT_BULLET_BOSS_MONSTER / 2) * 50);
	}
	for (int i = 3 * AMOUNT_BULLET_BOSS_MONSTER / 4; i < AMOUNT_BULLET_BOSS_MONSTER; i++) {
		bulletBossMonster[i].setCoordinates(coordinates.x, coordinates.y + (i - 3 * AMOUNT_BULLET_BOSS_MONSTER / 4) * 50);
	}
}