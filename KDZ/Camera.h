#pragma once

#include "Vector3.h"
#include "Matrix4.h"

namespace GL {

	// The Camera class represents a camera on the scene,
	// which holds the information about camera's position,
	// direction and projection type.
	class Camera
	{
	public:
		// Initializes a scene camera with the default position (0, 0, -1), target (0, 0, 0) and up (0, 1, 0) vectors.
		Camera();
		// Initializes a scene camera with given position, target and up vectors.
		// The up vector is used for calculating all the basis vectors of the view space.
		Camera(Vector3 _position, Vector3 _target, Vector3 _up);

		// Returns a LookAt matrix based on the Camera's current parameters.
		Matrix4 getLookAt();
		// Returns a perspective projection matrix with the specified parameters.
		Matrix4 perspective(float fov, float aspect, float near, float far);
		// Returns an orthgraphic projection matrix with the specified parameters.
		Matrix4 orthographic();
		// Sets the camera's position.
		void setPosition(const Vector3 &newPosition);
		// TODO: rotation
		void setRotation(const Vector3 &newRotation);
		// Sets the default position (0, 0, -1), target (0, 0, 0) and up (0, 1, 0) vectors.
		void reset();

	private:
		Vector3 up;
		Vector3 target;
		Vector3 position;
		Vector3 direction;
		Vector3 cameraRight;
		Vector3 cameraUp;
		void recalculateBasis();
	};
}
