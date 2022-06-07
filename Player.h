#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Window.h"
#include "Vec2.h"
#pragma once
using namespace std;

const float PADDLE_SPEED = 1.0f;

const uint8_t PLAYER_WIDTH = 20;
const uint8_t PLAYER_HEIGHT = 70;
class Player
{
public:
    Vec2 position;
    Vec2 velocity = {0,0};
	SDL_Rect rect;

    
    Player(Vec2 position);
    void Draw(SDL_Renderer* renderer);
    void Update(float dt);

    ~Player();
};