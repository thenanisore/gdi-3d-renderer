#pragma once

#include "Vector4.h"
#include "Matrix3.h"

#include <vector>

namespace GL {

	// The Matrix4 class represents a 4-dimensional matrix. The indices start at zero.
	class Matrix4
	{
	public:
		// Initializes an identity matrix.
		Matrix4();
		// Initializes a matrix with the values given in a list.
		Matrix4(const std::vector<float> _values);
		// Copy constructor
		Matrix4(const Matrix4 &mat);

		const int dim = 4;

		// Copy assignment operator.
		Matrix4& operator=(const Matrix4 &mat);
		Matrix4 operator*(float s) const;
		Matrix4 operator*(const Matrix4 &mat) const;
		Vector4 operator*(const Vector4 &vec) const;
		Matrix4 operator+(const Matrix4 &mat) const;
		Matrix4 operator-(const Matrix4 &mat) const;

		float get(int row, int col) const;
		void set(int row, int col, float val);
		Vector4 getRow(int row) const;
		Vector4 getColumn(int col) const;
		Matrix4 transposed() const;
		float determinant() const;
		Matrix3 toMat3() const;
		Matrix4 inverted() const;

	private:
		float minor(int row, int col) const;
		std::vector<float> values;
	};
}
