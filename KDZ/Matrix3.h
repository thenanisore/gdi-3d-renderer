#pragma once

#include "Vector3.h"

#include <vector>

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
	Vector3 getRow(int row) const;
	Vector3 getColumn(int col) const;
	Matrix3 transposed() const;

private:
	std::vector<float> values;
};

Matrix3::Matrix3() {
	values = { 1, 0, 0,
			   0, 1, 0,
			   0, 0, 1 };
}

Matrix3::Matrix3(const std::vector<float> _values) : values(_values) { }

Matrix3::Matrix3(const Matrix3 &mat) : values(mat.values) { }

Matrix3 Matrix3::operator*(float s) const {
	std::vector<float> newValues(values);
	for (int i = 0; i < newValues.size(); i++) {
		newValues[i] *= s;
	}
	return Matrix3(newValues);
}

Matrix3 Matrix3::operator*(const Matrix3 &mat) const {
	std::vector<float> newValues(values);
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			newValues[i * dim + j] = getRow(i).dot(mat.getColumn(j));
		}
	}
	return Matrix3(newValues);
}

Vector3 Matrix3::operator*(const Vector3 &vec) const {
	std::vector<float> newVector;
	for (int i = 0; i < dim; i++) {
		newVector.push_back(getRow(i).dot(vec));
	}
	return Vector3(newVector);
}

Matrix3 Matrix3::operator+(const Matrix3 &mat) const {
	std::vector<float> newValues(values);
	for (int i = 0; i < newValues.size(); i++) {
		newValues[i] += mat.get(i / dim, i % dim);
	}
	return Matrix3(newValues);
}

Matrix3 Matrix3::operator-(const Matrix3 &mat) const {
	std::vector<float> newValues(values);
	for (int i = 0; i < newValues.size(); i++) {
		newValues[i] -= mat.get(i / dim, i % dim);
	}
	return Matrix3(newValues);
}

float Matrix3::get(int row, int col) const {
	if (row < 0 || row > dim || col < 0 || col > dim)
		throw std::invalid_argument("Coordinates are invalid");
	return values[row * dim + col];
}

Vector3 Matrix3::getRow(int row) const {
	if (row < 0 || row > dim)
		throw std::invalid_argument("Row number is invalid");
	return Vector3(get(row, 0), get(row, 1), get(row, 2));
}

Vector3 Matrix3::getColumn(int col) const {
	if (col < 0 || col > dim)
		throw std::invalid_argument("Col number is invalid");
	return Vector3(get(0, col), get(1, col), get(2, col));
}

Matrix3 Matrix3::transposed() const {
	std::vector<float> newValues(values);
	for (int i = 0; i < newValues.size(); i++) {
		newValues[i] = get(i % dim, i / dim);
	}
	return Matrix3(newValues);
}
