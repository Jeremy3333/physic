#include "ProgSDL.hpp"
#include <cassert>

ProgSDL::ProgSDL()
{
    assert(SDL_Init(SDL_INIT_VIDEO) == 0);
    window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    assert(window != nullptr);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    assert(renderer != nullptr);
    running = true;
}

ProgSDL::~ProgSDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}