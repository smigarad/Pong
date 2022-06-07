#include "Player.h"

Player::Player(Vec2 position)
: position(position)
{
    this->rect=
    {
        static_cast<int>(position.x),
        static_cast<int>(position.y),
		PLAYER_WIDTH,
		PLAYER_HEIGHT
    };
}

void Player::Draw(SDL_Renderer* renderer)
{
	rect.y = static_cast<int>(position.y);
    SDL_RenderFillRect(renderer, &rect);
}

void Player::Update(float dt)
{
    position.y += velocity.y * 0.5 * dt;
    

    if (position.y <0)
    {
        position.y =0;
    }
    
    else if(position.y > (SIZEY - PLAYER_HEIGHT))
    {
        position.y = SIZEY - PLAYER_HEIGHT;
    }

    //rect.y = position.y;
}
Player::~Player()
{
    
}

