#include"Common.h"


SDL_Texture* loadImage(std::string path, SDL_Renderer* renderer)
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


SDL_Texture* loadText(std::string text, SDL_Renderer* renderer) {
    if (TTF_Init() == -1) {
        std::cout << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
        return nullptr;
    }
    TTF_Font* font = TTF_OpenFont("C:\\Users\\LENOVO\\Downloads\\8514oem.fon", 80);
    if (font == nullptr) {
        std::cout << "Font is not available" << std::endl << TTF_GetError();
        TTF_Quit();
        return nullptr;
    }

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), { 255,0,0 });
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


Mix_Chunk* loadAudio(std::string audioPath) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return nullptr;
    }

    Mix_Chunk* sound = Mix_LoadWAV(audioPath.c_str());
    if (sound == nullptr) {
        std::cerr << "Failed to load sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return nullptr;
    }
    return sound;
}

bool checkCollision(SDL_Rect a, SDL_Rect b) {
    if (a.x + a.w >= b.x && b.x + b.w >= a.x && a.y + a.h >= b.y && b.y + b.h >= a.y) {
        return true;
    }
    return false;
}