#pragma once

#include "Vector3.h"

#include <vector>

namespace GL {

	// The Matrix3 class represents a 3-dimensional matrix. The indices start at zero.
	class Matrix3
	{
	public:
		// Initializes an identity matrix.
		Matrix3();
		// Initializes a matrix with the values given in a list.
		Matrix3(const std::vector<float> _values);
		// Copy constructor
		Matrix3(const Matrix3 &mat);

		const int dim = 3;

		Matrix3 operator*(float s) const;
		Matrix3 operator*(const Matrix3 &mat) const;
		Vector3 operator*(const Vector3 &vec) const;
		Matrix3 operator+(const Matrix3 &mat) const;
		Matrix3 operator-(const Matrix3 &mat) const;

		float get(int row, int col) const;
		void set(int row, int col, float val);
		Vector3 getRow(int row) const;
		Vector3 getColumn(int col) const;
		Matrix3 transposed() const;

	private:
		std::vector<float> values;
	};
}
