#include "Util.h"
#include "Matrix3.h"
#include "Matrix4.h"

namespace GL {

	// The Matrix.h file contains utility functions for matrix transformations.
	namespace Util {

		// Converts degrees to radians.
		float degToRad(float degrees) {
			return degrees * PI / 180.0f;
		}

		// Moves the object by the given movement vector.
		Matrix4 translate(const Matrix4& mat, const Vector3 &move) {
			// set translation matrix
			Matrix4 translationMatrix;
			translationMatrix.set(0, 3, move.x);
			translationMatrix.set(1, 3, move.y);
			translationMatrix.set(2, 3, move.z);
			// apply by multiplication
			return translationMatrix * mat;
		}

		Matrix4 rotateX(const Matrix4& mat, float degrees) {
			// set rotation matrix
			float angle = degToRad(degrees);
			Matrix4 rotationMatrix;
			rotationMatrix.set(1, 1, cos(angle));
			rotationMatrix.set(2, 1, -sin(angle));
			rotationMatrix.set(1, 2, sin(angle));
			rotationMatrix.set(2, 2, cos(angle));
			// apply by multiplication
			return rotationMatrix * mat;
		}

		Matrix4 rotateY(const Matrix4& mat, float degrees) {
			// set rotation matrix
			float angle = degToRad(degrees);
			Matrix4 rotationMatrix;
			rotationMatrix.set(0, 0, cos(angle));
			rotationMatrix.set(0, 2, sin(angle));
			rotationMatrix.set(2, 0, -sin(angle));
			rotationMatrix.set(2, 2, cos(angle));
			// apply by multiplication
			return rotationMatrix * mat;
		}

		Matrix4 rotateZ(const Matrix4& mat, float degrees) {
			// set rotation matrix
			float angle = degToRad(degrees);
			Matrix4 rotationMatrix;
			rotationMatrix.set(0, 0, cos(angle));
			rotationMatrix.set(0, 1, -sin(angle));
			rotationMatrix.set(1, 0, sin(angle));
			rotationMatrix.set(1, 1, cos(angle));
			// apply by multiplication
			return rotationMatrix * mat;
		}

		// Reflects the object across the XY plane.
		Matrix4 reflectXY(const Matrix4& mat) {
			// set reflection matrix
			Matrix4 reflectionMatrix;
			reflectionMatrix.set(2, 2, -1);
			// apply by multiplication
			return reflectionMatrix * mat;
		}

		// Reflects the object across the XZ plane.
		Matrix4 reflectXZ(const Matrix4& mat) {
			// set reflection matrix
			Matrix4 reflectionMatrix;
			reflectionMatrix.set(1, 1, -1);
			// apply by multiplication
			return reflectionMatrix * mat;
		}

		// Reflects the object across the YZ plane.
		Matrix4 reflectYZ(const Matrix4& mat) {
			// set reflection matrix
			Matrix4 reflectionMatrix;
			reflectionMatrix.set(0, 0, -1);
			// apply by multiplication
			return reflectionMatrix * mat;
		}

		Matrix4 scale(const Matrix4& mat, const Vector3 magnitude) {
			// set scale matrix
			Matrix4 scaleMatrix;
			scaleMatrix.set(0, 0, magnitude.x);
			scaleMatrix.set(1, 1, magnitude.y);
			scaleMatrix.set(2, 2, magnitude.z);
			// apply by multiplication
			return scaleMatrix * mat;
		}

		// Returns a LookAt matrix.
		Matrix4 lookAt(const Vector3 &position, const Vector3 &target, const Vector3 &up) {
			// calculate the (reverse) direction vector
			Vector3 direction = (position - target).normalized();
			// calculate the basis vector that points to the right
			Vector3 cameraRight = (up.normalized()).cross(direction).normalized();
			// calculate the up basis vector
			Vector3 cameraUp = direction.cross(cameraRight);
			// calculate matrices
			Matrix4 rotational(std::vector<float> {
				cameraRight.x, cameraRight.y, cameraRight.z, 0.0f,
				cameraUp.x, cameraUp.y, cameraUp.z, 0.0f,
				direction.x, direction.y, direction.z, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			});
			Matrix4 positional(std::vector<float> {
				1.0f, 0.0f, 0.0f, -position.x,
				0.0f, 1.0f, 0.0f, -position.y,
				0.0f, 0.0f, 1.0f, -position.z,
				0.0f, 0.0f, 0.0f, 1.0f
			});

			return rotational * positional;
		}

		// Returns a perspective projection matrix with the specified parameters.
		Matrix4 perspective(float fov, float aspect, float near, float far) {
			// OpenGL projection matrix:
			float top = near * tan(Util::degToRad(fov) / 2.f);
			float bottom = -top;
			float right = top * aspect;
			float left = -right;
			Matrix4 proj;
			proj.set(0, 0, 2 * near / (right - left)); // scale the x coordinates
			proj.set(0, 2, (right + left) / (right - left));
			proj.set(1, 1, 2 * near / (top - bottom)); // scale the y coordinates
			proj.set(2, 2, -(far + near) / (far - near)); // used to remap z to [0, 1]
			proj.set(3, 3, 0.f);
			proj.set(2, 3, -2 * far * near / (far - near)); // used to remap z to [0, 1]
			proj.set(3, 2, -1.f); // used to remap z to [0, 1]
			return proj;
		}

		// Returns an orthgraphic projection matrix with the specified parameters.
		Matrix4 orthographic(float top, float right, float near, float far) {
			// OpenGL projection matrix;
			float left = -right;
			float bottom = -top;
			Matrix4 ortho;
			ortho.set(0, 0, 2.f / (right - left));
			ortho.set(1, 1, 2.f / (top - bottom));
			ortho.set(2, 2, -2.f / (far - near));
			ortho.set(0, 3, -(right + left) / (right - left));
			ortho.set(1, 3, -(top + bottom) / (top - bottom));
			ortho.set(2, 3, -(far + near) / (far - near));
			return ortho;
		}

		// Calculate barycentric coordinates (u, v, w) for point p with respect to triangle (a, b, c).
		Vector3 barycentric2d(const Vector3 &p, const Vector3 &a, const Vector3 &b, const Vector3 &c) {
			Vector3 v0 = b - a, v1 = c - a, v2 = p - a;
			// disregard z-coordinates
			v0.z = 0.f; v1.z = 0.f; v2.z = 0.f;
			// Cramer's method
			float d00 = v0.dot(v0);
			float d01 = v0.dot(v1);
			float d11 = v1.dot(v1);
			float d20 = v2.dot(v0);
			float d21 = v2.dot(v1);
			float denom = d00 * d11 - d01 * d01;
			float v = (d11 * d20 - d01 * d21) / denom;
			float w = (d00 * d21 - d01 * d20) / denom;
			float u = 1.0f - v - w;
			if (float::IsNaN(v) || float::IsNaN(u) || float::IsNaN(w)) {
				// deformed triangle
				throw new std::invalid_argument("Triangle is deformed: cannot computer barycentric coordinates");
			}
			return Vector3(u, v, w);
		}

		// Returns true if a point p in located inside a triangle (a, b, c) in 2d space.
		bool isInTriangle(const Vector3 &p, const Vector3 &a, const Vector3 &b, const Vector3 &c) {
			Vector3 barycentrics = barycentric2d(p, a, b, c);
			return barycentrics.x >= 0 && barycentrics.y >= 0 && barycentrics.z >= 0;
		}

		// Calculates a normal vector to a given triangle.
		Vector3 normal(const Vector3 &a, const Vector3 &b, const Vector3 &c) {
			Vector3 t1 = b - a;
			Vector3 t2 = c - a;
			return t1.cross(t2).normalized();
		}

		// Parses a string containing of three floating-point numbers and returns a resulting Vector3.
		Vector3 parseVec3(System::String^ str) {
			array<wchar_t, 1>^ delim = { ' ' };
			array<System::String^>^ strs = str->Split(delim);
			std::vector<float> nums;
			for (int i = 0; i < strs->Length; i++) {
				if (!System::String::IsNullOrWhiteSpace(strs[i])) {
					// culture info is provided for parsing dots correctly ("1.0")
					nums.push_back(float::Parse(strs[i], System::Globalization::CultureInfo::InvariantCulture));
				}
			}
			if (nums.size() != 3) {
				throw std::invalid_argument("Invalid string format (must be 3 numbers).");
			}
			return Vector3(nums);
		}

		bool compareFloat(float a, float b, float eps) {
			return abs(a - b) < eps;
		}

		// Returns a Color object with the RGBA values from the col vector.
		System::Drawing::Color vecToColor(const Vector4 &col) {
			return System::Drawing::Color::FromArgb(col.w * 255, col.x * 255, col.y * 255, col.z * 255);
		}

		// Returns a Vector4 object with the RGBA values from the Color object
		Vector4 colorToVec(System::Drawing::Color ^col) {
			return Vector4(col->R / 255.f, col->G / 255.f, col->B / 255.f, col->A / 255.f);
		}

		Vector3 reflect(const Vector3 & inc, const Vector3 & norm) {
			return inc - norm * (2.f * norm.dot(inc));
		}

		// Returns an area of the given triangle.
		float area(const GL::Polygon & poly) {
			float left = (poly.vertices[1].x - poly.vertices[0].x) * (poly.vertices[2].y - poly.vertices[0].y);
			float right = (poly.vertices[2].x - poly.vertices[0].x) * (poly.vertices[1].y - poly.vertices[0].y);
			return abs(0.5f * (left - right));
		}

		// Clamps a number between min and max values.
		float clamp(float num, float min, float max) {
			if (num > max) return max;
			else if (num < min) return min;
			else return num;
		}

		// returns a signum of x
		int sign(int x) {
			return (x > 0) - (x < 0);
		}

		float max(float a, float b) { return a > b ? a : b; }

		float min(float a, float b) { return a < b ? a : b; }

		// Returns a vector that has all coordinates in (min, max)
		Vector3 clampVec(Vector3 vec, float min, float max) {
			if (vec.x < min) vec.x = min;
			if (vec.y < min) vec.y = min;
			if (vec.z < min) vec.z = min;

			if (vec.x > max) vec.x = max;
			if (vec.y > max) vec.y = max;
			if (vec.z > max) vec.z = max;

			return vec;
		}

		// Returns a vector that has all coordinates in (min, max)
		Vector4 clampVec(Vector4 vec, float min, float max) {
			if (vec.x < min) vec.x = min;
			if (vec.y < min) vec.y = min;
			if (vec.z < min) vec.z = min;
			if (vec.w < min) vec.w = min;

			if (vec.x > max) vec.x = max;
			if (vec.y > max) vec.y = max;
			if (vec.z > max) vec.z = max;
			if (vec.w > max) vec.w = max;

			return vec;
		}
	}
}
