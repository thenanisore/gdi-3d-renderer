#include "Scene.h"
#include "Matrix.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	Scene::Scene() : camera(Vector3(0, 0, -5), Vector3(0, 0, 0), Vector3(0, 1, 0)) {
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

		// 4. model matrix transformations
		Matrix4 model;
		Util::rotateY(model, 15.0f);
		Util::rotateX(model, 15.0f);
		Util::rotateZ(model, 15.0f);
		Util::scale(model, Vector3(1.0f, 1.0f, 1.0f));
		Util::translate(model, Vector3(0.0f, 0.0f, 1.0f));

		// 5. get view and projection matrices
		Matrix4 view = camera.getLookAt();
		Matrix4 projection = camera.perspective(45.0f, 0, 0.1f, 100.0f);

		// 6. pass in a current object, a viewProjectin matrix and render
		renderer->renderObject(sceneObjects[0], projection * view * model);
	}

	void Scene::addObject(SceneObject obj) {
		sceneObjects.push_back(obj);
	}

	// methods to manipulate objects:

	void Scene::setObjectPosition(int x_coord, int y_coord, int z_coord) {
	}

	void Scene::setObjectRotation(float x_angle, float y_angle, float z_angle) {

	}

	void Scene::setObjectReflection(bool xy, bool xz, bool yz) {

	}

	void Scene::setObjectScale(int x_scale, int y_scale, int z_scale) {

	}

	// methods to manipulate the camera:

	void Scene::setCameraPosition(int x_coord, int y_coord, int z_coord) {

	}

	void Scene::setCameraRotation(float pitch, float yawn, float roll) {

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