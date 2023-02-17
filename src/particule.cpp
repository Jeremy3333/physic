#include "Particule.hpp"
#include "Utils.hpp"

Particule::Particule() : position(Vector2f()), velocity(Vector2f()), acceleration(Vector2f()), radius(0), color(Colors()) {}

Particule::Particule(Vector2f position, Vector2f velocity, Vector2f acceleration, float radius, Colors color) : position(position), velocity(velocity), acceleration(acceleration), radius(radius), color(color) {}

void Particule::update(float deltaTime)
{
    velocity += acceleration * deltaTime;
    velocity *= 0.99;
    // 1 meter = 100 pixels
    position += velocity * deltaTime * 100;
    if (position.y > WINDOW_HEIGHT - radius)
    {
        position.y = WINDOW_HEIGHT - radius;
        velocity.y *= -0.6;
    }
    if (position.x > WINDOW_WIDTH - radius)
    {
        position.x = WINDOW_WIDTH - radius;
        velocity.x *= -0.6;
    }
    if (position.x < radius)
    {
        position.x = radius;
        velocity.x *= -0.6;
    }
}

Vector2f Particule::getPosition()
{
    return position;
}

void Particule::SetPosition(Vector2f position)
{
    this->position = position;
}

Colors Particule::getColor()
{
    return color;
}

float Particule::getRadius()
{
    return radius;
}

Particule::~Particule() {}