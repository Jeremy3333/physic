#pragma once

#include "Particule.hpp"

#include <vector>

class World
{
private:
    float lastSpawnTime;

public:
    std::vector<Particule> particules;
    World();
    ~World();

    void update1(bool addParticule, float deltaTime);
};