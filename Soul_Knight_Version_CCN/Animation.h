
#ifndef ANIMATION_H
#define ANIMATION_H
#include"Common.h"
#include<vector>

class Animation {
	SDL_Texture* textureLeft;
    SDL_Texture* textureRight;
    SDL_Rect coordinates;
	std::vector<SDL_Rect> clips;
    int currentFrame=0;
public:
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
    ~Animation();
    void renderAnimation(SDL_Renderer* renderer, const Direction direction);
};

class Magic {
    SDL_Point target;
    SDL_Texture* texture;
    SDL_Rect coordinates;
    Uint32 preTime;
    std::vector<SDL_Rect> clips;
    int currentFrame = 0;
public:
    Magic(std::string imagePath, int _w, int _h, const int frames,
        const int _clips[][4], SDL_Renderer* renderer);
    ~Magic();
    void tick() {
        currentFrame = (currentFrame + 1) % clips.size();
    }
    void setCoordinates(int _x, int _y) { coordinates.x = _x, coordinates.y = _y; }
    void render(SDL_Renderer* renderer);
    bool isReady();
    void setTarget(const int& _x, const int& _y);
    void move();
};

#endif ANIMATION_H
