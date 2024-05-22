
#include"PlayerObject.h"


PlayerObject::PlayerObject(SDL_Renderer* renderer) {	
	high_score = PlayerObject::takeHighScore();
	//std::cout << "start init AnimatedSpirte*\n";
	animation = new Animation(PLAYER_LEFT_PATH, PLAYER_RIGHT_PATH, PLAYER_WIDTH,
		PLAYER_HEIGHT, MAGICAN_FRAMES, MAGICAN_CLIPS, renderer);
	animation->setCoordinates(300, 300);

	//std::cout << "ok init AnimatedSprite* -> start init playerSkill*\n";
	slash_sword = new Animation(SLASH_LEFT_PATH, SLASH_RIGHT_PATH, SLASH_SWORD_WIDTH, SLASH_SWORD_HEIGHT,
		PLAYER_SLASH_FRAMES, PLAYER_SLASH_CLIPS, renderer);
	turbulent_slash = new Skill(IMAGE_TURBULENT_SLASH_SKILL_PATH, TURBULENT_SLASH_PATH, TURBULENT_SLASH_WIDTH, TURBULENT_SLASH_HEIGHT,
		TURBULENT_SLASH_FRAMES, TURBULENT_SLASH_CLIPS, renderer);
	turbulent_slash->setCoordinatesImageSkill(1015, 200);
	tornado = new Skill(IMAGE_TORNADO_SKILL_PATH, TORNADO_EFFECT_PATH, TORNADO_WIDTH, TORNADO_HEIGHT, TORNADO_FRAMES, TORNADO_CLIPS, renderer);
	tornado->setCoordinatesImageSkill(1060, 200);
	shield = new Skill(IMAGE_SHIELD_SKILL_PATH, SHIELD_EFFECT_PATH, SHIELD_WIDTH, SHIELD_HEIGHT, SHIELD_FRAMES, SHIELD_CLIPS, renderer);
	shield->setCoordinatesImageSkill(1105,200);
	healing = new Skill(IMAGE_HEALING_SKILL_PATH, HEALING_PATH, HEALING_WIDTH, HEALING_HEIGHT, HEALING_FRAMES, HEALING_CLIPS, renderer);
	healing->setCoordinatesImageSkill(1150, 200);

	//std::cout << "ok init playerSkill*-> start init Hp* and Ex*\n";
	Hp = new Texture(1077, 89, 112, 14);
	Hp->setImageTexture(HP_PATH, renderer);
	Mana = new Texture(90, 50, 116, 14);
	Mana->setImageTexture(EX_PATH, renderer);
	Score = new Texture(1065, 360, 50, 25);
	Score->setText(std::to_string(0), RED_COLOR, FONT_PATH, renderer);
	High_score = new Texture(1070, 255, 80, 40);
	High_score->setText(std::to_string(high_score), BLACK_COLOR, FONT_PATH, renderer);
	std::cout << "ok init PlayeObject\n";
}

PlayerObject::~PlayerObject() {
	delete animation;
	delete Hp;
	delete Mana;
	delete slash_sword;
	delete shield;
	delete turbulent_slash;
	delete tornado;
}

void PlayerObject::renderPlayer(SDL_Renderer* renderer) {
	if (turbulent_slash->getTimeActive() == 0)
		animation->renderAnimation(renderer, direction);
	if (slash) {
		SDL_Rect position = animation->getCoordinates();
		if(direction==Direction::West)
			slash_sword->setCoordinates(position.x-20,position.y - 15);
		else
			slash_sword->setCoordinates(position.x, position.y - 15);

		slash_sword->renderAnimation(renderer, direction);
		time_slash = TIME_WAIT_SLASH;
		slash = false;
		//playAudio(attackAudio);
	}	
	
	turbulent_slash->render(renderer);
	tornado->render(renderer);
	shield->setCoordinates(posX - 5, posY - 5);
	shield->render(renderer);
	healing->render(renderer);

	Hp->setWidth(int(hp * 112.0 / HP_PLAYER ));
	Hp->render(renderer);
	//Mana->render(int(mana*118.0/200), renderer);
	Score->render(renderer);
	High_score->render(renderer);
}

SDL_Rect PlayerObject::getCoordinatesSkill(std::string id_skill) {
	if (id_skill == "slash_sword") {
		return slash_sword->getCoordinates();
	}
	else if (id_skill == "tornado") {
		return tornado->getCoordinates();
	}
	else if (id_skill == "turbulent_slash") {
		return turbulent_slash->getCoordinates();
	}
	else {
		std::cout << ":V ...\n";
		return { 0, 0, 0, 0 };
	}
}

int PlayerObject::getTimeActiveSkill(std::string id_skill) {
	if (id_skill == "tornado") {
		return tornado->getTimeActive();
	}
	else if (id_skill == "turbulent_slash") {
		return turbulent_slash->getTimeActive();
	}
	else {
		return 0;
	}
}

void PlayerObject::setDeltaPosionsion(int x, int y) {
	if (x >= 0) {
		delta_x = x;
	}
	if (y >= 0) {
		delta_y = y;
	}
}

void PlayerObject::newTurn() {
	hp = HP_PLAYER;
	mana = 200;
	damage = DAMAGE_PLAYER;
	PlayerObject::animation->setCoordinates(300, 300);
	delta_x = delta_y = 0;
	posX = posY = 300;
}

void PlayerObject::move() {
	posX += delta_x;
	posY += delta_y;
	if (posX < 0)
		posX = 0;
	if (posX > SCREEN_WIDTH - PLAYER_WIDTH)
		posX = SCREEN_WIDTH - PLAYER_WIDTH;
	if (posY < 0)
		posY = 0;
	if (posY > SCREEN_HEIGHT - PLAYER_HEIGHT)
		posY = SCREEN_HEIGHT - PLAYER_HEIGHT;
	animation->setCoordinates(posX, posY);
}


void PlayerObject::handleMoveAction() {
	delta_x = delta_y = 0;
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_UP] || currentKeyStates[SDL_SCANCODE_W]) {
		delta_y -= speed;
	}		
	if (currentKeyStates[SDL_SCANCODE_DOWN] || currentKeyStates[SDL_SCANCODE_S]) {
		delta_y += speed;
	}			
	if (currentKeyStates[SDL_SCANCODE_RIGHT] || currentKeyStates[SDL_SCANCODE_D]) {
		direction = Direction::East;
		delta_x += speed;
	}			
	if (currentKeyStates[SDL_SCANCODE_LEFT] || currentKeyStates[SDL_SCANCODE_A]){
		direction = Direction::West;
		delta_x -= speed;
	}
}

void PlayerObject::handleSkill(SDL_Event& e) {
	int mouseX, mouseY;
	if (e.button.button == SDL_BUTTON_LEFT && turbulent_slash->getTimeWait() == 0) {
		SDL_GetMouseState(&mouseX, &mouseY);	
		turbulent_slash->setCoordinates(mouseX - TURBULENT_SLASH_WIDTH / 2, mouseY - TURBULENT_SLASH_HEIGHT / 2);
		turbulent_slash->setTime(TIME_WAIT_TURBULENT_SLASH, TIME_ACTIVE_TURBULENT_SLASH);
	}
	if (e.button.button == SDL_BUTTON_RIGHT && tornado->getTimeWait() <=0) {
		SDL_GetMouseState(&mouseX, &mouseY);
		tornado->setCoordinates(mouseX-TORNADO_WIDTH/2, mouseY-TORNADO_HEIGHT/2);
		tornado->setTime(TIME_WAIT_TORNADO, TIME_ACTIVE_TORNADO);
	}
}

void PlayerObject::handleSlash() {
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_SPACE] && time_slash <= 0) {
		slash = true;
	}
	if (currentKeyStates[SDL_SCANCODE_T] && shield->getTimeWait() <= 0) {
		shield->setCoordinates(posX - 5, posY - 5);
		shield->setTime(TIME_WAIT_SHIELD, TIME_ACTIVE_SHIELD);
	}
	if (currentKeyStates[SDL_SCANCODE_H] && healing->getTimeWait() <= 0) {
		healing->setCoordinates(posX -5, posY - 10);
		healing->setTime(TIME_WAIT_HEALING, TIME_ACTIVE_HEALING);
		if (hp<HP_PLAYER)
			hp++;
	}
	if (!slash) {
		slash_sword->setCoordinates(0, 0);
	}
}



void PlayerObject::takeDamage(int _damage) {
	if (turbulent_slash->getTimeActive() > 0 || time_immortality > 0 || shield->getTimeActive() > 0 || _damage == 0) return;

	//std::cout << "player get damage\n";
	if (damage < 5) {
		hp -= _damage;

	}
	else {
		hp -= 4;
	}
	time_immortality = TIME_IMMORTALITY;
}

void PlayerObject::cooldown() {
	if (time_immortality > 0) {
		time_immortality--;
	}
	if (time_slash > 0) {
		time_slash--;
	}
	if (time_immortality > 0) {
		time_immortality--;
	}
	turbulent_slash->cooldown();
	tornado->cooldown();
	shield->cooldown();
	healing->cooldown();
}

int PlayerObject::takeHighScore() {
	std::ifstream inFile("HighScore.txt");
	if (!inFile.is_open()) {
		std::cout << "Error! Can not open HighScore.txt\n";
		return -1;
	}
	int getScore;
	while (!inFile.eof()) {
		inFile >> getScore;
	}
	inFile.close();
	return getScore;
}

void PlayerObject::getScore(int score_plus) {
	if (score_plus == 0) return;
	score += score_plus;
}


void PlayerObject::updateScore(SDL_Renderer* renderer) {
	Score->setText(std::to_string(score), RED_COLOR, FONT_PATH, renderer);
	if (score > high_score) {
		high_score = score;
		High_score->setText(std::to_string(high_score), RED_COLOR, FONT_PATH, renderer);
	}
}

void PlayerObject::saveHighScore() {
	std::ofstream outFile("HighScore.txt");
	if (!outFile.is_open()) {
		std::cout << "Error! Can not open HighScore.txt\n";
		return;
	}
	outFile << high_score;
	outFile.close();
}