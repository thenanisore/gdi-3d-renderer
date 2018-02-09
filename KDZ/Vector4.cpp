#include "Vector4.h"

namespace GL {

	Vector4::Vector4() : Vector4(0.0f, 0.0f, 0.0f, 0.0f) { }

	Vector4::Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) { }

	Vector4::Vector4(const Vector4 &vec) {
		x = vec.x; y = vec.y; z = vec.z; w = vec.w;
	}

	Vector4::Vector4(const std::vector<float> &vec) {
		if (vec.size() < 4)
			throw std::invalid_argument("Vector size less than dimension");
		x = vec[0]; y = vec[1]; z = vec[2]; w = vec[3];
	}

	Vector4::Vector4(const Vector3 &vec, float _w) {
		x = vec.x; y = vec.y; z = vec.z; w = _w;
	}

	Vector4::Vector4(const Vector3 & vec) : Vector4(vec.x, vec.y, vec.z, 1.f) { }

	Vector4& Vector4::operator=(const Vector4 &vec) {
		x = vec.x; y = vec.y; z = vec.z; w = vec.w;
		return *this;
	}

	bool Vector4::operator==(const Vector4 &vec) const {
		return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
	}

	bool Vector4::operator!=(const Vector4 &vec) const {
		return x != vec.x || y != vec.y || z != vec.z || w != vec.w;
	}

	Vector4 Vector4::operator+(const Vector4 &vec) const {
		return Vector4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
	}

	Vector4 Vector4::operator-(const Vector4 &vec) const {
		return Vector4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
	}

	Vector4 Vector4::operator-() const {
		return Vector4(-x, -y, -z, -w);
	}

	Vector4 Vector4::operator*(float s) const {
		return Vector4(s * x, s * y, s * z, s * w);
	}

	Vector4 Vector4::operator/(float s) const {
		if (s == 0)
			throw std::invalid_argument("Division by zero");
		return Vector4(x / s, y / s, z / s, w / s);
	}

	float Vector4::length() const {
		return sqrt(x * x + y * y + z * z + w * w);
	}

	float Vector4::dot(const Vector4 &vec) const {
		return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
	}

	Vector4 Vector4::normalized() const {
		// return a zero vector if already is one
		float len = length();
		return (*this) / (len == 0 ? 1 : len);
	}

	Vector3 Vector4::fromHomogeneous() const {
		return Vector3(x / w, y / w, z / w);
	}

	Vector3 Vector4::toVec3() const {
		return Vector3(x, y, z);
	}
}