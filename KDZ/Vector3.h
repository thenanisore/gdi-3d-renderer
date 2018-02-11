/*
* Студент: Иванов Олег Владимирович
* Группа: 141/1, 4 курс
* КДЗ #1, Вариант 1: 3D-сцена в GDI.
*
* Класс Vector3: 3-мерный вектор, векторные операции.
*/

#pragma once

#include <cmath>
#include <vector>

namespace GL {

	// The Vector3 class represents a vector in a 3-dimensional space.
	class Vector3
	{
	public:
		// Initializes a vector with the default values (0, 0, 0).
		Vector3();
		// Initializes a vector with the specified values.
		Vector3(float _x, float _y, float _z);
		// Initializes a vector with the first three values of the given std::vector.
		Vector3(const std::vector<float> &vec);
		// Copy constructor
		Vector3(const Vector3 &vec);

		float x, y, z;

		// Copy assignment operator
		Vector3& operator=(const Vector3 &vec);
		bool operator==(const Vector3 &vec) const;
		bool equalEpsilon(const Vector3 &vec, float eps) const;
		bool operator!=(const Vector3 &vec) const;
		Vector3 operator+(const Vector3 &vec) const;
		Vector3 operator+(float s) const;
		Vector3 operator-(float s) const;
		Vector3 operator-(const Vector3 &vec) const;
		Vector3 operator-() const;
		Vector3 operator*(float s) const;
		Vector3 operator*(const Vector3 &vec) const;
		Vector3 operator/(float s) const;
		// Returns a length of the vector.
		float length() const;
		// Returns a dot product of two vectors
		float dot(const Vector3 &vec) const;
		// Returns a cross product of two vectors
		Vector3 cross(const Vector3 &vec) const;
		// Returns a vector of the same direction with the length 1
		Vector3 normalized() const;
	};
}
