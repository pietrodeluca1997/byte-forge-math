#pragma once

#include <string.h>
#include <stdint.h>

typedef struct Matrix4_Linear
{
	float data[16];
} Matrix4_Linear;

static inline Matrix4_Linear Matrix4_Identity()
{
	Matrix4_Linear matrix = { 0 };
	memset(matrix.data, 0, sizeof(matrix.data));

	matrix.data[0] = 1;
	matrix.data[5] = 1;
	matrix.data[10] = 1;
	matrix.data[15] = 1;

	return matrix;
}

static inline Matrix4_Linear Matrix4_Translate(Matrix4_Linear matrix, const float x, const float y, const float z)
{
	matrix.data[12] = x;
	matrix.data[13] = y;
	matrix.data[14] = z;

	return matrix;
}

static inline Matrix4_Linear Matrix4_Scale(Matrix4_Linear matrix, const float sx, const float sy, const float sz)
{
	matrix.data[0] *= sx;
	matrix.data[5] *= sy;
	matrix.data[10] *= sz;

	return matrix;
}

static inline Matrix4_Linear Matrix4_Orthographic(float left, float right, float bottom, float top, float near, float far)
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