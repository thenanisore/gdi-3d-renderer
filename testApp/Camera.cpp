#include "stdafx.h"
#include "Matrix.h"
#include "Camera.h"

namespace GL {

	Camera::Camera(Vector3 _position, Vector3 _worldUp, Vector3 _rotation) : front(Vector3(0.0f, 0.0f, -1.0f)) {
		position = _position;
		worldUp = _worldUp;
		rotation = _rotation;
		updateVectors();
	}

	Matrix4 Camera::getViewMatrix() {
		return Util::lookAt(position, position + front, up);
	}

	// Sets the camera's position.
	void Camera::setPosition(const Vector3 &newPosition) {
		position = newPosition;
	}

	// Sets the camera's rotation.
	void Camera::setRotation(const Vector3 &newRotation) {
		rotation = newRotation;
		updateVectors();
	}

	// Sets the default position (0, 0, 3), front (0, 0, -1) and up (0, 1, 0) vectors.
	void Camera::reset() {
		position = Vector3(0.0f, 0.0f, 10.0f);
		front = Vector3(0.0f, 0.0f, -1.0f);
		worldUp = Vector3(0.0f, 1.0f, 0.0f);
		rotation = Vector3();
		updateVectors();
	}

	void Camera::updateVectors() {
		// calculate the front vector
		Vector3 _front;
		double pitch = Util::degreesToRadians(rotation.x);
		double yaw = Util::degreesToRadians(rotation.y);
		_front.x = sin(yaw) * cos(pitch);
		_front.y = sin(pitch);
		_front.z = cos(yaw) * cos(pitch);
		front = _front.normalized();
		// re-calculate the right and up vectors
		right = front.cross(worldUp).normalized();
		up = right.cross(front).normalized();
	}
}