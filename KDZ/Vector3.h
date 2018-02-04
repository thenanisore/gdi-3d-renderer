#pragma once

#include <cmath>
#include <vector>

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

	float x, y, z, len;

	inline bool operator==(const Vector3 &vec) const;
	inline bool operator!=(const Vector3 &vec) const;
	inline Vector3 operator+(const Vector3 &vec) const;
	inline Vector3 operator-(const Vector3 &vec) const;
	inline Vector3 operator-() const;
	inline Vector3 operator*(float s) const;
	inline Vector3 operator/(float s) const;
	// Returns a dot product of two vectors
	inline float dot(const Vector3 &vec) const;
	// Returns a cross product of two vectors
	inline Vector3 cross(const Vector3 &vec) const;
	// Returns a vector of the same direction with the length 1
	inline Vector3 normalized() const;
};

Vector3::Vector3() : Vector3(0.0f, 0.0f, 0.0f) { }

Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {
	len = sqrt(_x * _x + _y * _y + _z * _z);
}

Vector3::Vector3(const Vector3 &vec) {
	x = vec.x; y = vec.y; z = vec.z;
}

Vector3::Vector3(const std::vector<float> &vec) {
	if (vec.size() < 3)
		throw std::invalid_argument("Vector size less than dimension");
	x = vec[0]; y = vec[1]; z = vec[2];
}

inline bool Vector3::operator==(const Vector3 &vec) const {
	return x == vec.x && y == vec.y && z == vec.z;
}

inline bool Vector3::operator!=(const Vector3 &vec) const {
	return x != vec.x || y != vec.y || z != vec.z;
}

inline Vector3 Vector3::operator+(const Vector3 &vec) const {
	return Vector3(x + vec.x, y + vec.y, z + vec.z);
}

inline Vector3 Vector3::operator-(const Vector3 &vec) const {
	return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

inline Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

inline Vector3 Vector3::operator*(float s) const {
	return Vector3(s * x, s * y, s * z);
}

inline Vector3 Vector3::operator/(float s) const {
	if (s == 0)
		throw std::invalid_argument("Division by zero");
	return Vector3(x / s, y / s, z / s);
}

inline float Vector3::dot(const Vector3 &vec) const {
	return x * vec.x + y * vec.y + z * vec.z;
}

inline Vector3 Vector3::cross(const Vector3 &vec) const {
	return Vector3(y * vec.z - z * vec.y,
			   	   z * vec.x - x * vec.z,
				   x * vec.y - y * vec.x);
}

inline Vector3 Vector3::normalized() const {
	// return a zero vector if already is one
	return (*this) / (len == 0 ? 1 : len);
}
