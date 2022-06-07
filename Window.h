#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#pragma once
using namespace std;

const uint SIZEX = 800;
const uint SIZEY = 600;

class Window
{
private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    TTF_Font* scoreFont = TTF_OpenFont("DejaVuSans.ttf", 40);
public:
    Window(const char* name, uint sizex, uint sizey);
    void Display();
    SDL_Renderer* GetRenderer();
    TTF_Font* GetFont();
    ~Window();
};


