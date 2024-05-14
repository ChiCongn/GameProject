#pragma once
#ifndef SKILL_H
#define SKILL_H

#include"Animation.h"

class Skill {
public:
    SDL_Point target;
    int time_wait = TIME_WAIT_SKILL;
    int time_active = 1;
    Animation* skill;

    Skill(Skill& other) = delete;
    Skill(const std::string& animationPath, int width, int height, const int& frames, const int clips[][4], SDL_Renderer* renderer);
    ~Skill();

    void setCoordinates(int x, int y);
    void setTime(int _time_wait, int _time_active);
    void cooldown();
    void render(SDL_Renderer* renderer);
    void setTarget(int x, int y);
    void moveToTarget();
};


#endif