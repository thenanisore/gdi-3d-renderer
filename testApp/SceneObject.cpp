#include "stdafx.h"
#include "SceneObject.h"

namespace GL {

	SceneObject::SceneObject(std::vector<Polygon> _polygons)
		: polygons(_polygons), model() { }

	void SceneObject::translate(const Vector3 &move) {
		// set translation matrix
		Matrix4 translationMatrix;
		translationMatrix.set(0, 3, move.x);
		translationMatrix.set(1, 3, move.y);
		translationMatrix.set(2, 3, move.z);
		// apply to the current Model matrix
		model = translationMatrix * model;
	}

	void SceneObject::rotateX(float degrees) {
		// set rotation matrix
		float angle = degreesToRadians(degrees);
		Matrix4 rotationMatrix;
		rotationMatrix.set(1, 1, cos(angle));
		rotationMatrix.set(1, 2, -sin(angle));
		rotationMatrix.set(2, 1, sin(angle));
		rotationMatrix.set(2, 2, cos(angle));
		// apply to the current Model matrix
		model = rotationMatrix * model;
	}

	void SceneObject::rotateY(float degrees) {
		// set rotation matrix
		float angle = degreesToRadians(degrees);
		Matrix4 rotationMatrix;
		rotationMatrix.set(0, 0, cos(angle));
		rotationMatrix.set(0, 2, sin(angle));
		rotationMatrix.set(2, 0, -sin(angle));
		rotationMatrix.set(2, 2, cos(angle));
		// apply to the current Model matrix
		model = rotationMatrix * model;
	}

	void SceneObject::rotateZ(float degrees) {
		// set rotation matrix
		float angle = degreesToRadians(degrees);
		Matrix4 rotationMatrix;
		rotationMatrix.set(0, 0, cos(angle));
		rotationMatrix.set(0, 1, -sin(angle));
		rotationMatrix.set(1, 0, sin(angle));
		rotationMatrix.set(1, 1, cos(angle));
		// apply to the current Model matrix
		model = rotationMatrix * model;
	}

	// Reflects the object across the XY plane.
	void SceneObject::reflectXY() {
		// set reflection matrix
		Matrix4 reflectionMatrix;
		reflectionMatrix.set(2, 2, -1);
		// apply to the current Model matrix
		model = reflectionMatrix * model;
	}

	// Reflects the object across the XZ plane.
	void SceneObject::reflectXZ() {
		// set reflection matrix
		Matrix4 reflectionMatrix;
		reflectionMatrix.set(1, 1, -1);
		// apply to the current Model matrix
		model = reflectionMatrix * model;
	}

	// Reflects the object across the YZ plane.
	void SceneObject::reflectYZ() {
		// set reflection matrix
		Matrix4 reflectionMatrix;
		reflectionMatrix.set(0, 0, -1);
		// apply to the current Model matrix
		model = reflectionMatrix * model;
	}

	void SceneObject::scale(const Vector3 magnitude) {
		// set scale matrix
		Matrix4 scaleMatrix;
		scaleMatrix.set(0, 0, magnitude.x);
		scaleMatrix.set(1, 1, magnitude.y);
		scaleMatrix.set(2, 2, magnitude.z);
		// apply to the current Model matrix
		model = scaleMatrix * model;
	}

	// Recalculates the coordinates of each polygon by applying the transformations.
	void SceneObject::applyTransform() {
		// recalculate polygons
		for (int i = 0; i < polygons.size(); i++) {
			polygons[i].transform(model);
		}
		// reset the model matrix
		model = Matrix4();
	}

	// Applies a transformation to every SceneObject's polygon.
	void SceneObject::transform(const Matrix4 &tr) {
		model = tr * model;
	}

	void SceneObject::addPolygon(Polygon pol) {
		polygons.push_back(pol);
	}

	inline float SceneObject::degreesToRadians(float degrees) {
		return degrees * PI / 180.0f;
	}
}