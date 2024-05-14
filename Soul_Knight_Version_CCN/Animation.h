
#ifndef ANIMATION_H
#define ANIMATION_H
#include"Common.h"
#include"Texture.h"
#include<vector>

class Animation {
	SDL_Texture* textureLeft;
    SDL_Texture* textureRight;
	std::vector<SDL_Rect> clips;
    int currentFrame=0;
public:
    SDL_Rect coordinates;
    Animation() = delete;
    Animation(Animation& other) = delete;
    Animation(std::string imagePathLeft, std::string imagePathRight, int _w, int _h, const int frames,
            const int _clips[][4], SDL_Renderer* renderer);

    void setCoordinates(int _x, int _y) { coordinates.x = _x, coordinates.y = _y; }
    SDL_Rect getCoordinates() { return coordinates; }
    void tick() {
        currentFrame = (currentFrame + 1) % clips.size();
    }
    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }
    int getCurrentFrame() { return currentFrame; }
    ~Animation();
    void renderAnimation(SDL_Renderer* renderer, const Direction direction);
};



#endif ANIMATION_H
