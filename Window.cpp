#include "Window.h"

Window::Window(const char* name,uint sizex, uint sizey)
{
    window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,sizex,sizey,SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(this->window,-1,SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);

}

void Window::Display()
{
    SDL_RenderPresent(this->renderer);
}

SDL_Renderer* Window::GetRenderer()
{ 
    return this->renderer;
}

TTF_Font* Window::GetFont()
{
    return this->scoreFont;
}
Window::~Window()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    TTF_CloseFont(scoreFont);
}