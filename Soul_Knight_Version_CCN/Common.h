
#pragma once

#ifndef COMMON_H
#define COMMON_H

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include"Defs.h"

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void logSDLError(std::ostream& os,
	const std::string& msg, bool fatal = false);
void waitUntilKeyPressed();

TTF_Font* loadFont(std::string font_path);
SDL_Texture* loadText(std::string text, std::string font_path, SDL_Renderer* renderer);
SDL_Texture* loadImage(std::string path, SDL_Renderer* renderer);
Mix_Chunk* loadAudio(std::string audioPath);
void playAudio(Mix_Chunk* sound);

bool checkCollision(const SDL_Rect a,const SDL_Rect b);
bool checkCollisionCircle(const SDL_Point center, const SDL_Rect a);
Mix_Music* loadMusic(const char* path);
void playMusic(Mix_Music* gMusic);

#endif