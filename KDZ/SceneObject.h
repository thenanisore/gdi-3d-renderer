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

		std::vector<Polygon> polygons;

	private:
		inline float degreesToRadians(float degrees);
	};

	SceneObject::SceneObject(std::vector<Polygon> _polygons) : polygons(_polygons) { }

	void SceneObject::translate(const Vector3 &move) {
		// set translation matrix
		Matrix4 translationMatrix;
		translationMatrix.set(0, 3, move.x);
		translationMatrix.set(1, 3, move.y);
		translationMatrix.set(2, 3, move.z);
		// apply
		transformPolygons(translationMatrix);
	}

	void SceneObject::rotateX(float degrees) {
		// set rotation matrix
		float angle = degreesToRadians(degrees);
		Matrix4 rotationMatrix;
		rotationMatrix.set(1, 1, cos(angle));
		rotationMatrix.set(1, 2, -sin(angle));
		rotationMatrix.set(2, 1, sin(angle));
		rotationMatrix.set(2, 2, cos(angle));
		// apply
		transformPolygons(rotationMatrix);
	}

	void SceneObject::rotateY(float degrees) {
		// set rotation matrix
		float angle = degreesToRadians(degrees);
		Matrix4 rotationMatrix;
		rotationMatrix.set(0, 0, cos(angle));
		rotationMatrix.set(0, 2, sin(angle));
		rotationMatrix.set(2, 0, -sin(angle));
		rotationMatrix.set(2, 2, cos(angle));
		// apply
		transformPolygons(rotationMatrix);
	}

	void SceneObject::rotateZ(float degrees) {
		// set rotation matrix
		float angle = degreesToRadians(degrees);
		Matrix4 rotationMatrix;
		rotationMatrix.set(0, 0, cos(angle));
		rotationMatrix.set(0, 1, -sin(angle));
		rotationMatrix.set(1, 0, sin(angle));
		rotationMatrix.set(1, 1, cos(angle));
		// apply
		transformPolygons(rotationMatrix);
	}

	// Reflects the object across the XY plane.
	void SceneObject::reflectXY() {
		// set reflection matrix
		Matrix4 reflectionMatrix;
		reflectionMatrix.set(2, 2, -1);
		// apply
		transformPolygons(reflectionMatrix);
	}

	// Reflects the object across the XZ plane.
	void SceneObject::reflectXZ() {
		// set reflection matrix
		Matrix4 reflectionMatrix;
		reflectionMatrix.set(1, 1, -1);
		// apply
		transformPolygons(reflectionMatrix);
	}

	// Reflects the object across the YZ plane.
	void SceneObject::reflectYZ() {
		// set reflection matrix
		Matrix4 reflectionMatrix;
		reflectionMatrix.set(0, 0, -1);
		// apply
		transformPolygons(reflectionMatrix);
	}

	void SceneObject::scale(const Vector3 magnitude) {
		// set scale matrix
		Matrix4 scaleMatrix;
		scaleMatrix.set(0, 0, magnitude.x);
		scaleMatrix.set(1, 1, magnitude.y);
		scaleMatrix.set(2, 2, magnitude.z);
		// apply
		transformPolygons(scaleMatrix);
	}

	// Applies a transformation to every SceneObject's polygon.
	void SceneObject::transformPolygons(const Matrix4 &tr) {
		for (int i = 0; i < polygons.size(); i++) {
			polygons[i].transform(tr);
		}
	}

	inline float SceneObject::degreesToRadians(float degrees) {
		return degrees * PI / 180.0f;
	}
}
