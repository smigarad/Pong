#include "Ball.h"

Ball::Ball(Vec2 position, Vec2 velocity)
    : position(position), velocity(velocity)
{
    rect.x = static_cast<int>(position.x);
	rect.y = static_cast<int>(position.y);
	rect.w = WIDTH;
	rect.h = HEIGHT;
    
    
}

void Ball::Draw(SDL_Renderer* renderer)
    
{
    rect.x = static_cast<int>(position.x);
	rect.y = static_cast<int>(position.y);

	SDL_RenderFillRect(renderer, &rect);

}

void Ball::Update(float dt)
{
 position += velocity * dt;
}

Contact Ball::CheckPaddleCollision(Player* paddle)
{
	float ballLeft = position.x;
	float ballRight = position.x + WIDTH;
	float ballTop = position.y;
	float ballBottom = position.y + HEIGHT;

	float paddleLeft = paddle->position.x;
	float paddleRight = paddle->position.x + PLAYER_WIDTH;
	float paddleTop = paddle->position.y;
	float paddleBottom = paddle->position.y + PLAYER_HEIGHT;
	
	Contact contact{};

	if (ballLeft >= paddleRight)
	{
		return contact;
	}

	if (ballRight <= paddleLeft)
	{
		return contact;
	}

	if (ballTop >= paddleBottom)
	{
		return contact;
	}

	if (ballBottom <= paddleTop)
	{
		return contact;
	}

	float paddleRangeUpper = paddleBottom - (2.0f * PLAYER_HEIGHT / 3.0f);
	float paddleRangeMiddle = paddleBottom - (PLAYER_HEIGHT / 3.0f);

	if (velocity.x < 0) contact.penetratiton = paddleRight - ballLeft;
	else if (velocity.x > 0) contact.penetratiton = paddleLeft - ballRight;
	

	if ((ballBottom > paddleTop) && (ballBottom < paddleRangeUpper)) contact.type = CollisionType::Top;
	
	else if ((ballBottom > paddleRangeUpper) && (ballBottom < paddleRangeMiddle)) contact.type = CollisionType::Middle;
	else contact.type = CollisionType::Bottom;
	return contact;

}

Contact Ball::CheckCollisionWithWall()
{
	float ballTop = position.y;
	float ballBottom = position.y + HEIGHT;

	if (ballTop < 0)
	{
		contact.type = CollisionType::Top;
		contact.penetratiton = -ballTop;
	}
	else if (ballBottom > SIZEY)
	{
		contact.type = CollisionType::Bottom;
		contact.penetratiton = SIZEY - ballBottom;
	}

	return contact;
}

void Ball::CollideWithWall()
{
	if ((contact.type == CollisionType::Top) || (contact.type == CollisionType::Bottom))
	{
		position.y += contact.penetratiton;
		velocity.y = -velocity.y;
	}
}
void Ball::CollideWithPaddle(Contact contact)
{
		position.x += contact.penetratiton;
		velocity.x = -velocity.x;

		if (contact.type == CollisionType::Top)
		{
			velocity.y = -0.75f * SPEED;
		}
		else if (contact.type == CollisionType::Bottom)
		{
			velocity.y = 0.75f * SPEED;
		}
	}

Ball::~Ball()
{
    
}