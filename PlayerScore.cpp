#include "PlayerScore.h"

PlayerScore::PlayerScore(Vec2 positionn, SDL_Renderer* renderer, TTF_Font* font)
: renderer(renderer), font(font), position(positionn)
{
    surface = TTF_RenderText_Solid(font,"0", {255,255,255,255});
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    int width, height;
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

	rect.x = static_cast<int>(position.x);
	rect.y = static_cast<int>(position.y);
	rect.w = width;
	rect.h = height;


}
void PlayerScore::Add()
{
	score ++;
	SDL_FreeSurface(surface);
	//SDL_DestroyTexture(texture);
	surface = TTF_RenderText_Solid(font,to_string(score).c_str(), {255,255,255,255});
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    int width, height;
	

	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	
	rect.x = static_cast<int>(position.x);
	rect.y = static_cast<int>(position.y);
	rect.w = width;
	rect.h = height;
	
}
void PlayerScore::Draw()
{
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

PlayerScore::~PlayerScore()
{
    SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);

}