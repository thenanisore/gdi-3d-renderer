#pragma once

#include <cmath>

// The Vector4 class represents a vector in a 4-dimensional space.
class Vector4
{
public:
	// Initializes a vector with the default values (0, 0, 0, 0).
	Vector4();
	// Initializes a vector with the specified values.
	Vector4(float _x, float _y, float _z, float _w);
	// Copy constructor
	Vector4(const Vector4 &vec);

	float x, y, z, w, len;

	inline bool operator==(const Vector4 &vec);
	inline bool operator!=(const Vector4 &vec);
	inline Vector4 operator+(const Vector4 &vec);
	inline Vector4 operator-(const Vector4 &vec);
	inline Vector4 operator-();
	inline Vector4 operator*(float s);
	inline Vector4 operator/(float s);
	// Returns a dot product of two vectors
	inline float dot(const Vector4 &vec);
	// Returns a vector of the same direction with the length 1
	inline Vector4 normalized();
};

Vector4::Vector4() : Vector4(0.0f, 0.0f, 0.0f, 0.0f) { }

Vector4::Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {
	len = sqrt(_x * _x + _y * _y + _z * _z + _w * _w);
}

Vector4::Vector4(const Vector4 &vec) {
	x = vec.x; y = vec.y; z = vec.z; w = vec.w;
}

inline bool Vector4::operator==(const Vector4 &vec) {
	return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
}

inline bool Vector4::operator!=(const Vector4 &vec) {
	return x != vec.x || y != vec.y || z != vec.z || w != vec.w;
}

inline Vector4 Vector4::operator+(const Vector4 &vec) {
	return Vector4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}

inline Vector4 Vector4::operator-(const Vector4 &vec) {
	return Vector4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}

inline Vector4 Vector4::operator-() {
	return Vector4(-x, -y, -z, -w);
}

inline Vector4 Vector4::operator*(float s) {
	return Vector4(s * x, s * y, s * z, s * w);
}

inline Vector4 Vector4::operator/(float s) {
	return Vector4(x / s, y / s, z / s, w / s);
}

inline float Vector4::dot(const Vector4 &vec) {
	return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
}

inline Vector4 Vector4::normalized() {
	return (*this) / this->len;
}
