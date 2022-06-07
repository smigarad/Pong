#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Window.h"
#include "Vec2.h"
#include <SDL2/SDL_ttf.h>
#pragma once

using namespace std;

class PlayerScore
{
public:
    SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Rect rect;
    Vec2 position;
    int score =0;


    PlayerScore(Vec2 positionn, SDL_Renderer* renderer, TTF_Font* font);
    void Add();
    void Draw();
    ~PlayerScore();
};

