/*
* Студент: Иванов Олег Владимирович
* Группа: 141/1, 4 курс
* КДЗ #1, Вариант 1: 3D-сцена в GDI.
*
* Namespace Util: различные функции (расчёт матриц афинных преобразование, проекций, LookAt, барицентрических коорд. и др.).
*/

#pragma once

#include "Matrix3.h"
#include "Matrix4.h"
#include "Polygon.h"

namespace GL {

	// The Matrix.h file contains utility functions for matrix transformations.
	namespace Util {

		const long double PI = 3.141592653589793238462643383279502884L;

		// Converts degrees to radians.
		float degToRad(float degrees);
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
		Matrix4 orthographic(float top, float right, float near, float far);
		// Calculate barycentric coordinates (u, v, w) for point p with respect to triangle (a, b, c).
		Vector3 barycentric2d(const Vector3 &p, const Vector3 &a, const Vector3 &b, const Vector3 &c);
		// Returns true if a point p in located inside a triangle (a, b, c) in 2d space.
		bool isInTriangle(const Vector3 &p, const Vector3 &a, const Vector3 &b, const Vector3 &c);
		// Calculates a normal vector to a given triangle.
		Vector3 normal(const Vector3 &a, const Vector3 &b, const Vector3 &c);
		// Parses a string containing of three floating-point numbers and returns a resulting Vector3.
		Vector3 parseVec3(System::String^ str);
		// Returns true is the difference between a and b is less than epsilon.
		bool compareFloat(float a, float b, float eps);
		// Returns a Color object with the RGBA values from the col vector.
		System::Drawing::Color vecToColor(const Vector4 &col);
		// Returns a Vector4 object with the RGBA values from the Color object
		Vector4 colorToVec(System::Drawing::Color ^col);
		// Returns a reflection direction for a given incident vector and a normal.
		Vector3 reflect(const Vector3 &inc, const Vector3 &norm);
		// Returns an area of the given polygon.
		float area(const GL::Polygon &poly);
		// Clamps a number between min and max values.
		float clamp(float num, float min, float max);
		// returns a signum of x
		int sign(int x);
		// swaps two numbers in-place
		float max(float a, float b);
		float min(float a, float b);
		// Returns a vector that has all coordinates in (min, max).
		Vector3 clampVec(Vector3 vec, float min, float max);
		Vector4 clampVec(Vector4 vec, float min, float max);
		// swaps two numbers in-place
		template<typename T>
		void swap(T &x, T &y) {
			T t = x; x = y; y = t;
		}
	}
}
