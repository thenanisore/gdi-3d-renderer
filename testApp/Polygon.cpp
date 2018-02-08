#include "stdafx.h"
#include "Polygon.h"

namespace GL {

	Polygon::Polygon(const Vector3 &first, const Vector3 &second, const Vector3 &third) 
		: Polygon(Vector4(first, 1.0f), Vector4(second, 1.0f), Vector4(third, 1.0f)) { }

	Polygon::Polygon(const Vector4 &first, const Vector4 &second, const Vector4 &third) {
		vertices = std::vector<Vector4>{ first, second, third };
		// colors are initially all zero
		colors = std::vector<Vector4> { Vector4(), Vector4(), Vector4() };
		calculateNormals();
	}

	void Polygon::setColors(const Vector4 &first, const Vector4 &second, const Vector4 &third) {
		colors = std::vector<Vector4> { first, second, third };
	}

	void Polygon::calculateNormals() {
		Vector3 a = vertices[0].fromHomogeneous() - vertices[1].fromHomogeneous();
		Vector3 b = vertices[0].fromHomogeneous() - vertices[2].fromHomogeneous();
		Vector3 normal = a.cross(b).normalized();
		normals = std::vector<Vector3> { normal, normal, normal };
	}

	Polygon Polygon::getTransformed(const Matrix4 &mat) {
		Polygon transformed(vertices[0], vertices[1], vertices[2]);
		for (int i = 0; i < vertices.size(); i++) {
			transformed.vertices[i] = mat * vertices[i];
		}
		return transformed;
	}
}