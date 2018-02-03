#pragma once

#include "Vector3.h"

#include <vector>

// The Polygon class represents a polygon with 3-dimensional vertices represented as Vector3.
class Polygon
{
public:
	Polygon(std::vector<Vector3> _vertices);
	std::vector<Vector3> vertices;
};

Polygon::Polygon(std::vector<Vector3> _vertices) : vertices(_vertices) { }
