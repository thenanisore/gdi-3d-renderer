#pragma once

#include "Vector3.h"
#include "Matrix4.h"

// The Camera class represents a camera on the scene,
// which holds the information about camera's position,
// direction and projection type.
class Camera
{
public:
	// Initializes a scene camera with given position, target and up vectors.
	// The up vector is used for calculating all the basis vectors of the view space.
	Camera(Vector3 _position, Vector3 _target, Vector3 _up);

	// Returns a LookAt matrix based on the Camera's current parameters.
	Matrix4 getLookAt();
	// Returns a projection matrix with the specified parameters.
	Matrix4 getProjection(float fov, float aspect, float near, float far);
	// Returns an orthgraphic matrix with the specified parameters.
	Matrix4 getOrthographic();

private:
	Vector3 position;
	Vector3 direction;
	Vector3 cameraRight;
	Vector3 cameraUp;
};

Camera::Camera(Vector3 _position, Vector3 _target, Vector3 _up) : position(_position) {
	// calculate the (reverse) direction vector
	direction = (_position - _target).normalized();
	// calculate the basis vector that points to the right
	cameraRight = _up.cross(direction).normalized();
	// calculate the up basis vector
	cameraUp = direction.cross(cameraRight);
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

Matrix4 Camera::getProjection(float fov, float aspect, float near, float far) {
	// TODO: projection matrix
	return Matrix4();
}

Matrix4 Camera::getOrthographic() {
	// TODO: orthographic matrix
	return Matrix4();
}
