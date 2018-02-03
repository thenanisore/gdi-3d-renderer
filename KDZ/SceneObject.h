#pragma once

#include "Polygon.h"

#include <vector>

// The SceneObject class represents a 3D object on the scene, made up of polygons.
class SceneObject
{
public:
	SceneObject(std::vector<Polygon> _polygons);

	// Matrix transformations (in local coordinates).

	void translate(float angle);
	void rotate(float angle);
	void scale(float angle);

	std::vector<Polygon> polygons;
};

SceneObject::SceneObject(std::vector<Polygon> _polygons) : polygons(_polygons) { }
