
#include"AnimatedSprite.h"

void AnimatedSprite::initAnimatedSprite(std::string imagePath,const int frames, const int _clips[][4], SDL_Renderer* renderer) {
	currentFrame = 0;
	texture = loadImage(imagePath, renderer);
	SDL_Rect clip;
	for (int i = 0; i < frames; i++) {
		clip.x = _clips[i][0];
		clip.y = _clips[i][1];
		clip.w = _clips[i][2];
		clip.h = _clips[i][3];
		clips.push_back(clip);
	}
}

AnimatedSprite::~AnimatedSprite() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void AnimatedSprite::renderAnimatedSprite(SDL_Renderer* renderer, SDL_Rect& coordinates, const SDL_RendererFlip flip) {
	//SDL_RenderCopy(renderer, texture, &clips[currentFrame], &coordinates);
	SDL_RenderCopyEx(renderer, texture, &clips[currentFrame], &coordinates, 0, nullptr, flip);
	tick();
}