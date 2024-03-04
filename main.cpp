#include"Common.h"
#include"FigureObject.h"
#include"ThreatsObject.h"

const std::string WINDOW_TITLE = "Welcome to game!";

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void logSDLError(std::ostream& os,
	const std::string& msg, bool fatal = false);
void waitUntilKeyPressed();


int main(int argc, char* argv[])
{
    srand(time(0));
	SDL_Window* window;
	SDL_Renderer* renderer;
	initSDL(window, renderer);


    FigureObject player ;   
    player.updateTexture(renderer);
    
    ThreatsObject B52;
    B52.setTexture(renderer);
    B52.setCoordinates(200, 105);
    

    SDL_Event event;
    bool quit = false;
    while (!quit) {      
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }           
            else if (event.type == SDL_KEYDOWN) {  
               
                player.handleMoveAction(event);                                                                           
                player.attackThreats(event, renderer);
               
            }                       
        }  
        SDL_RenderClear(renderer);
        player.updateTexture(renderer);
        B52.autoMove();
        
        renderBkGround(renderer);
        player.render(renderer);
        B52.render(renderer);
        player.renderAttack(renderer);
        SDL_Delay(50);
    }

    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}


void initSDL(SDL_Window*& window, SDL_Renderer*& renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, 
    //SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    //Khi ch?y trong môi tr??ng bình th??ng (không ch?y trong máy ?o)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC);
    //Khi ch?y ? máy ?o (ví d? t?i máy tính trong phòng th?c hành ? tr??ng)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_WaitEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}
