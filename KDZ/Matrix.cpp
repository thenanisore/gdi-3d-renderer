#include "Matrix.h"
#include "Matrix3.h"
#include "Matrix4.h"

namespace GL {

	// The Matrix.h file contains utility functions for matrix transformations.
	namespace Util {

		// Converts degrees to radians.
		float degreesToRadians(float degrees) {
			return degrees * PI / 180.0f;
		}

		// Moves the object by the given movement vector.
		Matrix4 translate(const Matrix4& mat, const Vector3 &move) {
			// set translation matrix
			Matrix4 translationMatrix;
			translationMatrix.set(0, 3, move.x);
			translationMatrix.set(1, 3, move.y);
			translationMatrix.set(2, 3, move.z);
			// apply by multiplication
			return translationMatrix * mat;
		}

		Matrix4 rotateX(const Matrix4& mat, float degrees) {
			// set rotation matrix
			float angle = degreesToRadians(degrees);
			Matrix4 rotationMatrix;
			rotationMatrix.set(1, 1, cos(angle));
			rotationMatrix.set(1, 2, -sin(angle));
			rotationMatrix.set(2, 1, sin(angle));
			rotationMatrix.set(2, 2, cos(angle));
			// apply by multiplication
			return rotationMatrix * mat;
		}

		Matrix4 rotateY(const Matrix4& mat, float degrees) {
			// set rotation matrix
			float angle = degreesToRadians(degrees);
			Matrix4 rotationMatrix;
			rotationMatrix.set(0, 0, cos(angle));
			rotationMatrix.set(0, 2, sin(angle));
			rotationMatrix.set(2, 0, -sin(angle));
			rotationMatrix.set(2, 2, cos(angle));
			// apply by multiplication
			return rotationMatrix * mat;
		}

		Matrix4 rotateZ(const Matrix4& mat, float degrees) {
			// set rotation matrix
			float angle = degreesToRadians(degrees);
			Matrix4 rotationMatrix;
			rotationMatrix.set(0, 0, cos(angle));
			rotationMatrix.set(0, 1, -sin(angle));
			rotationMatrix.set(1, 0, sin(angle));
			rotationMatrix.set(1, 1, cos(angle));
			// apply by multiplication
			return rotationMatrix * mat;
		}

		// Reflects the object across the XY plane.
		Matrix4 reflectXY(const Matrix4& mat) {
			// set reflection matrix
			Matrix4 reflectionMatrix;
			reflectionMatrix.set(2, 2, -1);
			// apply by multiplication
			return reflectionMatrix * mat;
		}

		// Reflects the object across the XZ plane.
		Matrix4 reflectXZ(const Matrix4& mat) {
			// set reflection matrix
			Matrix4 reflectionMatrix;
			reflectionMatrix.set(1, 1, -1);
			// apply by multiplication
			return reflectionMatrix * mat;
		}

		// Reflects the object across the YZ plane.
		Matrix4 reflectYZ(const Matrix4& mat) {
			// set reflection matrix
			Matrix4 reflectionMatrix;
			reflectionMatrix.set(0, 0, -1);
			// apply by multiplication
			return reflectionMatrix * mat;
		}

		Matrix4 scale(const Matrix4& mat, const Vector3 magnitude) {
			// set scale matrix
			Matrix4 scaleMatrix;
			scaleMatrix.set(0, 0, magnitude.x);
			scaleMatrix.set(1, 1, magnitude.y);
			scaleMatrix.set(2, 2, magnitude.z);
			// apply by multiplication
			return scaleMatrix * mat;
		}

		// Returns a LookAt matrix.
		Matrix4 lookAt(const Vector3 &position, const Vector3 &target, const Vector3 &up) {
			// calculate the (reverse) direction vector
			Vector3 direction = (position - target).normalized();
			// calculate the basis vector that points to the right
			Vector3 cameraRight = (up.normalized()).cross(direction).normalized();
			// calculate the up basis vector
			Vector3 cameraUp = direction.cross(cameraRight);
			// calculate matrices
			Matrix4 rotational(std::vector<float> {
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

			return rotational * positional;
		}

		// Returns a perspective projection matrix with the specified parameters.
		Matrix4 perspective(float fov, float aspect, float near, float far) {
			// TODO: perspective matrix
			float scale = atan(Util::degreesToRadians(fov) / 2.0f);
			Matrix4 proj;
			proj.set(0, 0, scale / aspect); // scale the x coordinates
			proj.set(1, 1, scale); // scale the y coordinates
			proj.set(2, 2, (far + near) / (far - near)); // used to remap z to [0, 1]
			proj.set(3, 2, -2 * far * near / (far - near)); // used to remap z to [0, 1]
			proj.set(2, 3, 1.0f);
			proj.set(3, 3, 0.0f);
			return proj;
		}

		// Returns an orthgraphic projection matrix with the specified parameters.
		Matrix4 orthographic(float left, float right, float top, float bottom, float near, float far) {
			Matrix4 ortho;
			ortho.set(0, 0, 2.0f / (right - left));
			ortho.set(1, 1, 2.0f / (top - bottom));
			ortho.set(2, 2, -2.0f / (far - near));
			ortho.set(0, 3, -(right + left) / (right - left));
			ortho.set(1, 3, -(top + bottom) / (top - bottom));
			ortho.set(2, 3, -(far + near) / (far - near));
			return ortho;
		}
	}
}
