
#include"PlayerObject.h"


PlayerObject::PlayerObject(SDL_Renderer* renderer) {	
	std::cout<<"init dafault playerObject\n";
	std::cout << "start init Player\n";
	hp = MAX_HP_PLAYER, mana = 200, score = 0;
	//x_val = y_val = 0;
	damage = DAMAGE_PLAYER;
	speed = SPEED_PLAYER;
	direction = Direction::East;
	std::cout << "start init AnimatedSpirte*\n";
	animation = new Animation(IMAGE_PLAYER_LEFT_PATH, IMAGE_PLAYER_RIGHT_PATH, PLAYER_WIDTH,
		PLAYER_HEIGHT, MAGICAN_FRAMES, MAGICAN_CLIPS, renderer);

	std::cout << "ok init AnimatedSprite* -> start init playerSkill*\n";
	slashSword = new Animation(IMAGE_SLASH_LEFT_PATH, IMAGE_SLASH_RIGHT_PATH, SLASH_SWORD_WIDTH, SLASH_SWORD_HEIGHT,
		PLAYER_SLASH_FRAMES, PLAYER_SLASH_CLIPS, renderer);
	fireBall = new Skill(FIRE_BALL_PATH, SKILL_WIDTH, SKILL_HEIGHT, PLAYER_SKILL_FRAMES, PLAYER_SKILL_CLIPS, renderer);
	tornado = new Skill(TORNADO_EFFECT_PATH, TORNADO_WIDTH, TORNADO_HEIGHT, TORNADO_FRAMES, TORNADO_CLIPS, renderer);

	std::cout << "ok init playerSkill*-> start init Hp*\n";
	Hp = new Texture(888, 24, 124, 12);
	Hp->setImageTexture(IMAGE_HP_PATH, renderer);
	std::cout << "ok init Hp*->start init Ex*\n";
	Mana = new Texture(90, 50, 116, 14);
	Mana->setImageTexture(IMAGE_EX_PATH, renderer);
	Score = new Texture(865, 230, 50, 25);
	Score->setText(std::to_string(0), RED_COLOR, FONT_PATH, renderer);
	std::cout << "ok init Player\n";

	attackAudio = loadAudio(AUDIO_ATTACK_PATH);
	std::cout << "ok constructor PlayeObject\n";
}

PlayerObject::~PlayerObject() {
	delete animation;
	delete Hp;
	delete Mana;
	delete slashSword;
	Mix_FreeChunk(attackAudio);
	/*Mix_FreeChunk(getDamageAudio);
	Mix_FreeChunk(levelUpAudio);
	Mix_FreeChunk(getExAudio);*/
	//attackAudio = getDamageAudio = levelUpAudio = getExAudio = nullptr;
}

void PlayerObject::renderPlayer(SDL_Renderer* renderer) {
	animation->renderAnimation(renderer, direction);
	if (slash) {
		if(direction==Direction::West)
			slashSword->setCoordinates(animation->coordinates.x-20, animation->coordinates.y - 15);
		else
			slashSword->setCoordinates(animation->coordinates.x, animation->coordinates.y - 15);

		slashSword->renderAnimation(renderer, direction);
		timeSlash = TIME_WAIT_SLASH;
		slash = false;
		//playAudio(attackAudio);
	}	
	
	fireBall->render(renderer);
	tornado->render(renderer);

	Hp->setWidth(hp / MAX_HP_PLAYER * 124);
	Hp->render(renderer);
	//Mana->render(int(mana*118.0/200), renderer);
	Score->render(renderer);
	//playerSkill->setCoordinates(0, 0);
	
}

void PlayerObject::handleMoveAction() {
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_UP] || currentKeyStates[SDL_SCANCODE_W]) {
		y_val -= speed;
	}		
	if (currentKeyStates[SDL_SCANCODE_DOWN] || currentKeyStates[SDL_SCANCODE_S]) {
		y_val += speed;
	}			
	if (currentKeyStates[SDL_SCANCODE_RIGHT] || currentKeyStates[SDL_SCANCODE_D]) {
		direction = Direction::East;
		x_val += speed;
	}			
	if (currentKeyStates[SDL_SCANCODE_LEFT] || currentKeyStates[SDL_SCANCODE_A]){
		direction = Direction::West;
		x_val -= speed;
	}
}


void PlayerObject::move() {
	posX += x_val;
	posY += y_val;
	if (posX < 0)
		posX = 0;
	if (posX > SCREEN_WIDTH - PLAYER_WIDTH)
		posX = SCREEN_WIDTH - PLAYER_WIDTH;
	if (posY < 0)
		posY = 0;
	if (posY > SCREEN_HEIGHT - PLAYER_HEIGHT)
		posY = SCREEN_HEIGHT - PLAYER_HEIGHT;
	animation->setCoordinates(posX, posY);
	x_val = y_val = 0;
}


void PlayerObject::handleSkill(SDL_Event& e) {
	int mouseX, mouseY;
	if (e.button.button == SDL_BUTTON_LEFT) {
		SDL_GetMouseState(&mouseX, &mouseY);	
		fireBall->skill->setCoordinates(mouseX, -100);
		fireBall->setTarget(mouseX, mouseY);
	}
	if (e.button.button == SDL_BUTTON_RIGHT && tornado->time_wait<=0) {
		SDL_GetMouseState(&mouseX, &mouseY);
		tornado->skill->setCoordinates(mouseX-SKILL_WIDTH/2, mouseY-SKILL_HEIGHT/2);
		tornado->setTime(TIME_WAIT_TORNADO, TIME_ACTIVE_TORNADO);
	}
}

void PlayerObject::handleSlash() {
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_SPACE] && timeSlash <= 0) {
		slash = true;
	}
	if (!slash) {
		slashSword->setCoordinates(0, 0);
	}
}

void PlayerObject::handleAttackMovement() {
	fireBall->moveToTarget();
}



void PlayerObject::takeDamage(int _damage) {
	if (time_undead <= 0) {
		if (damage < 5) {
			hp -= _damage;

		}
		else {
			hp -= 4;
		}
		time_undead = TIME_UNDEAD;
	}
}

void PlayerObject::setUpNewTurn() {
	hp = MAX_HP_PLAYER;
	mana = 200;
	damage = DAMAGE_PLAYER;
	PlayerObject::animation->setCoordinates(0, 0);
	x_val = y_val = 0;
	posX = posY = 0;
}


void PlayerObject::updateScore(const int _score, SDL_Renderer* renderer) {
	score += _score;
	Score->setText(std::to_string(score), RED_COLOR, FONT_PATH, renderer);
}

void PlayerObject::cooldown() {
	if (timeSlash > 0) {
		timeSlash--;
	}
	fireBall->cooldown();
	tornado->cooldown();
	if (time_undead > 0) {
		time_undead--;
	}
}