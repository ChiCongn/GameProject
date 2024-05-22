
#include"Menu.h"


MenuGame::MenuGame(SDL_Renderer* renderer) {
	std::cout << "init menu game \n";

	game_intro = loadImage(GAME_INTRO_PATH, renderer);
	game_instructions = loadImage(GAME_INSTRUCTIONS_PATH, renderer);
	game_victory = loadImage(GAME_VICTORY_PATH, renderer);
	game_defeat = loadImage(GAME_DEFEAT_PATH, renderer);

	notification = loadImage(NOTIFICATION_PATH, renderer);
	position_notification.x = 1000;
	position_notification.y = 0;
	position_notification.w = NOTIFICATION_WIDTH;
	position_notification.h = NOTIFICATION_HEIGHT;

	std::cout << "ok init menu game\n";
}

MenuGame::~MenuGame() {
    if (game_intro != nullptr) {
        SDL_DestroyTexture(game_intro);
        game_intro = nullptr;
    }
    if (game_instructions != nullptr) {
        SDL_DestroyTexture(game_instructions);
        game_instructions = nullptr;
    }
    if (game_victory != nullptr) {
        SDL_DestroyTexture(game_victory);
        game_victory = nullptr;
    }
    if (game_defeat != nullptr) {
        SDL_DestroyTexture(game_defeat);
        game_defeat = nullptr;
    }
    if (notification != nullptr) {
        SDL_DestroyTexture(notification);
        notification = nullptr;
    }
}

void MenuGame::renderMenuGame(SDL_Renderer* renderer, const GameState& gameState) {
	switch (gameState)
	{
	case GameState::Play:
		SDL_RenderCopy(renderer, notification, NULL, &position_notification);
		break;
	case GameState::Intro:
		SDL_RenderCopy(renderer, game_intro, NULL, NULL);
		break;
	case GameState::Instruction:
		SDL_RenderCopy(renderer, game_instructions, NULL, NULL);
		break;
	case GameState::Defeat:
		SDL_RenderCopy(renderer, game_defeat, NULL, NULL);
		break;
	case GameState::Victory:
		SDL_RenderCopy(renderer, game_victory, NULL, NULL);
		break;
	default:
		break;
	}    
}

void MenuGame::gameIntro(GameState& gameState, SDL_Event& e, SDL_Renderer* renderer) {
    std::cout << "Game Intro\n";
    while (gameState == GameState::Intro) {
        //playAudio(gameIntroAudio);
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                std::cout << "Quit!\n";
                gameState = GameState::Quit;
                break;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                //std::cout << x << " " << y << std::endl;
                if (x >= 430 && x <= 750) {
                    if (y >= 80 && y <= 155) {
                        gameState = GameState::Play;
                        std::cout << "Play\n";
                        return;
                    }
                    else if (y >= 220 && y <= 295) {
                        gameState = GameState::Instruction;
                        MenuGame::gameInstructions(gameState, e, renderer);
                        break;
                    }
                    else if (y >= 370 && y <= 445) {
                        gameState = GameState::Quit;
                        break;
                    }
                    else {
                        ;
                    }
                }
            }
            else {
                ;
            }
        }
        MenuGame::renderMenuGame(renderer, gameState);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
    }
    std::cout << "ok game intro\n";
}

void MenuGame::gameInstructions(GameState& gameState, SDL_Event& e, SDL_Renderer* renderer) {
    while (gameState == GameState::Instruction) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                std::cout << "Quit\n";
                gameState = GameState::Quit;
                break;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= SCREEN_WIDTH - 50 && x <= SCREEN_WIDTH && y >= 0 && y <= 50) {
                    gameState = GameState::Intro;
                    break;
                }
            }
        }
        MenuGame::renderMenuGame(renderer, gameState);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
    }
}

void MenuGame::gameOver(GameState& gameState, SDL_Event& e, SDL_Renderer* renderer) {
    while (gameState == GameState::Victory || gameState == GameState::Defeat) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                std::cout << "Quit\n";
                gameState = GameState::Quit;
                break;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                std::cout << x<<" " << y << std::endl;
                if (x >= 360 && x <= 740 && y >= 270 && y <= 360) {
                    gameState = GameState::Play;
                    return;
                }
                else if (x >= 360 && x <= 740 && y >= 420 && y <= 500) {
                    gameState = GameState::Quit;
                    return;
                }
            }
        }
        MenuGame::renderMenuGame(renderer, gameState);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
    }
}