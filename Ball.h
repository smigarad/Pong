#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Vec2.h"
#include "Player.h"
#pragma once
using namespace std;


const uint8_t WIDTH = 15;
const uint8_t HEIGHT = 15;
const float SPEED = 1;


enum class CollisionType
{
	None,
	Top,
	Middle,
	Bottom
};

struct Contact
{
    CollisionType type;
    float penetratiton;

};
class Ball
{
private:
    Contact contact;
public:
    Vec2 position;
    Vec2 velocity;
	SDL_Rect rect;

    Ball(Vec2 position,Vec2 velocity);
    void Draw(SDL_Renderer* renderer);
    void Update(float dt);
    Contact CheckPaddleCollision(Player* paddle);
    void CollideWithPaddle(Contact Contact);
    Contact CheckCollisionWithWall();
    void CollideWithWall();

    ~Ball();
};

