
#include"GameLevel.h"

Structure::Structure(int level, SDL_Renderer* renderer) {
	amount = level;
	structure = new Texture(200, 100, TOWER_WIDTH, TOWER_HEIGHT);
	structure->setImageTexture(TOWER_PATH, renderer);
	//std::cout << "init thorn\n";
	thorn = new Animation*[4]; 
	for (int i = 0; i< 4; i++) {
		thorn[i]= new Animation(THORN_PATH, THORN_PATH, THORN_WIDTH, THORN_HEIGHT, THORN_FRAMES, THORN_CLIPS, renderer);
	}
	//std::cout << "ok init thorn\n";
	normalMonster = new NormalMonster*[level];
	alienMonster = new AlienMonster * [level];
	for (int i = 0; i < level; i++) {
		normalMonster[i] = new NormalMonster(renderer);
		normalMonster[i]->animation->setCoordinates(structure->coordinates.x + i * NORMAL_MONSTER_WIDTH, structure->coordinates.y- 30);
		alienMonster[i] = new AlienMonster(renderer);
		alienMonster[i]->animation->setCoordinates(structure->coordinates.x - 30, structure->coordinates.y + i*ALIEN_HEIGHT);
	}
	knightMonster = new KnightMonster(renderer);
	knightMonster->animation->setCoordinates(structure->coordinates.x, structure->coordinates.y + TOWER_HEIGHT);
	hp = HP_STRUCTURE;	
	Hp = new Texture(0, 0, 30, 8);
	Hp->setImageTexture(IMAGE_HP_PATH, renderer);
}

Structure::~Structure() {
	delete[] alienMonster;
	delete[] normalMonster;
	delete knightMonster;
	delete Hp;
	delete structure;
}

void Structure::render(SDL_Renderer* renderer) {
	knightMonster->render(renderer);
	for (int i = 0; i < amount; i++) {
		normalMonster[i]->render(renderer);
		alienMonster[i]->render(renderer);
	}

	if (hp <= 0) return;

	structure->render(renderer);
	if (time_thorn_grow > 0) {
		time_wait_grow = TIME_WAIT_GROW;
		for (int i = 0; i < 4; i++) {
			thorn[i]->renderAnimation(renderer, Direction::East);
		}
	}
	Hp->setCoordinates(structure->coordinates.x, structure->coordinates.y - 15);
	Hp->setWidth(hp / HP_STRUCTURE * 30);
	Hp->render(renderer);
}


void Structure::handleMonsterMovement(int x, int y) {
	knightMonster->move(x, y);
	knightMonster->defenceStructure(structure->coordinates);
	for (int i = 0; i < amount; i++) {
		normalMonster[i]->move(x, y);
		normalMonster[i]->defenceStructure(structure->coordinates);
		alienMonster[i]->move(x, y);
		alienMonster[i]->defenceStructure(structure->coordinates);
	}
}


void Structure::handleTakeDamage(const SDL_Rect& position, int damage) {
	if (time_undead <= 0) {
		if (checkCollision(structure->coordinates, position)) {
			hp -= damage;
			//std::cout << "structure takes damage\n";
			time_undead = TIME_UNDEAD_MONSTER;
		}
	}
	if (checkCollision(knightMonster->animation->coordinates, position)) {
		knightMonster->takeDamage(damage);
	}
	for (int i = 0; i < amount; i++) {
		if (checkCollision(normalMonster[i]->animation->coordinates, position)) {
			normalMonster[i]->takeDamage(damage);
		}
		if (checkCollision(alienMonster[i]->animation->coordinates, position)) {
			alienMonster[i]->takeDamage(damage);
		}
	}
}

void Structure::handleAttack(const SDL_Rect& player) {
	knightMonster->attack(player.x, player.y);
	for (int i = 0; i < amount; i++) {
		normalMonster[i]->attack(player.x, player.y);
		alienMonster[i]->attack(player.x, player.y);
	}

	if (hp <= 0) return ;
	int deltaX = structure->coordinates.x + structure->coordinates.w / 2 - player.x;
	int deltaY = structure->coordinates.y + structure->coordinates.h / 2 - player.y;
	float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
	if (time_wait_grow <= 0 && distance <= dangerousZone) {
		for (int i = 0; i < 4; i++) {
			thorn[i]->setCoordinates(player.x + i * 10 - 10, player.y + pow(-1, i) * 8);			
		}
		time_thorn_grow = TIME_THORN_GROW;
	}
}



int Structure::damageAttack(const SDL_Rect& player) {
	int damage = 0;
	damage += knightMonster->damageAttack(player);
	for (int i = 0; i < amount; i++) {
		damage += normalMonster[i]->damageAttack(player);
		damage += alienMonster[i]->damageAttack(player);
	}

	if (hp <= 0) return damage;
	if (time_thorn_grow > 0) {
		for (int i = 0; i < 4; i++) {
			if (thorn[i]->getCurrentFrame() >=6 && checkCollision(player, thorn[i]->coordinates)) {
				damage++;
			}
		}
	}
	return damage;
}


void Structure::regeneration() {
	if (hp <= 0) return;
	if (time_regeneration == 0) {
		Structure::newTurn();
		time_regeneration = TIME_REGENERATION;
	}
}

void Structure::cooldown() {
	knightMonster->cooldown();
	for (int i = 0; i < amount; i++) {
		normalMonster[i]->cooldown();
		alienMonster[i]->cooldown();
	}

	if (hp <= 0) return;
	if (time_thorn_grow > 0) {
		time_thorn_grow--;
	}
	if (time_wait_grow > 0) {
		time_wait_grow--;
	}
	if (time_undead > 0) {
		time_undead--;
	}
	if (time_regeneration > 0) {
		time_regeneration--;
	}	
}

void Structure::newTurn() {
	knightMonster->newTurn();
	for (int i = 0; i < amount; i++) {
		normalMonster[i]->newTurn();
		alienMonster[i]->newTurn();
	}
	hp = HP_STRUCTURE;
}