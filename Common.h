#pragma once

#ifndef COMMON_H
#define COMMON_H

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>

static const int SCREEN_WIDTH = 1200;
static const int SCREEN_HEIGHT = 650;

SDL_Texture* loadText(std::string path, SDL_Renderer* renderer);
SDL_Texture* loadImage(std::string path, SDL_Renderer* renderer);
Mix_Chunk* loadAudio(std::string audioPath);

bool checkCollision(SDL_Rect a, SDL_Rect b);

#endif