/*
* Студент: Иванов Олег Владимирович
* Группа: 141/1, 4 курс
* КДЗ #1, Вариант 1: 3D-сцена в GDI.
*
* Класс Matrix3: матрица 3x3, матричные операции.
*/

#include "Matrix3.h"

namespace GL {

	Matrix3::Matrix3() {
		values = { 1, 0, 0,
				   0, 1, 0,
				   0, 0, 1 };
	}

	Matrix3::Matrix3(const std::vector<float> _values) : values(_values) { }

	Matrix3::Matrix3(const Matrix3 &mat) : values(mat.values) { }

	Matrix3& Matrix3::operator=(const Matrix3 &mat) {
		values = mat.values;
		return *this;
	}

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

	void Matrix3::set(int row, int col, float val) {
		if (row < 0 || row > dim || col < 0 || col > dim)
			throw std::invalid_argument("Coordinates are invalid");
		values[row * dim + col] = val;
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

	float Matrix3::determinant() const {
		float minor1 = get(1, 1) * get(2, 2) - get(1, 2) * get(2, 1);
		float minor2 = get(1, 0) * get(2, 2) - get(1, 2) * get(2, 0);
		float minor3 = get(1, 0) * get(2, 1) - get(1, 1) * get(2, 0);
		return get(0, 0) * minor1 - get(0, 1) * minor2 + get(0, 2) * minor3;
	}

	Matrix3 Matrix3::transposed() const {
		std::vector<float> newValues(values);
		for (int i = 0; i < newValues.size(); i++) {
			newValues[i] = get(i % dim, i / dim);
		}
		return Matrix3(newValues);
	}
}