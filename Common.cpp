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

void renderBkGround(SDL_Renderer* renderer) {
    SDL_Texture* bkGround = loadImage("BkGround.png", renderer);
    SDL_RenderCopy(renderer, bkGround, NULL, NULL);
    SDL_RenderPresent(renderer);
}
