#include "Matrix.h"
#include "Camera.h"

namespace GL {

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

	Matrix4 Camera::perspective(float fov, float aspect, float near, float far) {
		// TODO: perspective matrix
		float scale = 1.0f / tan(Util::degreesToRadians(fov) / 2.0f);
		Matrix4 proj;
		proj.set(0, 0, scale); // scale the x coordinates
		proj.set(1, 1, scale); // scale the y coordinates
		proj.set(2, 2, -far / (far - near)); // used to remap z to [0, 1]
		proj.set(2, 3, -far * near / (far - near));
		proj.set(3, 2, -1.0f); // w := -z
		proj.set(3, 3, 0.0f);
		return proj;
	}

	Matrix4 Camera::orthographic() {
		// TODO: orthographic matrix
		return Matrix4();
	}
}