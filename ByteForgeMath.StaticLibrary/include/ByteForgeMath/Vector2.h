#pragma once

/**
 * @brief Represents a 2D vector with floating-point coordinates.
 *
 * This structure holds the x and y components of a 2D vector, useful for
 * operations in 2D space, such as graphics, physics, and geometry.
 */
typedef struct Vector2
{
    float x;
    float y;
} Vector2;

static inline Vector2 Vector2_Add(Vector2 a, Vector2 b) 
{
    Vector2 result = { a.x + b.x, a.y + b.y };
    return result;
}

static inline Vector2 Vector2_Sub(Vector2 a, Vector2 b) 
{
    Vector2 result = { a.x - b.x, a.y - b.y };
    return result;    
}

static inline float Vector2_Dot(Vector2 a, Vector2 b) 
{
    return (a.x * b.x) + (a.y * b.y);
}

static inline Vector2 Vector2_Scale(Vector2 v, float scalar) 
{
    Vector2 result = { v.x * scalar, v.y * scalar };
    return result;
}