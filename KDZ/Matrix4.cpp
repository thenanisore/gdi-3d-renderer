#include "Matrix4.h"

namespace GL {

	Matrix4::Matrix4() {
		values = { 1, 0, 0, 0,
				   0, 1, 0, 0,
				   0, 0, 1, 0,
				   0, 0, 0, 1 };
	}

	Matrix4::Matrix4(const std::vector<float> _values) : values(_values) { }

	Matrix4::Matrix4(const Matrix4 &mat) : values(mat.values) { }

	Matrix4& Matrix4::operator=(const Matrix4 &mat) {
		values = mat.values;
		return *this;
	}

	Matrix4 Matrix4::operator*(float s) const {
		std::vector<float> newValues(values);
		for (int i = 0; i < newValues.size(); i++) {
			newValues[i] *= s;
		}
		return Matrix4(newValues);
	}

	Matrix4 Matrix4::operator*(const Matrix4 &mat) const {
		std::vector<float> newValues(values);
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				newValues[i * dim + j] = getRow(i).dot(mat.getColumn(j));
			}
		}
		return Matrix4(newValues);
	}

	Vector4 Matrix4::operator*(const Vector4 &vec) const {
		std::vector<float> newVector;
		for (int i = 0; i < dim; i++) {
			newVector.push_back(getRow(i).dot(vec));
		}
		return Vector4(newVector);
	}

	Matrix4 Matrix4::operator+(const Matrix4 &mat) const {
		std::vector<float> newValues(values);
		for (int i = 0; i < newValues.size(); i++) {
			newValues[i] += mat.get(i / dim, i % dim);
		}
		return Matrix4(newValues);
	}

	Matrix4 Matrix4::operator-(const Matrix4 &mat) const {
		std::vector<float> newValues(values);
		for (int i = 0; i < newValues.size(); i++) {
			newValues[i] -= mat.get(i / dim, i % dim);
		}
		return Matrix4(newValues);
	}

	float Matrix4::get(int row, int col) const {
		if (row < 0 || row > dim || col < 0 || col > dim)
			throw std::invalid_argument("Coordinates are invalid");
		return values[row * dim + col];
	}

	void Matrix4::set(int row, int col, float val) {
		if (row < 0 || row > dim || col < 0 || col > dim)
			throw std::invalid_argument("Coordinates are invalid");
		values[row * dim + col] = val;
	}

	Vector4 Matrix4::getRow(int row) const {
		if (row < 0 || row > dim)
			throw std::invalid_argument("Row number is invalid");
		return Vector4(get(row, 0), get(row, 1), get(row, 2), get(row, 3));
	}

	Vector4 Matrix4::getColumn(int col) const {
		if (col < 0 || col > dim)
			throw std::invalid_argument("Col number is invalid");
		return Vector4(get(0, col), get(1, col), get(2, col), get(3, col));
	}

	Matrix4 Matrix4::transposed() const {
		std::vector<float> newValues(values);
		for (int i = 0; i < newValues.size(); i++) {
			newValues[i] = get(i % dim, i / dim);
		}
		return Matrix4(newValues);
	}
}