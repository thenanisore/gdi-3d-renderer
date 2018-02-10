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
			const std::vector<Vector3> vertices = {
				Vector3(0, -2, 0), Vector3(1, 0, 1), Vector3(-1, 0, 1),
				Vector3(1, 0, -1), Vector3(-1, 0, -1), Vector3(0, 2, 0)
			};
			const std::vector<Vector3> indices = {
				Vector3(0, 1, 2), Vector3(0, 3, 1), Vector3(0, 4, 3), Vector3(0, 2, 4),
				Vector3(2, 1, 5), Vector3(1, 3, 5), Vector3(3, 4, 5), Vector3(2, 5, 4)
			};
			const std::vector<Vector4> colors = {
				Vector4(1, 1, 1, 1), Vector4(1, 0, 1, 1), Vector4(1, 0, 1, 1),
				Vector4(1, 0, 1, 1), Vector4(1, 0, 1, 1), Vector4(1, 1, 1, 1)
			};
			return SceneObject(vertices, colors, indices);
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
			// generate icosahedron first
			float t = (1.f + sqrt(5.f)) / 2.f;

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