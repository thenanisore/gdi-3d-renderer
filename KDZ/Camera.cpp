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

	// Sets the default position (0, 0, 1), front (0, 0, -1) and up (0, 1, 0) vectors.
	void Camera::reset() {
		position = Vector3(0.0f, 0.0f, 1.0f);
		front = Vector3(0.0f, 0.0f, -1.0f);
		up = Vector3(0.0f, 1.0f, 0.0f);
		updateVectors();
	}

	void Camera::updateVectors() {
		// calculate the front vector
		Vector3 _front;
		_front.x = cos(Util::degreesToRadians(rotation.y)) * cos(Util::degreesToRadians(rotation.x));
		_front.y = sin(Util::degreesToRadians(rotation.x));
		_front.z = sin(Util::degreesToRadians(rotation.y)) * cos(Util::degreesToRadians(rotation.x));
		front = _front.normalized();
		// re-calculate the right and up vectors
		right = front.cross(worldUp).normalized();
		up = right.cross(front).normalized();
	}
}