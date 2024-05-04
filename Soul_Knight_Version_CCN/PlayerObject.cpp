
#include"PlayerObject.h"


PlayerObject::PlayerObject(SDL_Renderer* renderer) {	
	std::cout<<"init dafault playerObject\n";
	std::cout << "start init Player\n";
	hp = MAX_HP_PLAYER, mana = 200, score = 0;
	preTimeSkill = SDL_GetTicks();
	//x_val = y_val = 0;
	damage = DEFAUT_DAMAGE_PLAYER;
	speed = DEFAULT_SPEED_PLAYER;
	coordinates.x = 0;
	coordinates.y = 0;
	coordinates.w = PLAYER_WIDTH;
	coordinates.h = PLAYER_HEIGHT;

	attack = false;
	direction = Direction::East;
	std::cout << "start init AnimatedSpirte*\n";
	animation = new Animation(IMAGE_PLAYER_LEFT_PATH, IMAGE_PLAYER_RIGHT_PATH, PLAYER_WIDTH,
		PLAYER_HEIGHT, MAGICAN_FRAMES, MAGICAN_CLIPS, renderer);

	std::cout << "ok init AnimatedSprite* -> start init playerSkill*\n";
	playerSkill = new Animation(IMAGE_SLASH_LEFT_PATH, IMAGE_SLASH_RIGHT_PATH, PLAYER_SKILL_WIDTH, PLAYER_SKILL_HEIGHT,
		PLAYER_SLASH_FRAMES, PLAYER_SLASH_CLIPS, renderer);

	std::cout << "ok init playerSkill*-> start init Hp*\n";
	Hp = new Texture(90, 20, 57, 14);
	Hp->setImageTexture(IMAGE_HP_PATH, renderer);
	std::cout << "ok init Hp*->start init Ex*\n";
	Mana = new Texture(90, 50, 116, 14);
	Mana->setImageTexture(IMAGE_EX_PATH, renderer);
	Score = new Texture(950, 0, 50, 50);
	Score->setText(std::to_string(0), RED_COLOR, FONT_PATH, renderer);
	std::cout << "ok init Player\n";

	attackAudio = loadAudio(AUDIO_ATTACK_PATH);
	std::cout << "ok constructor PlayeObject\n";
}

PlayerObject::~PlayerObject() {
	delete animation;
	delete Hp;
	delete Mana;
	delete playerSkill;
	Mix_FreeChunk(attackAudio);
	/*Mix_FreeChunk(getDamageAudio);
	Mix_FreeChunk(levelUpAudio);
	Mix_FreeChunk(getExAudio);*/
	//attackAudio = getDamageAudio = levelUpAudio = getExAudio = nullptr;
}

void PlayerObject::renderPlayer(SDL_Renderer* renderer) {
	animation->setCoordinates(coordinates.x, coordinates.y);
	animation->renderAnimation(renderer, direction);
	if (attack) {
		if(direction==Direction::West)
			playerSkill->setCoordinates(coordinates.x-32, coordinates.y - 15);
		else
			playerSkill->setCoordinates(coordinates.x, coordinates.y - 15);

		playerSkill->renderAnimation(renderer, direction);
		attack = false;
		//playAudio(attackAudio);
	}	
	Hp->render(int(hp * 157.0/MAX_HP_PLAYER) , renderer);
	Mana->render(int(mana*118.0/200), renderer);
	Score->render(50, renderer);
	//playerSkill->setCoordinates(0, 0);
}

void PlayerObject::handleMoveAction(Map* map) {
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
	move();
	//if(coordinates.x < 200 || coordinates.y)
	map->handleCamera(x_val, y_val);
		
	x_val = y_val = 0;
}

//void PlayerObject::playerMove() {
//	//std::cout << "PlayerMove\n";
//	if (e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_w) {
//		coordinates.y -= speed;
//		if (coordinates.y < 50) {
//			coordinates.y = 50;
//		}
//		
//	}
//	else if (e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_s) {
//		coordinates.y += speed;
//		if (coordinates.y + PLAYER_HEIGHT > SCREEN_HEIGHT) {
//			coordinates.y -= speed;
//			coordinates.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
//		}
//		
//	}
//	else if (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_a) {
//		direction = Direction::West;
//		coordinates.x -= speed;
//		if (coordinates.x < 0) {
//			coordinates.x = 0;
//		}
//		/*for (int i = 0; i < 12; i++) {
//			if (checkCollision(obstacle[i], coordinates)) {
//				coordinates.x = obstacle[i].x + obstacle[i].w;
//				break;
//			}
//		}*/
//	}
//	else if (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_d) {
//		direction = Direction::East;
//		coordinates.x += speed;
//		if (coordinates.x + PLAYER_WIDTH > SCREEN_WIDTH) {
//			coordinates.x = SCREEN_WIDTH - PLAYER_WIDTH;
//		}
//		
//	}
//	else {
//		;
//	}
//}

void PlayerObject::move() {
	coordinates.x += x_val;
	coordinates.y += y_val;
	if (coordinates.x < 0)
		coordinates.x = 0;
	if (coordinates.x > SCREEN_WIDTH - PLAYER_WIDTH)
		coordinates.x = SCREEN_WIDTH - PLAYER_WIDTH;
	if (coordinates.y < 0)
		coordinates.y = 0;
	if (coordinates.y > SCREEN_HEIGHT - PLAYER_HEIGHT)
		coordinates.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
}

void PlayerObject::attackThreat(SDL_Event e) {
	if (e.key.keysym.sym==SDLK_SPACE) {
		attack = true;
	}
}

void PlayerObject::setUpNewTurn() {
	hp = MAX_HP_PLAYER;
	mana = 200;
	damage = DEFAUT_DAMAGE_PLAYER;
	setCoordinates(0, SCREEN_HEIGHT - PLAYER_HEIGHT);
}


void PlayerObject::updateScore(const int _score, SDL_Renderer* renderer) {
	score += _score;
	Score->setText(std::to_string(score), RED_COLOR, FONT_PATH, renderer);
}