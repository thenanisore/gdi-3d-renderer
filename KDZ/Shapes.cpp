#pragma once

#include "Shapes.h"
#include "Util.h"

namespace GL {

	// The Shapes.h file contains some pre-defined 3-dimensional objects.
	namespace Objects {

		// Returns a cube.
		SceneObject cube() {
			const std::vector<Vector3> vertices = {
				Vector3(1, 1, 1), Vector3(1, 1, -1), 
				Vector3(1, -1, 1), Vector3(1, -1, -1),
				Vector3(-1, 1, 1), Vector3(-1, 1, -1),
				Vector3(-1, -1, 1), Vector3(-1, -1, -1)
			};
			const std::vector<Vector3> indices = {
				Vector3(2, 0, 4), Vector3(4, 6, 2), // front
				Vector3(2, 3, 1), Vector3(1, 0, 2), // right
				Vector3(1, 3, 7), Vector3(7, 5, 1), // back
				Vector3(6, 5, 7), Vector3(6, 4, 5), // left
				Vector3(0, 1, 5), Vector3(5, 4, 0), // top
				Vector3(7, 3, 2), Vector3(2, 6, 7), // bottom
			};
			const std::vector<Vector4> colors = {
				Vector4(0, 0, 0, 1), Vector4(0, 0, 1, 1), 
				Vector4(0, 1, 0, 1), Vector4(0, 1, 1, 1), 
				Vector4(1, 0, 0, 1), Vector4(1, 0, 1, 1), 
				Vector4(1, 1, 0, 1), Vector4(1, 1, 1, 1)
			};
			return SceneObject(vertices, colors, indices);
		}

		// Returns a pyramid.
		SceneObject pyramid() {
			const std::vector<Vector3> vertices = {
				Vector3(0, 1, 0), 
				Vector3(1, -1, 1), Vector3(1, -1, -1),
				Vector3(-1, -1, 1), Vector3(-1, -1, -1)
			};
			const std::vector<Vector3> indices = {
				Vector3(1, 0, 3), // front
				Vector3(2, 0, 1), // right
				Vector3(4, 0, 2), // back
				Vector3(3, 0, 4), // left
				Vector3(1, 3, 4), Vector3(1, 4, 2), // bottom
			};
			const std::vector<Vector4> colors = {
				Vector4(1, 1, 1, 1), 
				Vector4(0.5, 0.5, 1, 1), Vector4(0.5, 0.5, 1, 1), 
				Vector4(0.5, 0.5, 1, 1), Vector4(0.5, 0.5, 1, 1)
			};
			return SceneObject(vertices, colors, indices);
		}

		// Generates an octahedron.
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

		// Generates a tetrahedron.
		SceneObject tetrahedron() {
			// TODO: tetraedron
			return cube();
		}

		// Generates a torus.
		SceneObject torus() {
			// TODO: torus
			return cube();
		}

		// Finds a vector between a and b disregarding w coordinate (w = 1).
		Vector4 middle(const Vector4 &a, const Vector4 &b) {
			Vector4 m = (a + b) * 0.5f;
			m.w = 1.f;
			return m;
		}

		void spherize(Polygon &poly, float radius) {
			for (int i = 0; i < poly.vertices.size(); i++) {
				poly.vertices[i] = Vector4((poly.vertices[i].toVec3().normalized()) * radius, 1.f);
				poly.normals[i] = poly.vertices[i].toVec3();
			}
		}

		std::vector<GL::Polygon> refinePolygon(const GL::Polygon &poly) {
			std::vector<GL::Polygon> refined;
			// middle points and middle values
			Vector4 mid01 = middle(poly.vertices[0], poly.vertices[1]);
			Vector4 mid12 = middle(poly.vertices[1], poly.vertices[2]);
			Vector4 mid20 = middle(poly.vertices[2], poly.vertices[0]);
			Vector4 colorMid01 = middle(poly.colors[0], poly.colors[1]);
			Vector4 colorMid12 = middle(poly.colors[1], poly.colors[2]);
			Vector4 colorMid20 = middle(poly.colors[2], poly.colors[0]);
			Vector3 normalMid01 = ((poly.normals[0] + poly.normals[1]) * 0.5f).normalized();
			Vector3 normalMid12 = ((poly.normals[1] + poly.normals[2]) * 0.5f).normalized();
			Vector3 normalMid20 = ((poly.normals[2] + poly.normals[0]) * 0.5f).normalized();
			// construct 4 new polygons
			refined.push_back(Polygon(poly.vertices[0], mid01, mid20));
			refined.push_back(Polygon(poly.vertices[1], mid12, mid01));
			refined.push_back(Polygon(poly.vertices[2], mid20, mid12));
			refined.push_back(Polygon(mid01, mid12, mid20));
			refined[0].setColors(poly.colors[0], colorMid01, colorMid20);
			refined[1].setColors(poly.colors[1], colorMid12, colorMid01);
			refined[2].setColors(poly.colors[2], colorMid20, colorMid12);
			refined[3].setColors(colorMid01, colorMid12, colorMid20);
			refined[0].setNormals(poly.normals[0], normalMid01, normalMid20);
			refined[1].setNormals(poly.normals[1], normalMid01, normalMid20);
			refined[2].setNormals(poly.normals[2], normalMid01, normalMid20);
			refined[3].setNormals(normalMid01, normalMid01, normalMid20);
			return refined;
		}

		// Generates a sphere.
		SceneObject sphere() {
			// generate icosahedron first
			float t = (1.f + sqrt(5.f)) / 2.f;
			const std::vector<Vector3> vertices = {
				Vector3(-1, t, 0), Vector3(1, t, 0), Vector3(-1, -t, 0), Vector3(1, -t, 0), 
				Vector3(0, -1, t), Vector3(0, 1, t), Vector3(0, -1, -t), Vector3(0, 1, -t), 
				Vector3(t, 0, -1), Vector3(t, 0, 1), Vector3(-t, 0, -1), Vector3(-t, 0, 1)
			};
			const std::vector<Vector3> indices = {
				Vector3(0, 11, 5),
				Vector3(0, 5, 1),
				Vector3(0, 1, 7),
				Vector3(0, 7, 10),
				Vector3(0, 10, 11),

				Vector3(1, 5, 9),
				Vector3(5, 11, 4),
				Vector3(11, 10, 2),
				Vector3(10, 7, 6),
				Vector3(7, 1, 8),

				Vector3(3, 9, 4),
				Vector3(3, 4, 2),
				Vector3(3, 2, 6),
				Vector3(3, 6, 8),
				Vector3(3, 8, 9),

				Vector3(4, 9, 5),
				Vector3(2, 4, 11),
				Vector3(6, 2, 10),
				Vector3(8, 6, 7),
				Vector3(9, 8, 1)
			};
			const std::vector<Vector4> colors = {
				Vector4(1, 0, 1, 1), Vector4(1, 0, 1, 1), Vector4(1, 0, 1, 1),
				Vector4(1, 0, 1, 1), Vector4(1, 0, 1, 1), Vector4(1, 0, 1, 1),
				Vector4(1, 0, 1, 1), Vector4(1, 0, 1, 1), Vector4(1, 0, 1, 1),
				Vector4(1, 0, 1, 1), Vector4(1, 0, 1, 1), Vector4(1, 0, 1, 1)
			};
			SceneObject iso = SceneObject(vertices, colors, indices);

			const int precisionLevel = 4;
			const float radius = 2.5f;

			// refine each triangle N times
			for (int i = 0; i < precisionLevel; i++) {
				std::vector<GL::Polygon> refined;
				for (const Polygon &poly : iso.polygons) {
					std::vector<GL::Polygon> polys = refinePolygon(poly);
					// append polygons
					refined.insert(std::end(refined), std::begin(polys), std::end(polys));
				}
				for (int i = 0; i < refined.size(); i++) {
					spherize(refined[i], radius);
				}
				Util::swap(iso.polygons, refined);
			}
			return iso;
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