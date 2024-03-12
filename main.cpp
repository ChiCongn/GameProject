#include"Common.h"
#include"FigureObject.h"
#include"ThreatsObject.h"

const std::string WINDOW_TITLE = "Welcome to game!";

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void logSDLError(std::ostream& os,
	const std::string& msg, bool fatal = false);
void waitUntilKeyPressed();

const int RandomCoordinatesXList[] = { 1100,1050, 1000, 950, 900, 850,800, 900, 850,800,1050, 1000, 950, 900 };
const int RandomCoordinatesYList[] = { 140, 200, 350, 425, 368, 120, 50, 75, 100, 280, 364, 444 };
const int sizeListX = sizeof(RandomCoordinatesXList) / sizeof(int);
const int sizeListY = sizeof(RandomCoordinatesYList) / sizeof(int);
const int MAX_ZOMBIE = 10;
const int LIGHTNING_DAMAGE = 10;

int main(int argc, char* argv[])
{
    srand(time(0));
	SDL_Window* window;
	SDL_Renderer* renderer;
	initSDL(window, renderer);

    SDL_Texture* bkGround = loadImage("night.jpg", renderer);

    FigureObject cat ;   
    cat.setTextureFigure(renderer);

    std::vector<ThreatsObject> zombies(MAX_ZOMBIE);
    for (int i = 0; i < MAX_ZOMBIE; i++) {    
        zombies[i].setTexture(renderer);
        zombies[i].setCoordinates(RandomCoordinatesXList[rand() % sizeListX], RandomCoordinatesYList[rand() % sizeListY]);      
    }
     
    SDL_Event event;
    bool quit = false;
    while (!quit) {      
        SDL_RenderClear(renderer);
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }           
            else if (event.type == SDL_KEYDOWN) {  
               
                cat.handleMoveAction(event);                                                                           
                cat.attackThreats(event, renderer);
               
            } 
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                cat.setCoordinatesSkill(event);
            }
        }  
       
       // zombie.autoMove(cat.getCoordinates().x+FIGURE_WIDTH/2, cat.getCoordinates().y+FIGURE_HEIGHT/2);
        //zombie.attackPlayer(renderer);
        SDL_RenderCopy(renderer, bkGround, NULL, NULL);
        cat.render(renderer);                        
        for (int i = 0; i < MAX_ZOMBIE; i++) {
            zombies[i].render(renderer);
            for (int j = 0; j < cat.bullet.size();j++) {
                if ( checkCollision(zombies[i].getCoordinates(), cat.bullet[j].getCoordinates())) {
                    zombies[i].getDamage();
                    cat.bullet.erase(cat.bullet.begin()+j);
                    //break;
                } 
            }   
            if ( checkCollision(zombies[i].getCoordinates(), cat.lightning.getCoordinates()) ) {
                zombies[i].getDamageLightning();
            }
        }

        for (int i = 0; i < MAX_ZOMBIE; i++) {
            if (zombies[i].isDied()) {
                zombies[i].recover();
                zombies[i].setCoordinates(RandomCoordinatesXList[rand() % sizeListX], RandomCoordinatesYList[rand() % sizeListY]);
            }
        }
       
        cat.renderAttack(renderer);
        cat.renderSkill(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(30);
    }

    cat.~FigureObject();
    for (int i = 0; i < MAX_ZOMBIE; i++) {
        zombies[i].~ThreatsObject();
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
 
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC);
 
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
    Mix_CloseAudio();
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
