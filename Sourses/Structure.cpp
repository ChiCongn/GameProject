
#include"Structure.h"

Structure::Structure(int level, int posX, int posY, SDL_Renderer* renderer) {
	amount = level;
	structure = new Texture(200, 100, TOWER_WIDTH, TOWER_HEIGHT);
	structure->setImageTexture(TOWER_PATH, renderer);
	structure->setCoordinates(posX, posY);
	//std::cout << "init thorn\n";
	thorn = new Animation*[4]; 
	for (int i = 0; i< 4; i++) {
		thorn[i]= new Animation(THORN_PATH, THORN_PATH, THORN_WIDTH, THORN_HEIGHT, THORN_FRAMES, THORN_CLIPS, renderer);
	}
	//std::cout << "ok init thorn\n";
	normal_monsters = new NormalMonster*[amount];
	alien_monsters = new AlienMonster *[amount];
	for (int i = 0; i < amount; i++) {
		normal_monsters[i] = new NormalMonster(renderer);
		normal_monsters[i]->setCoordinates(posX + i * NORMAL_MONSTER_WIDTH, posY- 30);
		alien_monsters[i] = new AlienMonster(renderer);
		alien_monsters[i]->setCoordinates(posX - 30, posY + i*ALIEN_HEIGHT);
	}
	knight_monster = new KnightMonster(renderer);
	knight_monster->setCoordinates(posX, posY + TOWER_HEIGHT);
	hp = HP_STRUCTURE;	
	Hp = new Texture(0, 0, 30, 15);
	Hp->setText(std::to_string(hp), RED_COLOR, FONT_PATH, renderer);
}

Structure::~Structure() {
	delete[] alien_monsters;
	delete[] normal_monsters;
	delete knight_monster;
	delete Hp;
	delete structure;
}

void Structure::render(SDL_Renderer* renderer) {
	knight_monster->render(renderer);
	for (int i = 0; i < amount; i++) {
		normal_monsters[i]->render(renderer);
		alien_monsters[i]->render(renderer);
	}

	//if (hp <= 0 || structure->coordinates.x < 0 || structure->coordinates.x > 800 ||
		//structure->coordinates.y < 0 || structure->coordinates.y >SCREEN_HEIGHT - TOWER_HEIGHT) return;
	if (hp <= 0) return;
	structure->render(renderer);
	if (time_thorn_grow > 0) {
		time_wait_grow = TIME_WAIT_GROW;
		for (int i = 0; i < 4; i++) {
			thorn[i]->renderAnimation(renderer, Direction::East);
		}
	}
	Hp->setCoordinates(structure->getCoordinates().x, structure->getCoordinates().y - 15);
	Hp->setText(std::to_string(hp), RED_COLOR, FONT_PATH, renderer);
	Hp->render(renderer);
}

void Structure::setCoordinates(int x, int y) {
	structure->setCoordinates(x, y);
}

void Structure::handleMonsterMovement(SDL_Point pos) {
	knight_monster->move(pos.x, pos.y);
	knight_monster->defenceStructure(structure->getCoordinates());
	for (int i = 0; i < amount; i++) {
		normal_monsters[i]->move(pos.x, pos.y);
		normal_monsters[i]->defenceStructure(structure->getCoordinates());
		alien_monsters[i]->move(pos.x, pos.y);
		alien_monsters[i]->defenceStructure(structure->getCoordinates());
	}
}


void Structure::handleTakeDamage(const SDL_Rect& position, int time_active, int damage) {
	if (time_active <= 0) return;
	if (checkCollision(knight_monster->getCoordinates(), position)) {
		knight_monster->takeDamage(damage);
	}
	for (int i = 0; i < amount; i++) {
		if (checkCollision(normal_monsters[i]->getCoordinates(), position)) {
			normal_monsters[i]->takeDamage(damage);
		}
		if (checkCollision(alien_monsters[i]->getCoordinates(), position)) {
			alien_monsters[i]->takeDamage(damage);
		}
	}
	if (time_immortality > 0 || hp <= 0) return;
	if (checkCollision(structure->getCoordinates(), position)) {
		hp -= damage;
		//std::cout << "structure takes damage\n";
		time_immortality = TIME_IMMORTALITY_MONSTER;
	}
}

void Structure::handleAttack(const SDL_Rect& player) {
	knight_monster->attack(player.x, player.y);
	for (int i = 0; i < amount; i++) {
		normal_monsters[i]->attack(player.x, player.y);
		alien_monsters[i]->attack(player.x, player.y);
	}

	if (hp <= 0) return ;
	SDL_Rect position = structure->getCoordinates();
	int deltaX = position.x + position.w / 2 - player.x;
	int deltaY = position.y + position.h / 2 - player.y;
	float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
	if (time_wait_grow <= 0 && distance <= dangerous_zone) {
		for (int i = 0; i < 4; i++) {
			thorn[i]->setCoordinates(player.x + i * 10 - 10, player.y + (int)pow(-1, i) * 8);			
		}
		time_thorn_grow = TIME_THORN_GROW;
	}
}

void Structure::moveFollowMap(int x, int y) {
	knight_monster->moveFollowMap(x, y);
	for (int i = 0; i < amount; i++) {
		normal_monsters[i]->moveFollowMap(x, y);
		alien_monsters[i]->moveFollowMap(x, y);
	}
	if (hp <= 0) return;
	structure->move(x, y);
}



int Structure::damageAttack(const SDL_Rect& player) {
	int damage = 0;
	damage += knight_monster->damageAttack(player);
	for (int i = 0; i < amount; i++) {
		damage += normal_monsters[i]->damageAttack(player);
		damage += alien_monsters[i]->damageAttack(player);
	}

	if (hp <= 0) return damage;
	if (time_thorn_grow > 0) {
		for (int i = 0; i < 4; i++) {
			if (checkCollision(player, thorn[i]->getCoordinates())) {
				damage++;
			}
		}
	}
	return damage;
}

int Structure::calculateScore() {
	int score = 0;
	if (hp <= 0) {
		if (!is_calculate) {
			score = SCORE_STRUCTURE;
			is_calculate = true;
		}
	}
	score += knight_monster->calculateScore();
	for (int i = 0; i < amount; i++) {
		score += normal_monsters[i]->calculateScore();
		score += alien_monsters[i]->calculateScore();
	}
	return score;
}


void Structure::regeneration() {
	if (hp <= 0) return;
	if (time_regeneration == 0) {
		Structure::newTurn();
		time_regeneration = TIME_REGENERATION;
	}
}

void Structure::cooldown() {
	knight_monster->cooldown();
	for (int i = 0; i < amount; i++) {
		normal_monsters[i]->cooldown();
		alien_monsters[i]->cooldown();
	}

	if (hp <= 0) return;
	if (time_thorn_grow > 0) {
		time_thorn_grow--;
	}
	if (time_wait_grow > 0) {
		time_wait_grow--;
	}
	if (time_immortality > 0) {
		time_immortality--;
	}
	if (time_regeneration > 0) {
		time_regeneration--;
	}	
}

void Structure::newTurn() {
	knight_monster->newTurn();
	SDL_Point pos = structure->getPosition();
	knight_monster->setCoordinates(pos.x, pos.y + TOWER_HEIGHT);
	for (int i = 0; i < amount; i++) {
		normal_monsters[i]->newTurn();
		normal_monsters[i]->setCoordinates(pos.x + i * NORMAL_MONSTER_WIDTH, pos.y - 30);

		alien_monsters[i]->newTurn();
		alien_monsters[i]->setCoordinates(pos.x - 30, pos.y + i * ALIEN_HEIGHT);
	}
	
	hp = HP_STRUCTURE;
}