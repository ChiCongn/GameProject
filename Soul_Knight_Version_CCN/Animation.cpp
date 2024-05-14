
#include"Animation.h"

Animation::Animation(std::string imagePathLeft, std::string imagePathRight, int _w, int _h, const int frames,
		const int _clips[][4], SDL_Renderer* renderer) {
	currentFrame = 0;
	coordinates.x = coordinates.y = 0;
	coordinates.w = _w, coordinates.h = _h;
	textureLeft = loadImage(imagePathLeft, renderer);
	textureRight = loadImage(imagePathRight, renderer);
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

Animation::~Animation() {
	std::cout << "start ~Animation-> delete texture*\n";
	if (textureLeft != nullptr) {
		SDL_DestroyTexture(textureLeft);		
		//texture = nullptr;
	}
	if (textureRight != nullptr) {
		SDL_DestroyTexture(textureRight);
	}
	std::cout << "ok ~Animation\n";
}

void Animation::renderAnimation(SDL_Renderer* renderer, const Direction direction) {
	//std::cout << "render animation\n";
	//SDL_RenderCopy(renderer, texture, &clips[currentFrame], &coordinates);
	if (direction == Direction::East) {
		SDL_RenderCopy(renderer, textureRight, &clips[currentFrame], &coordinates);
		//std::cout << "vcll\n";
	}
	else {
		SDL_RenderCopy(renderer, textureLeft, &clips[currentFrame], &coordinates);
	}
	tick();
	//std::cout << "ok render animation\n";
}
