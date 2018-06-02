/*
* Copyright © 2018 Oleg Ivanov
* Licensed under the MIT license.
*/

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
		// Initializes a scene camera with given position, and up vectors.
		Camera(Vector3 _position = Vector3(0.0f, 0.0f, 10.0f), Vector3 _worldUp = Vector3(0.0f, 1.0f, 0.0f), Vector3 _rotation = Vector3(0.0f, 180.0f, 0.0f));

		// Returns a LookAt matrix based on the Camera's current parameters.
		Matrix4 getViewMatrix();
		// Sets the camera's position.
		void setPosition(const Vector3 &newPosition);
		// Sets the camera's rotation.
		void setRotation(const Vector3 &newRotation);
		Vector3 getPosition() const;
		Vector3 getRotation() const;
		// Sets the default position (0, 0, 10), target (0, 0, 0) and up (0, 1, 0) vectors.
		void reset();

	private:
		// Camera attributes
		Vector3 position;
		Vector3 front;
		Vector3 up;
		Vector3 right;
		Vector3 worldUp;
		Vector3 rotation;
		void updateVectors();
	};
}
