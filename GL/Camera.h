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
}
