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
	Camera(Vector3 _position, Vector3 _target, Vector3 up);

	// Returns a LookAt matrix based on the Camera's current parameters.
	Matrix4 getLookAt();

private:
	Vector3 position;
	Vector3 direction;
	Vector3 right;
	Vector3 up;
};

Camera::Camera(Vector3 _position, Vector3 _target, Vector3 up): position(_position) {
	// calculate the (reverse) direction vector
	direction = (_position - _target).normalized();
	// calculate the basis vector that points to the right
	Vector3 _up(0, 1, 0);
	right = up.cross(direction).normalized();
	// calculate the up basis vector
	up = direction.cross(right);
}

Matrix4 Camera::getLookAt() {
	Matrix4 basis(std::vector<float> {
		right.x, right.y, right.z, 0.0f,
		up.x, up.y, up.z, 0.0f,
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
