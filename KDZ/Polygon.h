#pragma once

#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"

#include <vector>

namespace GL {

	// The Polygon class represents a triangular polygon with 3-dimensional vertices represented as Vector3.
	class Polygon
	{
	public:
		Polygon(const Vector3 &first, const Vector3 &second, const Vector3 &third);
		Polygon(const Vector4 &first, const Vector4 &second, const Vector4 &third);

		void setColors(const Vector4 &first, const Vector4 &second, const Vector4 &third);
		void calculateNormals();
		// Returns a Polygon with the given transformation applied.
		Polygon transform(const Matrix4 &mat);

		std::vector<Vector4> vertices;
		std::vector<Vector4> colors;
		std::vector<Vector3> normals;
	};
}