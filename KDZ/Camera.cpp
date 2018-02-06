#include "Matrix.h"
#include "Camera.h"

namespace GL {

	Camera::Camera() : Camera(Vector3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f)) { }

	Camera::Camera(Vector3 _position, Vector3 _target, Vector3 _up)
		: position(_position), target(_target), up(_up) {
		recalculateBasis();
	}

	Matrix4 Camera::getLookAt() {
		Matrix4 basis(std::vector<float> {
			cameraRight.x, cameraRight.y, cameraRight.z, 0.0f,
			cameraUp.x, cameraUp.y, cameraUp.z, 0.0f,
			direction.x, direction.y, direction.z, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		});
		Matrix4 positional(std::vector<float> {
			1.0f, 0.0f, 0.0f, -position.x,
			0.0f, 1.0f, 0.0f, -position.y,
			0.0f, 0.0f, 1.0f, -position.z,
			0.0f, 0.0f, 0.0f, 1.0f
		});
		return basis * positional;
	}

	Matrix4 Camera::perspective(float fov, float aspect, float near, float far) {
		// TODO: perspective matrix
		float scale = 1.0f / tan(Util::degreesToRadians(fov) / 2.0f);
		Matrix4 proj;
		proj.set(0, 0, scale); // scale the x coordinates
		proj.set(1, 1, scale); // scale the y coordinates
		proj.set(2, 2, -far / (far - near)); // used to remap z to [0, 1]
		proj.set(2, 3, -far * near / (far - near)); // used to remap z to [0, 1]
		proj.set(3, 2, -1.0f); // w := -z
		proj.set(3, 3, 0.0f);
		return proj;
	}

	Matrix4 Camera::orthographic() {
		// TODO: orthographic matrix
		return Matrix4();
	}

	// Sets the camera's position.
	void Camera::setPosition(const Vector3 &newPosition) {
		position = newPosition;
		recalculateBasis();
	}

	// TODO: rotation
	void Camera::setRotation(const Vector3 &newRotation) {
		// TODO
	}

	// Sets the default position (0, 0, -1), target (0, 0, 0) and up (0, 1, 0) vectors.
	void Camera::reset() {
		position = Vector3(0.0f, 0.0f, -1.0f);
		target = Vector3(0.0f, 0.0f, 0.0f);
		up = Vector3(0.0f, 0.0f, 1.0f);
		recalculateBasis();
	}

	void Camera::recalculateBasis() {
		// calculate the (reverse) direction vector
		direction = (position - target).normalized();
		// calculate the basis vector that points to the right
		cameraRight = up.cross(direction).normalized();
		// calculate the up basis vector
		cameraUp = direction.cross(cameraRight);
	}
}