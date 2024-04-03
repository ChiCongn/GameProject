
#include"ThreatObject.h"

//void ThreatObject::intialize(SDL_Rect rect,int _speed, int _damage, std::string path, SDL_Renderer* renderer) {
//	coordinates.x = rect.x;
//	coordinates.y = rect.y;
//	coordinates.w = rect.w;
//	coordinates.h = rect.h;
//	texture = loadImage(path, renderer);
//	speed = _speed;
//	damage = _damage;
//	DeadAudio = loadAudio(THREAT_DEAD_AUDIO_PATH);
//	AttackPlayerAudio = loadAudio(ATTACK_PLAYER_AUDIO_PATH);
//}

ThreatObject::~ThreatObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
	if (AttackPlayerAudio!=nullptr) {
		Mix_FreeChunk(AttackPlayerAudio);
		AttackPlayerAudio = nullptr;
	}
	if (DeadAudio != nullptr) {
		Mix_FreeChunk(DeadAudio);
		DeadAudio = nullptr;
	}
}

void NormalMonster::initNormalMonster(int _x, int _y, SDL_Renderer* renderer) {
	hp = HP_NORMAL_MONSTER;
	damage = DAMAGE_NORMAL_MONSTER;
	speed = SPEED_NORMAL_MONSTER;
	coordinates.x = _x, coordinates.y = _y;
	coordinates.w = NORMAL_MONSTER_WIDTH;
	coordinates.h = NORMAL_MONSTER_HEIGHT;
	texture = loadImage(NORMAL_MONSTER_PATH, renderer);
}

NormalMonster::~NormalMonster() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
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

void LazerMonster::initLazerMonster(int _x, int _y, SDL_Renderer* renderer) {
	hp = HP_NORMAL_MONSTER;
	damage = DAMAGE_NORMAL_MONSTER;
	speed = SPEED_LAZER_MONSTER;
	coordinates.x = _x, coordinates.y = _y;
	coordinates.w = LAZER_MONSTER_WIDTH;
	coordinates.h = LAZER_MONSTER_HEIGHT;
	texture = loadImage(LAZER_MONSTER_PATH, renderer);
}

