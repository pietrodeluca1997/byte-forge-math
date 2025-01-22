#pragma once

#include <string.h>
#include <stdint.h>

/**
 * @brief Represents a 4x4 matrix used in 3D graphics and transformations.
 *
 * This matrix is used for representing transformations such as translation, scaling, and projection.
 */
typedef struct Matrix4_Linear
{
	float data[16];
} Matrix4_Linear;

/**
 * @brief Returns the identity matrix (4x4).
 *
 * The identity matrix is a matrix that, when multiplied by another matrix, leaves it unchanged.
 *
 * @return A Matrix4_Linear representing the identity matrix.
 */
static inline Matrix4_Linear Matrix4_Identity()
{
	Matrix4_Linear matrix = { 0 };

	matrix.data[0] = 1;
	matrix.data[5] = 1;
	matrix.data[10] = 1;
	matrix.data[15] = 1;

	return matrix;
}

/**
 * @brief Translates a matrix by a given vector (x, y, z).
 *
 * This operation modifies the translation components of the matrix.
 *
 * @param matrix The matrix to be translated.
 * @param x The translation distance along the X axis.
 * @param y The translation distance along the Y axis.
 * @param z The translation distance along the Z axis.
 * @return A new Matrix4_Linear with the applied translation.
 */
static inline Matrix4_Linear Matrix4_Translate(Matrix4_Linear matrix, const float x, const float y, const float z)
{
	matrix.data[12] = x;
	matrix.data[13] = y;
	matrix.data[14] = z;

	return matrix;
}

/**
 * @brief Scales a matrix by a given factor on each axis (sx, sy, sz).
 *
 * This operation modifies the scaling components of the matrix.
 *
 * @param matrix The matrix to be scaled.
 * @param sx The scaling factor along the X axis.
 * @param sy The scaling factor along the Y axis.
 * @param sz The scaling factor along the Z axis.
 * @return A new Matrix4_Linear with the applied scaling.
 */
static inline Matrix4_Linear Matrix4_Scale(Matrix4_Linear matrix, const float sx, const float sy, const float sz)
{
	matrix.data[0] *= sx;
	matrix.data[5] *= sy;
	matrix.data[10] *= sz;

	return matrix;
}

/**
 * @brief Creates an orthographic projection matrix.
 *
 * This creates a 4x4 matrix suitable for orthogonal projection in 2D rendering, where objects are rendered without perspective.
 *
 * @param left The left boundary of the view frustum.
 * @param right The right boundary of the view frustum.
 * @param bottom The bottom boundary of the view frustum.
 * @param top The top boundary of the view frustum.
 * @param near The near clipping plane distance.
 * @param far The far clipping plane distance.
 * @return A Matrix4_Linear representing the orthographic projection matrix.
 */
static inline Matrix4_Linear Matrix4_Orthographic(const float left, const float right, const float bottom, const float top, const float near, const float far)
{
	Matrix4_Linear matrix = { 0 };

	matrix.data[0] = 2.0f / (right - left);
	matrix.data[5] = 2.0f / (top - bottom);
	matrix.data[10] = -2.0f / (far - near);
	matrix.data[15] = 1.0f;

	matrix.data[12] = -(right + left) / (right - left);
	matrix.data[13] = -(top + bottom) / (top - bottom);
	matrix.data[14] = - -(far + near) / (far - near);

	return matrix;
}