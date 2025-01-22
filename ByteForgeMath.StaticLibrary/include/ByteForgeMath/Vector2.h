#pragma once

#include <math.h>

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

/**
 * @brief Adds two 2D vectors.
 *
 * @param a The first vector to add.
 * @param b The second vector to add.
 * @return A new vector representing the sum of `a` and `b`.
 */
static inline Vector2 Vector2_Add(Vector2 a, Vector2 b) 
{
    Vector2 result = { a.x + b.x, a.y + b.y };
    return result;
}

/**
 * @brief Subtracts the second 2D vector from the first.
 *
 * @param a The vector to subtract from.
 * @param b The vector to subtract.
 * @return A new vector representing the result of `a - b`.
 */
static inline Vector2 Vector2_Sub(Vector2 a, Vector2 b) 
{
    Vector2 result = { a.x - b.x, a.y - b.y };
    return result;    
}

/**
 * @brief Calculates the dot product of two 2D vectors.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The dot product of `a` and `b`.
 */
static inline float Vector2_DotProduct(Vector2 a, Vector2 b)
{
    return (a.x * b.x) + (a.y * b.y);
}

/**
 * @brief Scales a 2D vector by a scalar.
 *
 * @param vector The vector to scale.
 * @param scalar The scalar factor.
 * @return A new vector representing the scaled vector.
 */
static inline Vector2 Vector2_Scale(Vector2 vector, float scalar) 
{
    Vector2 result = { vector.x * scalar, vector.y * scalar };
    return result;
}

/**
 * @brief Calculates the length (magnitude) of a 2D vector.
 *
 * @param vector The vector to calculate the length of.
 * @return The length of the vector.
 */
static inline float Vector2_Length(Vector2 vector)
{
    return sqrtf(vector.x * vector.x + vector.y * vector.y);
}

/**
 * @brief Normalizes a 2D vector (scales it to unit length).
 *
 * @param vector The vector to normalize.
 * @return A new normalized vector.
 */
static inline Vector2 Vector2_Normalize(Vector2 vector)
{
    float length = Vector2_Length(vector);

    if (length != 0.0f)
    {
        return Vector2_Scale(vector, 1.0f / length);
    }

    return vector;
}