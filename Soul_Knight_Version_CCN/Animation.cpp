
#include"Animation.h"

Animation::Animation(std::string imagePathLeft, std::string imagePathRight, int _w, int _h, const int frames,
		const int _clips[][4], SDL_Renderer* renderer) {
	current_frame = 0;
	coordinates.x = coordinates.y = 0;
	coordinates.w = _w, coordinates.h = _h;
	texture_left = loadImage(imagePathLeft, renderer);
	texture_right = loadImage(imagePathRight, renderer);
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
	//std::cout << "start ~Animation-> delete texture*\n";
	if (texture_left != nullptr) {
		SDL_DestroyTexture(texture_left);
		texture_left = nullptr;
	}
	if (texture_right != nullptr) {
		SDL_DestroyTexture(texture_right);
		texture_right = nullptr;
	}
	//std::cout << "ok ~Animation\n";
}

void Animation::renderAnimation(SDL_Renderer* renderer, const Direction direction) {
	//std::cout << "render animation\n";
	//SDL_RenderCopy(renderer, texture, &clips[currentFrame], &coordinates);
	if (direction == Direction::East) {
		SDL_RenderCopy(renderer, texture_right, &clips[current_frame], &coordinates);
		//std::cout << "vcll\n";
	}
	else {
		SDL_RenderCopy(renderer, texture_left, &clips[current_frame], &coordinates);
	}
	tick();
	//std::cout << "ok render animation\n";
}

void Animation::move(int x, int y) {
	coordinates.x -= x;
	coordinates.y -= y;
}