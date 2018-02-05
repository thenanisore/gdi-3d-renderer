#pragma once

#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"

#include <vector>

namespace GL {

	// The Polygon class represents a polygon with 3-dimensional vertices represented as Vector3.
	class Polygon
	{
	public:
		Polygon(const std::vector<Vector3> &_vertices);
		Polygon(const std::vector<Vector4> &_vertices);

		// Applies a matrix transformation to the polygon
		void transform(const Matrix4 &mat);

		std::vector<Vector4> vertices;
	};
}