#pragma once
#define PI 3.141592653589793238462643383279502884L

#include "Polygon.h"

#include <vector>
#include <cmath>

namespace GL {

	// The SceneObject class represents a 3D object on the scene, made up of polygons.
	class SceneObject
	{
	public:
		SceneObject(std::vector<Polygon> _polygons);

		// matrix transformations (in local coordinates):

		// Moves the object by the given movement vector.
		void translate(const Vector3 &move);
		// Rotates the object around the X-axis by a certain angle. 
		void rotateX(float angle);
		// Rotates the object around the Y-axis by a certain angle. 
		void rotateY(float angle);
		// Rotates the object around the Z-axis by a certain angle. 
		void rotateZ(float angle);
		// Reflects the object across the XY plane.
		void reflectXY();
		// Reflects the object across the XZ plane.
		void reflectXZ();
		// Reflects the object across the YZ plane.
		void reflectYZ();
		// Scales the object by the given magnitude vector.
		void scale(const Vector3 magnitude);
		// Applies a given Matrix4 to all the SceneObject's polygons.
		void transformPolygons(const Matrix4 &tr);
		// Adds a polygon to the SceneObject's mesh.
		void addPolygon(Polygon pol);

		std::vector<Polygon> polygons;

	private:
		inline float degreesToRadians(float degrees);
	};
}
