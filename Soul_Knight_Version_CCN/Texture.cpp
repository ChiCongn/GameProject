
#include"Texture.h"

Texture::~Texture() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

Texture::Texture(int _x, int _y, int _w, int _h) {
	coordinates.x = _x;
	coordinates.y = _y;
	coordinates.w = _w;
	coordinates.h = _h;
}

void Texture::setImageTexture(std::string imagePath, SDL_Renderer* renderer) {
	texture = loadImage(imagePath, renderer);
}

void Texture::setText(const std::string text, const SDL_Color color, const std::string fontPath, SDL_Renderer* renderer) {
	texture = loadText(text, color, fontPath, renderer);
}

void Texture::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}

void Texture::move(int x, int y) {
	coordinates.x += x;
	coordinates.y += y;
}

void Texture::renderEx(SDL_Renderer* renderer, double angle) {
	SDL_RenderCopyEx(renderer, texture, NULL, &coordinates, angle, NULL, SDL_FLIP_NONE);
}



void MenuGame::initMenuGame(SDL_Renderer* renderer) {
	std::cout << "init menu game \n";
	gameIntro = loadImage(IMAGE_GAME_INTRO_PATH, renderer);
	gameInstruction = loadImage(IMAGE_GAME_INSTRUCTION_PATH, renderer);
	gameVictory = loadImage(IMAGE_GAME_VICTORY_PATH, renderer);
	gameDefeat = loadImage(IMAGE_GAME_DEFEAT_PATH, renderer);
	std::cout << "ok init menu game\n";
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