#include "Scene.h"
#include "Matrix.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	Scene::Scene() : camera(Vector3(0, 0, -5), Vector3(0, 0, 0), Vector3(0, 1, 0)) {
		// test code
		addCube();
		selectedObject = 0;
	}

	void Scene::renderScene(Renderer ^renderer) {
		// 1. clear Z buffer
		renderer->clearZBuffer();

		// 2. clear screen
		renderer->clearScreen();

		// 3. draw axes/grid

		// 4. model matrix transformations
		Matrix4 model = sceneObjects[selectedObject].getModelMatrix();
		//model = Util::rotateY(model, 15.0f);
		//model = Util::rotateX(model, 15.0f);
		//model = Util::rotateZ(model, 15.0f);
		//model = Util::scale(model, Vector3(1.0f, 1.0f, 1.0f));
		//model = Util::translate(model, Vector3(0.0f, 0.0f, 0.0f));

		// 5. get view and projection matrices
		Matrix4 view = camera.getLookAt();
		Matrix4 projection = camera.perspective(60.0f, 0, 0.1f, 100.0f);

		// 6. pass in a current object, a viewProjectin matrix and render
		renderer->renderObject(sceneObjects[selectedObject], projection * view * model);
	}

	void Scene::addObject(SceneObject obj) {
		sceneObjects.push_back(obj);
	}

	// methods to manipulate objects:

	const float positionMultiplier = 0.1f;
	void Scene::setObjectPosition(int x_coord, int y_coord, int z_coord) {
		sceneObjects[selectedObject].setPosition(Vector3(x_coord, y_coord, z_coord) * positionMultiplier);
	}

	const float rotationMultiplier = 1.0f;
	void Scene::setObjectRotation(float x_angle, float y_angle, float z_angle) {
		sceneObjects[selectedObject].setRotation(Vector3(x_angle, y_angle, z_angle) * rotationMultiplier);
	}

	const float scaleMultiplier = 0.1f;
	void Scene::setObjectScale(int x_scale, int y_scale, int z_scale) {
		sceneObjects[selectedObject].setScale(Vector3(x_scale, y_scale, z_scale) * scaleMultiplier);
	}

	void Scene::setObjectReflection(bool xy, bool xz, bool yz) {
		sceneObjects[selectedObject].setReflection(xy, xz, yz);
	}

	void Scene::resetObject() {
		sceneObjects[selectedObject].reset();
	}

	void Scene::deleteObject() {
		// TODO
	}

	void Scene::selectNextObject() {
		if (selectedObject < sceneObjects.size()) {
			selectedObject++;
		}
	}

	void Scene::selectPreviousObject() {
		if (selectedObject > 0) {
			selectedObject--;
		}
	}

	// methods to manipulate the camera:

	const float cameraPositionMultiplier = 0.1f;
	void Scene::setCameraPosition(int x_coord, int y_coord, int z_coord) {
		camera.setPosition(Vector3(x_coord, y_coord, z_coord) * cameraPositionMultiplier);
	}

	const float camerRotationMultiplier = 1.0f;
	void Scene::setCameraRotation(float pitch, float yawn, float roll) {
		camera.setRotation(Vector3(pitch, yawn, roll) * camerRotationMultiplier);
	}

	void Scene::resetCamera() {
		camera.reset();
	}

	bool Scene::isEmpty() {
		return sceneObjects.size() == 0;
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