#pragma once

#include "Polygon.h"

#include <vector>

// The SceneObject class represents a 3D object on the scene, made up of polygons.
class SceneObject
{
public:
	SceneObject(std::vector<Polygon> _polygons);
	std::vector<Polygon> polygons;
};

SceneObject::SceneObject(std::vector<Polygon> _polygons) : polygons(_polygons) { }
