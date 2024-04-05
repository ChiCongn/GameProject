
#include"ThreatObject.h"

 ThreatObject::ThreatObject() {
	coordinates.x = 0;
	coordinates.y = 0;
	coordinates.w = 0;
	coordinates.h = 0;
	texture = nullptr;
	textureRight = nullptr;
	direction = Direction::West;
	speed = 0;
	damage = 0;
	hp = 0;
	DeadAudio = nullptr;
	AttackPlayerAudio = nullptr;
}

ThreatObject::~ThreatObject() {
	destructThreat();
}

void ThreatObject::destructThreat() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
	if (textureRight != nullptr) {
		SDL_DestroyTexture(textureRight);
		textureRight = nullptr;
	}
	if (AttackPlayerAudio != nullptr) {
		Mix_FreeChunk(AttackPlayerAudio);
		AttackPlayerAudio = nullptr;
	}
	if (DeadAudio != nullptr) {
		Mix_FreeChunk(DeadAudio);
		DeadAudio = nullptr;
	}
}

void NormalMonster::initNormalMonster(int _x, int _y,std::string bulletPath, SDL_Renderer* renderer) {
	hp = HP_NORMAL_MONSTER;
	damage = DAMAGE_NORMAL_MONSTER;
	speed = SPEED_NORMAL_MONSTER;
	direction = Direction::West;
	coordinates.x = _x, coordinates.y = _y;
	coordinates.w = NORMAL_MONSTER_WIDTH;
	coordinates.h = NORMAL_MONSTER_HEIGHT;
	texture = loadImage(NORMAL_MONSTER_LEFT_PATH, renderer);
	textureRight = loadImage(NORMAL_MONSTER_RIGHT_PATH, renderer);
	for (int i = 0; i < AMOUNT_BULLET_NORMAL_MONSTER/4 ; i++) {
		normalMonsterBullet[i].initialize(BULLET_NORMAL_MONSTER_PATH, SPEED_NORMAL_MONSTER_BULLET,Direction::NorthWest, renderer);
		normalMonsterBullet[i].setCoordinates(coordinates.x, coordinates.y);
		normalMonsterBullet[i].setSizeBullet(BULLET_NORMAL_MONSTER_WIDTH, BULLET_NORMAL_MONSTER_HEIGHT);
		std::cout << "ok setCoordinates Bullet\n";
	}
	for (int i = AMOUNT_BULLET_NORMAL_MONSTER / 4; i < AMOUNT_BULLET_NORMAL_MONSTER / 2; i++) {
		normalMonsterBullet[i].initialize(BULLET_NORMAL_MONSTER_PATH, SPEED_NORMAL_MONSTER_BULLET, Direction::NorthEast, renderer);
		normalMonsterBullet[i].setCoordinates(coordinates.x + NORMAL_MONSTER_WIDTH, coordinates.y);
		normalMonsterBullet[i].setSizeBullet(BULLET_NORMAL_MONSTER_WIDTH, BULLET_NORMAL_MONSTER_HEIGHT);
		std::cout << "ok set bullet normal monster with Northwest direction\n";
	}
	for (int i = AMOUNT_BULLET_NORMAL_MONSTER / 2; i < 3*AMOUNT_BULLET_NORMAL_MONSTER / 4; i++) {
		normalMonsterBullet[i].initialize(BULLET_NORMAL_MONSTER_PATH, SPEED_NORMAL_MONSTER_BULLET, Direction::SouthEast, renderer);
		normalMonsterBullet[i].setCoordinates(coordinates.x + NORMAL_MONSTER_WIDTH, coordinates.y+ NORMAL_MONSTER_HEIGHT);
		normalMonsterBullet[i].setSizeBullet(BULLET_NORMAL_MONSTER_WIDTH, BULLET_NORMAL_MONSTER_HEIGHT);

	}
	for (int i = 3*AMOUNT_BULLET_NORMAL_MONSTER / 4; i < AMOUNT_BULLET_NORMAL_MONSTER; i++) {
		normalMonsterBullet[i].initialize(BULLET_NORMAL_MONSTER_PATH, SPEED_NORMAL_MONSTER_BULLET, Direction::SouthWest, renderer);
		normalMonsterBullet[i].setCoordinates(coordinates.x, coordinates.y + NORMAL_MONSTER_HEIGHT);
		normalMonsterBullet[i].setSizeBullet(BULLET_NORMAL_MONSTER_WIDTH, BULLET_NORMAL_MONSTER_HEIGHT);
	}
}

NormalMonster::~NormalMonster() {
	destructThreat();
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
	if (direction == Direction::West) {
		SDL_RenderCopy(renderer, texture, NULL, &coordinates);
	}
	else {
		SDL_RenderCopy(renderer, textureRight, NULL, &coordinates);
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

// ==========================================================================

void LazerMonster::initLazerMonster(int _x, int _y, SDL_Renderer* renderer) {
	hp = HP_NORMAL_MONSTER;
	damage = DAMAGE_NORMAL_MONSTER;
	direction = Direction::East;
	speed = SPEED_LAZER_MONSTER;
	coordinates.x = _x, coordinates.y = _y;
	coordinates.w = LAZER_MONSTER_WIDTH;
	coordinates.h = LAZER_MONSTER_HEIGHT;
	texture = loadImage(LAZER_MONSTER_LEFT_PATH, renderer);
	textureRight = loadImage(LAZER_MONSTER_RIGHT_PATH, renderer);
}

LazerMonster::~LazerMonster() {
	destructThreat();
}

void LazerMonster::render(SDL_Renderer* renderer) {
	if (direction == Direction::West) {
		SDL_RenderCopy(renderer, texture, NULL, &coordinates);
	}
	else {
		SDL_RenderCopy(renderer, textureRight, NULL, &coordinates);
	}
}

// ================================================================

BossMonster::~BossMonster() {
	destructThreat();
}

void BossMonster::initBossMonster(int _x, int _y, SDL_Renderer* renderer) {
	hp = HP_BOSS_MONSTER;
	damage = DAMAGE_BOSS_MONSTER;
	direction = Direction::East;
	speed = SPEED_BOSS_MONSTER;
	coordinates.x = _x, coordinates.y = _y;
	coordinates.w = BOSS_MONSTER_WIDTH;
	coordinates.h = BOSS_MONSTER_HEIGHT;
	texture = loadImage(BOSS_PATH, renderer);
	textureRight = nullptr;
}

void BossMonster::renderBossMonster(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}