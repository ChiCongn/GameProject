#include"Common.h"


TTF_Font* setFontText(std::string font_path) {
	if (TTF_Init() == -1) {
		std::cout << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
		return nullptr;
	}
	TTF_Font* font = TTF_OpenFont(font_path.c_str(), 80);
	if (font == nullptr) {
		std::cout << "Font is not available " << TTF_GetError() << std::endl;
		TTF_Quit();
		return  nullptr;
	}
	return font;
}

SDL_Texture* loadText(std::string text, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer) {	
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

SDL_Texture* loadImage(const char* image_path, SDL_Renderer* renderer) {
	SDL_Texture* image = nullptr;
	SDL_Surface* imageSurface = IMG_Load(image_path);
	if (imageSurface == nullptr) {
		std::cout << "Unable to load image. " << "SDL_image get Error"
			<< IMG_GetError() << std::endl;
	}
	else {
		image = SDL_CreateTextureFromSurface(renderer, imageSurface);
		if (image == nullptr) {
			std::cout << "Unable to create texture to load image " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(imageSurface);
	}
	return image;
}

void showBkGround() {
	SDL_Texture* bkGround = loadImage("bkground.png", renderer);
	SDL_RenderCopy(renderer, bkGround, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void ShowMenu() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= 0 && x <= 2 && y >= 0 && y <= 6) {

	}
}