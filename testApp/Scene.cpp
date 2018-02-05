#include "stdafx.h"
#include "Scene.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	Scene::Scene() : camera(Vector3(0, 0, 3), Vector3(0, 0, 0), Vector3(0, 1, 0)) {
		// test code
		addCube();
	}

	void Scene::renderScene(Graphics ^gr, Color ^col, Pen ^pen) {
		sceneObjects[0].scale(Vector3(1, 1, 1) * 80);
		sceneObjects[0].translate(Vector3(300, 150, 0));
		sceneObjects[0].rotateY(30);
		sceneObjects[0].rotateX(30);
		sceneObjects[0].rotateZ(30);
		sceneObjects[0].transformPolygons(camera.getLookAt());
		//sceneObjects[0].transformPolygons(camera.getProjection(0, 0, 0, 0));
		gr->Clear(col->LightYellow);
		for (GL::Polygon pol : sceneObjects[0].polygons) {
			for (int i = 0; i < pol.vertices.size() - 1; i++) {
				gr->DrawLine(pen, pol.vertices[i].x, pol.vertices[i].y, pol.vertices[i + 1].x, pol.vertices[i + 1].y);
			}
			gr->DrawLine(pen, pol.vertices[pol.vertices.size() - 1].x, pol.vertices[pol.vertices.size() - 1].y, pol.vertices[0].x, pol.vertices[0].y);
		}
	}

	void Scene::addObject(SceneObject obj) {
		sceneObjects.push_back(obj);
	}

	// test
	void Scene::addCube() {
		SceneObject cube(std::vector<Polygon> {
			// front
			Polygon(std::vector<Vector3> { Vector3(1, -1, 1), Vector3(1, 1, 1), Vector3(-1, 1, 1) }),
			Polygon(std::vector<Vector3> { Vector3(-1, 1, 1), Vector3(-1, -1, 1), Vector3(1, -1, 1) }),
			// right
			Polygon(std::vector<Vector3> { Vector3(1, -1, 1), Vector3(1, -1, -1), Vector3(1, 1, -1) }),
			Polygon(std::vector<Vector3> { Vector3(1, 1, -1), Vector3(1, 1, 1), Vector3(1, -1, 1) }),
			// back
			Polygon(std::vector<Vector3> { Vector3(1, 1, -1), Vector3(1, -1, -1), Vector3(-1, -1, -1) }),
			Polygon(std::vector<Vector3> { Vector3(-1, -1, -1), Vector3(-1, 1, -1), Vector3(1, 1, -1) }),
			// left
			Polygon(std::vector<Vector3> { Vector3(-1, -1, 1), Vector3(-1, 1, -1), Vector3(-1, -1, -1) }),
			Polygon(std::vector<Vector3> { Vector3(-1, -1, 1), Vector3(-1, 1, 1), Vector3(-1, 1, -1) }),
			// top
			Polygon(std::vector<Vector3> { Vector3(1, 1, 1), Vector3(1, 1, -1), Vector3(-1, 1, -1) }),
			Polygon(std::vector<Vector3> { Vector3(-1, 1, -1), Vector3(-1, 1, 1), Vector3(1, 1, 1) }),
			// bottom
			Polygon(std::vector<Vector3> { Vector3(-1, -1, -1), Vector3(1, -1, -1), Vector3(1, -1, 1) }),
			Polygon(std::vector<Vector3> { Vector3(-1, -1, -1), Vector3(1, -1, 1), Vector3(1, -1, -1) })
		});
		sceneObjects.push_back(cube);
	}
}