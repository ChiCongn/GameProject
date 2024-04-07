
#include"Support.h"

SupportObject::~SupportObject() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void SupportObject::initSupportObject(int _x, int _y, int _h) {
	coordinates.x = _x;
	coordinates.y = _y;
	coordinates.h = _h;
}

void SupportObject::setImageSupport(std::string imagePath, SDL_Renderer* renderer) {
	texture = loadImage(imagePath, renderer);
}

void SupportObject::setTextSupport(std::string text,std::string fontPath, SDL_Renderer* renderer) {
	texture = loadText(text,fontPath,renderer);
}

void SupportObject::render(int width, SDL_Renderer* renderer) {
	coordinates.w = width*290/MAX_HP_PLAYER;
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}

void MenuGame::initMenuGame(SDL_Renderer* renderer) {
	gameIntro = loadImage(IMAGE_GAME_INTRO_PATH, renderer);
	gameInstruction = loadImage(IMAGE_GAME_INSTRUCTION_PATH, renderer);
	gameVictory = loadImage(IMAGE_GAME_VICTORY_PATH, renderer);
	gameDefeat = loadImage(IMAGE_GAME_DEFEAT_PATH, renderer);
	chibichibi = new AnimatedSprite(IMAGE_CHIBI_CHIBI_PATH, CHIBI_CHIBI_WIDTH, CHIBI_CHIBI_HEIGHT, CHIBI_CHIBI_FRAMES, CHIBI_CHIBI_CLIPS, renderer);	
}

MenuGame::~MenuGame() {
	if (gameIntro != nullptr) {
		SDL_DestroyTexture(gameIntro);
		gameIntro = nullptr;
	}
	if (gameDefeat != nullptr) {
		SDL_DestroyTexture(gameDefeat);
		
	}
	
}

void MenuGame::renderMenuGame(SDL_Renderer* renderer, GameState gameState) {
	switch (gameState)
	{
	case GameState::Intro:
		//std::cout << "render GameIntro\n";
		SDL_RenderCopy(renderer, gameIntro, NULL, NULL);
		//playAudio(gameIntroAudio);
		break;
	case GameState::Instruction:
		SDL_RenderCopy(renderer, gameInstruction, NULL, NULL);
		break;
	case GameState::Defeat:
		//playAudio(chibichibiAudio);
		SDL_RenderCopy(renderer, gameDefeat, NULL, NULL);
		chibichibi->renderAnimatedSprite(renderer, SDL_FLIP_NONE);
		break;
	case GameState::Victory:
		SDL_RenderCopy(renderer, gameVictory, NULL, NULL);
		//playAudio(gameVictoryAudio);
		break;
	default:
		std::cout << "default menuGame :(( \n";
		break;
	}
}