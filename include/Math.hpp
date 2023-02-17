#pragma once

class Vector2f
{
public:
    float x, y;
    Vector2f();
    Vector2f(float x, float y);
    Vector2f operator+(Vector2f v);
    Vector2f operator-(Vector2f v);
    Vector2f operator*(float f);
    Vector2f operator/(float f);
    Vector2f operator+=(Vector2f v);
    Vector2f operator-=(Vector2f v);
    Vector2f operator*=(float f);
    Vector2f operator/=(float f);
    bool operator==(Vector2f v);
    bool operator!=(Vector2f v);
    float length();
    Vector2f normalize();
    ~Vector2f();
};

float distance(Vector2f a, Vector2f b);
Vector2f normalize(Vector2f v);