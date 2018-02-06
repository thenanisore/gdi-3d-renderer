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
	}
}
