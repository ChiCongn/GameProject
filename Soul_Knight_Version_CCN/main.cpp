
#include"GameObject.h"

SDL_Window* window;
SDL_Renderer* renderer;

int main(int argv, char**argc)
{    
    initSDL(window, renderer);
    SDL_Event event;
    std::cout << "Chi-Cong <3" << std::endl;
	std::cout << "Hmmm" << std::endl;

    // initialize
	GameObject* game=new GameObject(renderer);	    
    Uint32 startTime = SDL_GetTicks()/1000;
    std::cout << "Start Time: " << startTime << std::endl;

    // Play
    
    game->gamePlay(event, renderer);     
    if(game->gameState==GameState::Quit)
        std::cout << "GameQuit" << std::endl;
    // Game Quit-> End
	std::cout << "OK!\n";
	game->~GameObject();
    std::cout << "Return pls\n";
    //waitUntilKeyPressed();
    quitSDL(window, renderer);
	return 0;
}


