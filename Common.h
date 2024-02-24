#pragma once

#ifndef COMMON_H
#define COMMON_H

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>

extern SDL_Renderer* renderer;

const int SCREEN_WIDTH = 1066;
const int SCREEN_HEIGHT = 602;
const std::string WINDOW_TITLE = "An Implementation of Code.org Painter";

const SDL_Color CYAN_COLOR = { 0,255,255 };
const SDL_Color BLUE_COLOR = { 0, 0, 255 };
const SDL_Color ORANGE_COLOR = { 255, 165, 0 };
const SDL_Color YELLOW_COLOR = { 255, 255, 0 };
const SDL_Color LIME_COLOR = { 0, 255, 0 };
const SDL_Color PURPLE_COLOR = { 128, 0, 128 };
const SDL_Color RED_COLOR = { 255, 0, 0 };
const SDL_Color WHITE_COLOR = { 255, 255, 255 };
const SDL_Color BLACK_COLOR = { 0, 0, 0 };
const SDL_Color GREEN_COLOR = { 0, 128, 0 };
const SDL_Color DEFAULT_COLOR = BLACK_COLOR;

TTF_Font* setFontText(std::string font_path);
SDL_Texture* loadText(std::string text, TTF_Font* font,SDL_Color color , SDL_Renderer* renderer);
SDL_Texture* loadImage(const char* path, SDL_Renderer* renderer);

void showBkGround();

void ShowMenu();

#endif COMMON_H