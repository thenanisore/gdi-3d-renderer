#include "stdafx.h"
#include "SceneObject.h"

namespace GL {

	SceneObject::SceneObject(std::vector<Polygon> _polygons) : polygons(_polygons) { }

	void SceneObject::translate(const Vector3 &move) {
		// set translation matrix
		Matrix4 translationMatrix;
		translationMatrix.set(0, 3, move.x);
		translationMatrix.set(1, 3, move.y);
		translationMatrix.set(2, 3, move.z);
		// apply
		transform(translationMatrix);
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
		transform(rotationMatrix);
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
		transform(rotationMatrix);
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
		transform(rotationMatrix);
	}

	// Reflects the object across the XY plane.
	void SceneObject::reflectXY() {
		// set reflection matrix
		Matrix4 reflectionMatrix;
		reflectionMatrix.set(2, 2, -1);
		// apply
		transform(reflectionMatrix);
	}

	// Reflects the object across the XZ plane.
	void SceneObject::reflectXZ() {
		// set reflection matrix
		Matrix4 reflectionMatrix;
		reflectionMatrix.set(1, 1, -1);
		// apply
		transform(reflectionMatrix);
	}

	// Reflects the object across the YZ plane.
	void SceneObject::reflectYZ() {
		// set reflection matrix
		Matrix4 reflectionMatrix;
		reflectionMatrix.set(0, 0, -1);
		// apply
		transform(reflectionMatrix);
	}

	void SceneObject::scale(const Vector3 magnitude) {
		// set scale matrix
		Matrix4 scaleMatrix;
		scaleMatrix.set(0, 0, magnitude.x);
		scaleMatrix.set(1, 1, magnitude.y);
		scaleMatrix.set(2, 2, magnitude.z);
		// apply
		transform(scaleMatrix);
	}

	// Applies a transformation to every SceneObject's polygon.
	void SceneObject::transform(const Matrix4 &tr) {
		for (int i = 0; i < polygons.size(); i++) {
			polygons[i].transform(tr);
		}
	}

	void SceneObject::addPolygon(Polygon pol) {
		polygons.push_back(pol);
	}

	inline float SceneObject::degreesToRadians(float degrees) {
		return degrees * PI / 180.0f;
	}
}