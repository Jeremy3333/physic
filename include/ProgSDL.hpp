#pragma once

#include <SDL2/SDL.h>

#include "World.hpp"

class ProgSDL
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    bool running, fps;
    float startTicks, frameTicks;
    World world;

    void loop();
    void draw();
    void drawBackground();
    void drawParticules(Particule particule);
    void fillCircle(int x, int y, int radius, Colors color);
    void checkFPS();

public:
    /**
     * @brief Construct a new ProgSDL object by initializing SDL2 and creating a window and renderer
     *
     */
    ProgSDL();

    /**
     * @brief Destroy the ProgSDL object by destroying the renderer and window and quitting SDL2
     *
     */
    ~ProgSDL();
};

float distance(int x1, int y1, int x2, int y2);