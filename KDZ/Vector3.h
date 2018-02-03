#pragma once

#include <cmath>

// The Vector3 class represents a vector in a 3-dimensional space.
class Vector3
{
public:
	// Initializes a vector with the default values (0, 0, 0).
	Vector3();
	// Initializes a vector with the specified values.
	Vector3(float _x, float _y, float _z);
	// Copy constructor
	Vector3(const Vector3 &vec);

	float x, y, z, len;

	inline bool operator==(const Vector3 &vec);
	inline bool operator!=(const Vector3 &vec);
	inline Vector3 operator+(const Vector3 &vec);
	inline Vector3 operator-(const Vector3 &vec);
	inline Vector3 operator-();
	inline Vector3 operator*(float s);
	inline Vector3 operator/(float s);
	// Returns a dot product of two vectors
	inline float dot(const Vector3 &vec);
	// Returns a vector of the same direction with the length 1
	inline Vector3 normalized();
};

Vector3::Vector3() : Vector3(0.0f, 0.0f, 0.0f) { }

Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {
	len = sqrt(_x * _x + _y * _y + _z * _z);
}

Vector3::Vector3(const Vector3 &vec) {
	x = vec.x; y = vec.y; z = vec.z;
}

inline bool Vector3::operator==(const Vector3 &vec) {
	return x == vec.x && y == vec.y && z == vec.z;
}

inline bool Vector3::operator!=(const Vector3 &vec) {
	return x != vec.x || y != vec.y || z != vec.z;
}

inline Vector3 Vector3::operator+(const Vector3 &vec) {
	return Vector3(x + vec.x, y + vec.y, z + vec.z);
}

inline Vector3 Vector3::operator-(const Vector3 &vec) {
	return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

inline Vector3 Vector3::operator-() {
	return Vector3(-x, -y, -z);
}

inline Vector3 Vector3::operator*(float s) {
	return Vector3(s * x, s * y, s * z);
}

inline Vector3 Vector3::operator/(float s) {
	return Vector3(x / s, y / s, z / s);
}

inline float Vector3::dot(const Vector3 &vec) {
	return x * vec.x + y * vec.y + z * vec.z;
}

inline Vector3 Vector3::normalized() {
	return (*this) / this->len;
}
