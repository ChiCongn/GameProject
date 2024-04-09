
#include"AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(std::string imagePath,int _w, int _h, const int frames, const int _clips[][4], SDL_Renderer* renderer) {
	currentFrame = 0;
	coordinates.x = coordinates.y = 0;
	coordinates.w = _w, coordinates.h = _h;
	texture = loadImage(imagePath, renderer);
	//std::cout << "success to load AnimatedSprite\n";
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
	std::cout << "start ~AnimatedSprite-> delete texture*\n";
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);		
		//texture = nullptr;
	}
	std::cout << "ok ~AnimatedSprite\n";
}

void AnimatedSprite::renderAnimatedSprite(SDL_Renderer* renderer,const SDL_RendererFlip flip) {
	//SDL_RenderCopy(renderer, texture, &clips[currentFrame], &coordinates);
	SDL_RenderCopyEx(renderer, texture, &clips[currentFrame], &coordinates, 0, nullptr, flip);
	tick();
}