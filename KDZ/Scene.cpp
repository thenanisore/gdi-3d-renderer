#include "Scene.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	Scene::Scene() : camera(Vector3(0, 0, 3), Vector3(0, 0, 0), Vector3(0, 1, 0)) {
		// 1. set up the camera
		// 2. set up the renderer (or pass him in renderScene method?)

		// test code
		addCube();
	}

	void Scene::renderScene(Renderer ^renderer) {
		// 1. clear Z buffer
		renderer->clearZBuffer();

		// 2. clear screen
		renderer->clearScreen();

		// 3. draw axes/grid

		// 4. perform all model transformations

		// test code
		sceneObjects[0].rotateY(45);
		sceneObjects[0].rotateX(45);
		//sceneObjects[0].rotateZ(45);
		sceneObjects[0].scale(Vector3(1, 1, 1) * 80);
		sceneObjects[0].translate(Vector3(200, 200, 0));
		sceneObjects[0].transform(camera.getLookAt());
		//sceneObjects[0].transformPolygons(camera.getProjection(0, 0, 0, 0));

		// 5. get view and projection matrices, transform every object
		Matrix4 view = camera.getLookAt();
		Matrix4 projection = camera.perspective(0, 0, 0, 0);

		// 6. apply all transformations, change polygon coordinates

		// 7. render
		renderer->renderObject(sceneObjects[0]);
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