
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
	std::cout << "start ~AnimatedSprite-> delete texture*\n";
	if (textureLeft != nullptr) {
		SDL_DestroyTexture(textureLeft);		
		//texture = nullptr;
	}
	if (textureRight != nullptr) {
		SDL_DestroyTexture(textureRight);
	}
	std::cout << "ok ~AnimatedSprite\n";
}

void Animation::renderAnimation(SDL_Renderer* renderer, const Direction direction) {
	//SDL_RenderCopy(renderer, texture, &clips[currentFrame], &coordinates);
	if(direction==Direction::East)
		SDL_RenderCopy(renderer, textureRight, &clips[currentFrame], &coordinates);
	else 
		SDL_RenderCopy(renderer, textureLeft, &clips[currentFrame], &coordinates);

	tick();
}

Magic::Magic(std::string imagePath, int _w, int _h, const int frames,
	const int _clips[][4], SDL_Renderer* renderer) {
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
	preTime = SDL_GetTicks()/1000;
	target = { 0, 0 };
}

Magic::~Magic() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void Magic::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, &clips[currentFrame], &coordinates);
	tick();
}

bool Magic::isReady() {
	Uint32 curTime = SDL_GetTicks()/1000;
	if (curTime - preTime >= COOLDOWN) {
		preTime = curTime;
		return true;
	}
	return false;
}

void Magic::setTarget(const int& _x, const int& _y) {
	target.x = _x;
	target.y = _y;
}

void Magic::move() {
	if (target.x != coordinates.x) {
		coordinates.x += (target.x - coordinates.x)%SPEED_SKILL;
	}
	if (target.y != coordinates.y) {
		coordinates.y + (target.y - coordinates.y) % SPEED_SKILL;
	}
}