#pragma once

#include "Vector3.h"

#include <cmath>

namespace GL {

	// The Vector4 class represents a vector in a 4-dimensional space.
	class Vector4
	{
	public:
		// Initializes a vector with the default values (0, 0, 0, 0).
		Vector4();
		// Initializes a vector with the specified values.
		Vector4(float _x, float _y, float _z, float _w);
		// Initializes a vector with the first four values of the given std::vector.
		Vector4::Vector4(const std::vector<float> &vec);
		// Initializes a vector with the values of the given Vector3 with a w-coordinate.
		Vector4(const Vector3 &vec, float _w);
		// Initializes a vector with the values of the given Vector3 with w = 1.
		Vector4(const Vector3 &vec);
		// Copy constructor
		Vector4(const Vector4 &vec);

		float x, y, z, w;

		// Copy assignment operator
		Vector4& operator=(const Vector4 &vec);
		bool operator==(const Vector4 &vec) const;
		bool operator!=(const Vector4 &vec) const;
		Vector4 operator+(const Vector4 &vec) const;
		Vector4 operator-(const Vector4 &vec) const;
		Vector4 operator-() const;
		Vector4 operator*(float s) const;
		Vector4 operator/(float s) const;
		// Returns a length of the vector.
		float length() const;
		// Returns a dot product of two vectors
		float dot(const Vector4 &vec) const;
		// Returns a vector of the same direction with the length 1
		Vector4 normalized() const;
		// Returns a normalized Vector3, dividing the coordinates by w.
		Vector3 fromHomogeneous() const;
		Vector3 toVec3() const;
	};
}