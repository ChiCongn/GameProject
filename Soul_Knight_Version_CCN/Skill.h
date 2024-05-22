#pragma once
#ifndef SKILL_H
#define SKILL_H

#include"Animation.h"
#include"Texture.h"

class Skill {
public:
    Skill(Skill& other) = delete;
    Skill(const std::string& image_path, const std::string& animationPath, int width, int height, 
        const int& frames, const int clips[][4], SDL_Renderer* renderer);
    ~Skill();
    void render(SDL_Renderer* renderer);

    void setCoordinates(int x, int y);
    void setTime(int _time_wait, int _time_active);
    void setCoordinatesImageSkill(int x, int y) { image_skill->setCoordinates(x, y); }

    SDL_Rect getCoordinates() { return animation->getCoordinates(); }
    int getTimeActive() { return time_active; }
    int getTimeWait() { return time_wait; }
    void cooldown();

private:
    Animation* animation;
    Texture* image_skill;
    int time_wait = 0;
    int time_active = 0;
};


#endif