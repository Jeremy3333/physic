#pragma once
#include "Math.hpp"
#include "Colors.hpp"

class Particule
{
private:
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;
    Colors color;
    float radius;

public:
    Particule();
    Particule(Vector2f position, Vector2f velocity, Vector2f acceleration, float radius, Colors color);
    void update(float deltaTime);
    Vector2f getPosition();
    void SetPosition(Vector2f position);
    Colors getColor();
    float getRadius();
    ~Particule();
};