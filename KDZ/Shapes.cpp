#pragma once

#include "Shapes.h"

namespace GL {

	// The Shapes.h file contains some pre-defined 3-dimensional objects.
	namespace Objects {

		// Returns a cube.
		SceneObject cube() {
			SceneObject c(std::vector<Polygon> {
				// front
				Polygon(Vector3(1, -1, 1), Vector3(1, 1, 1), Vector3(-1, 1, 1)),
				Polygon(Vector3(-1, 1, 1), Vector3(-1, -1, 1), Vector3(1, -1, 1)),
				// right
				Polygon(Vector3(1, -1, 1), Vector3(1, -1, -1), Vector3(1, 1, -1)),
				Polygon(Vector3(1, 1, -1), Vector3(1, 1, 1), Vector3(1, -1, 1)),
				// back
				Polygon(Vector3(1, 1, -1), Vector3(1, -1, -1), Vector3(-1, -1, -1)),
				Polygon(Vector3(-1, -1, -1), Vector3(-1, 1, -1), Vector3(1, 1, -1)),
				// left
				Polygon(Vector3(-1, -1, 1), Vector3(-1, 1, -1), Vector3(-1, -1, -1)),
				Polygon(Vector3(-1, -1, 1), Vector3(-1, 1, 1), Vector3(-1, 1, -1)),
				// top
				Polygon(Vector3(1, 1, 1), Vector3(1, 1, -1), Vector3(-1, 1, -1)),
				Polygon(Vector3(-1, 1, -1), Vector3(-1, 1, 1), Vector3(1, 1, 1)),
				// bottom
				Polygon(Vector3(-1, -1, -1), Vector3(1, -1, -1), Vector3(1, -1, 1)),
				Polygon(Vector3(1, -1, 1), Vector3(-1, -1, 1), Vector3(-1, -1, -1))
			});
			c.setPolygonColors(std::vector<Vector4> {
				// front
				Vector4(1.f, 0.f, 0.f, 1.f), Vector4(1.f, 0.f, 0.f, 1.f),
				// right
				Vector4(0.f, 1.f, 0.f, 1.f), Vector4(0.f, 1.f, 0.f, 1.f),
				// back
				Vector4(0.f, 0.f, 1.f, 1.f), Vector4(0.f, 0.f, 1.f, 1.f),
				// left
				Vector4(1.f, 0.f, 1.f, 1.f), Vector4(1.f, 0.f, 1.f, 1.f),
				// top
				Vector4(1.f, 1.f, 0.f, 1.f), Vector4(1.f, 1.f, 0.f, 1.f),
				// bottom
				Vector4(0.f, 1.f, 1.f, 1.f), Vector4(0.f, 1.f, 1.f, 1.f)
			});
			return c;
		}

		// Returns a pyramid.
		SceneObject pyramid() {
			SceneObject p(std::vector<Polygon> {
				// front
				Polygon(Vector3(1, -1, 1), Vector3(0, 1, 0), Vector3(-1, -1, 1)),
				// right
				Polygon(Vector3(1, -1, -1), Vector3(0, 1, 0), Vector3(1, -1, 1)),
				// back
				Polygon(Vector3(-1, -1, -1), Vector3(0, 1, 0), Vector3(1, -1, -1)),
				// left
				Polygon(Vector3(-1, -1, 1), Vector3(0, 1, 0), Vector3(-1, -1, -1)),
				// bottom
				Polygon(Vector3(-1, -1, -1), Vector3(1, -1, -1), Vector3(1, -1, 1)),
				Polygon(Vector3(1, -1, 1), Vector3(-1, -1, 1), Vector3(-1, -1, -1))
			});
			p.setPolygonColors(std::vector<Vector4> {
				// front
				Vector4(1.f, 0.f, 0.f, 1.f),
				// right
				Vector4(0.f, 1.f, 0.f, 1.f),
				// back
				Vector4(0.f, 0.f, 1.f, 1.f),
				// left
				Vector4(1.f, 0.f, 1.f, 1.f),
				// bottom
				Vector4(1.f, 1.f, 1.f, 1.f), Vector4(1.f, 1.f, 1.f, 1.f)
			});
			return p;
		}

		// Generates a octahedron.
		SceneObject octahedron() {
			// TODO: octahedron
			return cube();
		}

		// Generates a octaedron.
		SceneObject tetrahedron() {
			// TODO: tetraedron
			return cube();
		}

		// Generates a torus.
		SceneObject torus() {
			// TODO: torus
			return cube();
		}

		// Generates a sphere.
		SceneObject sphere() {
			// TODO: sphere
			return cube();
		}

		SceneObject generateObject(Shape objShape) {
			switch (objShape) {
			case CUBE:
				return cube();
			case PYRAMID:
				return pyramid();
			case TETRAHEDRON:
				return tetrahedron();
			case OCTAHEDRON:
				return octahedron();
			case SPHERE:
				return sphere();
			case TORUS:
				return torus();
			}
		}
	}
}