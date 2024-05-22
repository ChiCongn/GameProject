
#ifndef MENU_H
#define MENU_H

#include"Common.h"
#include"Defs.h"

class MenuGame {
public:
	MenuGame(SDL_Renderer* renderer);
	~MenuGame();
	void renderMenuGame(SDL_Renderer* renderer, const GameState& gameState);

	void gameIntro(GameState& gameState, SDL_Event& e, SDL_Renderer* renderer);
	void gameInstructions(GameState& gameState, SDL_Event& e, SDL_Renderer* renderer);
	void gameOver(GameState& gameState, SDL_Event& e, SDL_Renderer* renderer);
	
private:
	SDL_Texture* game_intro;
	SDL_Texture* game_instructions;
	SDL_Texture* game_victory;
	SDL_Texture* game_defeat;

	SDL_Texture* notification;
	SDL_Rect position_notification;

};


#endif 