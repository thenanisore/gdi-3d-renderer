#pragma once

#include "Matrix3.h"
#include "Matrix4.h"

namespace GL {

	// The Matrix.h file contains utility functions for matrix transformations.
	namespace Util {

		const long double PI = 3.141592653589793238462643383279502884L;

		// Converts degrees to radians.
		float degreesToRadians(float degrees);
		// Moves the object by the given movement vector.
		Matrix4 translate(const Matrix4& mat, const Vector3 &move);
		// Rotates the object around the X-axis.
		Matrix4 rotateX(const Matrix4& mat, float degrees);
		// Rotates the object around the Y-axis.
		Matrix4 rotateY(const Matrix4& mat, float degrees);
		// Rotates the object around the Z-axis.
		Matrix4 rotateZ(const Matrix4& mat, float degrees);
		// Reflects the object across the XY plane.
		Matrix4 reflectXY(const Matrix4& mat);
		// Reflects the object across the XZ plane.
		Matrix4 reflectXZ(const Matrix4& mat);
		// Reflects the object across the YZ plane.
		Matrix4 reflectYZ(const Matrix4& mat);
		// Scales the object by the magnitude vector.
		Matrix4 scale(const Matrix4& mat, const Vector3 magnitude);
		// Returns a LookAt matrix.
		Matrix4 lookAt(const Vector3 &position, const Vector3 &target, const Vector3 &up);
		// Returns a perspective projection matrix with the specified parameters.
		Matrix4 perspective(float fov, float aspect, float near, float far);
		// Returns an orthgraphic projection matrix with the specified parameters.
		Matrix4 orthographic(float left, float right, float top, float bottom, float near, float far);
	}
}
