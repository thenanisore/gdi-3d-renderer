#include "Polygon.h"

namespace GL {

	Polygon::Polygon(const std::vector<Vector3> &_vertices) {
		for (const Vector3 &vert : _vertices) {
			vertices.push_back(Vector4(vert, 1.0f));
		};
	}

	Polygon::Polygon(const std::vector<Vector4> &_vertices) : vertices(_vertices) { }

	void Polygon::transform(const Matrix4 &mat) {
		for (int i = 0; i < vertices.size(); i++) {
			vertices[i] = mat * vertices[i];
		}
	}
}