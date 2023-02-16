#pragma once

#include <SDL2/SDL.h>

class ProgSDL
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
    SDL_Event event;

public:
    ProgSDL();
    ~ProgSDL();
};