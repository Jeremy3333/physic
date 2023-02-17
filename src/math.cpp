#include "Math.hpp"
#include <cmath>

Vector2f::Vector2f() : x(0), y(0)
{
}

Vector2f::Vector2f(float x, float y) : x(x), y(y)
{
}

Vector2f Vector2f::operator+(Vector2f v)
{
    return Vector2f(x + v.x, y + v.y);
}

Vector2f Vector2f::operator-(Vector2f v)
{
    return Vector2f(x - v.x, y - v.y);
}

Vector2f Vector2f::operator*(float f)
{
    return Vector2f(x * f, y * f);
}

Vector2f Vector2f::operator/(float f)
{
    return Vector2f(x / f, y / f);
}

Vector2f Vector2f::operator+=(Vector2f v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vector2f Vector2f::operator-=(Vector2f v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

Vector2f Vector2f::operator*=(float f)
{
    x *= f;
    y *= f;
    return *this;
}

Vector2f Vector2f::operator/=(float f)
{
    x /= f;
    y /= f;
    return *this;
}

bool Vector2f::operator==(Vector2f v)
{
    return x == v.x && y == v.y;
}

bool Vector2f::operator!=(Vector2f v)
{
    return x != v.x || y != v.y;
}

float Vector2f::length()
{
    return sqrt(x * x + y * y);
}

Vector2f Vector2f::normalize()
{
    float l = length();
    return Vector2f(x / l, y / l);
}

Vector2f::~Vector2f()
{
}

float distance(Vector2f a, Vector2f b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Vector2f normalize(Vector2f v)
{
    float l = v.length();
    return Vector2f(v.x / l, v.y / l);
}