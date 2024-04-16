
#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H
#include"Common.h"
#include<vector>

class AnimatedSprite {
	SDL_Texture* texture;
    SDL_Rect coordinates;
	std::vector<SDL_Rect> clips;
    int currentFrame=0;
public:
    AnimatedSprite() = delete;
    AnimatedSprite(AnimatedSprite& other) = delete;
	AnimatedSprite(std::string imagePath,int _w, int _h, const int frames, const int _clips[][4], SDL_Renderer* renderer);
    void setCoordinates(int _x, int _y) { coordinates.x = _x, coordinates.y = _y; }
    SDL_Rect getCoordinates() { return coordinates; }
    void tick() {
        currentFrame = (currentFrame + 1) % clips.size();
    }
    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }
    ~AnimatedSprite();
    void renderAnimatedSprite(SDL_Renderer* renderer, const SDL_RendererFlip flip);
};

#endif ANIMATED_SPRITE_H
