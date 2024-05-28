
#include"Common.h"

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
    Mix_Quit();
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

SDL_Texture* loadImage(const std::string& path, SDL_Renderer* renderer)
{
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Unable to load image " << path << "SDL_image Error: "
            << IMG_GetError() << std::endl;
    }
    else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr) {
            std::cout << "Unable to create texture from " << path << "SDL_Error: "
                << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

TTF_Font* loadFont(const std::string& font_path) {
    if (TTF_Init() == -1) {
        std::cout << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
        return nullptr;
    }
    TTF_Font* font = TTF_OpenFont(font_path.c_str(), 80);
    if (font == nullptr) {
        std::cout << "Font is not available" << std::endl << TTF_GetError();
        TTF_Quit();
        return nullptr;
    }
    return font;
}

SDL_Texture* loadText(const std::string text, const SDL_Color& color, const std::string& fontPath, SDL_Renderer* renderer) {   
    TTF_Font* font = loadFont(fontPath);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (textSurface == nullptr) {
        std::cout << "Failed to render text surface: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        TTF_Quit();
        return nullptr;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == nullptr) {
        std::cout << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        TTF_Quit();
        return nullptr;
    }
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
    return textTexture;
}


Mix_Chunk* loadSound(std::string sound_path) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return nullptr;
    }

    Mix_Chunk* sound = Mix_LoadWAV(sound_path.c_str());
    if (sound == nullptr) {
        std::cerr << "Failed to load sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return nullptr;
    }
    return sound;
}


Mix_Music* loadMusic(const std::string& path) {
   ///* if (SDL_Init(SDL_INIT_AUDIO) < 0) {
   //     std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
   //     return nullptr;
   // }*/

   // if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
   //     std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
   //     return nullptr;
   // }
    Mix_Music* gMusic = Mix_LoadMUS(path.c_str());
    if (gMusic == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
            SDL_LOG_PRIORITY_ERROR,
            "Could not load music! SDL_mixer Error: %s", Mix_GetError());
    }
    return gMusic;
}


bool checkCollision(const SDL_Rect& a, const SDL_Rect& b) {
    if (a.x + a.w < b.x || b.x + b.w < a.x || a.y + a.h < b.y || b.y + b.h < a.y) {
        return false;
    }
    return true;
    //return SDL_HasIntersection(&a, &b);
}

float calculateDistance(const int& x1, const int& y1, const int& x2, const int& y2) {
    float distance = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return distance;
}


void playAudio(Mix_Chunk* sound) {
    if (sound != nullptr) {
        Mix_PlayChannel(-1, sound, 0);
    }
}

void playMusic(Mix_Music* gMusic) {
    if (gMusic == nullptr) return;
    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(gMusic, -1);
    }
    else if (Mix_PausedMusic() == 1) {
        Mix_ResumeMusic();
    }
}
