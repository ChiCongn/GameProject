
#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H
#include"Common.h"
#include<vector>

class AnimatedSprite {
	SDL_Texture* texture;
	std::vector<SDL_Rect> clips;
    int currentFrame=0;
public:
	void initAnimatedSprite (std::string imagePath, const int frames, const int _clips[][4], SDL_Renderer* renderer);
    void tick() {
        currentFrame = (currentFrame + 1) % clips.size();
    }
    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }
    ~AnimatedSprite();
    void renderAnimatedSprite(SDL_Renderer* renderer, SDL_Rect& coordinates, const SDL_RendererFlip flip);
};

#endif ANIMATED_SPRITE_H
