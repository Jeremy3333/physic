#include "ProgSDL.hpp"
#include "Utils.hpp"
#include <cassert>
#include <string>

void ProgSDL::loop()
{
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
        world.update1(true, frameTicks / 1000.0f);
        draw();
        SDL_RenderPresent(renderer);
        checkFPS();
    }
}

void ProgSDL::draw()
{
    drawBackground();
    for (Particule particule : world.particules)
    {
        drawParticules(particule);
    }
}

void ProgSDL::drawBackground()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void ProgSDL::drawParticules(Particule particule)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    fillCircle(particule.getPosition().x, particule.getPosition().y, particule.getRadius(), particule.getColor());
}

void ProgSDL::fillCircle(int x, int y, int radius, Colors color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    for (int i = x - radius; i < x + radius; i++)
    {
        for (int j = y - radius; j < y + radius; j++)
        {
            if (distance(i, j, x, y) < radius)
            {
                SDL_RenderDrawPoint(renderer, i, j);
            }
        }
    }
}

void ProgSDL::checkFPS()
{
    frameTicks = SDL_GetTicks() - startTicks;
    fps = frameTicks < 1000 / FPS;
    if (fps)
    {
        SDL_Delay((1000 / FPS) - frameTicks);
    }
    SDL_SetWindowTitle(window, (std::string(WINDOW_TITLE) + " - FPS: " + std::to_string(fps ? FPS : 1000 / frameTicks)).c_str());
    startTicks = SDL_GetTicks();
}

ProgSDL::ProgSDL() : window(nullptr), renderer(nullptr), running(false), event(), startTicks(0), frameTicks(0), fps(true), world()
{
    assert(SDL_Init(SDL_INIT_VIDEO) == 0);
    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    assert(window != nullptr);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    assert(renderer != nullptr);
    running = true;

    loop();
}

ProgSDL::~ProgSDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}