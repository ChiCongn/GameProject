
#ifndef ANIMATION_H
#define ANIMATION_H
#include"Common.h"
#include"Texture.h"
#include<vector>

class Animation {
public:
    Animation() = delete;
    Animation(Animation& other) = delete;
    Animation(std::string imagePathLeft, std::string imagePathRight, int _w, int _h, const int frames,
            const int _clips[][4], SDL_Renderer* renderer);
    void renderAnimation(SDL_Renderer* renderer, const Direction direction);

    void setCoordinates(int _x, int _y) { coordinates.x = _x, coordinates.y = _y; }
    void move(int x, int y);
    SDL_Rect getCoordinates() { return coordinates; }
    SDL_Point getPosition() { return { coordinates.x, coordinates.y }; }
    void tick() {
        current_frame = (current_frame + 1) % clips.size();
    }
    const SDL_Rect* getCurrentClip() const {
        return &(clips[current_frame]);
    }
    int getCurrentFrame() { return current_frame; }
    ~Animation();

private:
    SDL_Rect coordinates;
    SDL_Texture* texture_left;
    SDL_Texture* texture_right;
    std::vector<SDL_Rect> clips;
    int current_frame = 0;
};



#endif ANIMATION_H
