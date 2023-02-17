#include "World.hpp"
#include "Utils.hpp"
#include "Math.hpp"

World::World()
{
}

World::~World()
{
}

void World::update1(bool addParticule, float deltaTime)
{
    lastSpawnTime += deltaTime;
    if (addParticule && lastSpawnTime > 0.1f)
    {
        lastSpawnTime = 0;
        particules.push_back(Particule(Vector2f(0, 0), Vector2f(20, 0), Vector2f(0, GRAVITY), 5, Colors(0, 0, 255)));
    }
    for (int i = 0; i < particules.size(); i++)
    {
        particules[i].update(deltaTime);
    }
    // for (int i = 0; i < particules.size(); i++)
    // {
    //     for (int j = i + 1; j < particules.size(); j++)
    //     {
    //         if (distance(particules[i].getPosition(), particules[j].getPosition()) < particules[i].getRadius() + particules[j].getRadius())
    //         {
    //             // change the position of the particules so they don't overlap
    //             Vector2f normal = normalize(particules[i].getPosition() - particules[j].getPosition());
    //             Vector2f tangent = Vector2f(-normal.y, normal.x);
    //             Vector2f v1n = normal * dot(particules[i].velocity, normal);
    //             Vector2f v1t = tangent * dot(particules[i].velocity, tangent);
    //             Vector2f v2n = normal * dot(particules[j].velocity, normal);
    //             Vector2f v2t = tangent * dot(particules[j].velocity, tangent);
    //             particules[i].SetPosition(particules[i].getPosition() + normal * (particules[i].getRadius() + particules[j].getRadius() - distance(particules[i].getPosition(), particules[j].getPosition())));
    //             particules[j].SetPosition(particules[j].getPosition() - normal * (particules[i].getRadius() + particules[j].getRadius() - distance(particules[i].getPosition(), particules[j].getPosition())));
    //             // change the velocity of the particules
    //             particules[i].velocity = v1t + v2n;
    //             particules[j].velocity = v2t + v1n;
    //         }
    //     }
    // }
}