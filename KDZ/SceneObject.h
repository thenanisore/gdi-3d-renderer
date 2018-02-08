#pragma once

#include "Polygon.h"

#include <vector>
#include <cmath>

namespace GL {

	// The SceneObject class represents a 3D object on the scene, made up of polygons.
	class SceneObject
	{
	public:
		SceneObject(std::vector<Polygon> _polygons);

		// Adds a polygon to the SceneObject's mesh.
		void addPolygon(Polygon pol);

		Vector3 getPosition();
		Vector3 getScale();
		Vector3 getRotation();
		void setPosition(const Vector3 &newPosition);
		void setScale(const Vector3 &newScale);
		void setRotation(const Vector3 &newRotation);
		void setReflection(bool xy, bool xz, bool yz);
		void setPolygonColor(const std::vector<Vector4> cols);
		Matrix4 getModelMatrix();
		void reset();

		std::vector<Polygon> polygons;

	private:
		// Object's coordinates (in the world space).
		Vector3 position;
		// Scale multiplier (in the world space).
		Vector3 scale;
		// Rotation angles (in the world space).
		Vector3 rotation;

		// reflection flags:
		bool reflectionXY;
		bool reflectionXZ;
		bool reflectionYZ;
	};
}
